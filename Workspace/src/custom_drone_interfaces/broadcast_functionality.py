# broadcast_only_controller.py — stateless broadcast TX/RX with packet number, ms timestamps, and GPS

import socket
import json
import time
import subprocess
import logging
import argparse
import ipaddress
from typing import Optional, Dict, Any

# --- Logging ---
logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')
log = logging.getLogger("BroadcastOnly")

# --- Time helper (ms) ---
now_ms = lambda: int(time.time() * 1000)

# --- GPS helpers (gpsd via gpspipe) ---

def _parse_gpspipe_json_line(line: str) -> Optional[Dict[str, Any]]:
    try:
        obj = json.loads(line)
        if obj.get("class") == "TPV":
            lat = obj.get("lat")
            lon = obj.get("lon")
            alt = obj.get("alt")
            if lat is not None and lon is not None:
                return {"lat": float(lat), "lon": float(lon), "alt": float(alt) if alt is not None else None}
    except Exception:
        return None
    return None


def get_gps_position(timeout_s: float = 1.5) -> Optional[Dict[str, Any]]:
    """Return a dict with lat/lon(/alt) from gpsd via gpspipe, or None if unavailable."""
    try:
        proc = subprocess.Popen(["gpspipe", "-w", "-n", "10"], stdout=subprocess.PIPE, stderr=subprocess.DEVNULL, text=True)
        start = time.time()
        assert proc.stdout is not None
        for line in proc.stdout:
            pos = _parse_gpspipe_json_line(line)
            if pos is not None:
                proc.terminate()
                return pos
            if time.time() - start > timeout_s:
                proc.terminate()
                break
    except FileNotFoundError:
        log.debug("gpspipe not found. Install gpsd and gpsd-clients for GPS position.")
    except Exception as e:
        log.debug(f"GPS read failed: {e}")
    return None

# --- Interface helpers ---

def get_interface_ipv4(iface: str) -> Optional[str]:
    """Return IPv4 address (without mask) assigned to iface, or None."""
    try:
        out = subprocess.check_output(["ip", "-4", "-o", "addr", "show", "dev", iface], stderr=subprocess.DEVNULL, text=True)
        # Example line: "3: wlo1    inet 192.168.1.42/24 brd 192.168.1.255 scope global dynamic ..."
        for token in out.split():
            if "/" in token and token.count(".") == 3:
                return token.split("/")[0]
    except subprocess.CalledProcessError:
        return None
    return None


def compute_broadcast_from_ip(ip: str, prefix: int = 24) -> str:
    iface = ipaddress.IPv4Interface(f"{ip}/{prefix}")
    return str(iface.network.broadcast_address)

# --- Broadcast service ---

class BroadcastService:
    """
    Stateless broadcast-only service.
    - TX: once per second, send JSON with packet_number, tx_ms, position
    - RX: print augmented payload with rx_ms and receiver_position

    NOTE: On IP networks, *broadcast is UDP*. There is no TCP broadcast.
    We do not implement any unicast TCP/UDP sessions here.
    """

    def __init__(self, drone_id: str, interface: str, port: int, hz: float = 1.0):
        self.drone_id = drone_id
        self.interface = interface
        self.port = port
        self.period = 1.0 / hz if hz > 0 else 1.0
        self._running = False
        self._packet_number = 0

        # Prepare RX socket (bind to all)
        self.rx_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.rx_sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.rx_sock.bind(('', self.port))
        self.rx_sock.settimeout(0.5)

        # Prepare TX socket(s)
        self.tx_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.tx_sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)

        # Determine broadcast addresses
        self.own_ip = get_interface_ipv4(self.interface)
        if self.own_ip:
            try:
                self.subnet_broadcast = compute_broadcast_from_ip(self.own_ip, 24)
            except Exception:
                self.subnet_broadcast = "255.255.255.255"
        else:
            self.subnet_broadcast = "255.255.255.255"

        log.info(f"TX via broadcast {self.subnet_broadcast}:{self.port} (iface={self.interface}, ip={self.own_ip})")

    def run(self):
        self._running = True
        try:
            last = 0.0
            while self._running:
                # --- RX loop step ---
                try:
                    data, addr = self.rx_sock.recvfrom(65535)
                    self._handle_rx(data, addr)
                except socket.timeout:
                    pass

                # --- TX loop step ---
                now = time.time()
                if now - last >= self.period:
                    last = now
                    self._tx_once()
        except KeyboardInterrupt:
            pass
        finally:
            self.close()

    def close(self):
        if not self._running:
            return
        self._running = False
        try:
            self.rx_sock.close()
        except Exception:
            pass
        try:
            self.tx_sock.close()
        except Exception:
            pass
        log.info("Broadcast service stopped.")

    # --- internals ---

    def _tx_once(self):
        self._packet_number += 1
        payload = {
            "drone_id": self.drone_id,
            "protocol": "BROADCAST",  # simple tag
            "packet_number": self._packet_number,
            "tx_ms": now_ms(),
            "position": get_gps_position(),  # {lat, lon, alt} or None
        }
        msg = json.dumps(payload).encode('utf-8')

        # Prefer subnet broadcast, fall back to limited broadcast if needed
        try:
            self.tx_sock.sendto(msg, (self.subnet_broadcast, self.port))
        except OSError:
            self.tx_sock.sendto(msg, ("255.255.255.255", self.port))
            log.info("OSError occurred.")
        log.debug(f"TX {payload}")

    def _handle_rx(self, data: bytes, addr):
        try:
            message = json.loads(data.decode('utf-8'))
        except Exception:
            return
        # Ignore own messages (compare sender id or source address if present)
        if message.get('drone_id') == self.drone_id:
            return
        augmented = dict(message)
        augmented.update({
            "rx_ms": now_ms(),
            "receiver_position": get_gps_position(),
            "receiver_id": self.drone_id,
        })
        log.info(f"RX {json.dumps(augmented)}")

# --- CLI ---

def main():
    p = argparse.ArgumentParser(description="Stateless broadcast-only transmitter/receiver")
    p.add_argument('--drone-id', required=True, help='Unique ID for this node (e.g., drone_1)')
    p.add_argument('--interface', default='wlo1', help='Wireless interface to use (e.g., wlp1s0)')
    p.add_argument('--port', type=int, default=29999, help='UDP port for broadcast TX/RX')
    p.add_argument('--hz', type=float, default=1.0, help='Broadcast rate in Hz (default 1)')
    args = p.parse_args()

    # NOTE: No TCP or unicast UDP sessions are used here. Only UDP broadcast is employed,
    # because IP broadcast is inherently a UDP mechanism.

    svc = BroadcastService(drone_id=args.drone_id, interface=args.interface, port=args.port, hz=args.hz)
    try:
        svc.run()
    except KeyboardInterrupt:
        pass
    finally:
        svc.close()


if __name__ == '__main__':
    main()