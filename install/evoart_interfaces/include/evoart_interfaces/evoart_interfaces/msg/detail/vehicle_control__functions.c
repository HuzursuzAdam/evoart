// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from evoart_interfaces:msg/VehicleControl.idl
// generated code does not contain a copyright notice
#include "evoart_interfaces/msg/detail/vehicle_control__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
evoart_interfaces__msg__VehicleControl__init(evoart_interfaces__msg__VehicleControl * msg)
{
  if (!msg) {
    return false;
  }
  // target_velocity
  // steering_angle
  // emergency_stop
  return true;
}

void
evoart_interfaces__msg__VehicleControl__fini(evoart_interfaces__msg__VehicleControl * msg)
{
  if (!msg) {
    return;
  }
  // target_velocity
  // steering_angle
  // emergency_stop
}

bool
evoart_interfaces__msg__VehicleControl__are_equal(const evoart_interfaces__msg__VehicleControl * lhs, const evoart_interfaces__msg__VehicleControl * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // target_velocity
  if (lhs->target_velocity != rhs->target_velocity) {
    return false;
  }
  // steering_angle
  if (lhs->steering_angle != rhs->steering_angle) {
    return false;
  }
  // emergency_stop
  if (lhs->emergency_stop != rhs->emergency_stop) {
    return false;
  }
  return true;
}

bool
evoart_interfaces__msg__VehicleControl__copy(
  const evoart_interfaces__msg__VehicleControl * input,
  evoart_interfaces__msg__VehicleControl * output)
{
  if (!input || !output) {
    return false;
  }
  // target_velocity
  output->target_velocity = input->target_velocity;
  // steering_angle
  output->steering_angle = input->steering_angle;
  // emergency_stop
  output->emergency_stop = input->emergency_stop;
  return true;
}

evoart_interfaces__msg__VehicleControl *
evoart_interfaces__msg__VehicleControl__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  evoart_interfaces__msg__VehicleControl * msg = (evoart_interfaces__msg__VehicleControl *)allocator.allocate(sizeof(evoart_interfaces__msg__VehicleControl), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(evoart_interfaces__msg__VehicleControl));
  bool success = evoart_interfaces__msg__VehicleControl__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
evoart_interfaces__msg__VehicleControl__destroy(evoart_interfaces__msg__VehicleControl * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    evoart_interfaces__msg__VehicleControl__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
evoart_interfaces__msg__VehicleControl__Sequence__init(evoart_interfaces__msg__VehicleControl__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  evoart_interfaces__msg__VehicleControl * data = NULL;

  if (size) {
    data = (evoart_interfaces__msg__VehicleControl *)allocator.zero_allocate(size, sizeof(evoart_interfaces__msg__VehicleControl), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = evoart_interfaces__msg__VehicleControl__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        evoart_interfaces__msg__VehicleControl__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
evoart_interfaces__msg__VehicleControl__Sequence__fini(evoart_interfaces__msg__VehicleControl__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      evoart_interfaces__msg__VehicleControl__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

evoart_interfaces__msg__VehicleControl__Sequence *
evoart_interfaces__msg__VehicleControl__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  evoart_interfaces__msg__VehicleControl__Sequence * array = (evoart_interfaces__msg__VehicleControl__Sequence *)allocator.allocate(sizeof(evoart_interfaces__msg__VehicleControl__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = evoart_interfaces__msg__VehicleControl__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
evoart_interfaces__msg__VehicleControl__Sequence__destroy(evoart_interfaces__msg__VehicleControl__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    evoart_interfaces__msg__VehicleControl__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
evoart_interfaces__msg__VehicleControl__Sequence__are_equal(const evoart_interfaces__msg__VehicleControl__Sequence * lhs, const evoart_interfaces__msg__VehicleControl__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!evoart_interfaces__msg__VehicleControl__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
evoart_interfaces__msg__VehicleControl__Sequence__copy(
  const evoart_interfaces__msg__VehicleControl__Sequence * input,
  evoart_interfaces__msg__VehicleControl__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(evoart_interfaces__msg__VehicleControl);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    evoart_interfaces__msg__VehicleControl * data =
      (evoart_interfaces__msg__VehicleControl *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!evoart_interfaces__msg__VehicleControl__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          evoart_interfaces__msg__VehicleControl__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!evoart_interfaces__msg__VehicleControl__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
