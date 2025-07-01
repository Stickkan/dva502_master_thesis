// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_drone_interfaces:srv/ComputePath.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__SRV__DETAIL__COMPUTE_PATH__STRUCT_HPP_
#define CUSTOM_DRONE_INTERFACES__SRV__DETAIL__COMPUTE_PATH__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'input_path'
#include "custom_drone_interfaces/msg/detail/path3_d__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_drone_interfaces__srv__ComputePath_Request __attribute__((deprecated))
#else
# define DEPRECATED__custom_drone_interfaces__srv__ComputePath_Request __declspec(deprecated)
#endif

namespace custom_drone_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ComputePath_Request_
{
  using Type = ComputePath_Request_<ContainerAllocator>;

  explicit ComputePath_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : input_path(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 3>::iterator, double>(this->velocity_limit.begin(), this->velocity_limit.end(), 0.0);
      std::fill<typename std::array<double, 3>::iterator, double>(this->acceleration_limit.begin(), this->acceleration_limit.end(), 0.0);
      this->planning_method = "";
    }
  }

  explicit ComputePath_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : input_path(_alloc, _init),
    velocity_limit(_alloc),
    acceleration_limit(_alloc),
    planning_method(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 3>::iterator, double>(this->velocity_limit.begin(), this->velocity_limit.end(), 0.0);
      std::fill<typename std::array<double, 3>::iterator, double>(this->acceleration_limit.begin(), this->acceleration_limit.end(), 0.0);
      this->planning_method = "";
    }
  }

  // field types and members
  using _input_path_type =
    custom_drone_interfaces::msg::Path3D_<ContainerAllocator>;
  _input_path_type input_path;
  using _velocity_limit_type =
    std::array<double, 3>;
  _velocity_limit_type velocity_limit;
  using _acceleration_limit_type =
    std::array<double, 3>;
  _acceleration_limit_type acceleration_limit;
  using _planning_method_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _planning_method_type planning_method;

  // setters for named parameter idiom
  Type & set__input_path(
    const custom_drone_interfaces::msg::Path3D_<ContainerAllocator> & _arg)
  {
    this->input_path = _arg;
    return *this;
  }
  Type & set__velocity_limit(
    const std::array<double, 3> & _arg)
  {
    this->velocity_limit = _arg;
    return *this;
  }
  Type & set__acceleration_limit(
    const std::array<double, 3> & _arg)
  {
    this->acceleration_limit = _arg;
    return *this;
  }
  Type & set__planning_method(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->planning_method = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_drone_interfaces::srv::ComputePath_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_drone_interfaces::srv::ComputePath_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_drone_interfaces::srv::ComputePath_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_drone_interfaces::srv::ComputePath_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_drone_interfaces::srv::ComputePath_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_drone_interfaces::srv::ComputePath_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_drone_interfaces::srv::ComputePath_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_drone_interfaces::srv::ComputePath_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_drone_interfaces::srv::ComputePath_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_drone_interfaces::srv::ComputePath_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_drone_interfaces__srv__ComputePath_Request
    std::shared_ptr<custom_drone_interfaces::srv::ComputePath_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_drone_interfaces__srv__ComputePath_Request
    std::shared_ptr<custom_drone_interfaces::srv::ComputePath_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ComputePath_Request_ & other) const
  {
    if (this->input_path != other.input_path) {
      return false;
    }
    if (this->velocity_limit != other.velocity_limit) {
      return false;
    }
    if (this->acceleration_limit != other.acceleration_limit) {
      return false;
    }
    if (this->planning_method != other.planning_method) {
      return false;
    }
    return true;
  }
  bool operator!=(const ComputePath_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ComputePath_Request_

// alias to use template instance with default allocator
using ComputePath_Request =
  custom_drone_interfaces::srv::ComputePath_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace custom_drone_interfaces


// Include directives for member types
// Member 'planned_path'
// already included above
// #include "custom_drone_interfaces/msg/detail/path3_d__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_drone_interfaces__srv__ComputePath_Response __attribute__((deprecated))
#else
# define DEPRECATED__custom_drone_interfaces__srv__ComputePath_Response __declspec(deprecated)
#endif

namespace custom_drone_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ComputePath_Response_
{
  using Type = ComputePath_Response_<ContainerAllocator>;

  explicit ComputePath_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : planned_path(_init)
  {
    (void)_init;
  }

  explicit ComputePath_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : planned_path(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _planned_path_type =
    custom_drone_interfaces::msg::Path3D_<ContainerAllocator>;
  _planned_path_type planned_path;

  // setters for named parameter idiom
  Type & set__planned_path(
    const custom_drone_interfaces::msg::Path3D_<ContainerAllocator> & _arg)
  {
    this->planned_path = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_drone_interfaces::srv::ComputePath_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_drone_interfaces::srv::ComputePath_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_drone_interfaces::srv::ComputePath_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_drone_interfaces::srv::ComputePath_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_drone_interfaces::srv::ComputePath_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_drone_interfaces::srv::ComputePath_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_drone_interfaces::srv::ComputePath_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_drone_interfaces::srv::ComputePath_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_drone_interfaces::srv::ComputePath_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_drone_interfaces::srv::ComputePath_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_drone_interfaces__srv__ComputePath_Response
    std::shared_ptr<custom_drone_interfaces::srv::ComputePath_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_drone_interfaces__srv__ComputePath_Response
    std::shared_ptr<custom_drone_interfaces::srv::ComputePath_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ComputePath_Response_ & other) const
  {
    if (this->planned_path != other.planned_path) {
      return false;
    }
    return true;
  }
  bool operator!=(const ComputePath_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ComputePath_Response_

// alias to use template instance with default allocator
using ComputePath_Response =
  custom_drone_interfaces::srv::ComputePath_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace custom_drone_interfaces

namespace custom_drone_interfaces
{

namespace srv
{

struct ComputePath
{
  using Request = custom_drone_interfaces::srv::ComputePath_Request;
  using Response = custom_drone_interfaces::srv::ComputePath_Response;
};

}  // namespace srv

}  // namespace custom_drone_interfaces

#endif  // CUSTOM_DRONE_INTERFACES__SRV__DETAIL__COMPUTE_PATH__STRUCT_HPP_
