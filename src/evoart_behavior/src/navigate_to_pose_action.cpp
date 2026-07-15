// Dosya: ~/evoart_ws/src/evoart_behavior/src/navigate_to_pose_action.cpp

#include "evoart_behavior/navigate_to_pose_action.hpp"

namespace evoart_behavior
{

NavigateToPoseAction::NavigateToPoseAction(const std::string& name, const BT::NodeConfiguration& config, rclcpp::Node::SharedPtr node)
    : BT::StatefulActionNode(name, config), node_(node), goal_done_(false)
{
    // Nav2'nin eylem sunucusuna istemci (client) olarak bağlanıyoruz
    action_client_ = rclcpp_action::create_client<NavigateToPose>(node_, "navigate_to_pose");
}

BT::NodeStatus NavigateToPoseAction::onStart()
{
    // 1. Ağaçtan (XML) hedef koordinatları oku
    double goal_x, goal_y, goal_yaw;
    if (!getInput("goal_x", goal_x) || !getInput("goal_y", goal_y) || !getInput("goal_yaw", goal_yaw)) {
        RCLCPP_ERROR(node_->get_logger(), "Hedef koordinatlar okunamadi!");
        return BT::NodeStatus::FAILURE;
    }

    // 2. Nav2 sunucusu ayakta mı kontrol et
    if (!action_client_->wait_for_action_server(std::chrono::seconds(3))) {
        RCLCPP_ERROR(node_->get_logger(), "Nav2 Action Server bulunamadi!");
        return BT::NodeStatus::FAILURE;
    }

    // 3. Nav2'nin anladığı mesaj formatını doldur
    auto goal_msg = NavigateToPose::Goal();
    goal_msg.pose.header.frame_id = "map";
    goal_msg.pose.header.stamp = node_->now();
    goal_msg.pose.pose.position.x = goal_x;
    goal_msg.pose.pose.position.y = goal_y;

    // Yaw açısını Quaternion'a çevir (ROS 2 standardı)
    tf2::Quaternion q;
    q.setRPY(0, 0, goal_yaw);
    goal_msg.pose.pose.orientation = tf2::toMsg(q);

    // 4. Hedefi Nav2'ye gönder (Asenkron)
    auto send_goal_options = rclcpp_action::Client<NavigateToPose>::SendGoalOptions();
    
    // Hedef sonuçlandığında tetiklenecek fonksiyon (Callback)
    send_goal_options.result_callback = [this](const GoalHandleNav::WrappedResult& result) {
        goal_done_ = true;
        switch (result.code) {
            case rclcpp_action::ResultCode::SUCCEEDED:
                goal_result_ = BT::NodeStatus::SUCCESS;
                break;
            case rclcpp_action::ResultCode::ABORTED:
            case rclcpp_action::ResultCode::CANCELED:
                goal_result_ = BT::NodeStatus::FAILURE;
                break;
            default:
                goal_result_ = BT::NodeStatus::FAILURE;
                break;
        }
    };

    goal_done_ = false;
    auto goal_handle_future = action_client_->async_send_goal(goal_msg, send_goal_options);
    
    RCLCPP_INFO(node_->get_logger(), "Hedef Nav2'ye gonderildi: X:%.2f, Y:%.2f", goal_x, goal_y);
    
    // İşlem hemen bitmediği için ağaca "RUNNING" dönüyoruz
    return BT::NodeStatus::RUNNING;
}

BT::NodeStatus NavigateToPoseAction::onRunning()
{
    // Araç hedefe giderken ağaç bu fonksiyonu sürekli saniyede onlarca kez çağırır.
    // Eğer callback (result_callback) tetiklendiyse işlemi bitir.
    if (goal_done_) {
        return goal_result_;
    }
    
    // Hala yoldayız, ağacı kitlemeden RUNNING dön.
    return BT::NodeStatus::RUNNING;
}

void NavigateToPoseAction::onHalted()
{
    // EĞER AĞAÇ BU İŞLEMİ ZORLA KESERSE (Örn: Kırmızı Işık yandı veya Acil Durum)
    RCLCPP_WARN(node_->get_logger(), "Navigasyon iptal edildi! (Halted)");
    if (goal_handle_) {
        action_client_->async_cancel_goal(goal_handle_);
    }
}

} // namespace evoart_behavior
