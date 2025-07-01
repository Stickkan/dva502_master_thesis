// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_drone_interfaces:msg/AgentData.idl
// generated code does not contain a copyright notice
#include "custom_drone_interfaces/msg/detail/agent_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
custom_drone_interfaces__msg__AgentData__init(custom_drone_interfaces__msg__AgentData * msg)
{
  if (!msg) {
    return false;
  }
  // agentid
  // priority
  // vx
  // vy
  // vz
  // lat
  // lon
  // alt
  // time
  return true;
}

void
custom_drone_interfaces__msg__AgentData__fini(custom_drone_interfaces__msg__AgentData * msg)
{
  if (!msg) {
    return;
  }
  // agentid
  // priority
  // vx
  // vy
  // vz
  // lat
  // lon
  // alt
  // time
}

bool
custom_drone_interfaces__msg__AgentData__are_equal(const custom_drone_interfaces__msg__AgentData * lhs, const custom_drone_interfaces__msg__AgentData * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // agentid
  if (lhs->agentid != rhs->agentid) {
    return false;
  }
  // priority
  if (lhs->priority != rhs->priority) {
    return false;
  }
  // vx
  if (lhs->vx != rhs->vx) {
    return false;
  }
  // vy
  if (lhs->vy != rhs->vy) {
    return false;
  }
  // vz
  if (lhs->vz != rhs->vz) {
    return false;
  }
  // lat
  if (lhs->lat != rhs->lat) {
    return false;
  }
  // lon
  if (lhs->lon != rhs->lon) {
    return false;
  }
  // alt
  if (lhs->alt != rhs->alt) {
    return false;
  }
  // time
  if (lhs->time != rhs->time) {
    return false;
  }
  return true;
}

bool
custom_drone_interfaces__msg__AgentData__copy(
  const custom_drone_interfaces__msg__AgentData * input,
  custom_drone_interfaces__msg__AgentData * output)
{
  if (!input || !output) {
    return false;
  }
  // agentid
  output->agentid = input->agentid;
  // priority
  output->priority = input->priority;
  // vx
  output->vx = input->vx;
  // vy
  output->vy = input->vy;
  // vz
  output->vz = input->vz;
  // lat
  output->lat = input->lat;
  // lon
  output->lon = input->lon;
  // alt
  output->alt = input->alt;
  // time
  output->time = input->time;
  return true;
}

custom_drone_interfaces__msg__AgentData *
custom_drone_interfaces__msg__AgentData__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_drone_interfaces__msg__AgentData * msg = (custom_drone_interfaces__msg__AgentData *)allocator.allocate(sizeof(custom_drone_interfaces__msg__AgentData), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_drone_interfaces__msg__AgentData));
  bool success = custom_drone_interfaces__msg__AgentData__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_drone_interfaces__msg__AgentData__destroy(custom_drone_interfaces__msg__AgentData * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_drone_interfaces__msg__AgentData__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_drone_interfaces__msg__AgentData__Sequence__init(custom_drone_interfaces__msg__AgentData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_drone_interfaces__msg__AgentData * data = NULL;

  if (size) {
    data = (custom_drone_interfaces__msg__AgentData *)allocator.zero_allocate(size, sizeof(custom_drone_interfaces__msg__AgentData), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_drone_interfaces__msg__AgentData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_drone_interfaces__msg__AgentData__fini(&data[i - 1]);
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
custom_drone_interfaces__msg__AgentData__Sequence__fini(custom_drone_interfaces__msg__AgentData__Sequence * array)
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
      custom_drone_interfaces__msg__AgentData__fini(&array->data[i]);
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

custom_drone_interfaces__msg__AgentData__Sequence *
custom_drone_interfaces__msg__AgentData__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_drone_interfaces__msg__AgentData__Sequence * array = (custom_drone_interfaces__msg__AgentData__Sequence *)allocator.allocate(sizeof(custom_drone_interfaces__msg__AgentData__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_drone_interfaces__msg__AgentData__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_drone_interfaces__msg__AgentData__Sequence__destroy(custom_drone_interfaces__msg__AgentData__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_drone_interfaces__msg__AgentData__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_drone_interfaces__msg__AgentData__Sequence__are_equal(const custom_drone_interfaces__msg__AgentData__Sequence * lhs, const custom_drone_interfaces__msg__AgentData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_drone_interfaces__msg__AgentData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_drone_interfaces__msg__AgentData__Sequence__copy(
  const custom_drone_interfaces__msg__AgentData__Sequence * input,
  custom_drone_interfaces__msg__AgentData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_drone_interfaces__msg__AgentData);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_drone_interfaces__msg__AgentData * data =
      (custom_drone_interfaces__msg__AgentData *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_drone_interfaces__msg__AgentData__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_drone_interfaces__msg__AgentData__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_drone_interfaces__msg__AgentData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
