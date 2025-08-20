# generated from rosidl_generator_py/resource/_idl.py.em
# with input from custom_drone_interfaces:msg/Waypoint.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'commandid'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Waypoint(type):
    """Metaclass of message 'Waypoint'."""

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
                'custom_drone_interfaces.msg.Waypoint')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__waypoint
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__waypoint
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__waypoint
            cls._TYPE_SUPPORT = module.type_support_msg__msg__waypoint
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__waypoint

            from custom_drone_interfaces.msg import SubWaypoint
            if SubWaypoint.__class__._TYPE_SUPPORT is None:
                SubWaypoint.__class__.__import_type_support__()

            from custom_drone_interfaces.msg import TaskSpecification
            if TaskSpecification.__class__._TYPE_SUPPORT is None:
                TaskSpecification.__class__.__import_type_support__()

            from geometry_msgs.msg import Point
            if Point.__class__._TYPE_SUPPORT is None:
                Point.__class__.__import_type_support__()

            from geometry_msgs.msg import Vector3
            if Vector3.__class__._TYPE_SUPPORT is None:
                Vector3.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Waypoint(metaclass=Metaclass_Waypoint):
    """Message class 'Waypoint'."""

    __slots__ = [
        '_point',
        '_velocity',
        '_subtrajectory',
        '_stop',
        '_heading',
        '_time_in_seconds',
        '_hold_time',
        '_acceptence_radius',
        '_task',
        '_commandid',
    ]

    _fields_and_field_types = {
        'point': 'geometry_msgs/Point',
        'velocity': 'geometry_msgs/Vector3',
        'subtrajectory': 'sequence<custom_drone_interfaces/SubWaypoint>',
        'stop': 'boolean',
        'heading': 'double',
        'time_in_seconds': 'double',
        'hold_time': 'double',
        'acceptence_radius': 'float',
        'task': 'custom_drone_interfaces/TaskSpecification',
        'commandid': 'sequence<int32>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['custom_drone_interfaces', 'msg'], 'SubWaypoint')),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['custom_drone_interfaces', 'msg'], 'TaskSpecification'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('int32')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from geometry_msgs.msg import Point
        self.point = kwargs.get('point', Point())
        from geometry_msgs.msg import Vector3
        self.velocity = kwargs.get('velocity', Vector3())
        self.subtrajectory = kwargs.get('subtrajectory', [])
        self.stop = kwargs.get('stop', bool())
        self.heading = kwargs.get('heading', float())
        self.time_in_seconds = kwargs.get('time_in_seconds', float())
        self.hold_time = kwargs.get('hold_time', float())
        self.acceptence_radius = kwargs.get('acceptence_radius', float())
        from custom_drone_interfaces.msg import TaskSpecification
        self.task = kwargs.get('task', TaskSpecification())
        self.commandid = array.array('i', kwargs.get('commandid', []))

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
        if self.point != other.point:
            return False
        if self.velocity != other.velocity:
            return False
        if self.subtrajectory != other.subtrajectory:
            return False
        if self.stop != other.stop:
            return False
        if self.heading != other.heading:
            return False
        if self.time_in_seconds != other.time_in_seconds:
            return False
        if self.hold_time != other.hold_time:
            return False
        if self.acceptence_radius != other.acceptence_radius:
            return False
        if self.task != other.task:
            return False
        if self.commandid != other.commandid:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def point(self):
        """Message field 'point'."""
        return self._point

    @point.setter
    def point(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            assert \
                isinstance(value, Point), \
                "The 'point' field must be a sub message of type 'Point'"
        self._point = value

    @builtins.property
    def velocity(self):
        """Message field 'velocity'."""
        return self._velocity

    @velocity.setter
    def velocity(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'velocity' field must be a sub message of type 'Vector3'"
        self._velocity = value

    @builtins.property
    def subtrajectory(self):
        """Message field 'subtrajectory'."""
        return self._subtrajectory

    @subtrajectory.setter
    def subtrajectory(self, value):
        if __debug__:
            from custom_drone_interfaces.msg import SubWaypoint
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
                 all(isinstance(v, SubWaypoint) for v in value) and
                 True), \
                "The 'subtrajectory' field must be a set or sequence and each value of type 'SubWaypoint'"
        self._subtrajectory = value

    @builtins.property
    def stop(self):
        """Message field 'stop'."""
        return self._stop

    @stop.setter
    def stop(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'stop' field must be of type 'bool'"
        self._stop = value

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
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'heading' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._heading = value

    @builtins.property
    def time_in_seconds(self):
        """Message field 'time_in_seconds'."""
        return self._time_in_seconds

    @time_in_seconds.setter
    def time_in_seconds(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'time_in_seconds' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'time_in_seconds' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._time_in_seconds = value

    @builtins.property
    def hold_time(self):
        """Message field 'hold_time'."""
        return self._hold_time

    @hold_time.setter
    def hold_time(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'hold_time' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'hold_time' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._hold_time = value

    @builtins.property
    def acceptence_radius(self):
        """Message field 'acceptence_radius'."""
        return self._acceptence_radius

    @acceptence_radius.setter
    def acceptence_radius(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'acceptence_radius' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'acceptence_radius' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._acceptence_radius = value

    @builtins.property
    def task(self):
        """Message field 'task'."""
        return self._task

    @task.setter
    def task(self, value):
        if __debug__:
            from custom_drone_interfaces.msg import TaskSpecification
            assert \
                isinstance(value, TaskSpecification), \
                "The 'task' field must be a sub message of type 'TaskSpecification'"
        self._task = value

    @builtins.property
    def commandid(self):
        """Message field 'commandid'."""
        return self._commandid

    @commandid.setter
    def commandid(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'i', \
                "The 'commandid' array.array() must have the type code of 'i'"
            self._commandid = value
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
                 all(isinstance(v, int) for v in value) and
                 all(val >= -2147483648 and val < 2147483648 for val in value)), \
                "The 'commandid' field must be a set or sequence and each value of type 'int' and each integer in [-2147483648, 2147483647]"
        self._commandid = array.array('i', value)
