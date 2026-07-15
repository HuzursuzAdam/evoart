#include "evoart_behavior/check_traffic_light_condition.hpp"

namespace evoart_behavior
{

CheckTrafficLightCondition::CheckTrafficLightCondition(const std::string& name, const BT::NodeConfiguration& config, rclcpp::Node::SharedPtr node)
    : BT::ConditionNode(name, config), node_(node)
{
    // Varsayılan olarak ışığı "YEŞİL" kabul et (Araç hareket edebilsin diye)
    // Güvenlik için bunu KIRMIZI (0) da başlatabilirsin.
    current_light_color_ = evoart_interfaces::msg::TrafficLight::GREEN;

    // Perception (YOLO) paketinden gelen ışık verisini abone olup dinlemeye başlıyoruz
    sub_ = node_->create_subscription<evoart_interfaces::msg::TrafficLight>(
        "/traffic_light_status", 10,
        std::bind(&CheckTrafficLightCondition::trafficLightCallback, this, std::placeholders::_1));
}

void CheckTrafficLightCondition::trafficLightCallback(const evoart_interfaces::msg::TrafficLight::SharedPtr msg)
{
    // YOLO'dan yeni veri geldiğinde içerdeki değişkeni güncelle
    current_light_color_ = msg->color;
}

BT::NodeStatus CheckTrafficLightCondition::tick()
{
    // Ağaç her turda buraya uğrayıp soracak: "Geçeyim mi?"
    
    if (current_light_color_ == evoart_interfaces::msg::TrafficLight::RED) {
        RCLCPP_WARN(node_->get_logger(), "Işık KIRMIZI! Geçiş Yasak.");
        return BT::NodeStatus::FAILURE; // Ağaca "Başarısız" dön ki Nav2'yi durdursun
    } 
    else if (current_light_color_ == evoart_interfaces::msg::TrafficLight::YELLOW) {
        RCLCPP_WARN(node_->get_logger(), "Işık SARI! Dikkat et.");
        // Sarı ışık kuralına göre burada FAILURE da dönebilirsin, ama şimdilik devam edelim
        return BT::NodeStatus::SUCCESS;
    }
    
    // Işık yeşilse veya hiçbir tabela yoksa devam et
    return BT::NodeStatus::SUCCESS;
}

} // namespace evoart_behavior
