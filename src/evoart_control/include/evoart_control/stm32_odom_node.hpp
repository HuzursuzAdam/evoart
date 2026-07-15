#ifndef STM32_ODOM_NODE_HPP_
#define STM32_ODOM_NODE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "evoart_interfaces/msg/vehicle_control.hpp" // Özel mesaj kütüphanemiz
#include <vector>
#include <cstdint>
#include <string>

class Stm32OdomNode : public rclcpp::Node
{
public:
    Stm32OdomNode();
    ~Stm32OdomNode();

private:
    // ROS 2 Parametreleri (Kinematik ve Seri Haberleşme)
    std::string serial_port_;
    int baud_rate_;
    double wheel_radius_;
    double wheelbase_;
    
    // EKSİK OLAN VE EKLENMESİ GEREKEN SATIR BURASI:
    double max_steering_angle_;

    // Seri port dosya tanımlayıcısı ve veri tamponu
    int serial_fd_;
    std::vector<uint8_t> serial_buffer_;


    // ROS 2 Nesneleri (Yayıncılar, Aboneler ve Zamanlayıcılar)
    rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr odom_pub_;
    rclcpp::Subscription<evoart_interfaces::msg::VehicleControl>::SharedPtr vehicle_cmd_sub_;
    rclcpp::TimerBase::SharedPtr timer_;

    // Core Fonksiyonlar
    bool init_serial();
    
    // Okuma (STM32 -> ROS 2)
    void timer_callback();
    void process_binary_packet(const std::vector<uint8_t>& packet);
    
    // Yazma (ROS 2 -> STM32)
    void vehicle_cmd_callback(const evoart_interfaces::msg::VehicleControl::SharedPtr msg);
    
    // Gelecekteki Nav2 Odom Entegrasyonu İçin
    void publish_odometry(double rpm, double steering_angle_deg);
};

#endif // STM32_ODOM_NODE_HPP_
