// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from evoart_interfaces:srv/StartPark.idl
// generated code does not contain a copyright notice

#ifndef EVOART_INTERFACES__SRV__DETAIL__START_PARK__STRUCT_HPP_
#define EVOART_INTERFACES__SRV__DETAIL__START_PARK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__evoart_interfaces__srv__StartPark_Request __attribute__((deprecated))
#else
# define DEPRECATED__evoart_interfaces__srv__StartPark_Request __declspec(deprecated)
#endif

namespace evoart_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct StartPark_Request_
{
  using Type = StartPark_Request_<ContainerAllocator>;

  explicit StartPark_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->parking_slot_number = 0;
    }
  }

  explicit StartPark_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->parking_slot_number = 0;
    }
  }

  // field types and members
  using _parking_slot_number_type =
    int8_t;
  _parking_slot_number_type parking_slot_number;

  // setters for named parameter idiom
  Type & set__parking_slot_number(
    const int8_t & _arg)
  {
    this->parking_slot_number = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    evoart_interfaces::srv::StartPark_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const evoart_interfaces::srv::StartPark_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<evoart_interfaces::srv::StartPark_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<evoart_interfaces::srv::StartPark_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      evoart_interfaces::srv::StartPark_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<evoart_interfaces::srv::StartPark_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      evoart_interfaces::srv::StartPark_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<evoart_interfaces::srv::StartPark_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<evoart_interfaces::srv::StartPark_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<evoart_interfaces::srv::StartPark_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__evoart_interfaces__srv__StartPark_Request
    std::shared_ptr<evoart_interfaces::srv::StartPark_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__evoart_interfaces__srv__StartPark_Request
    std::shared_ptr<evoart_interfaces::srv::StartPark_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StartPark_Request_ & other) const
  {
    if (this->parking_slot_number != other.parking_slot_number) {
      return false;
    }
    return true;
  }
  bool operator!=(const StartPark_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StartPark_Request_

// alias to use template instance with default allocator
using StartPark_Request =
  evoart_interfaces::srv::StartPark_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace evoart_interfaces


#ifndef _WIN32
# define DEPRECATED__evoart_interfaces__srv__StartPark_Response __attribute__((deprecated))
#else
# define DEPRECATED__evoart_interfaces__srv__StartPark_Response __declspec(deprecated)
#endif

namespace evoart_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct StartPark_Response_
{
  using Type = StartPark_Response_<ContainerAllocator>;

  explicit StartPark_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit StartPark_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    evoart_interfaces::srv::StartPark_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const evoart_interfaces::srv::StartPark_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<evoart_interfaces::srv::StartPark_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<evoart_interfaces::srv::StartPark_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      evoart_interfaces::srv::StartPark_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<evoart_interfaces::srv::StartPark_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      evoart_interfaces::srv::StartPark_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<evoart_interfaces::srv::StartPark_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<evoart_interfaces::srv::StartPark_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<evoart_interfaces::srv::StartPark_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__evoart_interfaces__srv__StartPark_Response
    std::shared_ptr<evoart_interfaces::srv::StartPark_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__evoart_interfaces__srv__StartPark_Response
    std::shared_ptr<evoart_interfaces::srv::StartPark_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StartPark_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const StartPark_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StartPark_Response_

// alias to use template instance with default allocator
using StartPark_Response =
  evoart_interfaces::srv::StartPark_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace evoart_interfaces

namespace evoart_interfaces
{

namespace srv
{

struct StartPark
{
  using Request = evoart_interfaces::srv::StartPark_Request;
  using Response = evoart_interfaces::srv::StartPark_Response;
};

}  // namespace srv

}  // namespace evoart_interfaces

#endif  // EVOART_INTERFACES__SRV__DETAIL__START_PARK__STRUCT_HPP_
