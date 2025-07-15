# The message format:
"""    
    message = {
            "drone_id": self.drone_id,
            "package_number": self.package_number,
            "checksum": 0, # Placeholder for checksum logic
            "position": {"x": self.position.x, "y": self.position.y, "z": self.position.z},
            "velocity": {"x": self.velocity.x, "y": self.velocity.y, "z": self.velocity.z},
            "energy_level": self.energy_level,
            "connected_drones": self.connection_manager.get_connected_peers(),
            "protocol": "STATUS_BROADCAST",
            "interface": "WIFI_5GHZ" # Simulated
    }
"""

"""
    Create a dict which utilizes the package number as the key and the rest (- package number) as the value
    I think that a duplicate of the sent message should be saved in a dictionary. Once a message is received that should be save in another dict
    
"""

from datetime import timedelta
import math

def haversine(position_drone_1, position_drone_2):
        """
            Based on gps points i.e. longitude and latitude the haversine function can be utilized to figure out the distance between the nodes.
        """
        R = 6371  # Earth radius in kilometers

        lat1, lon1 = position_drone_1
        lat2, lon2 = position_drone_2

        # Convert degrees to radians
        lat1 = math.radians(lat1)
        lon1 = math.radians(lon1)
        lat2 = math.radians(lat2)
        lon2 = math.radians(lon2)

        # Differences
        delta_lat = lat2 - lat1
        delta_lon = lon2 - lon1

        # Haversine
        a = math.sin(delta_lat / 2)**2 + math.cos(lat1) * math.cos(lat2) * math.sin(delta_lon / 2)**2
        c = 2 * math.atan2(math.sqrt(a), math.sqrt(1 - a))
        distance = R * c

        return distance

class Message:
    def __init__(self, drone_id, package_number, checksum, position, velocity, energy_level, connected_drones):
        self.drone_id = drone_id
        self.package_number = package_number
        self.checksum = checksum
        self.pos = position
        self.vel = velocity
        self.energy_level = energy_level
        self.connected_drones = connected_drones

    def duration_transmission(self, time_sent, time_received):
        """
            Needs to have the timestamp from the when the package is sent and when the package is received.
        """
        duration = timedelta(time_received - time_sent)
        return duration

    def delta_energy(self, energy_level_when_sent, energy_level_when_received):
        """
            What is the unit of the energy level
        """

    
if __name__== '__main__':
    """
        Declare a dictionary and at the same time a message is sent the message should be saved in the dictionary where the key is the package number
        and the value is the rest of the "message"

        This should be the instance 
    """