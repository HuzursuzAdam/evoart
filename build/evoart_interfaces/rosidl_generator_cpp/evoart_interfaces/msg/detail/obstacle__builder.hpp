// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from evoart_interfaces:msg/Obstacle.idl
// generated code does not contain a copyright notice

#ifndef EVOART_INTERFACES__MSG__DETAIL__OBSTACLE__BUILDER_HPP_
#define EVOART_INTERFACES__MSG__DETAIL__OBSTACLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "evoart_interfaces/msg/detail/obstacle__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace evoart_interfaces
{

namespace msg
{

namespace builder
{

class Init_Obstacle_angle
{
public:
  explicit Init_Obstacle_angle(::evoart_interfaces::msg::Obstacle & msg)
  : msg_(msg)
  {}
  ::evoart_interfaces::msg::Obstacle angle(::evoart_interfaces::msg::Obstacle::_angle_type arg)
  {
    msg_.angle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::evoart_interfaces::msg::Obstacle msg_;
};

class Init_Obstacle_distance
{
public:
  explicit Init_Obstacle_distance(::evoart_interfaces::msg::Obstacle & msg)
  : msg_(msg)
  {}
  Init_Obstacle_angle distance(::evoart_interfaces::msg::Obstacle::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return Init_Obstacle_angle(msg_);
  }

private:
  ::evoart_interfaces::msg::Obstacle msg_;
};

class Init_Obstacle_obstacle_type
{
public:
  Init_Obstacle_obstacle_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Obstacle_distance obstacle_type(::evoart_interfaces::msg::Obstacle::_obstacle_type_type arg)
  {
    msg_.obstacle_type = std::move(arg);
    return Init_Obstacle_distance(msg_);
  }

private:
  ::evoart_interfaces::msg::Obstacle msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::evoart_interfaces::msg::Obstacle>()
{
  return evoart_interfaces::msg::builder::Init_Obstacle_obstacle_type();
}

}  // namespace evoart_interfaces

#endif  // EVOART_INTERFACES__MSG__DETAIL__OBSTACLE__BUILDER_HPP_
