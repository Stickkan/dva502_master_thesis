#  GNU nano 6.2                                                                                       setup.py                                                                                                 
from setuptools import setup

package_name = 'drone_com'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='fredrik',
    maintainer_email='lennie.ce@gmail.com',
    description='Drone communication node',
    license='MIT',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'drone2drone = drone_com.drone2drone:main',
        ],
    },
)
