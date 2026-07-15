// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from evoart_interfaces:msg/TrafficLight.idl
// generated code does not contain a copyright notice

#ifndef EVOART_INTERFACES__MSG__DETAIL__TRAFFIC_LIGHT__STRUCT_HPP_
#define EVOART_INTERFACES__MSG__DETAIL__TRAFFIC_LIGHT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__evoart_interfaces__msg__TrafficLight __attribute__((deprecated))
#else
# define DEPRECATED__evoart_interfaces__msg__TrafficLight __declspec(deprecated)
#endif

namespace evoart_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TrafficLight_
{
  using Type = TrafficLight_<ContainerAllocator>;

  explicit TrafficLight_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->color = 0;
      this->confidence = 0.0f;
    }
  }

  explicit TrafficLight_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->color = 0;
      this->confidence = 0.0f;
    }
  }

  // field types and members
  using _color_type =
    int8_t;
  _color_type color;
  using _confidence_type =
    float;
  _confidence_type confidence;

  // setters for named parameter idiom
  Type & set__color(
    const int8_t & _arg)
  {
    this->color = _arg;
    return *this;
  }
  Type & set__confidence(
    const float & _arg)
  {
    this->confidence = _arg;
    return *this;
  }

  // constant declarations
  static constexpr int8_t RED =
    0;
  static constexpr int8_t GREEN =
    1;
  static constexpr int8_t YELLOW =
    2;

  // pointer types
  using RawPtr =
    evoart_interfaces::msg::TrafficLight_<ContainerAllocator> *;
  using ConstRawPtr =
    const evoart_interfaces::msg::TrafficLight_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<evoart_interfaces::msg::TrafficLight_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<evoart_interfaces::msg::TrafficLight_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      evoart_interfaces::msg::TrafficLight_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<evoart_interfaces::msg::TrafficLight_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      evoart_interfaces::msg::TrafficLight_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<evoart_interfaces::msg::TrafficLight_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<evoart_interfaces::msg::TrafficLight_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<evoart_interfaces::msg::TrafficLight_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__evoart_interfaces__msg__TrafficLight
    std::shared_ptr<evoart_interfaces::msg::TrafficLight_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__evoart_interfaces__msg__TrafficLight
    std::shared_ptr<evoart_interfaces::msg::TrafficLight_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TrafficLight_ & other) const
  {
    if (this->color != other.color) {
      return false;
    }
    if (this->confidence != other.confidence) {
      return false;
    }
    return true;
  }
  bool operator!=(const TrafficLight_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TrafficLight_

// alias to use template instance with default allocator
using TrafficLight =
  evoart_interfaces::msg::TrafficLight_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t TrafficLight_<ContainerAllocator>::RED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t TrafficLight_<ContainerAllocator>::GREEN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t TrafficLight_<ContainerAllocator>::YELLOW;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace evoart_interfaces

#endif  // EVOART_INTERFACES__MSG__DETAIL__TRAFFIC_LIGHT__STRUCT_HPP_
