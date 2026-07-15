// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from evoart_interfaces:msg/VehicleControl.idl
// generated code does not contain a copyright notice

#ifndef EVOART_INTERFACES__MSG__DETAIL__VEHICLE_CONTROL__STRUCT_H_
#define EVOART_INTERFACES__MSG__DETAIL__VEHICLE_CONTROL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/VehicleControl in the package evoart_interfaces.
typedef struct evoart_interfaces__msg__VehicleControl
{
  /// İleri/geri hedef hız (m/s)
  float target_velocity;
  /// Direksiyon açısı (Radyan)
  float steering_angle;
  /// Acil durum freni (True/False)
  bool emergency_stop;
} evoart_interfaces__msg__VehicleControl;

// Struct for a sequence of evoart_interfaces__msg__VehicleControl.
typedef struct evoart_interfaces__msg__VehicleControl__Sequence
{
  evoart_interfaces__msg__VehicleControl * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} evoart_interfaces__msg__VehicleControl__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // EVOART_INTERFACES__MSG__DETAIL__VEHICLE_CONTROL__STRUCT_H_
