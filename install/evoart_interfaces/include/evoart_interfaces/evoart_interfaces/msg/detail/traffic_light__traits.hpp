// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from evoart_interfaces:msg/TrafficLight.idl
// generated code does not contain a copyright notice

#ifndef EVOART_INTERFACES__MSG__DETAIL__TRAFFIC_LIGHT__TRAITS_HPP_
#define EVOART_INTERFACES__MSG__DETAIL__TRAFFIC_LIGHT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "evoart_interfaces/msg/detail/traffic_light__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace evoart_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const TrafficLight & msg,
  std::ostream & out)
{
  out << "{";
  // member: color
  {
    out << "color: ";
    rosidl_generator_traits::value_to_yaml(msg.color, out);
    out << ", ";
  }

  // member: confidence
  {
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TrafficLight & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: color
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "color: ";
    rosidl_generator_traits::value_to_yaml(msg.color, out);
    out << "\n";
  }

  // member: confidence
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TrafficLight & msg, bool use_flow_style = false)
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
  const evoart_interfaces::msg::TrafficLight & msg,
  std::ostream & out, size_t indentation = 0)
{
  evoart_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use evoart_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const evoart_interfaces::msg::TrafficLight & msg)
{
  return evoart_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<evoart_interfaces::msg::TrafficLight>()
{
  return "evoart_interfaces::msg::TrafficLight";
}

template<>
inline const char * name<evoart_interfaces::msg::TrafficLight>()
{
  return "evoart_interfaces/msg/TrafficLight";
}

template<>
struct has_fixed_size<evoart_interfaces::msg::TrafficLight>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<evoart_interfaces::msg::TrafficLight>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<evoart_interfaces::msg::TrafficLight>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // EVOART_INTERFACES__MSG__DETAIL__TRAFFIC_LIGHT__TRAITS_HPP_
