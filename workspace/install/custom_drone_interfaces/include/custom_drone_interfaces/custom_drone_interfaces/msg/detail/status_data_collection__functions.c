// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_drone_interfaces:msg/StatusDataCollection.idl
// generated code does not contain a copyright notice
#include "custom_drone_interfaces/msg/detail/status_data_collection__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
custom_drone_interfaces__msg__StatusDataCollection__init(custom_drone_interfaces__msg__StatusDataCollection * msg)
{
  if (!msg) {
    return false;
  }
  // remaining
  // time_remaining_s
  // battery_warning
  // battery_unhealthy
  // angular_velocity_invalid
  // attitude_invalid
  // global_position_invalid
  // wind_limit_exceeded
  // esc_arming_failure
  // imbalanced_prop
  // motor_failure
  return true;
}

void
custom_drone_interfaces__msg__StatusDataCollection__fini(custom_drone_interfaces__msg__StatusDataCollection * msg)
{
  if (!msg) {
    return;
  }
  // remaining
  // time_remaining_s
  // battery_warning
  // battery_unhealthy
  // angular_velocity_invalid
  // attitude_invalid
  // global_position_invalid
  // wind_limit_exceeded
  // esc_arming_failure
  // imbalanced_prop
  // motor_failure
}

bool
custom_drone_interfaces__msg__StatusDataCollection__are_equal(const custom_drone_interfaces__msg__StatusDataCollection * lhs, const custom_drone_interfaces__msg__StatusDataCollection * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // remaining
  if (lhs->remaining != rhs->remaining) {
    return false;
  }
  // time_remaining_s
  if (lhs->time_remaining_s != rhs->time_remaining_s) {
    return false;
  }
  // battery_warning
  if (lhs->battery_warning != rhs->battery_warning) {
    return false;
  }
  // battery_unhealthy
  if (lhs->battery_unhealthy != rhs->battery_unhealthy) {
    return false;
  }
  // angular_velocity_invalid
  if (lhs->angular_velocity_invalid != rhs->angular_velocity_invalid) {
    return false;
  }
  // attitude_invalid
  if (lhs->attitude_invalid != rhs->attitude_invalid) {
    return false;
  }
  // global_position_invalid
  if (lhs->global_position_invalid != rhs->global_position_invalid) {
    return false;
  }
  // wind_limit_exceeded
  if (lhs->wind_limit_exceeded != rhs->wind_limit_exceeded) {
    return false;
  }
  // esc_arming_failure
  if (lhs->esc_arming_failure != rhs->esc_arming_failure) {
    return false;
  }
  // imbalanced_prop
  if (lhs->imbalanced_prop != rhs->imbalanced_prop) {
    return false;
  }
  // motor_failure
  if (lhs->motor_failure != rhs->motor_failure) {
    return false;
  }
  return true;
}

bool
custom_drone_interfaces__msg__StatusDataCollection__copy(
  const custom_drone_interfaces__msg__StatusDataCollection * input,
  custom_drone_interfaces__msg__StatusDataCollection * output)
{
  if (!input || !output) {
    return false;
  }
  // remaining
  output->remaining = input->remaining;
  // time_remaining_s
  output->time_remaining_s = input->time_remaining_s;
  // battery_warning
  output->battery_warning = input->battery_warning;
  // battery_unhealthy
  output->battery_unhealthy = input->battery_unhealthy;
  // angular_velocity_invalid
  output->angular_velocity_invalid = input->angular_velocity_invalid;
  // attitude_invalid
  output->attitude_invalid = input->attitude_invalid;
  // global_position_invalid
  output->global_position_invalid = input->global_position_invalid;
  // wind_limit_exceeded
  output->wind_limit_exceeded = input->wind_limit_exceeded;
  // esc_arming_failure
  output->esc_arming_failure = input->esc_arming_failure;
  // imbalanced_prop
  output->imbalanced_prop = input->imbalanced_prop;
  // motor_failure
  output->motor_failure = input->motor_failure;
  return true;
}

custom_drone_interfaces__msg__StatusDataCollection *
custom_drone_interfaces__msg__StatusDataCollection__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_drone_interfaces__msg__StatusDataCollection * msg = (custom_drone_interfaces__msg__StatusDataCollection *)allocator.allocate(sizeof(custom_drone_interfaces__msg__StatusDataCollection), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_drone_interfaces__msg__StatusDataCollection));
  bool success = custom_drone_interfaces__msg__StatusDataCollection__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_drone_interfaces__msg__StatusDataCollection__destroy(custom_drone_interfaces__msg__StatusDataCollection * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_drone_interfaces__msg__StatusDataCollection__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_drone_interfaces__msg__StatusDataCollection__Sequence__init(custom_drone_interfaces__msg__StatusDataCollection__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_drone_interfaces__msg__StatusDataCollection * data = NULL;

  if (size) {
    data = (custom_drone_interfaces__msg__StatusDataCollection *)allocator.zero_allocate(size, sizeof(custom_drone_interfaces__msg__StatusDataCollection), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_drone_interfaces__msg__StatusDataCollection__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_drone_interfaces__msg__StatusDataCollection__fini(&data[i - 1]);
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
custom_drone_interfaces__msg__StatusDataCollection__Sequence__fini(custom_drone_interfaces__msg__StatusDataCollection__Sequence * array)
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
      custom_drone_interfaces__msg__StatusDataCollection__fini(&array->data[i]);
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

custom_drone_interfaces__msg__StatusDataCollection__Sequence *
custom_drone_interfaces__msg__StatusDataCollection__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_drone_interfaces__msg__StatusDataCollection__Sequence * array = (custom_drone_interfaces__msg__StatusDataCollection__Sequence *)allocator.allocate(sizeof(custom_drone_interfaces__msg__StatusDataCollection__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_drone_interfaces__msg__StatusDataCollection__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_drone_interfaces__msg__StatusDataCollection__Sequence__destroy(custom_drone_interfaces__msg__StatusDataCollection__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_drone_interfaces__msg__StatusDataCollection__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_drone_interfaces__msg__StatusDataCollection__Sequence__are_equal(const custom_drone_interfaces__msg__StatusDataCollection__Sequence * lhs, const custom_drone_interfaces__msg__StatusDataCollection__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_drone_interfaces__msg__StatusDataCollection__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_drone_interfaces__msg__StatusDataCollection__Sequence__copy(
  const custom_drone_interfaces__msg__StatusDataCollection__Sequence * input,
  custom_drone_interfaces__msg__StatusDataCollection__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_drone_interfaces__msg__StatusDataCollection);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_drone_interfaces__msg__StatusDataCollection * data =
      (custom_drone_interfaces__msg__StatusDataCollection *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_drone_interfaces__msg__StatusDataCollection__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_drone_interfaces__msg__StatusDataCollection__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_drone_interfaces__msg__StatusDataCollection__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
