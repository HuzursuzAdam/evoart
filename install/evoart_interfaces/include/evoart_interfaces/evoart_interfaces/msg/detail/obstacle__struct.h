// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from evoart_interfaces:msg/Obstacle.idl
// generated code does not contain a copyright notice

#ifndef EVOART_INTERFACES__MSG__DETAIL__OBSTACLE__STRUCT_H_
#define EVOART_INTERFACES__MSG__DETAIL__OBSTACLE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'TYPE_CONE'.
enum
{
  evoart_interfaces__msg__Obstacle__TYPE_CONE = 0
};

/// Constant 'TYPE_PEDESTRIAN'.
enum
{
  evoart_interfaces__msg__Obstacle__TYPE_PEDESTRIAN = 1
};

/// Constant 'TYPE_VEHICLE'.
enum
{
  evoart_interfaces__msg__Obstacle__TYPE_VEHICLE = 2
};

/// Struct defined in msg/Obstacle in the package evoart_interfaces.
/**
  * Engel Tipleri
 */
typedef struct evoart_interfaces__msg__Obstacle
{
  int8_t obstacle_type;
  /// Metre cinsinden
  float distance;
  /// Radyan veya derece cinsinden
  float angle;
} evoart_interfaces__msg__Obstacle;

// Struct for a sequence of evoart_interfaces__msg__Obstacle.
typedef struct evoart_interfaces__msg__Obstacle__Sequence
{
  evoart_interfaces__msg__Obstacle * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} evoart_interfaces__msg__Obstacle__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // EVOART_INTERFACES__MSG__DETAIL__OBSTACLE__STRUCT_H_
