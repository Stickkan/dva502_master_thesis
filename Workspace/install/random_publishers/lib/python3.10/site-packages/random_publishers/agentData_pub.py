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
from custom_drone_interfaces.msg import MissionCommand, SensorDataCollection, Waypoint, Path3D, AgentsList, SubWaypoint, AgentData
from geometry_msgs.msg import Point, Vector3
from custom_drone_interfaces.srv import ComputePath


class random_publishers(Node):

	def __init__(self):

		super().__init__('publish_random_data')
		
		qos_profile = QoSProfile(depth=10)

		# You can also change reliability and durability settings if needed
		qos_profile.reliability = rclpy.qos.ReliabilityPolicy.RELIABLE
		qos_profile.history = rclpy.qos.HistoryPolicy.KEEP_LAST

		self.rand_data_pub = self.create_publisher(AgentData, '/mc_1/agent_data', qos_profile)
		
		timer_period = 0.5  # seconds
		self.timer = self.create_timer(timer_period, self.timer_callback)

	def timer_callback(self):
		msg = AgentData()
		msg.agentid = 1111
		msg.priority = 56
		msg.vx = 10.0
		msg.vy = 10.0
		msg.vz = 10.0
		msg.lat = 10.0
		msg.lon = 10.0
		msg.alt = 10.0
		msg.time = 100
		self.rand_data_pub.publish(msg)
		self.get_logger().info('Publishing: "%s"' % msg)

def main(args=None):
	rclpy.init(args=args)
	print('Hi from drone_com.')
		
	rand_pub = random_publishers()

	# Use a multi-threaded executor to handle multiple callbacks concurrently
	executor = MultiThreadedExecutor(num_threads = 2)
	rclpy.spin(rand_pub, executor=executor)

	rand_pub.destroy_node()
	rclpy.shutdown()

if __name__ == '__main__':
    main()
