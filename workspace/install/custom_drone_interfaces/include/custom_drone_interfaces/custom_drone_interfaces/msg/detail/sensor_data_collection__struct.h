// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_drone_interfaces:msg/SensorDataCollection.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__SENSOR_DATA_COLLECTION__STRUCT_H_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__SENSOR_DATA_COLLECTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/SensorDataCollection in the package custom_drone_interfaces.
/**
  * FUSED GLOBAL POSITION
  *  This struct contains global position estimation. It is not the raw GPS measurement
 */
typedef struct custom_drone_interfaces__msg__SensorDataCollection
{
  /// time since system start (microseconds)
  uint64_t global_position_time;
  /// Latitude, (degrees)
  double lat;
  /// Longitude, (degrees)
  double lon;
  /// Altitude AMSL, (meters)
  float alt;
  /// Altitude above ellipsoid, (meters)
  float alt_ellipsoid;
  /// Terrain altitude WGS84, (metres)
  float terrain_alt;
  /// Terrain altitude estimate is valid
  bool terrain_alt_valid;
  /// FUSED LOCAL POSITION
  /// time since system start (microseconds)
  uint64_t local_position_time;
  /// Position in local NED frame (Should be calculated myself instead of relying on px4)
  /// North position in NED earth-fixed frame, (metres)
  float x;
  /// East position in NED earth-fixed frame, (metres)
  float y;
  /// Down position (negative altitude) in NED earth-fixed frame, (metres)
  float z;
  /// Velocity in NED frame
  /// North velocity in NED earth-fixed frame, (metres/sec)
  float vx;
  /// East velocity in NED earth-fixed frame, (metres/sec)
  float vy;
  /// Down velocity in NED earth-fixed frame, (metres/sec)
  float vz;
  /// Acceleration in NED frame
  /// North velocity derivative in NED earth-fixed frame, (metres/sec^2)
  float ax;
  /// East velocity derivative in NED earth-fixed frame, (metres/sec^2)
  float ay;
  /// Down velocity derivative in NED earth-fixed frame, (metres/sec^2)
  float az;
  /// Euler yaw angle transforming the tangent plane relative to NED earth-fixed frame, -PI..+PI,  (radians)
  float heading;
  /// Position of reference point (local NED frame origin) in global (GPS / WGS84) frame
  /// Reference point latitude, (degrees)
  double ref_lat;
  /// Reference point longitude, (degrees)
  double ref_lon;
  /// Reference altitude AMSL, (metres)
  float ref_alt;
  /// Distance to surface
  /// Distance from from bottom surface to ground, (metres)
  float dist_bottom;
  /// true if distance to bottom surface is valid
  bool dist_bottom_valid;
  /// ATTITUDE_QUATERNION
  /// time since system start (microseconds)
  uint64_t attitude_quaternion_time;
  /// Quaternion rotation from the FRD body frame to the NED earth frame
  float q[4];
} custom_drone_interfaces__msg__SensorDataCollection;

// Struct for a sequence of custom_drone_interfaces__msg__SensorDataCollection.
typedef struct custom_drone_interfaces__msg__SensorDataCollection__Sequence
{
  custom_drone_interfaces__msg__SensorDataCollection * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_drone_interfaces__msg__SensorDataCollection__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__SENSOR_DATA_COLLECTION__STRUCT_H_
