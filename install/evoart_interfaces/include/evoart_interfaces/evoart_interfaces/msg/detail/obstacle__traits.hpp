// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from evoart_interfaces:msg/Obstacle.idl
// generated code does not contain a copyright notice

#ifndef EVOART_INTERFACES__MSG__DETAIL__OBSTACLE__TRAITS_HPP_
#define EVOART_INTERFACES__MSG__DETAIL__OBSTACLE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "evoart_interfaces/msg/detail/obstacle__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace evoart_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Obstacle & msg,
  std::ostream & out)
{
  out << "{";
  // member: obstacle_type
  {
    out << "obstacle_type: ";
    rosidl_generator_traits::value_to_yaml(msg.obstacle_type, out);
    out << ", ";
  }

  // member: distance
  {
    out << "distance: ";
    rosidl_generator_traits::value_to_yaml(msg.distance, out);
    out << ", ";
  }

  // member: angle
  {
    out << "angle: ";
    rosidl_generator_traits::value_to_yaml(msg.angle, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Obstacle & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: obstacle_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "obstacle_type: ";
    rosidl_generator_traits::value_to_yaml(msg.obstacle_type, out);
    out << "\n";
  }

  // member: distance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "distance: ";
    rosidl_generator_traits::value_to_yaml(msg.distance, out);
    out << "\n";
  }

  // member: angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angle: ";
    rosidl_generator_traits::value_to_yaml(msg.angle, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Obstacle & msg, bool use_flow_style = false)
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
  const evoart_interfaces::msg::Obstacle & msg,
  std::ostream & out, size_t indentation = 0)
{
  evoart_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use evoart_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const evoart_interfaces::msg::Obstacle & msg)
{
  return evoart_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<evoart_interfaces::msg::Obstacle>()
{
  return "evoart_interfaces::msg::Obstacle";
}

template<>
inline const char * name<evoart_interfaces::msg::Obstacle>()
{
  return "evoart_interfaces/msg/Obstacle";
}

template<>
struct has_fixed_size<evoart_interfaces::msg::Obstacle>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<evoart_interfaces::msg::Obstacle>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<evoart_interfaces::msg::Obstacle>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // EVOART_INTERFACES__MSG__DETAIL__OBSTACLE__TRAITS_HPP_
