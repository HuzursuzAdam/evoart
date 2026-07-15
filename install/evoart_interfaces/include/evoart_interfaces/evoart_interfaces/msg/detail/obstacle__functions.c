// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from evoart_interfaces:msg/Obstacle.idl
// generated code does not contain a copyright notice
#include "evoart_interfaces/msg/detail/obstacle__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
evoart_interfaces__msg__Obstacle__init(evoart_interfaces__msg__Obstacle * msg)
{
  if (!msg) {
    return false;
  }
  // obstacle_type
  // distance
  // angle
  return true;
}

void
evoart_interfaces__msg__Obstacle__fini(evoart_interfaces__msg__Obstacle * msg)
{
  if (!msg) {
    return;
  }
  // obstacle_type
  // distance
  // angle
}

bool
evoart_interfaces__msg__Obstacle__are_equal(const evoart_interfaces__msg__Obstacle * lhs, const evoart_interfaces__msg__Obstacle * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // obstacle_type
  if (lhs->obstacle_type != rhs->obstacle_type) {
    return false;
  }
  // distance
  if (lhs->distance != rhs->distance) {
    return false;
  }
  // angle
  if (lhs->angle != rhs->angle) {
    return false;
  }
  return true;
}

bool
evoart_interfaces__msg__Obstacle__copy(
  const evoart_interfaces__msg__Obstacle * input,
  evoart_interfaces__msg__Obstacle * output)
{
  if (!input || !output) {
    return false;
  }
  // obstacle_type
  output->obstacle_type = input->obstacle_type;
  // distance
  output->distance = input->distance;
  // angle
  output->angle = input->angle;
  return true;
}

evoart_interfaces__msg__Obstacle *
evoart_interfaces__msg__Obstacle__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  evoart_interfaces__msg__Obstacle * msg = (evoart_interfaces__msg__Obstacle *)allocator.allocate(sizeof(evoart_interfaces__msg__Obstacle), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(evoart_interfaces__msg__Obstacle));
  bool success = evoart_interfaces__msg__Obstacle__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
evoart_interfaces__msg__Obstacle__destroy(evoart_interfaces__msg__Obstacle * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    evoart_interfaces__msg__Obstacle__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
evoart_interfaces__msg__Obstacle__Sequence__init(evoart_interfaces__msg__Obstacle__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  evoart_interfaces__msg__Obstacle * data = NULL;

  if (size) {
    data = (evoart_interfaces__msg__Obstacle *)allocator.zero_allocate(size, sizeof(evoart_interfaces__msg__Obstacle), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = evoart_interfaces__msg__Obstacle__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        evoart_interfaces__msg__Obstacle__fini(&data[i - 1]);
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
evoart_interfaces__msg__Obstacle__Sequence__fini(evoart_interfaces__msg__Obstacle__Sequence * array)
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
      evoart_interfaces__msg__Obstacle__fini(&array->data[i]);
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

evoart_interfaces__msg__Obstacle__Sequence *
evoart_interfaces__msg__Obstacle__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  evoart_interfaces__msg__Obstacle__Sequence * array = (evoart_interfaces__msg__Obstacle__Sequence *)allocator.allocate(sizeof(evoart_interfaces__msg__Obstacle__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = evoart_interfaces__msg__Obstacle__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
evoart_interfaces__msg__Obstacle__Sequence__destroy(evoart_interfaces__msg__Obstacle__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    evoart_interfaces__msg__Obstacle__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
evoart_interfaces__msg__Obstacle__Sequence__are_equal(const evoart_interfaces__msg__Obstacle__Sequence * lhs, const evoart_interfaces__msg__Obstacle__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!evoart_interfaces__msg__Obstacle__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
evoart_interfaces__msg__Obstacle__Sequence__copy(
  const evoart_interfaces__msg__Obstacle__Sequence * input,
  evoart_interfaces__msg__Obstacle__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(evoart_interfaces__msg__Obstacle);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    evoart_interfaces__msg__Obstacle * data =
      (evoart_interfaces__msg__Obstacle *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!evoart_interfaces__msg__Obstacle__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          evoart_interfaces__msg__Obstacle__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!evoart_interfaces__msg__Obstacle__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
