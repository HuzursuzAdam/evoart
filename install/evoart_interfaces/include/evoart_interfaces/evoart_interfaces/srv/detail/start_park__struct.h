// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from evoart_interfaces:srv/StartPark.idl
// generated code does not contain a copyright notice

#ifndef EVOART_INTERFACES__SRV__DETAIL__START_PARK__STRUCT_H_
#define EVOART_INTERFACES__SRV__DETAIL__START_PARK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/StartPark in the package evoart_interfaces.
typedef struct evoart_interfaces__srv__StartPark_Request
{
  int8_t parking_slot_number;
} evoart_interfaces__srv__StartPark_Request;

// Struct for a sequence of evoart_interfaces__srv__StartPark_Request.
typedef struct evoart_interfaces__srv__StartPark_Request__Sequence
{
  evoart_interfaces__srv__StartPark_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} evoart_interfaces__srv__StartPark_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/StartPark in the package evoart_interfaces.
typedef struct evoart_interfaces__srv__StartPark_Response
{
  bool success;
  rosidl_runtime_c__String message;
} evoart_interfaces__srv__StartPark_Response;

// Struct for a sequence of evoart_interfaces__srv__StartPark_Response.
typedef struct evoart_interfaces__srv__StartPark_Response__Sequence
{
  evoart_interfaces__srv__StartPark_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} evoart_interfaces__srv__StartPark_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // EVOART_INTERFACES__SRV__DETAIL__START_PARK__STRUCT_H_
