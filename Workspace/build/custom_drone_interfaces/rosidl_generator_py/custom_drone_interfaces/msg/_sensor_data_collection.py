# generated from rosidl_generator_py/resource/_idl.py.em
# with input from custom_drone_interfaces:msg/SensorDataCollection.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

# Member 'q'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SensorDataCollection(type):
    """Metaclass of message 'SensorDataCollection'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('custom_drone_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'custom_drone_interfaces.msg.SensorDataCollection')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__sensor_data_collection
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__sensor_data_collection
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__sensor_data_collection
            cls._TYPE_SUPPORT = module.type_support_msg__msg__sensor_data_collection
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__sensor_data_collection

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SensorDataCollection(metaclass=Metaclass_SensorDataCollection):
    """Message class 'SensorDataCollection'."""

    __slots__ = [
        '_global_position_time',
        '_lat',
        '_lon',
        '_alt',
        '_alt_ellipsoid',
        '_terrain_alt',
        '_terrain_alt_valid',
        '_local_position_time',
        '_x',
        '_y',
        '_z',
        '_vx',
        '_vy',
        '_vz',
        '_ax',
        '_ay',
        '_az',
        '_heading',
        '_ref_lat',
        '_ref_lon',
        '_ref_alt',
        '_dist_bottom',
        '_dist_bottom_valid',
        '_attitude_quaternion_time',
        '_q',
    ]

    _fields_and_field_types = {
        'global_position_time': 'uint64',
        'lat': 'double',
        'lon': 'double',
        'alt': 'float',
        'alt_ellipsoid': 'float',
        'terrain_alt': 'float',
        'terrain_alt_valid': 'boolean',
        'local_position_time': 'uint64',
        'x': 'float',
        'y': 'float',
        'z': 'float',
        'vx': 'float',
        'vy': 'float',
        'vz': 'float',
        'ax': 'float',
        'ay': 'float',
        'az': 'float',
        'heading': 'float',
        'ref_lat': 'double',
        'ref_lon': 'double',
        'ref_alt': 'float',
        'dist_bottom': 'float',
        'dist_bottom_valid': 'boolean',
        'attitude_quaternion_time': 'uint64',
        'q': 'float[4]',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('float'), 4),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.global_position_time = kwargs.get('global_position_time', int())
        self.lat = kwargs.get('lat', float())
        self.lon = kwargs.get('lon', float())
        self.alt = kwargs.get('alt', float())
        self.alt_ellipsoid = kwargs.get('alt_ellipsoid', float())
        self.terrain_alt = kwargs.get('terrain_alt', float())
        self.terrain_alt_valid = kwargs.get('terrain_alt_valid', bool())
        self.local_position_time = kwargs.get('local_position_time', int())
        self.x = kwargs.get('x', float())
        self.y = kwargs.get('y', float())
        self.z = kwargs.get('z', float())
        self.vx = kwargs.get('vx', float())
        self.vy = kwargs.get('vy', float())
        self.vz = kwargs.get('vz', float())
        self.ax = kwargs.get('ax', float())
        self.ay = kwargs.get('ay', float())
        self.az = kwargs.get('az', float())
        self.heading = kwargs.get('heading', float())
        self.ref_lat = kwargs.get('ref_lat', float())
        self.ref_lon = kwargs.get('ref_lon', float())
        self.ref_alt = kwargs.get('ref_alt', float())
        self.dist_bottom = kwargs.get('dist_bottom', float())
        self.dist_bottom_valid = kwargs.get('dist_bottom_valid', bool())
        self.attitude_quaternion_time = kwargs.get('attitude_quaternion_time', int())
        if 'q' not in kwargs:
            self.q = numpy.zeros(4, dtype=numpy.float32)
        else:
            self.q = numpy.array(kwargs.get('q'), dtype=numpy.float32)
            assert self.q.shape == (4, )

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.global_position_time != other.global_position_time:
            return False
        if self.lat != other.lat:
            return False
        if self.lon != other.lon:
            return False
        if self.alt != other.alt:
            return False
        if self.alt_ellipsoid != other.alt_ellipsoid:
            return False
        if self.terrain_alt != other.terrain_alt:
            return False
        if self.terrain_alt_valid != other.terrain_alt_valid:
            return False
        if self.local_position_time != other.local_position_time:
            return False
        if self.x != other.x:
            return False
        if self.y != other.y:
            return False
        if self.z != other.z:
            return False
        if self.vx != other.vx:
            return False
        if self.vy != other.vy:
            return False
        if self.vz != other.vz:
            return False
        if self.ax != other.ax:
            return False
        if self.ay != other.ay:
            return False
        if self.az != other.az:
            return False
        if self.heading != other.heading:
            return False
        if self.ref_lat != other.ref_lat:
            return False
        if self.ref_lon != other.ref_lon:
            return False
        if self.ref_alt != other.ref_alt:
            return False
        if self.dist_bottom != other.dist_bottom:
            return False
        if self.dist_bottom_valid != other.dist_bottom_valid:
            return False
        if self.attitude_quaternion_time != other.attitude_quaternion_time:
            return False
        if all(self.q != other.q):
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def global_position_time(self):
        """Message field 'global_position_time'."""
        return self._global_position_time

    @global_position_time.setter
    def global_position_time(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'global_position_time' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'global_position_time' field must be an unsigned integer in [0, 18446744073709551615]"
        self._global_position_time = value

    @builtins.property
    def lat(self):
        """Message field 'lat'."""
        return self._lat

    @lat.setter
    def lat(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'lat' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'lat' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._lat = value

    @builtins.property
    def lon(self):
        """Message field 'lon'."""
        return self._lon

    @lon.setter
    def lon(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'lon' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'lon' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._lon = value

    @builtins.property
    def alt(self):
        """Message field 'alt'."""
        return self._alt

    @alt.setter
    def alt(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'alt' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'alt' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._alt = value

    @builtins.property
    def alt_ellipsoid(self):
        """Message field 'alt_ellipsoid'."""
        return self._alt_ellipsoid

    @alt_ellipsoid.setter
    def alt_ellipsoid(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'alt_ellipsoid' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'alt_ellipsoid' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._alt_ellipsoid = value

    @builtins.property
    def terrain_alt(self):
        """Message field 'terrain_alt'."""
        return self._terrain_alt

    @terrain_alt.setter
    def terrain_alt(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'terrain_alt' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'terrain_alt' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._terrain_alt = value

    @builtins.property
    def terrain_alt_valid(self):
        """Message field 'terrain_alt_valid'."""
        return self._terrain_alt_valid

    @terrain_alt_valid.setter
    def terrain_alt_valid(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'terrain_alt_valid' field must be of type 'bool'"
        self._terrain_alt_valid = value

    @builtins.property
    def local_position_time(self):
        """Message field 'local_position_time'."""
        return self._local_position_time

    @local_position_time.setter
    def local_position_time(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'local_position_time' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'local_position_time' field must be an unsigned integer in [0, 18446744073709551615]"
        self._local_position_time = value

    @builtins.property
    def x(self):
        """Message field 'x'."""
        return self._x

    @x.setter
    def x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._x = value

    @builtins.property
    def y(self):
        """Message field 'y'."""
        return self._y

    @y.setter
    def y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._y = value

    @builtins.property
    def z(self):
        """Message field 'z'."""
        return self._z

    @z.setter
    def z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'z' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'z' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._z = value

    @builtins.property
    def vx(self):
        """Message field 'vx'."""
        return self._vx

    @vx.setter
    def vx(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'vx' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'vx' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._vx = value

    @builtins.property
    def vy(self):
        """Message field 'vy'."""
        return self._vy

    @vy.setter
    def vy(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'vy' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'vy' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._vy = value

    @builtins.property
    def vz(self):
        """Message field 'vz'."""
        return self._vz

    @vz.setter
    def vz(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'vz' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'vz' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._vz = value

    @builtins.property
    def ax(self):
        """Message field 'ax'."""
        return self._ax

    @ax.setter
    def ax(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'ax' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'ax' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._ax = value

    @builtins.property
    def ay(self):
        """Message field 'ay'."""
        return self._ay

    @ay.setter
    def ay(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'ay' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'ay' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._ay = value

    @builtins.property
    def az(self):
        """Message field 'az'."""
        return self._az

    @az.setter
    def az(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'az' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'az' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._az = value

    @builtins.property
    def heading(self):
        """Message field 'heading'."""
        return self._heading

    @heading.setter
    def heading(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'heading' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'heading' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._heading = value

    @builtins.property
    def ref_lat(self):
        """Message field 'ref_lat'."""
        return self._ref_lat

    @ref_lat.setter
    def ref_lat(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'ref_lat' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'ref_lat' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._ref_lat = value

    @builtins.property
    def ref_lon(self):
        """Message field 'ref_lon'."""
        return self._ref_lon

    @ref_lon.setter
    def ref_lon(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'ref_lon' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'ref_lon' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._ref_lon = value

    @builtins.property
    def ref_alt(self):
        """Message field 'ref_alt'."""
        return self._ref_alt

    @ref_alt.setter
    def ref_alt(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'ref_alt' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'ref_alt' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._ref_alt = value

    @builtins.property
    def dist_bottom(self):
        """Message field 'dist_bottom'."""
        return self._dist_bottom

    @dist_bottom.setter
    def dist_bottom(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'dist_bottom' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'dist_bottom' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._dist_bottom = value

    @builtins.property
    def dist_bottom_valid(self):
        """Message field 'dist_bottom_valid'."""
        return self._dist_bottom_valid

    @dist_bottom_valid.setter
    def dist_bottom_valid(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'dist_bottom_valid' field must be of type 'bool'"
        self._dist_bottom_valid = value

    @builtins.property
    def attitude_quaternion_time(self):
        """Message field 'attitude_quaternion_time'."""
        return self._attitude_quaternion_time

    @attitude_quaternion_time.setter
    def attitude_quaternion_time(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'attitude_quaternion_time' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'attitude_quaternion_time' field must be an unsigned integer in [0, 18446744073709551615]"
        self._attitude_quaternion_time = value

    @builtins.property
    def q(self):
        """Message field 'q'."""
        return self._q

    @q.setter
    def q(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float32, \
                "The 'q' numpy.ndarray() must have the dtype of 'numpy.float32'"
            assert value.size == 4, \
                "The 'q' numpy.ndarray() must have a size of 4"
            self._q = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 4 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'q' field must be a set or sequence with length 4 and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._q = numpy.array(value, dtype=numpy.float32)
