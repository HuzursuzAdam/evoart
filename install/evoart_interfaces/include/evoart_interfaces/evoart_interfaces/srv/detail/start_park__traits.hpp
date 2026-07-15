// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from evoart_interfaces:srv/StartPark.idl
// generated code does not contain a copyright notice

#ifndef EVOART_INTERFACES__SRV__DETAIL__START_PARK__TRAITS_HPP_
#define EVOART_INTERFACES__SRV__DETAIL__START_PARK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "evoart_interfaces/srv/detail/start_park__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace evoart_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const StartPark_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: parking_slot_number
  {
    out << "parking_slot_number: ";
    rosidl_generator_traits::value_to_yaml(msg.parking_slot_number, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const StartPark_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: parking_slot_number
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "parking_slot_number: ";
    rosidl_generator_traits::value_to_yaml(msg.parking_slot_number, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const StartPark_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace evoart_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use evoart_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const evoart_interfaces::srv::StartPark_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  evoart_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use evoart_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const evoart_interfaces::srv::StartPark_Request & msg)
{
  return evoart_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<evoart_interfaces::srv::StartPark_Request>()
{
  return "evoart_interfaces::srv::StartPark_Request";
}

template<>
inline const char * name<evoart_interfaces::srv::StartPark_Request>()
{
  return "evoart_interfaces/srv/StartPark_Request";
}

template<>
struct has_fixed_size<evoart_interfaces::srv::StartPark_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<evoart_interfaces::srv::StartPark_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<evoart_interfaces::srv::StartPark_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace evoart_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const StartPark_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const StartPark_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const StartPark_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace evoart_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use evoart_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const evoart_interfaces::srv::StartPark_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  evoart_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use evoart_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const evoart_interfaces::srv::StartPark_Response & msg)
{
  return evoart_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<evoart_interfaces::srv::StartPark_Response>()
{
  return "evoart_interfaces::srv::StartPark_Response";
}

template<>
inline const char * name<evoart_interfaces::srv::StartPark_Response>()
{
  return "evoart_interfaces/srv/StartPark_Response";
}

template<>
struct has_fixed_size<evoart_interfaces::srv::StartPark_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<evoart_interfaces::srv::StartPark_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<evoart_interfaces::srv::StartPark_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<evoart_interfaces::srv::StartPark>()
{
  return "evoart_interfaces::srv::StartPark";
}

template<>
inline const char * name<evoart_interfaces::srv::StartPark>()
{
  return "evoart_interfaces/srv/StartPark";
}

template<>
struct has_fixed_size<evoart_interfaces::srv::StartPark>
  : std::integral_constant<
    bool,
    has_fixed_size<evoart_interfaces::srv::StartPark_Request>::value &&
    has_fixed_size<evoart_interfaces::srv::StartPark_Response>::value
  >
{
};

template<>
struct has_bounded_size<evoart_interfaces::srv::StartPark>
  : std::integral_constant<
    bool,
    has_bounded_size<evoart_interfaces::srv::StartPark_Request>::value &&
    has_bounded_size<evoart_interfaces::srv::StartPark_Response>::value
  >
{
};

template<>
struct is_service<evoart_interfaces::srv::StartPark>
  : std::true_type
{
};

template<>
struct is_service_request<evoart_interfaces::srv::StartPark_Request>
  : std::true_type
{
};

template<>
struct is_service_response<evoart_interfaces::srv::StartPark_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // EVOART_INTERFACES__SRV__DETAIL__START_PARK__TRAITS_HPP_
