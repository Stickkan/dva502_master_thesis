// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_drone_interfaces:msg/SensorDataCollection.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__SENSOR_DATA_COLLECTION__STRUCT_HPP_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__SENSOR_DATA_COLLECTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_drone_interfaces__msg__SensorDataCollection __attribute__((deprecated))
#else
# define DEPRECATED__custom_drone_interfaces__msg__SensorDataCollection __declspec(deprecated)
#endif

namespace custom_drone_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SensorDataCollection_
{
  using Type = SensorDataCollection_<ContainerAllocator>;

  explicit SensorDataCollection_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->global_position_time = 0ull;
      this->lat = 0.0;
      this->lon = 0.0;
      this->alt = 0.0f;
      this->alt_ellipsoid = 0.0f;
      this->terrain_alt = 0.0f;
      this->terrain_alt_valid = false;
      this->local_position_time = 0ull;
      this->x = 0.0f;
      this->y = 0.0f;
      this->z = 0.0f;
      this->vx = 0.0f;
      this->vy = 0.0f;
      this->vz = 0.0f;
      this->ax = 0.0f;
      this->ay = 0.0f;
      this->az = 0.0f;
      this->heading = 0.0f;
      this->ref_lat = 0.0;
      this->ref_lon = 0.0;
      this->ref_alt = 0.0f;
      this->dist_bottom = 0.0f;
      this->dist_bottom_valid = false;
      this->attitude_quaternion_time = 0ull;
      std::fill<typename std::array<float, 4>::iterator, float>(this->q.begin(), this->q.end(), 0.0f);
    }
  }

  explicit SensorDataCollection_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : q(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->global_position_time = 0ull;
      this->lat = 0.0;
      this->lon = 0.0;
      this->alt = 0.0f;
      this->alt_ellipsoid = 0.0f;
      this->terrain_alt = 0.0f;
      this->terrain_alt_valid = false;
      this->local_position_time = 0ull;
      this->x = 0.0f;
      this->y = 0.0f;
      this->z = 0.0f;
      this->vx = 0.0f;
      this->vy = 0.0f;
      this->vz = 0.0f;
      this->ax = 0.0f;
      this->ay = 0.0f;
      this->az = 0.0f;
      this->heading = 0.0f;
      this->ref_lat = 0.0;
      this->ref_lon = 0.0;
      this->ref_alt = 0.0f;
      this->dist_bottom = 0.0f;
      this->dist_bottom_valid = false;
      this->attitude_quaternion_time = 0ull;
      std::fill<typename std::array<float, 4>::iterator, float>(this->q.begin(), this->q.end(), 0.0f);
    }
  }

  // field types and members
  using _global_position_time_type =
    uint64_t;
  _global_position_time_type global_position_time;
  using _lat_type =
    double;
  _lat_type lat;
  using _lon_type =
    double;
  _lon_type lon;
  using _alt_type =
    float;
  _alt_type alt;
  using _alt_ellipsoid_type =
    float;
  _alt_ellipsoid_type alt_ellipsoid;
  using _terrain_alt_type =
    float;
  _terrain_alt_type terrain_alt;
  using _terrain_alt_valid_type =
    bool;
  _terrain_alt_valid_type terrain_alt_valid;
  using _local_position_time_type =
    uint64_t;
  _local_position_time_type local_position_time;
  using _x_type =
    float;
  _x_type x;
  using _y_type =
    float;
  _y_type y;
  using _z_type =
    float;
  _z_type z;
  using _vx_type =
    float;
  _vx_type vx;
  using _vy_type =
    float;
  _vy_type vy;
  using _vz_type =
    float;
  _vz_type vz;
  using _ax_type =
    float;
  _ax_type ax;
  using _ay_type =
    float;
  _ay_type ay;
  using _az_type =
    float;
  _az_type az;
  using _heading_type =
    float;
  _heading_type heading;
  using _ref_lat_type =
    double;
  _ref_lat_type ref_lat;
  using _ref_lon_type =
    double;
  _ref_lon_type ref_lon;
  using _ref_alt_type =
    float;
  _ref_alt_type ref_alt;
  using _dist_bottom_type =
    float;
  _dist_bottom_type dist_bottom;
  using _dist_bottom_valid_type =
    bool;
  _dist_bottom_valid_type dist_bottom_valid;
  using _attitude_quaternion_time_type =
    uint64_t;
  _attitude_quaternion_time_type attitude_quaternion_time;
  using _q_type =
    std::array<float, 4>;
  _q_type q;

  // setters for named parameter idiom
  Type & set__global_position_time(
    const uint64_t & _arg)
  {
    this->global_position_time = _arg;
    return *this;
  }
  Type & set__lat(
    const double & _arg)
  {
    this->lat = _arg;
    return *this;
  }
  Type & set__lon(
    const double & _arg)
  {
    this->lon = _arg;
    return *this;
  }
  Type & set__alt(
    const float & _arg)
  {
    this->alt = _arg;
    return *this;
  }
  Type & set__alt_ellipsoid(
    const float & _arg)
  {
    this->alt_ellipsoid = _arg;
    return *this;
  }
  Type & set__terrain_alt(
    const float & _arg)
  {
    this->terrain_alt = _arg;
    return *this;
  }
  Type & set__terrain_alt_valid(
    const bool & _arg)
  {
    this->terrain_alt_valid = _arg;
    return *this;
  }
  Type & set__local_position_time(
    const uint64_t & _arg)
  {
    this->local_position_time = _arg;
    return *this;
  }
  Type & set__x(
    const float & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const float & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__z(
    const float & _arg)
  {
    this->z = _arg;
    return *this;
  }
  Type & set__vx(
    const float & _arg)
  {
    this->vx = _arg;
    return *this;
  }
  Type & set__vy(
    const float & _arg)
  {
    this->vy = _arg;
    return *this;
  }
  Type & set__vz(
    const float & _arg)
  {
    this->vz = _arg;
    return *this;
  }
  Type & set__ax(
    const float & _arg)
  {
    this->ax = _arg;
    return *this;
  }
  Type & set__ay(
    const float & _arg)
  {
    this->ay = _arg;
    return *this;
  }
  Type & set__az(
    const float & _arg)
  {
    this->az = _arg;
    return *this;
  }
  Type & set__heading(
    const float & _arg)
  {
    this->heading = _arg;
    return *this;
  }
  Type & set__ref_lat(
    const double & _arg)
  {
    this->ref_lat = _arg;
    return *this;
  }
  Type & set__ref_lon(
    const double & _arg)
  {
    this->ref_lon = _arg;
    return *this;
  }
  Type & set__ref_alt(
    const float & _arg)
  {
    this->ref_alt = _arg;
    return *this;
  }
  Type & set__dist_bottom(
    const float & _arg)
  {
    this->dist_bottom = _arg;
    return *this;
  }
  Type & set__dist_bottom_valid(
    const bool & _arg)
  {
    this->dist_bottom_valid = _arg;
    return *this;
  }
  Type & set__attitude_quaternion_time(
    const uint64_t & _arg)
  {
    this->attitude_quaternion_time = _arg;
    return *this;
  }
  Type & set__q(
    const std::array<float, 4> & _arg)
  {
    this->q = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_drone_interfaces::msg::SensorDataCollection_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_drone_interfaces::msg::SensorDataCollection_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_drone_interfaces::msg::SensorDataCollection_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_drone_interfaces::msg::SensorDataCollection_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_drone_interfaces::msg::SensorDataCollection_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_drone_interfaces::msg::SensorDataCollection_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_drone_interfaces::msg::SensorDataCollection_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_drone_interfaces::msg::SensorDataCollection_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_drone_interfaces::msg::SensorDataCollection_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_drone_interfaces::msg::SensorDataCollection_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_drone_interfaces__msg__SensorDataCollection
    std::shared_ptr<custom_drone_interfaces::msg::SensorDataCollection_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_drone_interfaces__msg__SensorDataCollection
    std::shared_ptr<custom_drone_interfaces::msg::SensorDataCollection_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SensorDataCollection_ & other) const
  {
    if (this->global_position_time != other.global_position_time) {
      return false;
    }
    if (this->lat != other.lat) {
      return false;
    }
    if (this->lon != other.lon) {
      return false;
    }
    if (this->alt != other.alt) {
      return false;
    }
    if (this->alt_ellipsoid != other.alt_ellipsoid) {
      return false;
    }
    if (this->terrain_alt != other.terrain_alt) {
      return false;
    }
    if (this->terrain_alt_valid != other.terrain_alt_valid) {
      return false;
    }
    if (this->local_position_time != other.local_position_time) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    if (this->vx != other.vx) {
      return false;
    }
    if (this->vy != other.vy) {
      return false;
    }
    if (this->vz != other.vz) {
      return false;
    }
    if (this->ax != other.ax) {
      return false;
    }
    if (this->ay != other.ay) {
      return false;
    }
    if (this->az != other.az) {
      return false;
    }
    if (this->heading != other.heading) {
      return false;
    }
    if (this->ref_lat != other.ref_lat) {
      return false;
    }
    if (this->ref_lon != other.ref_lon) {
      return false;
    }
    if (this->ref_alt != other.ref_alt) {
      return false;
    }
    if (this->dist_bottom != other.dist_bottom) {
      return false;
    }
    if (this->dist_bottom_valid != other.dist_bottom_valid) {
      return false;
    }
    if (this->attitude_quaternion_time != other.attitude_quaternion_time) {
      return false;
    }
    if (this->q != other.q) {
      return false;
    }
    return true;
  }
  bool operator!=(const SensorDataCollection_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SensorDataCollection_

// alias to use template instance with default allocator
using SensorDataCollection =
  custom_drone_interfaces::msg::SensorDataCollection_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_drone_interfaces

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__SENSOR_DATA_COLLECTION__STRUCT_HPP_
