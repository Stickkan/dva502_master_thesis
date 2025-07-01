// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_drone_interfaces:msg/SubWaypoint.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__SUB_WAYPOINT__STRUCT_HPP_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__SUB_WAYPOINT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'point'
#include "geometry_msgs/msg/detail/point__struct.hpp"
// Member 'velocity'
// Member 'acceleration'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_drone_interfaces__msg__SubWaypoint __attribute__((deprecated))
#else
# define DEPRECATED__custom_drone_interfaces__msg__SubWaypoint __declspec(deprecated)
#endif

namespace custom_drone_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SubWaypoint_
{
  using Type = SubWaypoint_<ContainerAllocator>;

  explicit SubWaypoint_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : point(_init),
    velocity(_init),
    acceleration(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->heading = 0.0;
      this->time_sec = 0.0;
    }
  }

  explicit SubWaypoint_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : point(_alloc, _init),
    velocity(_alloc, _init),
    acceleration(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->heading = 0.0;
      this->time_sec = 0.0;
    }
  }

  // field types and members
  using _point_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _point_type point;
  using _velocity_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _velocity_type velocity;
  using _acceleration_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _acceleration_type acceleration;
  using _heading_type =
    double;
  _heading_type heading;
  using _time_sec_type =
    double;
  _time_sec_type time_sec;

  // setters for named parameter idiom
  Type & set__point(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->point = _arg;
    return *this;
  }
  Type & set__velocity(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->velocity = _arg;
    return *this;
  }
  Type & set__acceleration(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->acceleration = _arg;
    return *this;
  }
  Type & set__heading(
    const double & _arg)
  {
    this->heading = _arg;
    return *this;
  }
  Type & set__time_sec(
    const double & _arg)
  {
    this->time_sec = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_drone_interfaces::msg::SubWaypoint_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_drone_interfaces::msg::SubWaypoint_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_drone_interfaces::msg::SubWaypoint_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_drone_interfaces::msg::SubWaypoint_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_drone_interfaces::msg::SubWaypoint_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_drone_interfaces::msg::SubWaypoint_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_drone_interfaces::msg::SubWaypoint_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_drone_interfaces::msg::SubWaypoint_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_drone_interfaces::msg::SubWaypoint_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_drone_interfaces::msg::SubWaypoint_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_drone_interfaces__msg__SubWaypoint
    std::shared_ptr<custom_drone_interfaces::msg::SubWaypoint_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_drone_interfaces__msg__SubWaypoint
    std::shared_ptr<custom_drone_interfaces::msg::SubWaypoint_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SubWaypoint_ & other) const
  {
    if (this->point != other.point) {
      return false;
    }
    if (this->velocity != other.velocity) {
      return false;
    }
    if (this->acceleration != other.acceleration) {
      return false;
    }
    if (this->heading != other.heading) {
      return false;
    }
    if (this->time_sec != other.time_sec) {
      return false;
    }
    return true;
  }
  bool operator!=(const SubWaypoint_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SubWaypoint_

// alias to use template instance with default allocator
using SubWaypoint =
  custom_drone_interfaces::msg::SubWaypoint_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_drone_interfaces

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__SUB_WAYPOINT__STRUCT_HPP_
