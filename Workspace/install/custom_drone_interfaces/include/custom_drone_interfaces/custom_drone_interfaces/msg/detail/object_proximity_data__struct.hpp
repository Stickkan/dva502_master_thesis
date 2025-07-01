// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_drone_interfaces:msg/ObjectProximityData.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__OBJECT_PROXIMITY_DATA__STRUCT_HPP_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__OBJECT_PROXIMITY_DATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_drone_interfaces__msg__ObjectProximityData __attribute__((deprecated))
#else
# define DEPRECATED__custom_drone_interfaces__msg__ObjectProximityData __declspec(deprecated)
#endif

namespace custom_drone_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ObjectProximityData_
{
  using Type = ObjectProximityData_<ContainerAllocator>;

  explicit ObjectProximityData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->agentid = 0ul;
      this->priority = 0;
      this->vx = 0.0f;
      this->vy = 0.0f;
      this->vz = 0.0f;
      this->lat = 0.0;
      this->lon = 0.0;
      this->alt = 0.0f;
      this->time = 0ull;
    }
  }

  explicit ObjectProximityData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->agentid = 0ul;
      this->priority = 0;
      this->vx = 0.0f;
      this->vy = 0.0f;
      this->vz = 0.0f;
      this->lat = 0.0;
      this->lon = 0.0;
      this->alt = 0.0f;
      this->time = 0ull;
    }
  }

  // field types and members
  using _agentid_type =
    uint32_t;
  _agentid_type agentid;
  using _priority_type =
    uint8_t;
  _priority_type priority;
  using _vx_type =
    float;
  _vx_type vx;
  using _vy_type =
    float;
  _vy_type vy;
  using _vz_type =
    float;
  _vz_type vz;
  using _lat_type =
    double;
  _lat_type lat;
  using _lon_type =
    double;
  _lon_type lon;
  using _alt_type =
    float;
  _alt_type alt;
  using _time_type =
    uint64_t;
  _time_type time;

  // setters for named parameter idiom
  Type & set__agentid(
    const uint32_t & _arg)
  {
    this->agentid = _arg;
    return *this;
  }
  Type & set__priority(
    const uint8_t & _arg)
  {
    this->priority = _arg;
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
  Type & set__time(
    const uint64_t & _arg)
  {
    this->time = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_drone_interfaces::msg::ObjectProximityData_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_drone_interfaces::msg::ObjectProximityData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_drone_interfaces::msg::ObjectProximityData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_drone_interfaces::msg::ObjectProximityData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_drone_interfaces::msg::ObjectProximityData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_drone_interfaces::msg::ObjectProximityData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_drone_interfaces::msg::ObjectProximityData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_drone_interfaces::msg::ObjectProximityData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_drone_interfaces::msg::ObjectProximityData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_drone_interfaces::msg::ObjectProximityData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_drone_interfaces__msg__ObjectProximityData
    std::shared_ptr<custom_drone_interfaces::msg::ObjectProximityData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_drone_interfaces__msg__ObjectProximityData
    std::shared_ptr<custom_drone_interfaces::msg::ObjectProximityData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ObjectProximityData_ & other) const
  {
    if (this->agentid != other.agentid) {
      return false;
    }
    if (this->priority != other.priority) {
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
    if (this->lat != other.lat) {
      return false;
    }
    if (this->lon != other.lon) {
      return false;
    }
    if (this->alt != other.alt) {
      return false;
    }
    if (this->time != other.time) {
      return false;
    }
    return true;
  }
  bool operator!=(const ObjectProximityData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ObjectProximityData_

// alias to use template instance with default allocator
using ObjectProximityData =
  custom_drone_interfaces::msg::ObjectProximityData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_drone_interfaces

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__OBJECT_PROXIMITY_DATA__STRUCT_HPP_
