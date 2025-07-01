// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_drone_interfaces:msg/MissionResult.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__MISSION_RESULT__STRUCT_HPP_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__MISSION_RESULT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_drone_interfaces__msg__MissionResult __attribute__((deprecated))
#else
# define DEPRECATED__custom_drone_interfaces__msg__MissionResult __declspec(deprecated)
#endif

namespace custom_drone_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MissionResult_
{
  using Type = MissionResult_<ContainerAllocator>;

  explicit MissionResult_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result_message = "";
    }
  }

  explicit MissionResult_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result_message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result_message = "";
    }
  }

  // field types and members
  using _result_message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _result_message_type result_message;

  // setters for named parameter idiom
  Type & set__result_message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->result_message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_drone_interfaces::msg::MissionResult_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_drone_interfaces::msg::MissionResult_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_drone_interfaces::msg::MissionResult_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_drone_interfaces::msg::MissionResult_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_drone_interfaces::msg::MissionResult_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_drone_interfaces::msg::MissionResult_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_drone_interfaces::msg::MissionResult_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_drone_interfaces::msg::MissionResult_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_drone_interfaces::msg::MissionResult_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_drone_interfaces::msg::MissionResult_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_drone_interfaces__msg__MissionResult
    std::shared_ptr<custom_drone_interfaces::msg::MissionResult_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_drone_interfaces__msg__MissionResult
    std::shared_ptr<custom_drone_interfaces::msg::MissionResult_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MissionResult_ & other) const
  {
    if (this->result_message != other.result_message) {
      return false;
    }
    return true;
  }
  bool operator!=(const MissionResult_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MissionResult_

// alias to use template instance with default allocator
using MissionResult =
  custom_drone_interfaces::msg::MissionResult_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_drone_interfaces

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__MISSION_RESULT__STRUCT_HPP_
