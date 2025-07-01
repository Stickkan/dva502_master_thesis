import threading
import time
import json
import numpy as np
import casadi as ca
import rclpy
from rclpy.clock import Clock
from scipy.optimize import fsolve
import math
import argparse
import asyncio
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy, DurabilityPolicy
from rclpy.qos import QoSReliabilityPolicy, QoSHistoryPolicy
from rclpy.callback_groups import ReentrantCallbackGroup, MutuallyExclusiveCallbackGroup
from rclpy.executors import MultiThreadedExecutor, SingleThreadedExecutor
from std_msgs.msg import String
from std_srvs.srv import Empty
from custom_drone_interfaces.msg import MissionCommand, SensorDataCollection, Waypoint, Path3D, AgentsList, SubWaypoint
from geometry_msgs.msg import Point, Vector3
from custom_drone_interfaces.srv import ComputePath


class droneCommunication(Node):

	def __init__(self):

		super().__init__('drone_communication')

		self.group = ReentrantCallbackGroup()
		self.sensor_data_subscriber = self.create_subscription(SensorDataCollection, '/mc_1/sensor_data', self.listener_vehicle_sensors, QoSProfile(depth=10, reliability=ReliabilityPolicy.BEST_EFFORT), callback_group=self.group)
	
	def listener_vehicle_sensors(self, msg):
		try:
			self.get_logger().info(msg)
		except Exception as e:
			self.get_logger().info(f'Error in listener_vehicle_sensors: {e}')


def main(args=None):
	rclpy.init(args=args)
	print('Hi from drone_com.')
		
	drone_Communication = droneCommunication()

	# Use a multi-threaded executor to handle multiple callbacks concurrently
	executor = MultiThreadedExecutor(num_threads = 2)
	rclpy.spin(drone_Communication, executor=executor)

	drone_Communication.destroy_node()
	rclpy.shutdown()

if __name__ == '__main__':
    main()
