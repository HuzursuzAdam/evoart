#ifndef CMD_VEL_TO_ACKERMANN_HPP_
#define CMD_VEL_TO_ACKERMANN_HPP_

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "evoart_interfaces/msg/vehicle_control.hpp"

namespace evoart_control
{
class CmdVelToAckermann : public rclcpp::Node
{
public:
    CmdVelToAckermann();

private:
    void cmdVelCallback(const geometry_msgs::msg::Twist::SharedPtr msg);

    // Parametreler
    double wheelbase_;
    double max_steering_angle_;

    // Abone ve Yayıncı
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr sub_cmd_vel_;
    rclcpp::Publisher<evoart_interfaces::msg::VehicleControl>::SharedPtr pub_vehicle_cmd_;
};
} // namespace evoart_control

#endif // CMD_VEL_TO_ACKERMANN_HPP_
