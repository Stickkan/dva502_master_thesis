# launch/adhoc_launch.py

from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
import yaml
import os
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    
    # You can create a config file for trusted IDs, e.g., 'config/trusted_ids.yaml'
    # For this example, we pass them directly as parameters.
    # Example YAML content:
    # adhoc_node:
    #   ros__parameters:
    #     trusted_drone_ids: ['drone_2', 'drone_3', 'drone_4']
    
    # --- Drone 1 ---
    node_1 = Node(
        package='adhoc_comms',
        executable='adhoc_node',
        name='adhoc_node_1',
        namespace='drone_1',
        output='screen',
        emulate_tty=True,
        parameters=[
            {'drone_id': 'drone_1'},
            {'trusted_drone_ids': ['drone_2', 'drone_3']}
        ]
    )

    # --- Drone 2 ---
    node_2 = Node(
        package='adhoc_comms',
        executable='adhoc_node',
        name='adhoc_node_2',
        namespace='drone_2',
        output='screen',
        emulate_tty=True,
        parameters=[
            {'drone_id': 'drone_2'},
            {'trusted_drone_ids': ['drone_1', 'drone_3']}
        ]
    )
    
    # --- Drone 3 ---
    node_3 = Node(
        package='adhoc_comms',
        executable='adhoc_node',
        name='adhoc_node_3',
        namespace='drone_3',
        output='screen',
        emulate_tty=True,
        parameters=[
            {'drone_id': 'drone_3'},
            {'trusted_drone_ids': ['drone_1', 'drone_2']}
        ]
    )

    return LaunchDescription([
        # To run a single drone:
        node_1
        
        # To simulate a swarm, uncomment the other nodes.
        # You would run each on a separate machine (or terminal for simulation).
        # node_2,
        # node_3,
    ])

