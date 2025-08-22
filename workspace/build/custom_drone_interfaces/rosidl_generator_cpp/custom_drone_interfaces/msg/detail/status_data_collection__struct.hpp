// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_drone_interfaces:msg/StatusDataCollection.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__STATUS_DATA_COLLECTION__STRUCT_HPP_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__STATUS_DATA_COLLECTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_drone_interfaces__msg__StatusDataCollection __attribute__((deprecated))
#else
# define DEPRECATED__custom_drone_interfaces__msg__StatusDataCollection __declspec(deprecated)
#endif

namespace custom_drone_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct StatusDataCollection_
{
  using Type = StatusDataCollection_<ContainerAllocator>;

  explicit StatusDataCollection_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->remaining = 0.0f;
      this->time_remaining_s = 0.0f;
      this->battery_warning = 0;
      this->battery_unhealthy = false;
      this->angular_velocity_invalid = false;
      this->attitude_invalid = false;
      this->global_position_invalid = false;
      this->wind_limit_exceeded = false;
      this->esc_arming_failure = false;
      this->imbalanced_prop = false;
      this->motor_failure = false;
    }
  }

  explicit StatusDataCollection_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->remaining = 0.0f;
      this->time_remaining_s = 0.0f;
      this->battery_warning = 0;
      this->battery_unhealthy = false;
      this->angular_velocity_invalid = false;
      this->attitude_invalid = false;
      this->global_position_invalid = false;
      this->wind_limit_exceeded = false;
      this->esc_arming_failure = false;
      this->imbalanced_prop = false;
      this->motor_failure = false;
    }
  }

  // field types and members
  using _remaining_type =
    float;
  _remaining_type remaining;
  using _time_remaining_s_type =
    float;
  _time_remaining_s_type time_remaining_s;
  using _battery_warning_type =
    uint8_t;
  _battery_warning_type battery_warning;
  using _battery_unhealthy_type =
    bool;
  _battery_unhealthy_type battery_unhealthy;
  using _angular_velocity_invalid_type =
    bool;
  _angular_velocity_invalid_type angular_velocity_invalid;
  using _attitude_invalid_type =
    bool;
  _attitude_invalid_type attitude_invalid;
  using _global_position_invalid_type =
    bool;
  _global_position_invalid_type global_position_invalid;
  using _wind_limit_exceeded_type =
    bool;
  _wind_limit_exceeded_type wind_limit_exceeded;
  using _esc_arming_failure_type =
    bool;
  _esc_arming_failure_type esc_arming_failure;
  using _imbalanced_prop_type =
    bool;
  _imbalanced_prop_type imbalanced_prop;
  using _motor_failure_type =
    bool;
  _motor_failure_type motor_failure;

  // setters for named parameter idiom
  Type & set__remaining(
    const float & _arg)
  {
    this->remaining = _arg;
    return *this;
  }
  Type & set__time_remaining_s(
    const float & _arg)
  {
    this->time_remaining_s = _arg;
    return *this;
  }
  Type & set__battery_warning(
    const uint8_t & _arg)
  {
    this->battery_warning = _arg;
    return *this;
  }
  Type & set__battery_unhealthy(
    const bool & _arg)
  {
    this->battery_unhealthy = _arg;
    return *this;
  }
  Type & set__angular_velocity_invalid(
    const bool & _arg)
  {
    this->angular_velocity_invalid = _arg;
    return *this;
  }
  Type & set__attitude_invalid(
    const bool & _arg)
  {
    this->attitude_invalid = _arg;
    return *this;
  }
  Type & set__global_position_invalid(
    const bool & _arg)
  {
    this->global_position_invalid = _arg;
    return *this;
  }
  Type & set__wind_limit_exceeded(
    const bool & _arg)
  {
    this->wind_limit_exceeded = _arg;
    return *this;
  }
  Type & set__esc_arming_failure(
    const bool & _arg)
  {
    this->esc_arming_failure = _arg;
    return *this;
  }
  Type & set__imbalanced_prop(
    const bool & _arg)
  {
    this->imbalanced_prop = _arg;
    return *this;
  }
  Type & set__motor_failure(
    const bool & _arg)
  {
    this->motor_failure = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_drone_interfaces::msg::StatusDataCollection_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_drone_interfaces::msg::StatusDataCollection_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_drone_interfaces::msg::StatusDataCollection_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_drone_interfaces::msg::StatusDataCollection_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_drone_interfaces::msg::StatusDataCollection_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_drone_interfaces::msg::StatusDataCollection_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_drone_interfaces::msg::StatusDataCollection_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_drone_interfaces::msg::StatusDataCollection_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_drone_interfaces::msg::StatusDataCollection_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_drone_interfaces::msg::StatusDataCollection_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_drone_interfaces__msg__StatusDataCollection
    std::shared_ptr<custom_drone_interfaces::msg::StatusDataCollection_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_drone_interfaces__msg__StatusDataCollection
    std::shared_ptr<custom_drone_interfaces::msg::StatusDataCollection_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StatusDataCollection_ & other) const
  {
    if (this->remaining != other.remaining) {
      return false;
    }
    if (this->time_remaining_s != other.time_remaining_s) {
      return false;
    }
    if (this->battery_warning != other.battery_warning) {
      return false;
    }
    if (this->battery_unhealthy != other.battery_unhealthy) {
      return false;
    }
    if (this->angular_velocity_invalid != other.angular_velocity_invalid) {
      return false;
    }
    if (this->attitude_invalid != other.attitude_invalid) {
      return false;
    }
    if (this->global_position_invalid != other.global_position_invalid) {
      return false;
    }
    if (this->wind_limit_exceeded != other.wind_limit_exceeded) {
      return false;
    }
    if (this->esc_arming_failure != other.esc_arming_failure) {
      return false;
    }
    if (this->imbalanced_prop != other.imbalanced_prop) {
      return false;
    }
    if (this->motor_failure != other.motor_failure) {
      return false;
    }
    return true;
  }
  bool operator!=(const StatusDataCollection_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StatusDataCollection_

// alias to use template instance with default allocator
using StatusDataCollection =
  custom_drone_interfaces::msg::StatusDataCollection_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_drone_interfaces

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__STATUS_DATA_COLLECTION__STRUCT_HPP_
