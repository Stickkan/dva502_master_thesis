from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration

def generate_launch_description():
    # Declare a launch argument named 'file_path'
    file_path_arg = DeclareLaunchArgument(
        'file_path',
        default_value='/home/lennie/tmp_ws/config_files/',  
        description='Path to the configuration files.'
    )

    # Use LaunchConfiguration to reference the 'file_path' argument
    file_path = LaunchConfiguration('file_path')

    # Define the nodes, passing the 'file_path' as a parameter to each node
    drone_communication = Node(
        package='drone_com',
        executable='drone2drone',
        output='screen',
        arguments=['--ros-args', '--log-level', 'INFO'],
        parameters=[{'file_path': file_path}]  # Pass the file_path as a parameter
    )
    rand_pub_data = Node(
        package='random_publishers',
        executable='agentData_pub',
        output='screen',
        arguments=['--ros-args', '--log-level', 'INFO'],
        parameters=[{'file_path': file_path}]  # Pass the file_path as a parameter
    )


    # Create a LaunchDescription and populate it with our nodes and launch argument
    LDnodes = LaunchDescription()

    # Add the file path argument
    LDnodes.add_action(file_path_arg)

    # Add the nodes to the LaunchDescription
    LDnodes.add_action(drone_communication)
    LDnodes.add_action(rand_pub_data)



    return LDnodes
