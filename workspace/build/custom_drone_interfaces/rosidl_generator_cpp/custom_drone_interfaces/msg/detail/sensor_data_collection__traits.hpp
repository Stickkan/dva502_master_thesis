// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_drone_interfaces:msg/SensorDataCollection.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__SENSOR_DATA_COLLECTION__TRAITS_HPP_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__SENSOR_DATA_COLLECTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_drone_interfaces/msg/detail/sensor_data_collection__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace custom_drone_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const SensorDataCollection & msg,
  std::ostream & out)
{
  out << "{";
  // member: global_position_time
  {
    out << "global_position_time: ";
    rosidl_generator_traits::value_to_yaml(msg.global_position_time, out);
    out << ", ";
  }

  // member: lat
  {
    out << "lat: ";
    rosidl_generator_traits::value_to_yaml(msg.lat, out);
    out << ", ";
  }

  // member: lon
  {
    out << "lon: ";
    rosidl_generator_traits::value_to_yaml(msg.lon, out);
    out << ", ";
  }

  // member: alt
  {
    out << "alt: ";
    rosidl_generator_traits::value_to_yaml(msg.alt, out);
    out << ", ";
  }

  // member: alt_ellipsoid
  {
    out << "alt_ellipsoid: ";
    rosidl_generator_traits::value_to_yaml(msg.alt_ellipsoid, out);
    out << ", ";
  }

  // member: terrain_alt
  {
    out << "terrain_alt: ";
    rosidl_generator_traits::value_to_yaml(msg.terrain_alt, out);
    out << ", ";
  }

  // member: terrain_alt_valid
  {
    out << "terrain_alt_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.terrain_alt_valid, out);
    out << ", ";
  }

  // member: local_position_time
  {
    out << "local_position_time: ";
    rosidl_generator_traits::value_to_yaml(msg.local_position_time, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << ", ";
  }

  // member: vx
  {
    out << "vx: ";
    rosidl_generator_traits::value_to_yaml(msg.vx, out);
    out << ", ";
  }

  // member: vy
  {
    out << "vy: ";
    rosidl_generator_traits::value_to_yaml(msg.vy, out);
    out << ", ";
  }

  // member: vz
  {
    out << "vz: ";
    rosidl_generator_traits::value_to_yaml(msg.vz, out);
    out << ", ";
  }

  // member: ax
  {
    out << "ax: ";
    rosidl_generator_traits::value_to_yaml(msg.ax, out);
    out << ", ";
  }

  // member: ay
  {
    out << "ay: ";
    rosidl_generator_traits::value_to_yaml(msg.ay, out);
    out << ", ";
  }

  // member: az
  {
    out << "az: ";
    rosidl_generator_traits::value_to_yaml(msg.az, out);
    out << ", ";
  }

  // member: heading
  {
    out << "heading: ";
    rosidl_generator_traits::value_to_yaml(msg.heading, out);
    out << ", ";
  }

  // member: ref_lat
  {
    out << "ref_lat: ";
    rosidl_generator_traits::value_to_yaml(msg.ref_lat, out);
    out << ", ";
  }

  // member: ref_lon
  {
    out << "ref_lon: ";
    rosidl_generator_traits::value_to_yaml(msg.ref_lon, out);
    out << ", ";
  }

  // member: ref_alt
  {
    out << "ref_alt: ";
    rosidl_generator_traits::value_to_yaml(msg.ref_alt, out);
    out << ", ";
  }

  // member: dist_bottom
  {
    out << "dist_bottom: ";
    rosidl_generator_traits::value_to_yaml(msg.dist_bottom, out);
    out << ", ";
  }

  // member: dist_bottom_valid
  {
    out << "dist_bottom_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.dist_bottom_valid, out);
    out << ", ";
  }

  // member: attitude_quaternion_time
  {
    out << "attitude_quaternion_time: ";
    rosidl_generator_traits::value_to_yaml(msg.attitude_quaternion_time, out);
    out << ", ";
  }

  // member: q
  {
    if (msg.q.size() == 0) {
      out << "q: []";
    } else {
      out << "q: [";
      size_t pending_items = msg.q.size();
      for (auto item : msg.q) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SensorDataCollection & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: global_position_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "global_position_time: ";
    rosidl_generator_traits::value_to_yaml(msg.global_position_time, out);
    out << "\n";
  }

  // member: lat
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lat: ";
    rosidl_generator_traits::value_to_yaml(msg.lat, out);
    out << "\n";
  }

  // member: lon
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lon: ";
    rosidl_generator_traits::value_to_yaml(msg.lon, out);
    out << "\n";
  }

  // member: alt
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "alt: ";
    rosidl_generator_traits::value_to_yaml(msg.alt, out);
    out << "\n";
  }

  // member: alt_ellipsoid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "alt_ellipsoid: ";
    rosidl_generator_traits::value_to_yaml(msg.alt_ellipsoid, out);
    out << "\n";
  }

  // member: terrain_alt
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "terrain_alt: ";
    rosidl_generator_traits::value_to_yaml(msg.terrain_alt, out);
    out << "\n";
  }

  // member: terrain_alt_valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "terrain_alt_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.terrain_alt_valid, out);
    out << "\n";
  }

  // member: local_position_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "local_position_time: ";
    rosidl_generator_traits::value_to_yaml(msg.local_position_time, out);
    out << "\n";
  }

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << "\n";
  }

  // member: vx
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vx: ";
    rosidl_generator_traits::value_to_yaml(msg.vx, out);
    out << "\n";
  }

  // member: vy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vy: ";
    rosidl_generator_traits::value_to_yaml(msg.vy, out);
    out << "\n";
  }

  // member: vz
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vz: ";
    rosidl_generator_traits::value_to_yaml(msg.vz, out);
    out << "\n";
  }

  // member: ax
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ax: ";
    rosidl_generator_traits::value_to_yaml(msg.ax, out);
    out << "\n";
  }

  // member: ay
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ay: ";
    rosidl_generator_traits::value_to_yaml(msg.ay, out);
    out << "\n";
  }

  // member: az
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "az: ";
    rosidl_generator_traits::value_to_yaml(msg.az, out);
    out << "\n";
  }

  // member: heading
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "heading: ";
    rosidl_generator_traits::value_to_yaml(msg.heading, out);
    out << "\n";
  }

  // member: ref_lat
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ref_lat: ";
    rosidl_generator_traits::value_to_yaml(msg.ref_lat, out);
    out << "\n";
  }

  // member: ref_lon
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ref_lon: ";
    rosidl_generator_traits::value_to_yaml(msg.ref_lon, out);
    out << "\n";
  }

  // member: ref_alt
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ref_alt: ";
    rosidl_generator_traits::value_to_yaml(msg.ref_alt, out);
    out << "\n";
  }

  // member: dist_bottom
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dist_bottom: ";
    rosidl_generator_traits::value_to_yaml(msg.dist_bottom, out);
    out << "\n";
  }

  // member: dist_bottom_valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dist_bottom_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.dist_bottom_valid, out);
    out << "\n";
  }

  // member: attitude_quaternion_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "attitude_quaternion_time: ";
    rosidl_generator_traits::value_to_yaml(msg.attitude_quaternion_time, out);
    out << "\n";
  }

  // member: q
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.q.size() == 0) {
      out << "q: []\n";
    } else {
      out << "q:\n";
      for (auto item : msg.q) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SensorDataCollection & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace custom_drone_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_drone_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_drone_interfaces::msg::SensorDataCollection & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_drone_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_drone_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const custom_drone_interfaces::msg::SensorDataCollection & msg)
{
  return custom_drone_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custom_drone_interfaces::msg::SensorDataCollection>()
{
  return "custom_drone_interfaces::msg::SensorDataCollection";
}

template<>
inline const char * name<custom_drone_interfaces::msg::SensorDataCollection>()
{
  return "custom_drone_interfaces/msg/SensorDataCollection";
}

template<>
struct has_fixed_size<custom_drone_interfaces::msg::SensorDataCollection>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<custom_drone_interfaces::msg::SensorDataCollection>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<custom_drone_interfaces::msg::SensorDataCollection>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__SENSOR_DATA_COLLECTION__TRAITS_HPP_
