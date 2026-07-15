// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from evoart_interfaces:srv/StartPark.idl
// generated code does not contain a copyright notice

#ifndef EVOART_INTERFACES__SRV__DETAIL__START_PARK__BUILDER_HPP_
#define EVOART_INTERFACES__SRV__DETAIL__START_PARK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "evoart_interfaces/srv/detail/start_park__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace evoart_interfaces
{

namespace srv
{

namespace builder
{

class Init_StartPark_Request_parking_slot_number
{
public:
  Init_StartPark_Request_parking_slot_number()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::evoart_interfaces::srv::StartPark_Request parking_slot_number(::evoart_interfaces::srv::StartPark_Request::_parking_slot_number_type arg)
  {
    msg_.parking_slot_number = std::move(arg);
    return std::move(msg_);
  }

private:
  ::evoart_interfaces::srv::StartPark_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::evoart_interfaces::srv::StartPark_Request>()
{
  return evoart_interfaces::srv::builder::Init_StartPark_Request_parking_slot_number();
}

}  // namespace evoart_interfaces


namespace evoart_interfaces
{

namespace srv
{

namespace builder
{

class Init_StartPark_Response_message
{
public:
  explicit Init_StartPark_Response_message(::evoart_interfaces::srv::StartPark_Response & msg)
  : msg_(msg)
  {}
  ::evoart_interfaces::srv::StartPark_Response message(::evoart_interfaces::srv::StartPark_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::evoart_interfaces::srv::StartPark_Response msg_;
};

class Init_StartPark_Response_success
{
public:
  Init_StartPark_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StartPark_Response_message success(::evoart_interfaces::srv::StartPark_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_StartPark_Response_message(msg_);
  }

private:
  ::evoart_interfaces::srv::StartPark_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::evoart_interfaces::srv::StartPark_Response>()
{
  return evoart_interfaces::srv::builder::Init_StartPark_Response_success();
}

}  // namespace evoart_interfaces

#endif  // EVOART_INTERFACES__SRV__DETAIL__START_PARK__BUILDER_HPP_
