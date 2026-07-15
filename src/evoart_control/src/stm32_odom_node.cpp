#include "evoart_control/stm32_odom_node.hpp"
#include <fcntl.h>    
#include <termios.h>  
#include <unistd.h>   
#include <cmath>      // M_PI (Pi sayısı) ve matematiksel işlemler için gerekli

Stm32OdomNode::Stm32OdomNode() : Node("stm32_odom_node"), serial_fd_(-1)
{
    this->declare_parameter<std::string>("serial_port", "/dev/ttyUSB0");
    this->declare_parameter<int>("baud_rate", 115200);
    this->declare_parameter<double>("wheel_radius", 0.27);  // Tekerlek yarıçapı (m)
    this->declare_parameter<double>("wheelbase", 1.425);
    this->declare_parameter<double>("max_steering_angle", 0.349);
    
    this->get_parameter("serial_port", serial_port_);
    this->get_parameter("baud_rate", baud_rate_);
    this->get_parameter("wheel_radius", wheel_radius_);
    this->get_parameter("wheelbase", wheelbase_);
    this->get_parameter("max_steering_angle", max_steering_angle_);

    odom_pub_ = this->create_publisher<nav_msgs::msg::Odometry>("wheel/odometry", 10);

    vehicle_cmd_sub_ = this->create_subscription<evoart_interfaces::msg::VehicleControl>(
        "/vehicle_command", 10, std::bind(&Stm32OdomNode::vehicle_cmd_callback, this, std::placeholders::_1));

    if (init_serial()) {
        RCLCPP_INFO(this->get_logger(), "Seri port başarıyla açıldı: %s", serial_port_.c_str());
    } else {
        RCLCPP_ERROR(this->get_logger(), "Seri port AÇILAMADI!");
    }

    timer_ = this->create_wall_timer(
        std::chrono::milliseconds(20),
        std::bind(&Stm32OdomNode::timer_callback, this)
    );
}

Stm32OdomNode::~Stm32OdomNode()
{
    if (serial_fd_ != -1) {
        close(serial_fd_);
    }
}

bool Stm32OdomNode::init_serial()
{
    serial_fd_ = open(serial_port_.c_str(), O_RDWR | O_NOCTTY | O_NDELAY);
    if (serial_fd_ == -1) return false;

    struct termios tty;
    if (tcgetattr(serial_fd_, &tty) != 0) return false;

    tty.c_cflag &= ~PARENB; 
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;
    tty.c_cflag |= CREAD | CLOCAL;

    cfsetispeed(&tty, B115200);
    cfsetospeed(&tty, B115200);

    tty.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    tty.c_iflag &= ~(IXON | IXOFF | IXANY);
    tty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL);
    tty.c_oflag &= ~OPOST;

    if (tcsetattr(serial_fd_, TCSANOW, &tty) != 0) return false;
    return true;
}

void Stm32OdomNode::vehicle_cmd_callback(const evoart_interfaces::msg::VehicleControl::SharedPtr msg)
{
    if (serial_fd_ == -1) return;

    // --- A. HIZ, YÖN VE FREN HESAPLAMALARI ---
    double v = msg->target_velocity;
    
    // Güvenlik Kilidi: Maksimum 5 m/s, Minimum -5 m/s
    if (v > 5.0) v = 5.0;
    if (v < -5.0) v = -5.0;

    uint8_t direction = 100; // Varsayılan: İleri
    uint8_t brake = 0;       // Varsayılan: Fren Yok

    if (v < -0.01) {
        direction = 200; // Geri vites
    }
    
    if (std::abs(v) < 0.01) {
        brake = 1; // Hız 0 ise freni çek
    }

    // --- YENİ HIZ HESAPLAMASI (0-5 m/s -> 1500-2000 PWM) ---
    // Mutlak hızı 100 ile çarpıp 1500'e ekliyoruz.
    double speed_pwm = 1500.0 + (std::abs(v) * 100.0);
    
    // Değerin 1500 ile 2000 dışına çıkmasını kesin olarak engelliyoruz
    speed_pwm = std::clamp(speed_pwm, 1500.0, 2000.0);
    uint16_t target_speed = static_cast<uint16_t>(speed_pwm);

    // --- B. DİREKSİYON HESAPLAMASI (Formül ile) ---
    double steer_pwm = 1500.0 - (msg->steering_angle / max_steering_angle_) * 500.0;
    steer_pwm = std::clamp(steer_pwm, 1000.0, 2000.0);
    uint16_t target_steer = static_cast<uint16_t>(steer_pwm);

    // --- C. 8 BYTE'LIK PAKETİ OLUŞTUR VE GÖNDER ---
    uint8_t tx_buffer[8];
    tx_buffer[0] = 16;
    tx_buffer[1] = 128;
    
    // Hız verisi (Artık RPM değil, 1500-2000 arası PWM değeri)
    tx_buffer[2] = (target_speed >> 8) & 0xFF;
    tx_buffer[3] = target_speed & 0xFF;
    
    // Direksiyon verisi
    tx_buffer[4] = (target_steer >> 8) & 0xFF;
    tx_buffer[5] = target_steer & 0xFF;
    
    // Yön ve Fren
    tx_buffer[6] = direction;
    tx_buffer[7] = brake;

    int bytes_written = write(serial_fd_, tx_buffer, 8);
    if (bytes_written > 0) {
        RCLCPP_INFO(this->get_logger(), 
            "YAZILDI -> Hız(PWM):%d | Açı(PWM):%d | Yön:%d | Fren:%d", 
            target_speed, target_steer, direction, brake);
    }
}

// ─── 2. OKUMA (STM32 -> ROS 2) HİZALAMA FONKSİYONU ───
void Stm32OdomNode::timer_callback()
{
    if (serial_fd_ == -1) return;

    uint8_t buf[256];
    int n = read(serial_fd_, buf, sizeof(buf));

    if (n > 0) {
        serial_buffer_.insert(serial_buffer_.end(), buf, buf + n);

        while (serial_buffer_.size() >= 8) {
            
            // YENİ HİZALAMA KURALI: 0. index 32, 1. index 16 olmalı!
            if (serial_buffer_[0] != 32 || serial_buffer_[1] != 16) {
                serial_buffer_.erase(serial_buffer_.begin());
                continue;
            }

            std::vector<uint8_t> packet(serial_buffer_.begin(), serial_buffer_.begin() + 8);
            process_binary_packet(packet);
            serial_buffer_.erase(serial_buffer_.begin(), serial_buffer_.begin() + 8);
        }
    }
}

void Stm32OdomNode::process_binary_packet(const std::vector<uint8_t>& packet)
{
    uint8_t header1 = packet[0];
    uint8_t header2 = packet[1];
    // B2 (MSB) ve B3 (LSB) birleştirilerek 16-bit Hız değeri elde edilir
    uint16_t speed_val = (packet[2] << 8) | packet[3];

    // B4 (MSB) ve B5 (LSB) birleştirilerek 16-bit Direksiyon değeri elde edilir
    uint16_t steer_val = (packet[4] << 8) | packet[5];

    // B6: Yön bilgisi (100 veya 200)
    uint8_t direction_val = packet[6];

    // B7: Fren bilgisi (0 veya 1)
    uint8_t brake_val = packet[7];

    // İstenilen format: Sadece onluk tabandaki saf sayısal değerleri ekrana bas
    RCLCPP_INFO(this->get_logger(), 
        "OKUNDU ->  Sabit1: %u | Sabit2: %u | Direksiyon: %u | Hız: %u | Yön: %u | Fren: %u",
        header1, header2, speed_val, steer_val, direction_val, brake_val);
}

void Stm32OdomNode::publish_odometry(double /*rpm*/, double /*steering_angle_deg*/)
{
    // EKF entegrasyonu için ayrılmış alan
    // Parametre isimleri yorum satırına alındığı için derleyici artık uyarı vermeyecek.
}

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Stm32OdomNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
