// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_drone_interfaces:msg/MissionCommand.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__MISSION_COMMAND__STRUCT_HPP_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__MISSION_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_drone_interfaces__msg__MissionCommand __attribute__((deprecated))
#else
# define DEPRECATED__custom_drone_interfaces__msg__MissionCommand __declspec(deprecated)
#endif

namespace custom_drone_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MissionCommand_
{
  using Type = MissionCommand_<ContainerAllocator>;

  explicit MissionCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command_flag = 0;
    }
  }

  explicit MissionCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command_flag = 0;
    }
  }

  // field types and members
  using _command_flag_type =
    uint16_t;
  _command_flag_type command_flag;

  // setters for named parameter idiom
  Type & set__command_flag(
    const uint16_t & _arg)
  {
    this->command_flag = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_drone_interfaces::msg::MissionCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_drone_interfaces::msg::MissionCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_drone_interfaces::msg::MissionCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_drone_interfaces::msg::MissionCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_drone_interfaces::msg::MissionCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_drone_interfaces::msg::MissionCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_drone_interfaces::msg::MissionCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_drone_interfaces::msg::MissionCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_drone_interfaces::msg::MissionCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_drone_interfaces::msg::MissionCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_drone_interfaces__msg__MissionCommand
    std::shared_ptr<custom_drone_interfaces::msg::MissionCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_drone_interfaces__msg__MissionCommand
    std::shared_ptr<custom_drone_interfaces::msg::MissionCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MissionCommand_ & other) const
  {
    if (this->command_flag != other.command_flag) {
      return false;
    }
    return true;
  }
  bool operator!=(const MissionCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MissionCommand_

// alias to use template instance with default allocator
using MissionCommand =
  custom_drone_interfaces::msg::MissionCommand_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_drone_interfaces

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__MISSION_COMMAND__STRUCT_HPP_
