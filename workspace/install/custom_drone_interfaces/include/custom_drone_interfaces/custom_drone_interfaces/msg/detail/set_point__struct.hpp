// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_drone_interfaces:msg/SetPoint.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__SET_POINT__STRUCT_HPP_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__SET_POINT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'setpoint_data'
#include "custom_drone_interfaces/msg/detail/sub_waypoint__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_drone_interfaces__msg__SetPoint __attribute__((deprecated))
#else
# define DEPRECATED__custom_drone_interfaces__msg__SetPoint __declspec(deprecated)
#endif

namespace custom_drone_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SetPoint_
{
  using Type = SetPoint_<ContainerAllocator>;

  explicit SetPoint_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : setpoint_data(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->frequency = 0.0f;
      this->r_t_f = false;
    }
  }

  explicit SetPoint_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : setpoint_data(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->frequency = 0.0f;
      this->r_t_f = false;
    }
  }

  // field types and members
  using _setpoint_data_type =
    custom_drone_interfaces::msg::SubWaypoint_<ContainerAllocator>;
  _setpoint_data_type setpoint_data;
  using _frequency_type =
    float;
  _frequency_type frequency;
  using _r_t_f_type =
    bool;
  _r_t_f_type r_t_f;

  // setters for named parameter idiom
  Type & set__setpoint_data(
    const custom_drone_interfaces::msg::SubWaypoint_<ContainerAllocator> & _arg)
  {
    this->setpoint_data = _arg;
    return *this;
  }
  Type & set__frequency(
    const float & _arg)
  {
    this->frequency = _arg;
    return *this;
  }
  Type & set__r_t_f(
    const bool & _arg)
  {
    this->r_t_f = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_drone_interfaces::msg::SetPoint_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_drone_interfaces::msg::SetPoint_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_drone_interfaces::msg::SetPoint_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_drone_interfaces::msg::SetPoint_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_drone_interfaces::msg::SetPoint_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_drone_interfaces::msg::SetPoint_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_drone_interfaces::msg::SetPoint_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_drone_interfaces::msg::SetPoint_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_drone_interfaces::msg::SetPoint_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_drone_interfaces::msg::SetPoint_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_drone_interfaces__msg__SetPoint
    std::shared_ptr<custom_drone_interfaces::msg::SetPoint_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_drone_interfaces__msg__SetPoint
    std::shared_ptr<custom_drone_interfaces::msg::SetPoint_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetPoint_ & other) const
  {
    if (this->setpoint_data != other.setpoint_data) {
      return false;
    }
    if (this->frequency != other.frequency) {
      return false;
    }
    if (this->r_t_f != other.r_t_f) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetPoint_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetPoint_

// alias to use template instance with default allocator
using SetPoint =
  custom_drone_interfaces::msg::SetPoint_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_drone_interfaces

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__SET_POINT__STRUCT_HPP_
