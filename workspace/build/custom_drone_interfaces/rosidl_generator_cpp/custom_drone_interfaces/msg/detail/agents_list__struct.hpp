// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_drone_interfaces:msg/AgentsList.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__AGENTS_LIST__STRUCT_HPP_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__AGENTS_LIST__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'agents'
#include "custom_drone_interfaces/msg/detail/agent_data__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_drone_interfaces__msg__AgentsList __attribute__((deprecated))
#else
# define DEPRECATED__custom_drone_interfaces__msg__AgentsList __declspec(deprecated)
#endif

namespace custom_drone_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AgentsList_
{
  using Type = AgentsList_<ContainerAllocator>;

  explicit AgentsList_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit AgentsList_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _agents_type =
    std::vector<custom_drone_interfaces::msg::AgentData_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<custom_drone_interfaces::msg::AgentData_<ContainerAllocator>>>;
  _agents_type agents;

  // setters for named parameter idiom
  Type & set__agents(
    const std::vector<custom_drone_interfaces::msg::AgentData_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<custom_drone_interfaces::msg::AgentData_<ContainerAllocator>>> & _arg)
  {
    this->agents = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_drone_interfaces::msg::AgentsList_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_drone_interfaces::msg::AgentsList_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_drone_interfaces::msg::AgentsList_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_drone_interfaces::msg::AgentsList_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_drone_interfaces::msg::AgentsList_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_drone_interfaces::msg::AgentsList_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_drone_interfaces::msg::AgentsList_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_drone_interfaces::msg::AgentsList_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_drone_interfaces::msg::AgentsList_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_drone_interfaces::msg::AgentsList_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_drone_interfaces__msg__AgentsList
    std::shared_ptr<custom_drone_interfaces::msg::AgentsList_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_drone_interfaces__msg__AgentsList
    std::shared_ptr<custom_drone_interfaces::msg::AgentsList_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AgentsList_ & other) const
  {
    if (this->agents != other.agents) {
      return false;
    }
    return true;
  }
  bool operator!=(const AgentsList_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AgentsList_

// alias to use template instance with default allocator
using AgentsList =
  custom_drone_interfaces::msg::AgentsList_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_drone_interfaces

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__AGENTS_LIST__STRUCT_HPP_
