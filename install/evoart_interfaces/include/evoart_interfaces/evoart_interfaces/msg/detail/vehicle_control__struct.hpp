// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from evoart_interfaces:msg/VehicleControl.idl
// generated code does not contain a copyright notice

#ifndef EVOART_INTERFACES__MSG__DETAIL__VEHICLE_CONTROL__STRUCT_HPP_
#define EVOART_INTERFACES__MSG__DETAIL__VEHICLE_CONTROL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__evoart_interfaces__msg__VehicleControl __attribute__((deprecated))
#else
# define DEPRECATED__evoart_interfaces__msg__VehicleControl __declspec(deprecated)
#endif

namespace evoart_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct VehicleControl_
{
  using Type = VehicleControl_<ContainerAllocator>;

  explicit VehicleControl_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->target_velocity = 0.0f;
      this->steering_angle = 0.0f;
      this->emergency_stop = false;
    }
  }

  explicit VehicleControl_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->target_velocity = 0.0f;
      this->steering_angle = 0.0f;
      this->emergency_stop = false;
    }
  }

  // field types and members
  using _target_velocity_type =
    float;
  _target_velocity_type target_velocity;
  using _steering_angle_type =
    float;
  _steering_angle_type steering_angle;
  using _emergency_stop_type =
    bool;
  _emergency_stop_type emergency_stop;

  // setters for named parameter idiom
  Type & set__target_velocity(
    const float & _arg)
  {
    this->target_velocity = _arg;
    return *this;
  }
  Type & set__steering_angle(
    const float & _arg)
  {
    this->steering_angle = _arg;
    return *this;
  }
  Type & set__emergency_stop(
    const bool & _arg)
  {
    this->emergency_stop = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    evoart_interfaces::msg::VehicleControl_<ContainerAllocator> *;
  using ConstRawPtr =
    const evoart_interfaces::msg::VehicleControl_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<evoart_interfaces::msg::VehicleControl_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<evoart_interfaces::msg::VehicleControl_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      evoart_interfaces::msg::VehicleControl_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<evoart_interfaces::msg::VehicleControl_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      evoart_interfaces::msg::VehicleControl_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<evoart_interfaces::msg::VehicleControl_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<evoart_interfaces::msg::VehicleControl_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<evoart_interfaces::msg::VehicleControl_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__evoart_interfaces__msg__VehicleControl
    std::shared_ptr<evoart_interfaces::msg::VehicleControl_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__evoart_interfaces__msg__VehicleControl
    std::shared_ptr<evoart_interfaces::msg::VehicleControl_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const VehicleControl_ & other) const
  {
    if (this->target_velocity != other.target_velocity) {
      return false;
    }
    if (this->steering_angle != other.steering_angle) {
      return false;
    }
    if (this->emergency_stop != other.emergency_stop) {
      return false;
    }
    return true;
  }
  bool operator!=(const VehicleControl_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct VehicleControl_

// alias to use template instance with default allocator
using VehicleControl =
  evoart_interfaces::msg::VehicleControl_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace evoart_interfaces

#endif  // EVOART_INTERFACES__MSG__DETAIL__VEHICLE_CONTROL__STRUCT_HPP_
