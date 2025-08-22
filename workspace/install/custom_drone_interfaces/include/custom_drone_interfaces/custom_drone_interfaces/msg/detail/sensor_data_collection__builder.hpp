// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_drone_interfaces:msg/SensorDataCollection.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__SENSOR_DATA_COLLECTION__BUILDER_HPP_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__SENSOR_DATA_COLLECTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_drone_interfaces/msg/detail/sensor_data_collection__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_drone_interfaces
{

namespace msg
{

namespace builder
{

class Init_SensorDataCollection_q
{
public:
  explicit Init_SensorDataCollection_q(::custom_drone_interfaces::msg::SensorDataCollection & msg)
  : msg_(msg)
  {}
  ::custom_drone_interfaces::msg::SensorDataCollection q(::custom_drone_interfaces::msg::SensorDataCollection::_q_type arg)
  {
    msg_.q = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_drone_interfaces::msg::SensorDataCollection msg_;
};

class Init_SensorDataCollection_attitude_quaternion_time
{
public:
  explicit Init_SensorDataCollection_attitude_quaternion_time(::custom_drone_interfaces::msg::SensorDataCollection & msg)
  : msg_(msg)
  {}
  Init_SensorDataCollection_q attitude_quaternion_time(::custom_drone_interfaces::msg::SensorDataCollection::_attitude_quaternion_time_type arg)
  {
    msg_.attitude_quaternion_time = std::move(arg);
    return Init_SensorDataCollection_q(msg_);
  }

private:
  ::custom_drone_interfaces::msg::SensorDataCollection msg_;
};

class Init_SensorDataCollection_dist_bottom_valid
{
public:
  explicit Init_SensorDataCollection_dist_bottom_valid(::custom_drone_interfaces::msg::SensorDataCollection & msg)
  : msg_(msg)
  {}
  Init_SensorDataCollection_attitude_quaternion_time dist_bottom_valid(::custom_drone_interfaces::msg::SensorDataCollection::_dist_bottom_valid_type arg)
  {
    msg_.dist_bottom_valid = std::move(arg);
    return Init_SensorDataCollection_attitude_quaternion_time(msg_);
  }

private:
  ::custom_drone_interfaces::msg::SensorDataCollection msg_;
};

class Init_SensorDataCollection_dist_bottom
{
public:
  explicit Init_SensorDataCollection_dist_bottom(::custom_drone_interfaces::msg::SensorDataCollection & msg)
  : msg_(msg)
  {}
  Init_SensorDataCollection_dist_bottom_valid dist_bottom(::custom_drone_interfaces::msg::SensorDataCollection::_dist_bottom_type arg)
  {
    msg_.dist_bottom = std::move(arg);
    return Init_SensorDataCollection_dist_bottom_valid(msg_);
  }

private:
  ::custom_drone_interfaces::msg::SensorDataCollection msg_;
};

class Init_SensorDataCollection_ref_alt
{
public:
  explicit Init_SensorDataCollection_ref_alt(::custom_drone_interfaces::msg::SensorDataCollection & msg)
  : msg_(msg)
  {}
  Init_SensorDataCollection_dist_bottom ref_alt(::custom_drone_interfaces::msg::SensorDataCollection::_ref_alt_type arg)
  {
    msg_.ref_alt = std::move(arg);
    return Init_SensorDataCollection_dist_bottom(msg_);
  }

private:
  ::custom_drone_interfaces::msg::SensorDataCollection msg_;
};

class Init_SensorDataCollection_ref_lon
{
public:
  explicit Init_SensorDataCollection_ref_lon(::custom_drone_interfaces::msg::SensorDataCollection & msg)
  : msg_(msg)
  {}
  Init_SensorDataCollection_ref_alt ref_lon(::custom_drone_interfaces::msg::SensorDataCollection::_ref_lon_type arg)
  {
    msg_.ref_lon = std::move(arg);
    return Init_SensorDataCollection_ref_alt(msg_);
  }

private:
  ::custom_drone_interfaces::msg::SensorDataCollection msg_;
};

class Init_SensorDataCollection_ref_lat
{
public:
  explicit Init_SensorDataCollection_ref_lat(::custom_drone_interfaces::msg::SensorDataCollection & msg)
  : msg_(msg)
  {}
  Init_SensorDataCollection_ref_lon ref_lat(::custom_drone_interfaces::msg::SensorDataCollection::_ref_lat_type arg)
  {
    msg_.ref_lat = std::move(arg);
    return Init_SensorDataCollection_ref_lon(msg_);
  }

private:
  ::custom_drone_interfaces::msg::SensorDataCollection msg_;
};

class Init_SensorDataCollection_heading
{
public:
  explicit Init_SensorDataCollection_heading(::custom_drone_interfaces::msg::SensorDataCollection & msg)
  : msg_(msg)
  {}
  Init_SensorDataCollection_ref_lat heading(::custom_drone_interfaces::msg::SensorDataCollection::_heading_type arg)
  {
    msg_.heading = std::move(arg);
    return Init_SensorDataCollection_ref_lat(msg_);
  }

private:
  ::custom_drone_interfaces::msg::SensorDataCollection msg_;
};

class Init_SensorDataCollection_az
{
public:
  explicit Init_SensorDataCollection_az(::custom_drone_interfaces::msg::SensorDataCollection & msg)
  : msg_(msg)
  {}
  Init_SensorDataCollection_heading az(::custom_drone_interfaces::msg::SensorDataCollection::_az_type arg)
  {
    msg_.az = std::move(arg);
    return Init_SensorDataCollection_heading(msg_);
  }

private:
  ::custom_drone_interfaces::msg::SensorDataCollection msg_;
};

class Init_SensorDataCollection_ay
{
public:
  explicit Init_SensorDataCollection_ay(::custom_drone_interfaces::msg::SensorDataCollection & msg)
  : msg_(msg)
  {}
  Init_SensorDataCollection_az ay(::custom_drone_interfaces::msg::SensorDataCollection::_ay_type arg)
  {
    msg_.ay = std::move(arg);
    return Init_SensorDataCollection_az(msg_);
  }

private:
  ::custom_drone_interfaces::msg::SensorDataCollection msg_;
};

class Init_SensorDataCollection_ax
{
public:
  explicit Init_SensorDataCollection_ax(::custom_drone_interfaces::msg::SensorDataCollection & msg)
  : msg_(msg)
  {}
  Init_SensorDataCollection_ay ax(::custom_drone_interfaces::msg::SensorDataCollection::_ax_type arg)
  {
    msg_.ax = std::move(arg);
    return Init_SensorDataCollection_ay(msg_);
  }

private:
  ::custom_drone_interfaces::msg::SensorDataCollection msg_;
};

class Init_SensorDataCollection_vz
{
public:
  explicit Init_SensorDataCollection_vz(::custom_drone_interfaces::msg::SensorDataCollection & msg)
  : msg_(msg)
  {}
  Init_SensorDataCollection_ax vz(::custom_drone_interfaces::msg::SensorDataCollection::_vz_type arg)
  {
    msg_.vz = std::move(arg);
    return Init_SensorDataCollection_ax(msg_);
  }

private:
  ::custom_drone_interfaces::msg::SensorDataCollection msg_;
};

class Init_SensorDataCollection_vy
{
public:
  explicit Init_SensorDataCollection_vy(::custom_drone_interfaces::msg::SensorDataCollection & msg)
  : msg_(msg)
  {}
  Init_SensorDataCollection_vz vy(::custom_drone_interfaces::msg::SensorDataCollection::_vy_type arg)
  {
    msg_.vy = std::move(arg);
    return Init_SensorDataCollection_vz(msg_);
  }

private:
  ::custom_drone_interfaces::msg::SensorDataCollection msg_;
};

class Init_SensorDataCollection_vx
{
public:
  explicit Init_SensorDataCollection_vx(::custom_drone_interfaces::msg::SensorDataCollection & msg)
  : msg_(msg)
  {}
  Init_SensorDataCollection_vy vx(::custom_drone_interfaces::msg::SensorDataCollection::_vx_type arg)
  {
    msg_.vx = std::move(arg);
    return Init_SensorDataCollection_vy(msg_);
  }

private:
  ::custom_drone_interfaces::msg::SensorDataCollection msg_;
};

class Init_SensorDataCollection_z
{
public:
  explicit Init_SensorDataCollection_z(::custom_drone_interfaces::msg::SensorDataCollection & msg)
  : msg_(msg)
  {}
  Init_SensorDataCollection_vx z(::custom_drone_interfaces::msg::SensorDataCollection::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_SensorDataCollection_vx(msg_);
  }

private:
  ::custom_drone_interfaces::msg::SensorDataCollection msg_;
};

class Init_SensorDataCollection_y
{
public:
  explicit Init_SensorDataCollection_y(::custom_drone_interfaces::msg::SensorDataCollection & msg)
  : msg_(msg)
  {}
  Init_SensorDataCollection_z y(::custom_drone_interfaces::msg::SensorDataCollection::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_SensorDataCollection_z(msg_);
  }

private:
  ::custom_drone_interfaces::msg::SensorDataCollection msg_;
};

class Init_SensorDataCollection_x
{
public:
  explicit Init_SensorDataCollection_x(::custom_drone_interfaces::msg::SensorDataCollection & msg)
  : msg_(msg)
  {}
  Init_SensorDataCollection_y x(::custom_drone_interfaces::msg::SensorDataCollection::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_SensorDataCollection_y(msg_);
  }

private:
  ::custom_drone_interfaces::msg::SensorDataCollection msg_;
};

class Init_SensorDataCollection_local_position_time
{
public:
  explicit Init_SensorDataCollection_local_position_time(::custom_drone_interfaces::msg::SensorDataCollection & msg)
  : msg_(msg)
  {}
  Init_SensorDataCollection_x local_position_time(::custom_drone_interfaces::msg::SensorDataCollection::_local_position_time_type arg)
  {
    msg_.local_position_time = std::move(arg);
    return Init_SensorDataCollection_x(msg_);
  }

private:
  ::custom_drone_interfaces::msg::SensorDataCollection msg_;
};

class Init_SensorDataCollection_terrain_alt_valid
{
public:
  explicit Init_SensorDataCollection_terrain_alt_valid(::custom_drone_interfaces::msg::SensorDataCollection & msg)
  : msg_(msg)
  {}
  Init_SensorDataCollection_local_position_time terrain_alt_valid(::custom_drone_interfaces::msg::SensorDataCollection::_terrain_alt_valid_type arg)
  {
    msg_.terrain_alt_valid = std::move(arg);
    return Init_SensorDataCollection_local_position_time(msg_);
  }

private:
  ::custom_drone_interfaces::msg::SensorDataCollection msg_;
};

class Init_SensorDataCollection_terrain_alt
{
public:
  explicit Init_SensorDataCollection_terrain_alt(::custom_drone_interfaces::msg::SensorDataCollection & msg)
  : msg_(msg)
  {}
  Init_SensorDataCollection_terrain_alt_valid terrain_alt(::custom_drone_interfaces::msg::SensorDataCollection::_terrain_alt_type arg)
  {
    msg_.terrain_alt = std::move(arg);
    return Init_SensorDataCollection_terrain_alt_valid(msg_);
  }

private:
  ::custom_drone_interfaces::msg::SensorDataCollection msg_;
};

class Init_SensorDataCollection_alt_ellipsoid
{
public:
  explicit Init_SensorDataCollection_alt_ellipsoid(::custom_drone_interfaces::msg::SensorDataCollection & msg)
  : msg_(msg)
  {}
  Init_SensorDataCollection_terrain_alt alt_ellipsoid(::custom_drone_interfaces::msg::SensorDataCollection::_alt_ellipsoid_type arg)
  {
    msg_.alt_ellipsoid = std::move(arg);
    return Init_SensorDataCollection_terrain_alt(msg_);
  }

private:
  ::custom_drone_interfaces::msg::SensorDataCollection msg_;
};

class Init_SensorDataCollection_alt
{
public:
  explicit Init_SensorDataCollection_alt(::custom_drone_interfaces::msg::SensorDataCollection & msg)
  : msg_(msg)
  {}
  Init_SensorDataCollection_alt_ellipsoid alt(::custom_drone_interfaces::msg::SensorDataCollection::_alt_type arg)
  {
    msg_.alt = std::move(arg);
    return Init_SensorDataCollection_alt_ellipsoid(msg_);
  }

private:
  ::custom_drone_interfaces::msg::SensorDataCollection msg_;
};

class Init_SensorDataCollection_lon
{
public:
  explicit Init_SensorDataCollection_lon(::custom_drone_interfaces::msg::SensorDataCollection & msg)
  : msg_(msg)
  {}
  Init_SensorDataCollection_alt lon(::custom_drone_interfaces::msg::SensorDataCollection::_lon_type arg)
  {
    msg_.lon = std::move(arg);
    return Init_SensorDataCollection_alt(msg_);
  }

private:
  ::custom_drone_interfaces::msg::SensorDataCollection msg_;
};

class Init_SensorDataCollection_lat
{
public:
  explicit Init_SensorDataCollection_lat(::custom_drone_interfaces::msg::SensorDataCollection & msg)
  : msg_(msg)
  {}
  Init_SensorDataCollection_lon lat(::custom_drone_interfaces::msg::SensorDataCollection::_lat_type arg)
  {
    msg_.lat = std::move(arg);
    return Init_SensorDataCollection_lon(msg_);
  }

private:
  ::custom_drone_interfaces::msg::SensorDataCollection msg_;
};

class Init_SensorDataCollection_global_position_time
{
public:
  Init_SensorDataCollection_global_position_time()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SensorDataCollection_lat global_position_time(::custom_drone_interfaces::msg::SensorDataCollection::_global_position_time_type arg)
  {
    msg_.global_position_time = std::move(arg);
    return Init_SensorDataCollection_lat(msg_);
  }

private:
  ::custom_drone_interfaces::msg::SensorDataCollection msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_drone_interfaces::msg::SensorDataCollection>()
{
  return custom_drone_interfaces::msg::builder::Init_SensorDataCollection_global_position_time();
}

}  // namespace custom_drone_interfaces

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__SENSOR_DATA_COLLECTION__BUILDER_HPP_
