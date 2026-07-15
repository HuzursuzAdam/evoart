// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from evoart_interfaces:msg/VehicleControl.idl
// generated code does not contain a copyright notice

#ifndef EVOART_INTERFACES__MSG__DETAIL__VEHICLE_CONTROL__TRAITS_HPP_
#define EVOART_INTERFACES__MSG__DETAIL__VEHICLE_CONTROL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "evoart_interfaces/msg/detail/vehicle_control__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace evoart_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const VehicleControl & msg,
  std::ostream & out)
{
  out << "{";
  // member: target_velocity
  {
    out << "target_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.target_velocity, out);
    out << ", ";
  }

  // member: steering_angle
  {
    out << "steering_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.steering_angle, out);
    out << ", ";
  }

  // member: emergency_stop
  {
    out << "emergency_stop: ";
    rosidl_generator_traits::value_to_yaml(msg.emergency_stop, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const VehicleControl & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: target_velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.target_velocity, out);
    out << "\n";
  }

  // member: steering_angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "steering_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.steering_angle, out);
    out << "\n";
  }

  // member: emergency_stop
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "emergency_stop: ";
    rosidl_generator_traits::value_to_yaml(msg.emergency_stop, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const VehicleControl & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace evoart_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use evoart_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const evoart_interfaces::msg::VehicleControl & msg,
  std::ostream & out, size_t indentation = 0)
{
  evoart_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use evoart_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const evoart_interfaces::msg::VehicleControl & msg)
{
  return evoart_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<evoart_interfaces::msg::VehicleControl>()
{
  return "evoart_interfaces::msg::VehicleControl";
}

template<>
inline const char * name<evoart_interfaces::msg::VehicleControl>()
{
  return "evoart_interfaces/msg/VehicleControl";
}

template<>
struct has_fixed_size<evoart_interfaces::msg::VehicleControl>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<evoart_interfaces::msg::VehicleControl>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<evoart_interfaces::msg::VehicleControl>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // EVOART_INTERFACES__MSG__DETAIL__VEHICLE_CONTROL__TRAITS_HPP_
