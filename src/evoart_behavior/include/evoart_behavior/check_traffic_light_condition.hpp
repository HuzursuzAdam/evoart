#ifndef CHECK_TRAFFIC_LIGHT_CONDITION_HPP
#define CHECK_TRAFFIC_LIGHT_CONDITION_HPP

#include <rclcpp/rclcpp.hpp>
#include <behaviortree_cpp_v3/condition_node.h>
#include "evoart_interfaces/msg/traffic_light.hpp" // Özel mesajımızı içeri aktarıyoruz

namespace evoart_behavior
{
class CheckTrafficLightCondition : public BT::ConditionNode
{
public:
    CheckTrafficLightCondition(const std::string& name, const BT::NodeConfiguration& config, rclcpp::Node::SharedPtr node);

    static BT::PortsList providedPorts()
    {
        return {}; // Şimdilik dışarıdan bir XML parametresi almıyoruz
    }

    // Condition düğümleri sadece "tick" çalıştırır, asenkron değillerdir
    BT::NodeStatus tick() override;

private:
    rclcpp::Node::SharedPtr node_;
    rclcpp::Subscription<evoart_interfaces::msg::TrafficLight>::SharedPtr sub_;
    
    // Kameradan gelen son ışık verisini tutacağımız değişken
    int8_t current_light_color_;

    void trafficLightCallback(const evoart_interfaces::msg::TrafficLight::SharedPtr msg);
};

} // namespace evoart_behavior

#endif // CHECK_TRAFFIC_LIGHT_CONDITION_HPP
