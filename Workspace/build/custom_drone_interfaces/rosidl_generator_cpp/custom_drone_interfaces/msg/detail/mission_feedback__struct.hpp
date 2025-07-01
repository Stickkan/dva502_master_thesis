// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_drone_interfaces:msg/MissionFeedback.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__MISSION_FEEDBACK__STRUCT_HPP_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__MISSION_FEEDBACK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_drone_interfaces__msg__MissionFeedback __attribute__((deprecated))
#else
# define DEPRECATED__custom_drone_interfaces__msg__MissionFeedback __declspec(deprecated)
#endif

namespace custom_drone_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MissionFeedback_
{
  using Type = MissionFeedback_<ContainerAllocator>;

  explicit MissionFeedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->feedback_message = "";
    }
  }

  explicit MissionFeedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : feedback_message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->feedback_message = "";
    }
  }

  // field types and members
  using _feedback_message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _feedback_message_type feedback_message;

  // setters for named parameter idiom
  Type & set__feedback_message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->feedback_message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_drone_interfaces::msg::MissionFeedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_drone_interfaces::msg::MissionFeedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_drone_interfaces::msg::MissionFeedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_drone_interfaces::msg::MissionFeedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_drone_interfaces::msg::MissionFeedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_drone_interfaces::msg::MissionFeedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_drone_interfaces::msg::MissionFeedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_drone_interfaces::msg::MissionFeedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_drone_interfaces::msg::MissionFeedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_drone_interfaces::msg::MissionFeedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_drone_interfaces__msg__MissionFeedback
    std::shared_ptr<custom_drone_interfaces::msg::MissionFeedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_drone_interfaces__msg__MissionFeedback
    std::shared_ptr<custom_drone_interfaces::msg::MissionFeedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MissionFeedback_ & other) const
  {
    if (this->feedback_message != other.feedback_message) {
      return false;
    }
    return true;
  }
  bool operator!=(const MissionFeedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MissionFeedback_

// alias to use template instance with default allocator
using MissionFeedback =
  custom_drone_interfaces::msg::MissionFeedback_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_drone_interfaces

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__MISSION_FEEDBACK__STRUCT_HPP_
