import socket
import threading
import json
import time

class Discovery:
    """
    Handles the discovery of other drones on the network via UDP broadcast.
    """
    def __init__(self, drone_id, discovery_port=19999):
        self._drone_id = drone_id
        self._port = discovery_port
        self._broadcast_ip = '255.255.255.255'
        self.on_peer_discovered = None

        self._running = threading.Event()
        self._running.set()

        self._broadcast_thread = threading.Thread(target=self._broadcast_presence, daemon=True)
        self._listen_thread = threading.Thread(target=self._listen_for_peers, daemon=True)

    def start(self):
        print(f"[INFO] Starting discovery on port {self._port}...")
        self._broadcast_thread.start()
        self._listen_thread.start()

    def stop(self):
        print("[INFO] Stopping discovery...")
        self._running.clear()
        self._broadcast_thread.join()
        self._listen_thread.join()
        print("[INFO] Discovery stopped.")

    def _broadcast_presence(self):
        sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)

        hostname = socket.gethostname()
        ip_address = socket.gethostbyname(hostname)

        message = {
            "id": self._drone_id,
            "ip": ip_address
        }

        while self._running.is_set():
            try:
                sock.sendto(json.dumps(message).encode('utf-8'), (self._broadcast_ip, self._port))
                print(f"[DEBUG] Broadcasted presence: {message}")
            except Exception as e:
                print(f"[ERROR] Error broadcasting presence: {e}")
            time.sleep(5)

    def _listen_for_peers(self):
        sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        sock.bind(('', self._port))
        sock.settimeout(1.0)

        while self._running.is_set():
            try:
                data, addr = sock.recvfrom(1024)
                message = json.loads(data.decode('utf-8'))

                peer_id = message.get("id")
                peer_ip = message.get("ip")

                if peer_id == self._drone_id:
                    continue

                print(f"[INFO] Discovered peer '{peer_id}' at {peer_ip}")

                if self.on_peer_discovered:
                    self.on_peer_discovered(peer_id, peer_ip)

            except socket.timeout:
                continue
            except Exception as e:
                print(f"[ERROR] Error listening for peers: {e}")

# ✅ Run without ROS
if __name__ == '__main__':
    drone_id = input("Enter drone ID (e.g., drone_001): ")
    discovery = Discovery(drone_id)

    try:
        discovery.start()
        print("[INFO] Discovery running. Press Ctrl+C to stop.")
        while True:
            time.sleep(1)
    except KeyboardInterrupt:
        print("\n[INFO] Interrupted by user.") 
    finally:
        discovery.stop()
