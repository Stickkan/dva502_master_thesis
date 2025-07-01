// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from custom_drone_interfaces:msg/SensorDataCollection.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "custom_drone_interfaces/msg/detail/sensor_data_collection__struct.h"
#include "custom_drone_interfaces/msg/detail/sensor_data_collection__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool custom_drone_interfaces__msg__sensor_data_collection__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[73];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("custom_drone_interfaces.msg._sensor_data_collection.SensorDataCollection", full_classname_dest, 72) == 0);
  }
  custom_drone_interfaces__msg__SensorDataCollection * ros_message = _ros_message;
  {  // global_position_time
    PyObject * field = PyObject_GetAttrString(_pymsg, "global_position_time");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->global_position_time = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // lat
    PyObject * field = PyObject_GetAttrString(_pymsg, "lat");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->lat = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // lon
    PyObject * field = PyObject_GetAttrString(_pymsg, "lon");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->lon = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // alt
    PyObject * field = PyObject_GetAttrString(_pymsg, "alt");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->alt = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // alt_ellipsoid
    PyObject * field = PyObject_GetAttrString(_pymsg, "alt_ellipsoid");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->alt_ellipsoid = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // terrain_alt
    PyObject * field = PyObject_GetAttrString(_pymsg, "terrain_alt");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->terrain_alt = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // terrain_alt_valid
    PyObject * field = PyObject_GetAttrString(_pymsg, "terrain_alt_valid");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->terrain_alt_valid = (Py_True == field);
    Py_DECREF(field);
  }
  {  // local_position_time
    PyObject * field = PyObject_GetAttrString(_pymsg, "local_position_time");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->local_position_time = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // x
    PyObject * field = PyObject_GetAttrString(_pymsg, "x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // y
    PyObject * field = PyObject_GetAttrString(_pymsg, "y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // z
    PyObject * field = PyObject_GetAttrString(_pymsg, "z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->z = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // vx
    PyObject * field = PyObject_GetAttrString(_pymsg, "vx");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->vx = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // vy
    PyObject * field = PyObject_GetAttrString(_pymsg, "vy");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->vy = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // vz
    PyObject * field = PyObject_GetAttrString(_pymsg, "vz");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->vz = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // ax
    PyObject * field = PyObject_GetAttrString(_pymsg, "ax");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->ax = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // ay
    PyObject * field = PyObject_GetAttrString(_pymsg, "ay");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->ay = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // az
    PyObject * field = PyObject_GetAttrString(_pymsg, "az");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->az = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // heading
    PyObject * field = PyObject_GetAttrString(_pymsg, "heading");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->heading = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // ref_lat
    PyObject * field = PyObject_GetAttrString(_pymsg, "ref_lat");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->ref_lat = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // ref_lon
    PyObject * field = PyObject_GetAttrString(_pymsg, "ref_lon");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->ref_lon = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // ref_alt
    PyObject * field = PyObject_GetAttrString(_pymsg, "ref_alt");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->ref_alt = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // dist_bottom
    PyObject * field = PyObject_GetAttrString(_pymsg, "dist_bottom");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->dist_bottom = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // dist_bottom_valid
    PyObject * field = PyObject_GetAttrString(_pymsg, "dist_bottom_valid");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->dist_bottom_valid = (Py_True == field);
    Py_DECREF(field);
  }
  {  // attitude_quaternion_time
    PyObject * field = PyObject_GetAttrString(_pymsg, "attitude_quaternion_time");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->attitude_quaternion_time = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // q
    PyObject * field = PyObject_GetAttrString(_pymsg, "q");
    if (!field) {
      return false;
    }
    {
      // TODO(dirk-thomas) use a better way to check the type before casting
      assert(field->ob_type != NULL);
      assert(field->ob_type->tp_name != NULL);
      assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
      PyArrayObject * seq_field = (PyArrayObject *)field;
      Py_INCREF(seq_field);
      assert(PyArray_NDIM(seq_field) == 1);
      assert(PyArray_TYPE(seq_field) == NPY_FLOAT32);
      Py_ssize_t size = 4;
      float * dest = ros_message->q;
      for (Py_ssize_t i = 0; i < size; ++i) {
        float tmp = *(npy_float32 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(float));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * custom_drone_interfaces__msg__sensor_data_collection__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of SensorDataCollection */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("custom_drone_interfaces.msg._sensor_data_collection");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "SensorDataCollection");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  custom_drone_interfaces__msg__SensorDataCollection * ros_message = (custom_drone_interfaces__msg__SensorDataCollection *)raw_ros_message;
  {  // global_position_time
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->global_position_time);
    {
      int rc = PyObject_SetAttrString(_pymessage, "global_position_time", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // lat
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->lat);
    {
      int rc = PyObject_SetAttrString(_pymessage, "lat", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // lon
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->lon);
    {
      int rc = PyObject_SetAttrString(_pymessage, "lon", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // alt
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->alt);
    {
      int rc = PyObject_SetAttrString(_pymessage, "alt", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // alt_ellipsoid
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->alt_ellipsoid);
    {
      int rc = PyObject_SetAttrString(_pymessage, "alt_ellipsoid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // terrain_alt
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->terrain_alt);
    {
      int rc = PyObject_SetAttrString(_pymessage, "terrain_alt", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // terrain_alt_valid
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->terrain_alt_valid ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "terrain_alt_valid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // local_position_time
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->local_position_time);
    {
      int rc = PyObject_SetAttrString(_pymessage, "local_position_time", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vx
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->vx);
    {
      int rc = PyObject_SetAttrString(_pymessage, "vx", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vy
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->vy);
    {
      int rc = PyObject_SetAttrString(_pymessage, "vy", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vz
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->vz);
    {
      int rc = PyObject_SetAttrString(_pymessage, "vz", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ax
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->ax);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ax", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ay
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->ay);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ay", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // az
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->az);
    {
      int rc = PyObject_SetAttrString(_pymessage, "az", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // heading
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->heading);
    {
      int rc = PyObject_SetAttrString(_pymessage, "heading", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ref_lat
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->ref_lat);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ref_lat", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ref_lon
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->ref_lon);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ref_lon", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ref_alt
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->ref_alt);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ref_alt", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // dist_bottom
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->dist_bottom);
    {
      int rc = PyObject_SetAttrString(_pymessage, "dist_bottom", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // dist_bottom_valid
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->dist_bottom_valid ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "dist_bottom_valid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // attitude_quaternion_time
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->attitude_quaternion_time);
    {
      int rc = PyObject_SetAttrString(_pymessage, "attitude_quaternion_time", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // q
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "q");
    if (!field) {
      return NULL;
    }
    assert(field->ob_type != NULL);
    assert(field->ob_type->tp_name != NULL);
    assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
    PyArrayObject * seq_field = (PyArrayObject *)field;
    assert(PyArray_NDIM(seq_field) == 1);
    assert(PyArray_TYPE(seq_field) == NPY_FLOAT32);
    assert(sizeof(npy_float32) == sizeof(float));
    npy_float32 * dst = (npy_float32 *)PyArray_GETPTR1(seq_field, 0);
    float * src = &(ros_message->q[0]);
    memcpy(dst, src, 4 * sizeof(float));
    Py_DECREF(field);
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
