# broadcast_only_controller.py — IBSS bring-up + concurrent broadcast TX/RX with GPS cache
import socket
import json
import time
import subprocess
import logging
import argparse
import ipaddress
import threading
from typing import Optional, Dict, Any

# --- Configurable Defaults ---
DEFAULT_SSID = 'drone-swarm-net'
DEFAULT_CHANNEL = 6
DEFAULT_PORT = 29999
DEFAULT_HZ = 1.0

# --- Logging ---
logging.basicConfig(level=logging.DEBUG, format='%(asctime)s - %(levelname)s - %(message)s')
log = logging.getLogger("BroadcastOnly")

# --- Time helper (ms) ---
now_ms = lambda: int(time.time() * 1000)

# --- Shell helpers ---
def run(cmd: list[str], ignore_rc: bool = False) -> bool:
    log.debug(f"RUN: {' '.join(cmd)}")
    try:
        p = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        out, err = p.communicate()
        if out:
            log.debug(out.strip())
        if p.returncode != 0 and not ignore_rc:
            log.error(f"cmd failed ({p.returncode}): {' '.join(cmd)} :: {err.strip()}")
            return False
        return True
    except FileNotFoundError:
        log.error(f"not found: {cmd[0]}")
        return False

# --- GPS helpers ---
def _parse_gpspipe_json_line(line: str) -> Optional[Dict[str, float]]:
    try:
        obj = json.loads(line)
        if obj.get("class") == "TPV":
            lat = obj.get("lat"); lon = obj.get("lon"); alt = obj.get("alt")
            if lat is not None and lon is not None:
                return {"lat": float(lat), "lon": float(lon), "alt": float(alt) if alt is not None else None}
    except Exception:
        return None
    return None

class GpsCache:
    """Background GPS reader to avoid blocking RX/TX."""
    def __init__(self, period_s: float = 1.0, timeout_s: float = 1.5):
        self._period = period_s
        self._timeout = timeout_s
        self._lock = threading.Lock()
        self._last: Optional[Dict[str, float]] = None
        self._stop = threading.Event()
        self._thread = threading.Thread(target=self._loop, name="gps-cache", daemon=True)

    def start(self):
        self._thread.start()

    def stop(self):
        self._stop.set()
        self._thread.join(timeout=2.0)

    def get(self) -> Optional[Dict[str, float]]:
        with self._lock:
            return dict(self._last) if self._last else None

    def _loop(self):
        while not self._stop.is_set():
            pos = self._read_once(timeout_s=self._timeout)
            if pos:
                with self._lock:
                    self._last = pos
            # even if none, keep the previous fix; just sleep
            self._stop.wait(self._period)

    @staticmethod
    def _read_once(timeout_s: float) -> Optional[Dict[str, float]]:
        try:
            proc = subprocess.Popen(["gpspipe", "-w", "-n", "10"],
                                    stdout=subprocess.PIPE, stderr=subprocess.DEVNULL, text=True)
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
def compute_broadcast_from_ip(ip_cidr: str) -> str:
    iface = ipaddress.IPv4Interface(ip_cidr)
    return str(iface.network.broadcast_address)

# --- NetworkManager helpers (save & restore previous connection) ---
def get_active_connection_on_device(interface: str) -> Optional[str]:
    try:
        p = subprocess.Popen(
            ['nmcli', '-t', '-f', 'NAME,DEVICE', 'connection', 'show', '--active'],
            stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True
        )
        out, err = p.communicate(timeout=5)
        if p.returncode != 0:
            log.debug(f"nmcli active con err: {err.strip()}")
            return None
        for line in out.strip().splitlines():
            if not line:
                continue
            name, dev = (line.split(':', 1) + [None])[:2]
            if dev == interface:
                log.info(f"Detected active connection on {interface}: '{name}'")
                return name
    except Exception as e:
        log.debug(f"get_active_connection_on_device failed: {e}")
    return None

def reconnect_previous_connection(interface: str, conn_name: Optional[str]) -> None:
    if not conn_name:
        log.info("No previous connection name recorded; skipping reconnect.")
        return
    log.info(f"Attempting to reconnect to previous network: '{conn_name}' on {interface}")
    run(['sudo', 'nmcli', 'dev', 'set', interface, 'managed', 'yes'], ignore_rc=True)
    run(['sudo', 'nmcli', 'dev', 'disconnect', interface], ignore_rc=True)
    run(['sudo', 'nmcli', 'connection', 'up', 'id', conn_name], ignore_rc=True)

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
        time.sleep(0.15)
    # Try to disable power saving where possible
    run(['sudo', 'iw', 'dev', interface, 'set', 'power_save', 'off'], ignore_rc=True)
    run(['sudo', 'iwconfig', interface, 'power', 'off'], ignore_rc=True)
    return True

def teardown_adhoc(interface: str):
    log.info("Tearing down IBSS and returning control to NetworkManager…")
    run(['sudo', 'ip', 'addr', 'flush', 'dev', interface], ignore_rc=True)
    run(['sudo', 'nmcli', 'dev', 'set', interface, 'managed', 'yes'], ignore_rc=True)

# --- Broadcast service (concurrent) ---
class BroadcastService:
    def __init__(self, drone_id: str, interface: str, port: int, hz: float, ip_cidr: str, gps: GpsCache):
        self.drone_id = drone_id
        self.interface = interface
        self.port = port
        self.period = 1.0 / hz
        self.subnet_broadcast = compute_broadcast_from_ip(ip_cidr)
        self._packet_number = 0
        self._stop = threading.Event()
        self._gps = gps

        # Sockets
        self.rx_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.rx_sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.rx_sock.bind(('', self.port))
        # Leave blocking mode for RX thread (clean shutdown via closing socket)
        self.tx_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.tx_sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)

        # Threads
        self._rx_thr = threading.Thread(target=self._rx_loop, name="rx-loop", daemon=True)
        self._tx_thr = threading.Thread(target=self._tx_loop, name="tx-loop", daemon=True)

        log.info(f"TX via broadcast {self.subnet_broadcast}:{self.port} (iface={self.interface})")

    # --- lifecycle ---
    def start(self):
        self._rx_thr.start()
        self._tx_thr.start()

    def stop(self):
        self._stop.set()
        try:
            # Closing the socket will unblock recvfrom()
            self.rx_sock.close()
        except Exception:
            pass
        self._rx_thr.join(timeout=2.0)
        self._tx_thr.join(timeout=2.0)
        try: self.tx_sock.close()
        except Exception: pass

    # --- loops ---
    def _tx_loop(self):
        next_t = time.time()
        while not self._stop.is_set():
            now = time.time()
            if now < next_t:
                # Sleep a short, bounded interval so stop() remains responsive
                self._stop.wait(min(next_t - now, 0.05))
                continue
            self._tx_once()
            next_t += self.period

    def _rx_loop(self):
        while not self._stop.is_set():
            try:
                data, _ = self.rx_sock.recvfrom(65535)  # unbounded block; close socket to exit
            except OSError:
                break  # socket closed during stop()
            self._handle_rx(data)

    # --- helpers ---
    def _tx_once(self):
        self._packet_number += 1
        payload = {
            "drone_id": self.drone_id,
            "protocol": "BROADCAST",
            "packet_number": self._packet_number,
            "tx_ms": now_ms(),
            "position": self._gps.get(),
        }
        msg = json.dumps(payload).encode('utf-8')
        log.debug(f"TX {json.dumps(payload)}")
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
            "receiver_position": self._gps.get(),
            "receiver_id": self.drone_id,
        })
        log.info(f"RX {json.dumps(message)}")

# --- CLI ---
def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--drone-id', required=True, help='Unique ID for this drone')
    parser.add_argument('--interface', required=True, help='Name of the network card, e.g., wlo1')
    args = parser.parse_args()

    # Save currently active connection for this interface BEFORE tearing it down
    prev_connection = get_active_connection_on_device(args.interface)

    # Deterministic per-drone IP in 192.168.88.0/24
    last_octet = abs(hash(args.drone_id)) % 200 + 20
    ip_cidr = f"192.168.88.{last_octet}/24"

    if not setup_adhoc(args.interface, DEFAULT_SSID, DEFAULT_CHANNEL, ip_cidr):
        reconnect_previous_connection(args.interface, prev_connection)
        return

    gps = GpsCache(period_s=1.0, timeout_s=1.5)
    gps.start()
    svc = BroadcastService(
        drone_id=args.drone_id,
        interface=args.interface,
        port=DEFAULT_PORT,
        hz=DEFAULT_HZ,
        ip_cidr=ip_cidr,
        gps=gps,
    )

    try:
        svc.start()
        # Park the main thread until Ctrl+C
        while True:
            time.sleep(1.0)
    except KeyboardInterrupt:
        log.info("Keyboard interrupt detected, shutting down…")
    finally:
        svc.stop()
        gps.stop()
        teardown_adhoc(args.interface)
        reconnect_previous_connection(args.interface, prev_connection)

if __name__ == '__main__':
    main()