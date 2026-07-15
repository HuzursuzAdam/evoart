// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from evoart_interfaces:msg/TrafficLight.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "evoart_interfaces/msg/detail/traffic_light__rosidl_typesupport_introspection_c.h"
#include "evoart_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "evoart_interfaces/msg/detail/traffic_light__functions.h"
#include "evoart_interfaces/msg/detail/traffic_light__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void evoart_interfaces__msg__TrafficLight__rosidl_typesupport_introspection_c__TrafficLight_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  evoart_interfaces__msg__TrafficLight__init(message_memory);
}

void evoart_interfaces__msg__TrafficLight__rosidl_typesupport_introspection_c__TrafficLight_fini_function(void * message_memory)
{
  evoart_interfaces__msg__TrafficLight__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember evoart_interfaces__msg__TrafficLight__rosidl_typesupport_introspection_c__TrafficLight_message_member_array[2] = {
  {
    "color",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(evoart_interfaces__msg__TrafficLight, color),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "confidence",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(evoart_interfaces__msg__TrafficLight, confidence),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers evoart_interfaces__msg__TrafficLight__rosidl_typesupport_introspection_c__TrafficLight_message_members = {
  "evoart_interfaces__msg",  // message namespace
  "TrafficLight",  // message name
  2,  // number of fields
  sizeof(evoart_interfaces__msg__TrafficLight),
  evoart_interfaces__msg__TrafficLight__rosidl_typesupport_introspection_c__TrafficLight_message_member_array,  // message members
  evoart_interfaces__msg__TrafficLight__rosidl_typesupport_introspection_c__TrafficLight_init_function,  // function to initialize message memory (memory has to be allocated)
  evoart_interfaces__msg__TrafficLight__rosidl_typesupport_introspection_c__TrafficLight_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t evoart_interfaces__msg__TrafficLight__rosidl_typesupport_introspection_c__TrafficLight_message_type_support_handle = {
  0,
  &evoart_interfaces__msg__TrafficLight__rosidl_typesupport_introspection_c__TrafficLight_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_evoart_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, evoart_interfaces, msg, TrafficLight)() {
  if (!evoart_interfaces__msg__TrafficLight__rosidl_typesupport_introspection_c__TrafficLight_message_type_support_handle.typesupport_identifier) {
    evoart_interfaces__msg__TrafficLight__rosidl_typesupport_introspection_c__TrafficLight_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &evoart_interfaces__msg__TrafficLight__rosidl_typesupport_introspection_c__TrafficLight_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
