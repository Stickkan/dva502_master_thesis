// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_drone_interfaces:msg/SetPoint.idl
// generated code does not contain a copyright notice
#include "custom_drone_interfaces/msg/detail/set_point__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `setpoint_data`
#include "custom_drone_interfaces/msg/detail/sub_waypoint__functions.h"

bool
custom_drone_interfaces__msg__SetPoint__init(custom_drone_interfaces__msg__SetPoint * msg)
{
  if (!msg) {
    return false;
  }
  // setpoint_data
  if (!custom_drone_interfaces__msg__SubWaypoint__init(&msg->setpoint_data)) {
    custom_drone_interfaces__msg__SetPoint__fini(msg);
    return false;
  }
  // frequency
  // r_t_f
  return true;
}

void
custom_drone_interfaces__msg__SetPoint__fini(custom_drone_interfaces__msg__SetPoint * msg)
{
  if (!msg) {
    return;
  }
  // setpoint_data
  custom_drone_interfaces__msg__SubWaypoint__fini(&msg->setpoint_data);
  // frequency
  // r_t_f
}

bool
custom_drone_interfaces__msg__SetPoint__are_equal(const custom_drone_interfaces__msg__SetPoint * lhs, const custom_drone_interfaces__msg__SetPoint * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // setpoint_data
  if (!custom_drone_interfaces__msg__SubWaypoint__are_equal(
      &(lhs->setpoint_data), &(rhs->setpoint_data)))
  {
    return false;
  }
  // frequency
  if (lhs->frequency != rhs->frequency) {
    return false;
  }
  // r_t_f
  if (lhs->r_t_f != rhs->r_t_f) {
    return false;
  }
  return true;
}

bool
custom_drone_interfaces__msg__SetPoint__copy(
  const custom_drone_interfaces__msg__SetPoint * input,
  custom_drone_interfaces__msg__SetPoint * output)
{
  if (!input || !output) {
    return false;
  }
  // setpoint_data
  if (!custom_drone_interfaces__msg__SubWaypoint__copy(
      &(input->setpoint_data), &(output->setpoint_data)))
  {
    return false;
  }
  // frequency
  output->frequency = input->frequency;
  // r_t_f
  output->r_t_f = input->r_t_f;
  return true;
}

custom_drone_interfaces__msg__SetPoint *
custom_drone_interfaces__msg__SetPoint__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_drone_interfaces__msg__SetPoint * msg = (custom_drone_interfaces__msg__SetPoint *)allocator.allocate(sizeof(custom_drone_interfaces__msg__SetPoint), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_drone_interfaces__msg__SetPoint));
  bool success = custom_drone_interfaces__msg__SetPoint__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_drone_interfaces__msg__SetPoint__destroy(custom_drone_interfaces__msg__SetPoint * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_drone_interfaces__msg__SetPoint__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_drone_interfaces__msg__SetPoint__Sequence__init(custom_drone_interfaces__msg__SetPoint__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_drone_interfaces__msg__SetPoint * data = NULL;

  if (size) {
    data = (custom_drone_interfaces__msg__SetPoint *)allocator.zero_allocate(size, sizeof(custom_drone_interfaces__msg__SetPoint), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_drone_interfaces__msg__SetPoint__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_drone_interfaces__msg__SetPoint__fini(&data[i - 1]);
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
custom_drone_interfaces__msg__SetPoint__Sequence__fini(custom_drone_interfaces__msg__SetPoint__Sequence * array)
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
      custom_drone_interfaces__msg__SetPoint__fini(&array->data[i]);
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

custom_drone_interfaces__msg__SetPoint__Sequence *
custom_drone_interfaces__msg__SetPoint__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_drone_interfaces__msg__SetPoint__Sequence * array = (custom_drone_interfaces__msg__SetPoint__Sequence *)allocator.allocate(sizeof(custom_drone_interfaces__msg__SetPoint__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_drone_interfaces__msg__SetPoint__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_drone_interfaces__msg__SetPoint__Sequence__destroy(custom_drone_interfaces__msg__SetPoint__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_drone_interfaces__msg__SetPoint__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_drone_interfaces__msg__SetPoint__Sequence__are_equal(const custom_drone_interfaces__msg__SetPoint__Sequence * lhs, const custom_drone_interfaces__msg__SetPoint__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_drone_interfaces__msg__SetPoint__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_drone_interfaces__msg__SetPoint__Sequence__copy(
  const custom_drone_interfaces__msg__SetPoint__Sequence * input,
  custom_drone_interfaces__msg__SetPoint__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_drone_interfaces__msg__SetPoint);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_drone_interfaces__msg__SetPoint * data =
      (custom_drone_interfaces__msg__SetPoint *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_drone_interfaces__msg__SetPoint__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_drone_interfaces__msg__SetPoint__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_drone_interfaces__msg__SetPoint__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
