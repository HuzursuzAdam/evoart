// Dosya: ~/evoart_ws/src/evoart_behavior/include/evoart_behavior/navigate_to_pose_action.hpp

#ifndef NAVIGATE_TO_POSE_ACTION_HPP
#define NAVIGATE_TO_POSE_ACTION_HPP

#include <rclcpp/rclcpp.hpp>
#include <rclcpp_action/rclcpp_action.hpp>
#include <nav2_msgs/action/navigate_to_pose.hpp>
#include <behaviortree_cpp_v3/action_node.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>

namespace evoart_behavior
{
class NavigateToPoseAction : public BT::StatefulActionNode
{
public:
    using NavigateToPose = nav2_msgs::action::NavigateToPose;
    using GoalHandleNav = rclcpp_action::ClientGoalHandle<NavigateToPose>;

    // Düğümün Kurucusu (Constructor)
    NavigateToPoseAction(const std::string& name, const BT::NodeConfiguration& config, rclcpp::Node::SharedPtr node);

    // Ağaçtan alınacak parametreler (XML üzerinden verilecek hedefler)
    static BT::PortsList providedPorts()
    {
        return {
            BT::InputPort<double>("goal_x", "Hedef X koordinati"),
            BT::InputPort<double>("goal_y", "Hedef Y koordinati"),
            BT::InputPort<double>("goal_yaw", "Hedef Z acisi (Radyan)")
        };
    }

    // Behavior Tree Yaşam Döngüsü Fonksiyonları
    BT::NodeStatus onStart() override;
    BT::NodeStatus onRunning() override;
    void onHalted() override;

private:
    rclcpp::Node::SharedPtr node_;
    rclcpp_action::Client<NavigateToPose>::SharedPtr action_client_;
    GoalHandleNav::SharedPtr goal_handle_;
    bool goal_done_;
    BT::NodeStatus goal_result_;
};

} // namespace evoart_behavior

#endif // NAVIGATE_TO_POSE_ACTION_HPP
