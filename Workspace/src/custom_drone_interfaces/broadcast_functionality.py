# broadcast_only_controller.py — ad-hoc (IBSS) bring-up + stateless broadcast TX/RX with packet number, ms timestamps, GPS
# Now with selectable band (2.4 or 5 GHz) and channel, using `iw ... ibss join <freqMHz> HT20`.

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
DEFAULT_PORT = 29999
DEFAULT_HZ = 1.0

# --- Band/Channel defaults ---
DEFAULT_BAND = '2.4'      # '2.4' or '5'
DEFAULT_CHANNEL_24 = 6
DEFAULT_CHANNEL_5  = 149   # Use 149/153/157/161/165 only; 36–144 are typically no-IR for IBSS on many chipsets/reg domains

# Channel → frequency (MHz) maps
CHAN_TO_FREQ_24 = {
    1:2412, 2:2417, 3:2422, 4:2427, 5:2432, 6:2437, 7:2442,
    8:2447, 9:2452, 10:2457, 11:2462, 12:2467, 13:2472
}
# Stick to U-NII-3 (commonly allowed to initiate without DFS on many EU setups)
CHAN_TO_FREQ_5 = {149:5745, 153:5765, 157:5785, 161:5805, 165:5825}

def chan_to_freq(channel: int, band: str) -> int:
    if band == '2.4':
        if channel not in CHAN_TO_FREQ_24:
            raise ValueError(f"2.4 GHz channel {channel} not in {sorted(CHAN_TO_FREQ_24)}")
        return CHAN_TO_FREQ_24[channel]
    if band == '5':
        if channel not in CHAN_TO_FREQ_5:
            raise ValueError(f"5 GHz channel {channel} not in {sorted(CHAN_TO_FREQ_5)} "
                             f"(IBSS initiation on 36–144 is usually blocked by no-IR/DFS)")
        return CHAN_TO_FREQ_5[channel]
    raise ValueError(f"Unknown band '{band}'")

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

# --- NetworkManager helpers (save & restore previous connection) ---

def get_active_connection_on_device(interface: str) -> Optional[str]:
    """Return active connection NAME for the given device, if any."""
    try:
        p = subprocess.Popen([
            'nmcli', '-t', '-f', 'NAME,DEVICE', 'connection', 'show', '--active'
        ], stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
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

def setup_adhoc(interface: str, ssid: str, band: str, channel: int, ip_cidr: str) -> bool:
    log.info(f"Configuring IBSS on {interface} SSID='{ssid}' band={band} channel={channel} ip={ip_cidr}")
    steps = [
        ['sudo', 'nmcli', 'dev', 'disconnect', interface],
        ['sudo', 'nmcli', 'dev', 'set', interface, 'managed', 'no'],
        ['sudo', 'killall', 'wpa_supplicant'],
        ['sudo', 'ip', 'link', 'set', interface, 'down'],
        ['sudo', 'ip', 'addr', 'flush', 'dev', interface],
        ['sudo', 'ip', 'link', 'set', interface, 'up'],
    ]
    for cmd in steps:
        if not run(cmd, ignore_rc=('killall' in cmd)):
            return False
        time.sleep(0.15)

    try:
        freq = chan_to_freq(channel, band)
    except Exception as e:
        log.error(f"Invalid band/channel: {e}")
        return False

    # Join IBSS by frequency; HT20 is conservative and widely allowed
    if not run(['sudo', 'iw', 'dev', interface, 'ibss', 'join', ssid, str(freq), 'HT20']):
        return False

    if not run(['sudo', 'ip', 'addr', 'add', ip_cidr, 'dev', interface]):
        return False

    # Try to disable power saving where possible (best-effort)
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
            log.info("Keyboard interrupt detected, shutting down…")
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
        log.debug(f"TX {json.dumps(payload)}")
        try:
            self.tx_sock.sendto(msg, (self.subnet_broadcast, self.port))
        except OSError:
            # Fallback to global broadcast
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
    parser.add_argument('--band', choices=['2.4', '5'], default=DEFAULT_BAND,
                        help="Wi-Fi band: '2.4' or '5' (default: 2.4)")
    parser.add_argument('--channel', type=int,
                        help='Channel number (optional). Defaults: 6 on 2.4 GHz, 149 on 5 GHz.')
    args = parser.parse_args()

    # Decide channel default based on band
    channel = args.channel
    if channel is None:
        channel = DEFAULT_CHANNEL_24 if args.band == '2.4' else DEFAULT_CHANNEL_5

    # Save currently active connection for this interface BEFORE tearing it down
    prev_connection = get_active_connection_on_device(args.interface)

    # Deterministic per-drone IP in 192.168.88.0/24
    last_octet = abs(hash(args.drone_id)) % 200 + 20
    ip_cidr = f"192.168.88.{last_octet}/24"

    if not setup_adhoc(args.interface, DEFAULT_SSID, args.band, channel, ip_cidr):
        # If setup fails, try to restore previous network
        reconnect_previous_connection(args.interface, prev_connection)
        return

    svc = BroadcastService(drone_id=args.drone_id, interface=args.interface, port=DEFAULT_PORT, hz=DEFAULT_HZ, ip_cidr=ip_cidr)
    try:
        svc.run()
    except KeyboardInterrupt:
        pass
    finally:
        svc.close()
        teardown_adhoc(args.interface)
        reconnect_previous_connection(args.interface, prev_connection)

if __name__ == '__main__':
    main()
