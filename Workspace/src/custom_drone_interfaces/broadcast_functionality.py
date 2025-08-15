# broadcast_only_controller.py — ad-hoc (IBSS) bring-up + stateless broadcast TX/RX with packet number, ms timestamps, and GPS

import socket
import json
import time
import subprocess
import logging
import argparse
import ipaddress
from typing import Optional, Dict, Any

# --- Configurable Defaults ---
DEFAULT_SSID = 'drone-swarm-net'
DEFAULT_CHANNEL = 6
DEFAULT_PORT = 29999
DEFAULT_HZ = 1.0

# --- Logging ---
logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')
log = logging.getLogger("BroadcastOnly")

# --- Time helper (ms) ---
now_ms = lambda: int(time.time() * 1000)

# --- Shell helpers ---

def run(cmd: list[str], ignore_rc: bool = False) -> bool:
    try:
        p = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        _, err = p.communicate()
        if p.returncode != 0 and not ignore_rc:
            log.error(f"cmd failed ({p.returncode}): {' '.join(cmd)} :: {err.strip()}")
            return False
        return True
    except FileNotFoundError:
        log.error(f"not found: {cmd[0]}")
        return False

# --- GPS helpers ---

def _parse_gpspipe_json_line(line: str) -> Optional[Dict[str, Any]]:
    try:
        obj = json.loads(line)
        if obj.get("class") == "TPV":
            lat = obj.get("lat"); lon = obj.get("lon"); alt = obj.get("alt")
            if lat is not None and lon is not None:
                return {"lat": float(lat), "lon": float(lon), "alt": float(alt) if alt is not None else None}
    except Exception:
        return None
    return None

def get_gps_position(timeout_s: float = 1.5) -> Optional[Dict[str, Any]]:
    try:
        proc = subprocess.Popen(["gpspipe", "-w", "-n", "10"], stdout=subprocess.PIPE, stderr=subprocess.DEVNULL, text=True)
        start = time.time()
        assert proc.stdout is not None
        for line in proc.stdout:
            pos = _parse_gpspipe_json_line(line)
            if pos is not None:
                proc.terminate(); return pos
            if time.time() - start > timeout_s:
                proc.terminate(); break
    except FileNotFoundError:
        log.debug("gpspipe not found. Install gpsd and gpsd-clients for GPS position.")
    except Exception as e:
        log.debug(f"GPS read failed: {e}")
    return None

# --- Interface helpers ---

def compute_broadcast_from_ip(ip_cidr: str) -> str:
    iface = ipaddress.IPv4Interface(ip_cidr)
    return str(iface.network.broadcast_address)

# --- Ad-hoc setup/teardown ---

def setup_adhoc(interface: str, ssid: str, channel: int, ip_cidr: str) -> bool:
    log.info(f"Configuring IBSS on {interface} SSID='{ssid}' channel={channel} ip={ip_cidr}")
    steps = [
        ['sudo', 'nmcli', 'dev', 'disconnect', interface],
        ['sudo', 'nmcli', 'dev', 'set', interface, 'managed', 'no'],
        ['sudo', 'killall', 'wpa_supplicant'],
        ['sudo', 'ip', 'link', 'set', interface, 'down'],
        ['sudo', 'iwconfig', interface, 'mode', 'ad-hoc'],
        ['sudo', 'iwconfig', interface, 'essid', ssid],
        ['sudo', 'iwconfig', interface, 'channel', str(channel)],
        ['sudo', 'ip', 'addr', 'flush', 'dev', interface],
        ['sudo', 'ip', 'link', 'set', interface, 'up'],
        ['sudo', 'ip', 'addr', 'add', ip_cidr, 'dev', interface],
    ]
    for cmd in steps:
        if not run(cmd, ignore_rc=('killall' in cmd)):
            return False
        time.sleep(0.2)
    run(['sudo', 'iw', 'dev', interface, 'set', 'power_save', 'off'], ignore_rc=True)
    run(['sudo', 'iwconfig', interface, 'power', 'off'], ignore_rc=True)
    return True

def teardown_adhoc(interface: str):
    log.info("Tearing down IBSS and returning control to NetworkManager…")
    run(['sudo', 'ip', 'addr', 'flush', 'dev', interface], ignore_rc=True)
    run(['sudo', 'nmcli', 'dev', 'set', interface, 'managed', 'yes'], ignore_rc=True)

# --- Broadcast service ---

class BroadcastService:
    def __init__(self, drone_id: str, interface: str, port: int, hz: float, ip_cidr: str):
        self.drone_id = drone_id
        self.interface = interface
        self.port = port
        self.period = 1.0 / hz
        self._running = False
        self._packet_number = 0
        self.subnet_broadcast = compute_broadcast_from_ip(ip_cidr)
        self.rx_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.rx_sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.rx_sock.bind(('', self.port))
        self.rx_sock.settimeout(0.5)
        self.tx_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.tx_sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
        log.info(f"TX via broadcast {self.subnet_broadcast}:{self.port} (iface={self.interface})")

    def run(self):
        self._running = True
        last = 0.0
        try:
            while self._running:
                try:
                    data, _ = self.rx_sock.recvfrom(65535)
                    self._handle_rx(data)
                except socket.timeout:
                    pass
                now = time.time()
                if now - last >= self.period:
                    last = now
                    self._tx_once()
        except KeyboardInterrupt:
            log.info("Keyboard interrupt detected, shutting down...")
            self.close()
            raise
        finally:
            self.close()

    def close(self):
        self._running = False
        try: self.rx_sock.close()
        except: pass
        try: self.tx_sock.close()
        except: pass

    def _tx_once(self):
        self._packet_number += 1
        payload = {
            "drone_id": self.drone_id,
            "protocol": "BROADCAST",
            "packet_number": self._packet_number,
            "tx_ms": now_ms(),
            "position": get_gps_position(),
        }
        msg = json.dumps(payload).encode('utf-8')
        try:
            self.tx_sock.sendto(msg, (self.subnet_broadcast, self.port))
        except OSError:
            self.tx_sock.sendto(msg, ("255.255.255.255", self.port))

    def _handle_rx(self, data: bytes):
        try:
            message = json.loads(data.decode('utf-8'))
        except Exception:
            return
        if message.get('drone_id') == self.drone_id:
            return
        message.update({
            "rx_ms": now_ms(),
            "receiver_position": get_gps_position(),
            "receiver_id": self.drone_id,
        })
        log.info(f"RX {json.dumps(message)}")

# --- CLI ---

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--drone-id', required=True, help='Unique ID for this drone')
    parser.add_argument('--interface', required=True, help='Name of the network card, e.g., wlo1')
    args = parser.parse_args()

    last_octet = abs(hash(args.drone_id)) % 200 + 20
    ip_cidr = f"192.168.88.{last_octet}/24"

    if not setup_adhoc(args.interface, DEFAULT_SSID, DEFAULT_CHANNEL, ip_cidr):
        return

    svc = BroadcastService(drone_id=args.drone_id, interface=args.interface, port=DEFAULT_PORT, hz=DEFAULT_HZ, ip_cidr=ip_cidr)
    try:
        svc.run()
    except KeyboardInterrupt:
        pass
    finally:
        svc.close()
        teardown_adhoc(args.interface)

if __name__ == '__main__':
    main()