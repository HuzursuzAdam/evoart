// Dosya: ~/evoart_ws/src/evoart_behavior/src/bt_engine.cpp

#include <rclcpp/rclcpp.hpp>
#include <behaviortree_cpp_v3/bt_factory.h>
#include <behaviortree_cpp_v3/loggers/bt_cout_logger.h>
#include <ament_index_cpp/get_package_share_directory.hpp>

// Yazdığımız özel düğümlerin başlık dosyalarını ekliyoruz
#include "evoart_behavior/navigate_to_pose_action.hpp"
#include "evoart_behavior/check_traffic_light_condition.hpp"

int main(int argc, char **argv)
{
    // ROS 2'yi başlat
    rclcpp::init(argc, argv);
    auto node = std::make_shared<rclcpp::Node>("bt_engine_node");

    // Behavior Tree Fabrikasını oluştur
    BT::BehaviorTreeFactory factory;

    // 1. ÖZEL DÜĞÜMLERİMİZİ FABRİKAYA KAYDEDİYORUZ
    // Ağacın XML dosyasındaki isimleri bu C++ sınıflarıyla eşleştirmesi için:
    factory.registerBuilder<evoart_behavior::NavigateToPoseAction>(
        "NavigateToPoseAction",
        [node](const std::string& name, const BT::NodeConfiguration& config) {
            return std::make_unique<evoart_behavior::NavigateToPoseAction>(name, config, node);
        });

    factory.registerBuilder<evoart_behavior::CheckTrafficLightCondition>(
        "CheckTrafficLightCondition",
        [node](const std::string& name, const BT::NodeConfiguration& config) {
            return std::make_unique<evoart_behavior::CheckTrafficLightCondition>(name, config, node);
        });

    // 2. XML DOSYASINI BUL VE AĞACI OLUŞTUR
    std::string pkg_share_dir = ament_index_cpp::get_package_share_directory("evoart_behavior");
    std::string xml_file_path = pkg_share_dir + "/bt_xml/robotaksi_tree.xml";
    
    RCLCPP_INFO(node->get_logger(), "Behavior Tree Yukleniyor: %s", xml_file_path.c_str());
    
    auto tree = factory.createTreeFromFile(xml_file_path);

    // Ağacın ne yaptığını terminalde görmek için basit bir loglayıcı
    BT::StdCoutLogger logger_cout(tree);

    // 3. AĞACI SÜREKLİ OLARAK ÇALIŞTIR (TICK LOOP)
    rclcpp::Rate loop_rate(10); // Saniyede 10 kez çalışsın (10 Hz)
    
    while (rclcpp::ok()) {
        // Ağacı bir kez tur attır
        BT::NodeStatus status = tree.tickRoot();
        
        // Eğer ağaç tamamen biterse veya iptal olursa döngüyü kır
        if (status == BT::NodeStatus::SUCCESS || status == BT::NodeStatus::FAILURE) {
            RCLCPP_INFO(node->get_logger(), "Gorev Agaci Tamamlandi. Durum: %s", 
                        status == BT::NodeStatus::SUCCESS ? "BASARILI" : "BASARISIZ");
            break;
        }

        // ROS 2'nin arkadaki mesajları (Traffic Light gibi) okuyabilmesi için spin_some şarttır
        rclcpp::spin_some(node);
        loop_rate.sleep();
    }

    rclcpp::shutdown();
    return 0;
}
