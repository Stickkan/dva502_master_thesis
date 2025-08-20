// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_drone_interfaces:msg/SensorDataCollection.idl
// generated code does not contain a copyright notice
#include "custom_drone_interfaces/msg/detail/sensor_data_collection__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
custom_drone_interfaces__msg__SensorDataCollection__init(custom_drone_interfaces__msg__SensorDataCollection * msg)
{
  if (!msg) {
    return false;
  }
  // global_position_time
  // lat
  // lon
  // alt
  // alt_ellipsoid
  // terrain_alt
  // terrain_alt_valid
  // local_position_time
  // x
  // y
  // z
  // vx
  // vy
  // vz
  // ax
  // ay
  // az
  // heading
  // ref_lat
  // ref_lon
  // ref_alt
  // dist_bottom
  // dist_bottom_valid
  // attitude_quaternion_time
  // q
  return true;
}

void
custom_drone_interfaces__msg__SensorDataCollection__fini(custom_drone_interfaces__msg__SensorDataCollection * msg)
{
  if (!msg) {
    return;
  }
  // global_position_time
  // lat
  // lon
  // alt
  // alt_ellipsoid
  // terrain_alt
  // terrain_alt_valid
  // local_position_time
  // x
  // y
  // z
  // vx
  // vy
  // vz
  // ax
  // ay
  // az
  // heading
  // ref_lat
  // ref_lon
  // ref_alt
  // dist_bottom
  // dist_bottom_valid
  // attitude_quaternion_time
  // q
}

bool
custom_drone_interfaces__msg__SensorDataCollection__are_equal(const custom_drone_interfaces__msg__SensorDataCollection * lhs, const custom_drone_interfaces__msg__SensorDataCollection * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // global_position_time
  if (lhs->global_position_time != rhs->global_position_time) {
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
  // alt_ellipsoid
  if (lhs->alt_ellipsoid != rhs->alt_ellipsoid) {
    return false;
  }
  // terrain_alt
  if (lhs->terrain_alt != rhs->terrain_alt) {
    return false;
  }
  // terrain_alt_valid
  if (lhs->terrain_alt_valid != rhs->terrain_alt_valid) {
    return false;
  }
  // local_position_time
  if (lhs->local_position_time != rhs->local_position_time) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // z
  if (lhs->z != rhs->z) {
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
  // ax
  if (lhs->ax != rhs->ax) {
    return false;
  }
  // ay
  if (lhs->ay != rhs->ay) {
    return false;
  }
  // az
  if (lhs->az != rhs->az) {
    return false;
  }
  // heading
  if (lhs->heading != rhs->heading) {
    return false;
  }
  // ref_lat
  if (lhs->ref_lat != rhs->ref_lat) {
    return false;
  }
  // ref_lon
  if (lhs->ref_lon != rhs->ref_lon) {
    return false;
  }
  // ref_alt
  if (lhs->ref_alt != rhs->ref_alt) {
    return false;
  }
  // dist_bottom
  if (lhs->dist_bottom != rhs->dist_bottom) {
    return false;
  }
  // dist_bottom_valid
  if (lhs->dist_bottom_valid != rhs->dist_bottom_valid) {
    return false;
  }
  // attitude_quaternion_time
  if (lhs->attitude_quaternion_time != rhs->attitude_quaternion_time) {
    return false;
  }
  // q
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->q[i] != rhs->q[i]) {
      return false;
    }
  }
  return true;
}

bool
custom_drone_interfaces__msg__SensorDataCollection__copy(
  const custom_drone_interfaces__msg__SensorDataCollection * input,
  custom_drone_interfaces__msg__SensorDataCollection * output)
{
  if (!input || !output) {
    return false;
  }
  // global_position_time
  output->global_position_time = input->global_position_time;
  // lat
  output->lat = input->lat;
  // lon
  output->lon = input->lon;
  // alt
  output->alt = input->alt;
  // alt_ellipsoid
  output->alt_ellipsoid = input->alt_ellipsoid;
  // terrain_alt
  output->terrain_alt = input->terrain_alt;
  // terrain_alt_valid
  output->terrain_alt_valid = input->terrain_alt_valid;
  // local_position_time
  output->local_position_time = input->local_position_time;
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // z
  output->z = input->z;
  // vx
  output->vx = input->vx;
  // vy
  output->vy = input->vy;
  // vz
  output->vz = input->vz;
  // ax
  output->ax = input->ax;
  // ay
  output->ay = input->ay;
  // az
  output->az = input->az;
  // heading
  output->heading = input->heading;
  // ref_lat
  output->ref_lat = input->ref_lat;
  // ref_lon
  output->ref_lon = input->ref_lon;
  // ref_alt
  output->ref_alt = input->ref_alt;
  // dist_bottom
  output->dist_bottom = input->dist_bottom;
  // dist_bottom_valid
  output->dist_bottom_valid = input->dist_bottom_valid;
  // attitude_quaternion_time
  output->attitude_quaternion_time = input->attitude_quaternion_time;
  // q
  for (size_t i = 0; i < 4; ++i) {
    output->q[i] = input->q[i];
  }
  return true;
}

custom_drone_interfaces__msg__SensorDataCollection *
custom_drone_interfaces__msg__SensorDataCollection__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_drone_interfaces__msg__SensorDataCollection * msg = (custom_drone_interfaces__msg__SensorDataCollection *)allocator.allocate(sizeof(custom_drone_interfaces__msg__SensorDataCollection), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_drone_interfaces__msg__SensorDataCollection));
  bool success = custom_drone_interfaces__msg__SensorDataCollection__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_drone_interfaces__msg__SensorDataCollection__destroy(custom_drone_interfaces__msg__SensorDataCollection * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_drone_interfaces__msg__SensorDataCollection__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_drone_interfaces__msg__SensorDataCollection__Sequence__init(custom_drone_interfaces__msg__SensorDataCollection__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_drone_interfaces__msg__SensorDataCollection * data = NULL;

  if (size) {
    data = (custom_drone_interfaces__msg__SensorDataCollection *)allocator.zero_allocate(size, sizeof(custom_drone_interfaces__msg__SensorDataCollection), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_drone_interfaces__msg__SensorDataCollection__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_drone_interfaces__msg__SensorDataCollection__fini(&data[i - 1]);
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
custom_drone_interfaces__msg__SensorDataCollection__Sequence__fini(custom_drone_interfaces__msg__SensorDataCollection__Sequence * array)
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
      custom_drone_interfaces__msg__SensorDataCollection__fini(&array->data[i]);
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

custom_drone_interfaces__msg__SensorDataCollection__Sequence *
custom_drone_interfaces__msg__SensorDataCollection__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_drone_interfaces__msg__SensorDataCollection__Sequence * array = (custom_drone_interfaces__msg__SensorDataCollection__Sequence *)allocator.allocate(sizeof(custom_drone_interfaces__msg__SensorDataCollection__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_drone_interfaces__msg__SensorDataCollection__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_drone_interfaces__msg__SensorDataCollection__Sequence__destroy(custom_drone_interfaces__msg__SensorDataCollection__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_drone_interfaces__msg__SensorDataCollection__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_drone_interfaces__msg__SensorDataCollection__Sequence__are_equal(const custom_drone_interfaces__msg__SensorDataCollection__Sequence * lhs, const custom_drone_interfaces__msg__SensorDataCollection__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_drone_interfaces__msg__SensorDataCollection__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_drone_interfaces__msg__SensorDataCollection__Sequence__copy(
  const custom_drone_interfaces__msg__SensorDataCollection__Sequence * input,
  custom_drone_interfaces__msg__SensorDataCollection__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_drone_interfaces__msg__SensorDataCollection);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_drone_interfaces__msg__SensorDataCollection * data =
      (custom_drone_interfaces__msg__SensorDataCollection *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_drone_interfaces__msg__SensorDataCollection__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_drone_interfaces__msg__SensorDataCollection__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_drone_interfaces__msg__SensorDataCollection__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
