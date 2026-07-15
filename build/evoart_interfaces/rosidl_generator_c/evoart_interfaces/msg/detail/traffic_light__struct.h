// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from evoart_interfaces:msg/TrafficLight.idl
// generated code does not contain a copyright notice

#ifndef EVOART_INTERFACES__MSG__DETAIL__TRAFFIC_LIGHT__STRUCT_H_
#define EVOART_INTERFACES__MSG__DETAIL__TRAFFIC_LIGHT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'RED'.
enum
{
  evoart_interfaces__msg__TrafficLight__RED = 0
};

/// Constant 'GREEN'.
enum
{
  evoart_interfaces__msg__TrafficLight__GREEN = 1
};

/// Constant 'YELLOW'.
enum
{
  evoart_interfaces__msg__TrafficLight__YELLOW = 2
};

/// Struct defined in msg/TrafficLight in the package evoart_interfaces.
/**
  * Işık Durumları
 */
typedef struct evoart_interfaces__msg__TrafficLight
{
  int8_t color;
  /// Yapay zekanın emin olma oranı (0.0 - 1.0)
  float confidence;
} evoart_interfaces__msg__TrafficLight;

// Struct for a sequence of evoart_interfaces__msg__TrafficLight.
typedef struct evoart_interfaces__msg__TrafficLight__Sequence
{
  evoart_interfaces__msg__TrafficLight * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} evoart_interfaces__msg__TrafficLight__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // EVOART_INTERFACES__MSG__DETAIL__TRAFFIC_LIGHT__STRUCT_H_
