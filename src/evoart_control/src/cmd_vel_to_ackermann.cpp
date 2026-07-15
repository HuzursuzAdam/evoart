#include "evoart_control/cmd_vel_to_ackermann.hpp"
#include <cmath>
#include <algorithm>

namespace evoart_control
{
CmdVelToAckermann::CmdVelToAckermann() : Node("cmd_vel_to_ackermann_node")
{
    this->declare_parameter<double>("wheelbase", 1.425);
    this->declare_parameter<double>("max_steering_angle",  0.349);

    this->get_parameter("wheelbase", wheelbase_);
    this->get_parameter("max_steering_angle", max_steering_angle_);

    sub_cmd_vel_ = this->create_subscription<geometry_msgs::msg::Twist>(
        "/cmd_vel", 10, std::bind(&CmdVelToAckermann::cmdVelCallback, this, std::placeholders::_1));
    
    // ─── KESİN ÇÖZÜM: INTRA-PROCESS BAYPASI ───
    // Derleyicinin çöktüğü hafıza yöneticisini tamamen devre dışı bırakıyoruz.
    rclcpp::PublisherOptions pub_options;
    pub_options.use_intra_process_comm = rclcpp::IntraProcessSetting::Disable;
    
    // Yayıncıyı (Publisher) bu özel ayarlarla kuruyoruz
    pub_vehicle_cmd_ = this->create_publisher<evoart_interfaces::msg::VehicleControl>(
        "/vehicle_command", 10, pub_options);
        
    RCLCPP_INFO(this->get_logger(), "CmdVel -> Ackermann Donusturucu Basladi.");
    RCLCPP_INFO(this->get_logger(), "Wheelbase: %.3f m, Max Steering: %.3f rad", wheelbase_, max_steering_angle_);
}

void CmdVelToAckermann::cmdVelCallback(const geometry_msgs::msg::Twist::SharedPtr msg)
{
    auto cmd_msg = evoart_interfaces::msg::VehicleControl();
    
    double v = msg->linear.x;
    double w = msg->angular.z;
    double steering_angle = 0.0;

    // Kinematik Dönüşüm
    if (std::abs(v) > 0.01) {
        steering_angle = std::atan((wheelbase_ * w) / v);
    } else if (std::abs(w) > 0.01) {
        steering_angle = (w > 0) ? max_steering_angle_ : -max_steering_angle_;
    }

    // Açıyı maksimum limitlere kırp
    steering_angle = std::clamp(steering_angle, -max_steering_angle_, max_steering_angle_);

    cmd_msg.target_velocity = v;
    cmd_msg.steering_angle = steering_angle;
    
    pub_vehicle_cmd_->publish(cmd_msg);
}
} // namespace evoart_control

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<evoart_control::CmdVelToAckermann>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
