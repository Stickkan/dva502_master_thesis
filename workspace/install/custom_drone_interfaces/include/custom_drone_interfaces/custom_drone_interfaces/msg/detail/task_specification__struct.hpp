// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_drone_interfaces:msg/TaskSpecification.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__TASK_SPECIFICATION__STRUCT_HPP_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__TASK_SPECIFICATION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_drone_interfaces__msg__TaskSpecification __attribute__((deprecated))
#else
# define DEPRECATED__custom_drone_interfaces__msg__TaskSpecification __declspec(deprecated)
#endif

namespace custom_drone_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TaskSpecification_
{
  using Type = TaskSpecification_<ContainerAllocator>;

  explicit TaskSpecification_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->flag = 0;
      std::fill<typename std::array<double, 5>::iterator, double>(this->settings.begin(), this->settings.end(), 0.0);
    }
  }

  explicit TaskSpecification_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : settings(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->flag = 0;
      std::fill<typename std::array<double, 5>::iterator, double>(this->settings.begin(), this->settings.end(), 0.0);
    }
  }

  // field types and members
  using _flag_type =
    int16_t;
  _flag_type flag;
  using _settings_type =
    std::array<double, 5>;
  _settings_type settings;

  // setters for named parameter idiom
  Type & set__flag(
    const int16_t & _arg)
  {
    this->flag = _arg;
    return *this;
  }
  Type & set__settings(
    const std::array<double, 5> & _arg)
  {
    this->settings = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_drone_interfaces::msg::TaskSpecification_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_drone_interfaces::msg::TaskSpecification_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_drone_interfaces::msg::TaskSpecification_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_drone_interfaces::msg::TaskSpecification_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_drone_interfaces::msg::TaskSpecification_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_drone_interfaces::msg::TaskSpecification_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_drone_interfaces::msg::TaskSpecification_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_drone_interfaces::msg::TaskSpecification_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_drone_interfaces::msg::TaskSpecification_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_drone_interfaces::msg::TaskSpecification_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_drone_interfaces__msg__TaskSpecification
    std::shared_ptr<custom_drone_interfaces::msg::TaskSpecification_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_drone_interfaces__msg__TaskSpecification
    std::shared_ptr<custom_drone_interfaces::msg::TaskSpecification_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TaskSpecification_ & other) const
  {
    if (this->flag != other.flag) {
      return false;
    }
    if (this->settings != other.settings) {
      return false;
    }
    return true;
  }
  bool operator!=(const TaskSpecification_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TaskSpecification_

// alias to use template instance with default allocator
using TaskSpecification =
  custom_drone_interfaces::msg::TaskSpecification_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_drone_interfaces

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__TASK_SPECIFICATION__STRUCT_HPP_
