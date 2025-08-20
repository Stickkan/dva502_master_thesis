// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_drone_interfaces:msg/Waypoint.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__WAYPOINT__STRUCT_HPP_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__WAYPOINT__STRUCT_HPP_

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
#include "geometry_msgs/msg/detail/vector3__struct.hpp"
// Member 'subtrajectory'
#include "custom_drone_interfaces/msg/detail/sub_waypoint__struct.hpp"
// Member 'task'
#include "custom_drone_interfaces/msg/detail/task_specification__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_drone_interfaces__msg__Waypoint __attribute__((deprecated))
#else
# define DEPRECATED__custom_drone_interfaces__msg__Waypoint __declspec(deprecated)
#endif

namespace custom_drone_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Waypoint_
{
  using Type = Waypoint_<ContainerAllocator>;

  explicit Waypoint_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : point(_init),
    velocity(_init),
    task(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->stop = false;
      this->heading = 0.0;
      this->time_in_seconds = 0.0;
      this->hold_time = 0.0;
      this->acceptence_radius = 0.0f;
    }
  }

  explicit Waypoint_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : point(_alloc, _init),
    velocity(_alloc, _init),
    task(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->stop = false;
      this->heading = 0.0;
      this->time_in_seconds = 0.0;
      this->hold_time = 0.0;
      this->acceptence_radius = 0.0f;
    }
  }

  // field types and members
  using _point_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _point_type point;
  using _velocity_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _velocity_type velocity;
  using _subtrajectory_type =
    std::vector<custom_drone_interfaces::msg::SubWaypoint_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<custom_drone_interfaces::msg::SubWaypoint_<ContainerAllocator>>>;
  _subtrajectory_type subtrajectory;
  using _stop_type =
    bool;
  _stop_type stop;
  using _heading_type =
    double;
  _heading_type heading;
  using _time_in_seconds_type =
    double;
  _time_in_seconds_type time_in_seconds;
  using _hold_time_type =
    double;
  _hold_time_type hold_time;
  using _acceptence_radius_type =
    float;
  _acceptence_radius_type acceptence_radius;
  using _task_type =
    custom_drone_interfaces::msg::TaskSpecification_<ContainerAllocator>;
  _task_type task;
  using _commandid_type =
    std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>>;
  _commandid_type commandid;

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
  Type & set__subtrajectory(
    const std::vector<custom_drone_interfaces::msg::SubWaypoint_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<custom_drone_interfaces::msg::SubWaypoint_<ContainerAllocator>>> & _arg)
  {
    this->subtrajectory = _arg;
    return *this;
  }
  Type & set__stop(
    const bool & _arg)
  {
    this->stop = _arg;
    return *this;
  }
  Type & set__heading(
    const double & _arg)
  {
    this->heading = _arg;
    return *this;
  }
  Type & set__time_in_seconds(
    const double & _arg)
  {
    this->time_in_seconds = _arg;
    return *this;
  }
  Type & set__hold_time(
    const double & _arg)
  {
    this->hold_time = _arg;
    return *this;
  }
  Type & set__acceptence_radius(
    const float & _arg)
  {
    this->acceptence_radius = _arg;
    return *this;
  }
  Type & set__task(
    const custom_drone_interfaces::msg::TaskSpecification_<ContainerAllocator> & _arg)
  {
    this->task = _arg;
    return *this;
  }
  Type & set__commandid(
    const std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> & _arg)
  {
    this->commandid = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_drone_interfaces::msg::Waypoint_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_drone_interfaces::msg::Waypoint_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_drone_interfaces::msg::Waypoint_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_drone_interfaces::msg::Waypoint_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_drone_interfaces::msg::Waypoint_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_drone_interfaces::msg::Waypoint_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_drone_interfaces::msg::Waypoint_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_drone_interfaces::msg::Waypoint_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_drone_interfaces::msg::Waypoint_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_drone_interfaces::msg::Waypoint_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_drone_interfaces__msg__Waypoint
    std::shared_ptr<custom_drone_interfaces::msg::Waypoint_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_drone_interfaces__msg__Waypoint
    std::shared_ptr<custom_drone_interfaces::msg::Waypoint_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Waypoint_ & other) const
  {
    if (this->point != other.point) {
      return false;
    }
    if (this->velocity != other.velocity) {
      return false;
    }
    if (this->subtrajectory != other.subtrajectory) {
      return false;
    }
    if (this->stop != other.stop) {
      return false;
    }
    if (this->heading != other.heading) {
      return false;
    }
    if (this->time_in_seconds != other.time_in_seconds) {
      return false;
    }
    if (this->hold_time != other.hold_time) {
      return false;
    }
    if (this->acceptence_radius != other.acceptence_radius) {
      return false;
    }
    if (this->task != other.task) {
      return false;
    }
    if (this->commandid != other.commandid) {
      return false;
    }
    return true;
  }
  bool operator!=(const Waypoint_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Waypoint_

// alias to use template instance with default allocator
using Waypoint =
  custom_drone_interfaces::msg::Waypoint_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_drone_interfaces

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__WAYPOINT__STRUCT_HPP_
