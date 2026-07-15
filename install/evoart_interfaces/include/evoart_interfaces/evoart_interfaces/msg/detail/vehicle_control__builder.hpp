// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from evoart_interfaces:msg/VehicleControl.idl
// generated code does not contain a copyright notice

#ifndef EVOART_INTERFACES__MSG__DETAIL__VEHICLE_CONTROL__BUILDER_HPP_
#define EVOART_INTERFACES__MSG__DETAIL__VEHICLE_CONTROL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "evoart_interfaces/msg/detail/vehicle_control__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace evoart_interfaces
{

namespace msg
{

namespace builder
{

class Init_VehicleControl_emergency_stop
{
public:
  explicit Init_VehicleControl_emergency_stop(::evoart_interfaces::msg::VehicleControl & msg)
  : msg_(msg)
  {}
  ::evoart_interfaces::msg::VehicleControl emergency_stop(::evoart_interfaces::msg::VehicleControl::_emergency_stop_type arg)
  {
    msg_.emergency_stop = std::move(arg);
    return std::move(msg_);
  }

private:
  ::evoart_interfaces::msg::VehicleControl msg_;
};

class Init_VehicleControl_steering_angle
{
public:
  explicit Init_VehicleControl_steering_angle(::evoart_interfaces::msg::VehicleControl & msg)
  : msg_(msg)
  {}
  Init_VehicleControl_emergency_stop steering_angle(::evoart_interfaces::msg::VehicleControl::_steering_angle_type arg)
  {
    msg_.steering_angle = std::move(arg);
    return Init_VehicleControl_emergency_stop(msg_);
  }

private:
  ::evoart_interfaces::msg::VehicleControl msg_;
};

class Init_VehicleControl_target_velocity
{
public:
  Init_VehicleControl_target_velocity()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VehicleControl_steering_angle target_velocity(::evoart_interfaces::msg::VehicleControl::_target_velocity_type arg)
  {
    msg_.target_velocity = std::move(arg);
    return Init_VehicleControl_steering_angle(msg_);
  }

private:
  ::evoart_interfaces::msg::VehicleControl msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::evoart_interfaces::msg::VehicleControl>()
{
  return evoart_interfaces::msg::builder::Init_VehicleControl_target_velocity();
}

}  // namespace evoart_interfaces

#endif  // EVOART_INTERFACES__MSG__DETAIL__VEHICLE_CONTROL__BUILDER_HPP_
