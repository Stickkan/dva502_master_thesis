// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_drone_interfaces:msg/ObjectProximityData.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__OBJECT_PROXIMITY_DATA__BUILDER_HPP_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__OBJECT_PROXIMITY_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_drone_interfaces/msg/detail/object_proximity_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_drone_interfaces
{

namespace msg
{

namespace builder
{

class Init_ObjectProximityData_time
{
public:
  explicit Init_ObjectProximityData_time(::custom_drone_interfaces::msg::ObjectProximityData & msg)
  : msg_(msg)
  {}
  ::custom_drone_interfaces::msg::ObjectProximityData time(::custom_drone_interfaces::msg::ObjectProximityData::_time_type arg)
  {
    msg_.time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_drone_interfaces::msg::ObjectProximityData msg_;
};

class Init_ObjectProximityData_alt
{
public:
  explicit Init_ObjectProximityData_alt(::custom_drone_interfaces::msg::ObjectProximityData & msg)
  : msg_(msg)
  {}
  Init_ObjectProximityData_time alt(::custom_drone_interfaces::msg::ObjectProximityData::_alt_type arg)
  {
    msg_.alt = std::move(arg);
    return Init_ObjectProximityData_time(msg_);
  }

private:
  ::custom_drone_interfaces::msg::ObjectProximityData msg_;
};

class Init_ObjectProximityData_lon
{
public:
  explicit Init_ObjectProximityData_lon(::custom_drone_interfaces::msg::ObjectProximityData & msg)
  : msg_(msg)
  {}
  Init_ObjectProximityData_alt lon(::custom_drone_interfaces::msg::ObjectProximityData::_lon_type arg)
  {
    msg_.lon = std::move(arg);
    return Init_ObjectProximityData_alt(msg_);
  }

private:
  ::custom_drone_interfaces::msg::ObjectProximityData msg_;
};

class Init_ObjectProximityData_lat
{
public:
  explicit Init_ObjectProximityData_lat(::custom_drone_interfaces::msg::ObjectProximityData & msg)
  : msg_(msg)
  {}
  Init_ObjectProximityData_lon lat(::custom_drone_interfaces::msg::ObjectProximityData::_lat_type arg)
  {
    msg_.lat = std::move(arg);
    return Init_ObjectProximityData_lon(msg_);
  }

private:
  ::custom_drone_interfaces::msg::ObjectProximityData msg_;
};

class Init_ObjectProximityData_vz
{
public:
  explicit Init_ObjectProximityData_vz(::custom_drone_interfaces::msg::ObjectProximityData & msg)
  : msg_(msg)
  {}
  Init_ObjectProximityData_lat vz(::custom_drone_interfaces::msg::ObjectProximityData::_vz_type arg)
  {
    msg_.vz = std::move(arg);
    return Init_ObjectProximityData_lat(msg_);
  }

private:
  ::custom_drone_interfaces::msg::ObjectProximityData msg_;
};

class Init_ObjectProximityData_vy
{
public:
  explicit Init_ObjectProximityData_vy(::custom_drone_interfaces::msg::ObjectProximityData & msg)
  : msg_(msg)
  {}
  Init_ObjectProximityData_vz vy(::custom_drone_interfaces::msg::ObjectProximityData::_vy_type arg)
  {
    msg_.vy = std::move(arg);
    return Init_ObjectProximityData_vz(msg_);
  }

private:
  ::custom_drone_interfaces::msg::ObjectProximityData msg_;
};

class Init_ObjectProximityData_vx
{
public:
  explicit Init_ObjectProximityData_vx(::custom_drone_interfaces::msg::ObjectProximityData & msg)
  : msg_(msg)
  {}
  Init_ObjectProximityData_vy vx(::custom_drone_interfaces::msg::ObjectProximityData::_vx_type arg)
  {
    msg_.vx = std::move(arg);
    return Init_ObjectProximityData_vy(msg_);
  }

private:
  ::custom_drone_interfaces::msg::ObjectProximityData msg_;
};

class Init_ObjectProximityData_priority
{
public:
  explicit Init_ObjectProximityData_priority(::custom_drone_interfaces::msg::ObjectProximityData & msg)
  : msg_(msg)
  {}
  Init_ObjectProximityData_vx priority(::custom_drone_interfaces::msg::ObjectProximityData::_priority_type arg)
  {
    msg_.priority = std::move(arg);
    return Init_ObjectProximityData_vx(msg_);
  }

private:
  ::custom_drone_interfaces::msg::ObjectProximityData msg_;
};

class Init_ObjectProximityData_agentid
{
public:
  Init_ObjectProximityData_agentid()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ObjectProximityData_priority agentid(::custom_drone_interfaces::msg::ObjectProximityData::_agentid_type arg)
  {
    msg_.agentid = std::move(arg);
    return Init_ObjectProximityData_priority(msg_);
  }

private:
  ::custom_drone_interfaces::msg::ObjectProximityData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_drone_interfaces::msg::ObjectProximityData>()
{
  return custom_drone_interfaces::msg::builder::Init_ObjectProximityData_agentid();
}

}  // namespace custom_drone_interfaces

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__OBJECT_PROXIMITY_DATA__BUILDER_HPP_
