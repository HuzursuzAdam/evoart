// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from evoart_interfaces:msg/TrafficLight.idl
// generated code does not contain a copyright notice

#ifndef EVOART_INTERFACES__MSG__DETAIL__TRAFFIC_LIGHT__BUILDER_HPP_
#define EVOART_INTERFACES__MSG__DETAIL__TRAFFIC_LIGHT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "evoart_interfaces/msg/detail/traffic_light__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace evoart_interfaces
{

namespace msg
{

namespace builder
{

class Init_TrafficLight_confidence
{
public:
  explicit Init_TrafficLight_confidence(::evoart_interfaces::msg::TrafficLight & msg)
  : msg_(msg)
  {}
  ::evoart_interfaces::msg::TrafficLight confidence(::evoart_interfaces::msg::TrafficLight::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return std::move(msg_);
  }

private:
  ::evoart_interfaces::msg::TrafficLight msg_;
};

class Init_TrafficLight_color
{
public:
  Init_TrafficLight_color()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TrafficLight_confidence color(::evoart_interfaces::msg::TrafficLight::_color_type arg)
  {
    msg_.color = std::move(arg);
    return Init_TrafficLight_confidence(msg_);
  }

private:
  ::evoart_interfaces::msg::TrafficLight msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::evoart_interfaces::msg::TrafficLight>()
{
  return evoart_interfaces::msg::builder::Init_TrafficLight_color();
}

}  // namespace evoart_interfaces

#endif  // EVOART_INTERFACES__MSG__DETAIL__TRAFFIC_LIGHT__BUILDER_HPP_
