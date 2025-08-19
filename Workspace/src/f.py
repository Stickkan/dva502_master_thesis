# swarm_controller_wext_broadcast.py
# WEXT ad-hoc (scan-first join-or-create) + continuous telemetry broadcast + discovery + TCP/UDP links + heartbeat

import argparse
import ipaddress
import json
import logging
import re
import socket
import subprocess
import threading
import time
from collections import deque
from typing import Optional, Dict, Any

# ---------- Logging ----------
logging.basicConfig(level=logging.DEBUG, format='%(asctime)s - %(name)s - %(levelname)s - %(message)s')
log = logging.getLogger("Swarm")

# ---------- Constants ----------
DISCOVERY_PORT = 19999
TELEMETRY_PORT = 29999
SCAN_INTERVAL_S = 1.0
FOUNDERS_SHORT_SCAN_S = 2.0   # short scan window before possibly creating a cell
FOLLOWER_GRACE_S = 8.0        # not used in this version (we always scan then create if none)

# ---------- Utils ----------
def run(cmd: list[str], ignore_rc: bool = False) -> bool:
    log.info("RUN: %s", ' '.join(cmd))
    try:
        p = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        out, err = p.communicate()
        if out:
            log.debug(out.strip())
        if p.returncode != 0 and not ignore_rc:
            if err:
                log.error("cmd failed (%s): %s :: %s", p.returncode, ' '.join(cmd), err.strip())
            return False
        return True
    except Exception as e:
        if not ignore_rc:
            log.error("cmd exception: %s :: %s", ' '.join(cmd), e)
        return False

def detect_wifi_interface() -> Optional[str]:
    # Try 'iw dev'
    try:
        out = subprocess.check_output(['iw', 'dev'], stderr=subprocess.DEVNULL, text=True)
        for line in out.splitlines():
            line = line.strip()
            if line.startswith('Interface '):
                return line.split()[1]
    except Exception:
        pass
    # Fallback to nmcli
    try:
        out = subprocess.check_output(['nmcli', '-t', '-f', 'DEVICE,TYPE', 'device'],
                                      stderr=subprocess.DEVNULL, text=True)
        for line in out.splitlines():
            dev, typ = line.split(':')
            if typ == 'wifi':
                return dev
    except Exception:
        pass
    return None

def id_num(s: str) -> int:
    d = ''.join(filter(str.isdigit, s))
    return int(d) if d else 0

def compute_broadcast_from_ip(ip_cidr: str) -> str:
    iface = ipaddress.IPv4Interface(ip_cidr)
    return str(iface.network.broadcast_address)

def now_ms() -> int:
    return int(time.time() * 1000)

# ---------- GPS helpers (cached) ----------
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

class GpsCache:
    def __init__(self, period_s: float = 1.0, timeout_s: float = 1.5):
        self._period = period_s
        self._timeout = timeout_s
        self._lock = threading.Lock()
        self._last: Optional[Dict[str, float]] = None
        self._stop = threading.Event()
        self._thr = threading.Thread(target=self._loop, name="gps-cache", daemon=True)

    def start(self):
        self._thr.start()

    def stop(self):
        self._stop.set()
        self._thr.join(timeout=2.0)

    def get(self) -> Optional[Dict[str, float]]:
        with self._lock:
            return dict(self._last) if self._last else None

    def _loop(self):
        while not self._stop.is_set():
            pos = self._read_once(self._timeout)
            if pos:
                with self._lock:
                    self._last = pos
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
            log.debug("gpspipe not found. Install gpsd and gpsd-clients for GPS.")
        except Exception as e:
            log.debug(f"GPS read failed: {e}")
        return None

# ---------- WEXT Ad-Hoc bring-up (scan-first join-or-create) ----------
class WextAdhoc:
    def __init__(self, iface: str, ssid: str, channel: int):
        self.iface = iface
        self.ssid = ssid
        self.channel = int(channel)
        self._original_connection = self._get_active_connection()

    def _get_active_connection(self) -> Optional[str]:
        try:
            out = subprocess.check_output(
                ['nmcli', '-t', '-f', 'NAME,DEVICE', 'con', 'show', '--active'],
                stderr=subprocess.DEVNULL, text=True
            )
            for line in out.strip().splitlines():
                if not line.strip():
                    continue
                name, dev = line.split(':')
                if dev == self.iface:
                    log.info("Detected active connection on %s: '%s'", self.iface, name)
                    return name
        except Exception:
            pass
        return None

    def _scan_once(self) -> list[Dict[str, Any]]:
        try:
            out = subprocess.check_output(['sudo', 'iwlist', self.iface, 'scan'],
                                          stderr=subprocess.DEVNULL, text=True, timeout=7)
        except Exception:
            return []
        matches = []
        for blob in out.split("Cell ")[1:]:
            m_addr = re.search(r'Address:\s*([0-9A-Fa-f:]{17})', blob)
            m_mode = re.search(r'Mode:\s*Ad-Hoc', blob)
            m_ess  = re.search(r'ESSID:"([^"]+)"', blob)
            m_ch   = re.search(r'Channel\s*:\s*(\d+)', blob) or re.search(r'Frequency:.*\(Channel\s*(\d+)\)', blob)
            if not (m_addr and m_mode and m_ess and m_ch):
                continue
            if m_ess.group(1) != self.ssid:
                continue
            try:
                matches.append({'bssid': m_addr.group(1).lower(), 'channel': int(m_ch.group(1))})
            except ValueError:
                continue
        return matches

    def _scan_until(self, seconds: float) -> Optional[Dict[str, Any]]:
        deadline = time.time() + seconds
        run(['sudo', 'ip', 'link', 'set', self.iface, 'up'], ignore_rc=True)
        while time.time() < deadline:
            ms = self._scan_once()
            if ms:
                return ms[0]
            time.sleep(SCAN_INTERVAL_S)
        return None

    def bring_up(self) -> bool:
        log.info("Preparing interface for WEXT Ad-Hoc (scan-first): %s", self.iface)

        # Neutralize managers & state
        run(['sudo', 'nmcli', 'dev', 'disconnect', self.iface], ignore_rc=True)
        run(['sudo', 'nmcli', 'dev', 'set', self.iface, 'managed', 'no'], ignore_rc=True)
        run(['sudo', 'systemctl', 'stop', 'iwd'], ignore_rc=True)
        run(['sudo', 'killall', 'wpa_supplicant'], ignore_rc=True)
        run(['sudo', 'iw', 'dev', self.iface, 'ibss', 'leave'], ignore_rc=True)
        run(['sudo', 'iw', 'dev', self.iface, 'mesh', 'leave'], ignore_rc=True)
        run(['sudo', 'ip', 'addr', 'flush', 'dev', self.iface], ignore_rc=True)
        run(['sudo', 'ip', 'link', 'set', self.iface, 'down'], ignore_rc=True)

        # Scan (iface must be up), then DOWN again before changing mode
        log.info('Scanning up to %.1fs for existing ad-hoc cell ESSID="%s"...', FOUNDERS_SHORT_SCAN_S, self.ssid)
        run(['sudo', 'ip', 'link', 'set', self.iface, 'up'], ignore_rc=True)
        found = self._scan_until(FOUNDERS_SHORT_SCAN_S)

        use_channel = self.channel
        if found:
            use_channel = found['channel']
            log.info("Found existing cell on channel %d; will join.", use_channel)
        else:
            log.info("No existing cell; will create on channel %d.", use_channel)

        run(['sudo', 'ip', 'link', 'set', self.iface, 'down'], ignore_rc=True)
        time.sleep(0.1)
        run(['sudo', 'iw', 'dev', self.iface, 'set', 'type', 'managed'], ignore_rc=True)
        time.sleep(0.05)

        # Configure legacy ad-hoc
        if not run(['sudo', 'iwconfig', self.iface, 'mode', 'ad-hoc']): return False
        if not run(['sudo', 'iwconfig', self.iface, 'essid', self.ssid]): return False
        if not run(['sudo', 'iwconfig', self.iface, 'channel', str(use_channel)]): return False
        if not run(['sudo', 'ip', 'link', 'set', self.iface, 'up']): return False

        # Verify
        try:
            out = subprocess.check_output(['iwconfig', self.iface], stderr=subprocess.DEVNULL, text=True)
            if ('Mode:Ad-Hoc' not in out) or (f'ESSID:"{self.ssid}"' not in out):
                log.error("WEXT state not as expected:\n%s", out.strip()); return False
            cell = re.search(r'Cell\s*[:=]\s*([0-9A-Fa-f:]{17})', out)
            ch   = re.search(r'Channel\s*:(\d+)', out) or re.search(r'Frequency:.*\(Channel\s*(\d+)\)', out)
            log.info("Ad-Hoc up. %s %s",
                     f"Cell={cell.group(1).lower()}" if cell else "Cell=unknown",
                     f"Channel={ch.group(1)}" if ch else "Channel=unknown")
        except subprocess.CalledProcessError:
            log.error("Cannot read iwconfig state."); return False

        return True

    def add_ip(self, ip_cidr: str) -> bool:
        # iface is clean (we flushed), so add should succeed
        if not run(['sudo', 'ip', 'addr', 'add', ip_cidr, 'dev', self.iface]):
            log.error("Failed to assign IP %s to %s.", ip_cidr, self.iface); return False
        log.info("Assigned IP %s to %s.", ip_cidr, self.iface); return True

    def teardown(self):
        log.info("Restoring original network state...")
        run(['sudo', 'ip', 'addr', 'flush', 'dev', self.iface], ignore_rc=True)
        run(['sudo', 'ip', 'link', 'set', self.iface, 'down'], ignore_rc=True)
        if not run(['sudo', 'iw', 'dev', self.iface, 'set', 'type', 'managed'], ignore_rc=True):
            run(['sudo', 'iwconfig', self.iface, 'mode', 'managed'], ignore_rc=True)
        run(['sudo', 'nmcli', 'dev', 'set', self.iface, 'managed', 'yes'], ignore_rc=True)
        run(['nmcli', 'radio', 'wifi', 'on'], ignore_rc=True)
        run(['sudo', 'ip', 'link', 'set', self.iface, 'up'], ignore_rc=True)
        time.sleep(2)
        prev = self._original_connection
        if prev:
            log.info("Attempting to reconnect to '%s'...", prev)
            run(['nmcli', 'con', 'up', 'id', prev], ignore_rc=True)

# ---------- Telemetry broadcast (continuous) ----------
class TelemetryBroadcaster:
    def __init__(self, drone_id: str, ip_cidr: str, port: int, hz: float, gps: GpsCache, bind_iface: Optional[str] = None):
        self.drone_id = drone_id
        self.period = 1.0 / max(hz, 0.1)
        self.port = port
        self._gps = gps
        self._stop = threading.Event()
        self._pkt = 0
        self._bcast_ip = compute_broadcast_from_ip(ip_cidr)

        # RX socket
        self.rx_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.rx_sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.rx_sock.bind(('', self.port))

        # TX socket
        self.tx_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.tx_sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
        if bind_iface:
            try:
                self.tx_sock.setsockopt(socket.SOL_SOCKET, 25, bind_iface.encode())  # SO_BINDTODEVICE
                log.debug("Telemetry TX bound to iface %s", bind_iface)
            except OSError:
                pass

        self._tx_thr = threading.Thread(target=self._tx_loop, name="telemetry-tx", daemon=True)
        self._rx_thr = threading.Thread(target=self._rx_loop, name="telemetry-rx", daemon=True)
        log.info(f"Telemetry TX to {self._bcast_ip}:{self.port}")

    def start(self):
        self._rx_thr.start()
        self._tx_thr.start()

    def stop(self):
        self._stop.set()
        try: self.rx_sock.close()
        except Exception: pass
        try: self.tx_sock.close()
        except Exception: pass
        self._rx_thr.join(timeout=2.0)
        self._tx_thr.join(timeout=2.0)

    def _tx_loop(self):
        next_t = time.time()
        while not self._stop.is_set():
            now = time.time()
            if now < next_t:
                self._stop.wait(min(next_t - now, 0.05)); continue
            self._pkt += 1
            payload = {
                "protocol": "TELEMETRY",
                "drone_id": self.drone_id,
                "packet_number": self._pkt,
                "tx_ms": now_ms(),
                "position": self._gps.get(),
            }
            msg = json.dumps(payload).encode('utf-8')
            try:
                self.tx_sock.sendto(msg, (self._bcast_ip, self.port))
            except OSError:
                # try limited broadcast
                try: self.tx_sock.sendto(msg, ("255.255.255.255", self.port))
                except OSError: pass
            log.debug("TX TELEMETRY %s", json.dumps(payload))
            next_t += self.period

    def _rx_loop(self):
        while not self._stop.is_set():
            try:
                data, _ = self.rx_sock.recvfrom(65535)
            except OSError:
                break
            try:
                msg = json.loads(data.decode('utf-8', errors='ignore'))
            except Exception:
                continue
            if msg.get("protocol") == "TELEMETRY" and msg.get("drone_id") != self.drone_id:
                log.info("RX TELEMETRY from %s: %s", msg.get("drone_id"), json.dumps(msg))

# ---------- Discovery (beacons) ----------
class Discovery:
    def __init__(self, drone_id: str, iface: str, ip_cidr: str, tcp_port: int, udp_port: int, port: int = DISCOVERY_PORT):
        self._drone_id = drone_id
        self._iface = iface
        self._port = port
        self._tcp_port = tcp_port
        self._udp_port = udp_port
        ip = str(ipaddress.IPv4Interface(ip_cidr).ip)
        self._ip = ip
        self._bcast_ip = compute_broadcast_from_ip(ip_cidr)
        self._running = False
        self.on_peer_discovered = None
        self._tx_thr = None
        self._rx_thr = None

    def start(self):
        self._running = True
        self._tx_thr = threading.Thread(target=self._tx_loop, name="disc-tx", daemon=True)
        self._rx_thr = threading.Thread(target=self._rx_loop, name="disc-rx", daemon=True)
        self._tx_thr.start(); self._rx_thr.start()

    def stop(self):
        self._running = False
        try:
            with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
                s.sendto(b'stop', ('127.0.0.1', self._port))
        except Exception:
            pass
        if self._tx_thr: self._tx_thr.join(timeout=2.0)
        if self._rx_thr: self._rx_thr.join(timeout=2.0)

    def _tx_loop(self):
        msg = json.dumps({
            "protocol": "DISCOVERY",
            "id": self._drone_id, "ip": self._ip,
            "tcp_port": self._tcp_port, "udp_port": self._udp_port
        }).encode("utf-8")
        s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        s.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
        try:
            # bind to iface so beacons egress the ad-hoc NIC
            try:
                s.setsockopt(socket.SOL_SOCKET, 25, self._iface.encode())
                log.debug("Discovery TX bound to iface %s", self._iface)
            except OSError:
                pass
            while self._running:
                try:
                    s.sendto(msg, (self._bcast_ip, self._port))
                except OSError as e:
                    log.error("Discovery broadcast failed: %s", e)
                time.sleep(1.0)
        finally:
            s.close()

    def _rx_loop(self):
        s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        try:
            s.bind(('', self._port))
        except OSError as e:
            log.error("Discovery bind failed: %s", e); return
        s.settimeout(1.0)
        while self._running:
            try:
                data, _ = s.recvfrom(2048)
                msg = json.loads(data.decode('utf-8', errors='ignore'))
                if msg.get("protocol") != "DISCOVERY":
                    continue
                pid = msg.get("id"); pip = msg.get("ip")
                if pid and pip and pid != self._drone_id and self.on_peer_discovered:
                    self.on_peer_discovered(msg)
            except socket.timeout:
                continue
            except Exception:
                if not self._running: break
        s.close()

# ---------- Connection Manager (TCP/UDP) with message queue ----------
class ConnectionManager:
    def __init__(self, drone_id: str, on_message, tcp_port: int, udp_port: int, protocol: str):
        self._drone_id = drone_id
        self._on_message = on_message
        self._tcp_port = tcp_port
        self._udp_port = udp_port
        self._proto = protocol.upper()  # "TCP" or "UDP"
        self._running = False
        self._threads = []
        self._clients: Dict[str, socket.socket] = {}
        self._peers: Dict[str, dict] = {}
        self._lock = threading.Lock()
        self._queue = deque()

    def start(self):
        self._running = True
        # servers
        t1 = threading.Thread(target=self._tcp_server, daemon=True); t1.start(); self._threads.append(t1)
        t2 = threading.Thread(target=self._udp_server, daemon=True); t2.start(); self._threads.append(t2)
        t3 = threading.Thread(target=self._worker, daemon=True); t3.start(); self._threads.append(t3)
        log.info("TCP server listening on %d; UDP server on %d", self._tcp_port, self._udp_port)

    def stop(self):
        if not self._running: return
        self._running = False
        with self._lock:
            for s in list(self._clients.values()):
                try: s.close()
                except Exception: pass
        try:
            socket.create_connection(('127.0.0.1', self._tcp_port), timeout=0.5).close()
            with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
                s.sendto(b'stop', ('127.0.0.1', self._udp_port))
        except Exception:
            pass
        for t in self._threads: t.join(timeout=2.0)
        self._threads.clear()

    def get_connected_peers(self):
        with self._lock:
            return list(self._clients.keys())

    def register_peer_info(self, info: dict):
        with self._lock:
            self._peers[info['id']] = info

    def connect_to_peer(self, info: dict):
        pid = info['id']
        with self._lock:
            if pid in self._clients:
                return
        log.info("Connecting to %s at %s via %s...", pid, info['ip'], self._proto)
        try:
            if self._proto == "TCP":
                s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                s.setsockopt(socket.SOL_SOCKET, socket.SO_KEEPALIVE, 1)
                try:
                    s.setsockopt(socket.IPPROTO_TCP, socket.TCP_KEEPIDLE, 5)
                    s.setsockopt(socket.IPPROTO_TCP, socket.TCP_KEEPINTVL, 3)
                    s.setsockopt(socket.IPPROTO_TCP, socket.TCP_KEEPCNT, 3)
                except (AttributeError, OSError):
                    pass
                s.settimeout(3.0)
                s.connect((info['ip'], info['tcp_port']))
                s.settimeout(None)
                hello = {"protocol": "HELLO", "drone_id": self._drone_id}
                s.sendall((json.dumps(hello) + "\n").encode("utf-8"))
                t = threading.Thread(target=self._tcp_reader, args=(pid, s), daemon=True)
                t.start(); self._threads.append(t)
            else:
                s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
            with self._lock:
                self._clients[pid] = s
                self._peers[pid] = info
            log.info("Connected to %s via %s.", pid, self._proto)
        except Exception as e:
            log.error("Failed to connect to %s: %s", pid, e)

    def disconnect_from_peer(self, pid: str):
        with self._lock:
            s = self._clients.pop(pid, None)
            self._peers.pop(pid, None)
        if s:
            try: s.close()
            except Exception: pass

    def send_message(self, pid: str, message: dict):
        with self._lock:
            s = self._clients.get(pid)
            info = self._peers.get(pid)
        if not s or not info:
            return
        try:
            if 'drone_id' not in message:
                message['drone_id'] = self._drone_id
            if self._proto == "TCP" and s.type == socket.SOCK_STREAM:
                s.sendall((json.dumps(message) + "\n").encode('utf-8'))
            else:
                s.sendto(json.dumps(message).encode('utf-8'), (info['ip'], info['udp_port']))
        except Exception as e:
            log.error("Error sending to %s: %s", pid, e)
            self.disconnect_from_peer(pid)

    # servers & readers
    def _tcp_server(self):
        srv = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        srv.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        try:
            srv.bind(('', self._tcp_port))
        except OSError as e:
            log.error("TCP bind failed: %s", e); return
        srv.listen(5); srv.settimeout(1.0)
        while self._running:
            try:
                c, addr = srv.accept()
                log.info("Accepted TCP connection from %s", addr)
                c.setsockopt(socket.SOL_SOCKET, socket.SO_KEEPALIVE, 1)
                try:
                    c.setsockopt(socket.IPPROTO_TCP, socket.TCP_KEEPIDLE, 5)
                    c.setsockopt(socket.IPPROTO_TCP, socket.TCP_KEEPINTVL, 3)
                    c.setsockopt(socket.IPPROTO_TCP, socket.TCP_KEEPCNT, 3)
                except (AttributeError, OSError): pass
                t = threading.Thread(target=self._tcp_reader, args=(None, c), daemon=True)
                t.start(); self._threads.append(t)
            except socket.timeout:
                continue
            except Exception as e:
                if self._running: log.error("TCP server error: %s", e)
        srv.close()

    def _tcp_reader(self, pid, c):
        buf = ""; identified = pid is not None
        while self._running:
            try:
                data = c.recv(4096)
                if not data: break
                buf += data.decode('utf-8', errors='ignore')
                while '\n' in buf:
                    line, buf = buf.split('\n', 1)
                    if not line: continue
                    msg = json.loads(line)
                    if not identified:
                        new_id = msg.get('drone_id')
                        if new_id:
                            with self._lock: self._clients[new_id] = c
                            identified = True; pid = new_id
                    self._queue.append(msg)
            except (ConnectionResetError, BrokenPipeError, OSError):
                break
            except Exception as e:
                log.error("TCP reader error (%s): %s", pid, e); break
        if pid: self.disconnect_from_peer(pid)
        try: c.close()
        except Exception: pass

    def _udp_server(self):
        srv = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        try:
            srv.bind(('', self._udp_port))
        except OSError as e:
            log.error("UDP bind failed: %s", e); return
        srv.settimeout(1.0)
        while self._running:
            try:
                data, _ = srv.recvfrom(4096)
                try:
                    self._queue.append(json.loads(data.decode('utf-8', errors='ignore')))
                except json.JSONDecodeError:
                    log.debug("Ignoring non-JSON UDP payload.")
            except socket.timeout:
                continue
            except Exception as e:
                if self._running: log.error("UDP server error: %s", e)
        srv.close()

    def _worker(self):
        while self._running:
            try:
                msg = self._queue.popleft()
                self._on_message(msg)
            except IndexError:
                time.sleep(0.01)
            except Exception as e:
                log.error("Worker error: %s", e)

# ---------- Controller ----------
class Controller:
    def __init__(self, drone_id: str, iface: str, ssid: str, channel: int,
                 tcp_port: int, udp_port: int, connect_protocol: str,
                 hb_interval: float, hb_timeout: float,
                 telemetry_hz: float):
        self.drone_id = drone_id
        self.iface = iface
        self.ssid = ssid
        self.channel = int(channel)
        self.tcp_port = int(tcp_port)
        self.udp_port = int(udp_port)
        self.connect_protocol = connect_protocol.upper()
        self.hb_interval = hb_interval
        self.hb_timeout = hb_timeout

        ip_end = self._ip_octet_from_id(drone_id)
        self.ip_base = "192.168.1."
        self.ip_cidr = f"{self.ip_base}{ip_end}/24"

        self.wext = WextAdhoc(iface, ssid, self.channel)
        self.gps = GpsCache(period_s=1.0, timeout_s=1.5)
        self.telemetry = TelemetryBroadcaster(drone_id, self.ip_cidr, TELEMETRY_PORT, telemetry_hz, self.gps, bind_iface=iface)
        self.discovery = Discovery(drone_id, iface, self.ip_cidr, self.tcp_port, self.udp_port, port=DISCOVERY_PORT)
        self.discovery.on_peer_discovered = self._on_peer
        self.cm = ConnectionManager(drone_id, self._on_message, self.tcp_port, self.udp_port, self.connect_protocol)

        self._discovered: Dict[str, dict] = {}
        self._last_rx: Dict[str, float] = {}  # last time we saw any message from peer
        self._lock = threading.Lock()
        self._app_running = False
        self._app_threads = []

    @staticmethod
    def _ip_octet_from_id(s: str) -> int:
        d = ''.join(filter(str.isdigit, s))
        return int(d) if d else (abs(hash(s)) % 200 + 20)

    def start(self) -> bool:
        log.info("--- Starting Swarm Controller for %s ---", self.drone_id)
        log.info("Step 1a: Bring up WEXT ad-hoc (join-or-create)...")
        if not self.wext.bring_up():
            log.critical("Ad-hoc bring-up failed.")
            return False
        log.info("Step 1b: Assign IP...")
        if not self.wext.add_ip(self.ip_cidr):
            log.critical("IP assignment failed."); return False

        log.info("Step 2: Start GPS + telemetry broadcaster...")
        self.gps.start()
        self.telemetry.start()

        log.info("Step 3: Start Connection Manager...")
        self.cm.start()

        log.info("Step 4: Start Discovery...")
        self.discovery.start()

        log.info("Step 5: Start app loops (status/heartbeat/prune)...")
        self._app_running = True
        for target in (self._status_broadcast_loop, self._heartbeat_loop, self._prune_loop, self._reconnect_loop):
            t = threading.Thread(target=target, daemon=True); t.start(); self._app_threads.append(t)

        log.info("--- Controller Running (proto=%s, hb=%ss/%ss) ---", self.connect_protocol, self.hb_interval, self.hb_timeout)
        return True

    def stop(self):
        log.info("--- Stopping Controller ---")
        self._app_running = False
        for t in self._app_threads: t.join(timeout=2.0)
        self.discovery.stop()
        self.cm.stop()
        self.telemetry.stop()
        self.gps.stop()
        self.wext.teardown()
        log.info("--- Stopped ---")

    # ----- Loops -----
    def _status_broadcast_loop(self):
        n = 0
        while self._app_running:
            time.sleep(10)
            n += 1
            with self._lock:
                targets = list(self._discovered.keys())
            for pid in targets:
                self.cm.send_message(pid, {"protocol": "STATUS", "seq": n})
            # (Telemetry broadcast is already continuous & independent.)

    def _heartbeat_loop(self):
        while self._app_running:
            time.sleep(self.hb_interval)
            # send PING to connected peers
            connected = self.cm.get_connected_peers()
            now = time.time()
            for pid in connected:
                self.cm.send_message(pid, {"protocol": "PING", "ts": now})
            # drop stale peers
            with self._lock:
                stale = [pid for pid in connected if (now - self._last_rx.get(pid, 0)) > self.hb_timeout]
            for pid in stale:
                log.warning("Peer %s heartbeat timed out (> %.1fs). Disconnecting.", pid, self.hb_timeout)
                self.cm.disconnect_from_peer(pid)

    def _prune_loop(self):
        while self._app_running:
            time.sleep(15)
            # Prune discovered entries that haven't refreshed via discovery beacons
            now = time.time()
            with self._lock:
                to_prune = [pid for pid, d in list(self._discovered.items()) if (now - d['last_seen']) > max(self.hb_timeout, 30)]
                for pid in to_prune:
                    self._discovered.pop(pid, None)
            for pid in to_prune:
                self.cm.disconnect_from_peer(pid)

    def _reconnect_loop(self):
        while self._app_running:
            time.sleep(7)
            with self._lock:
                peers = list(self._discovered.values())
            connected = set(self.cm.get_connected_peers())
            myn = id_num(self.drone_id)
            for d in peers:
                pid = d['info']['id']
                if pid in connected:
                    continue
                # Tie-break: only higher numeric id initiates
                if myn > id_num(pid):
                    self.cm.connect_to_peer(d['info'])

    # ----- Callbacks -----
    def _on_peer(self, info: dict):
        pid = info['id']
        with self._lock:
            self._discovered[pid] = {'info': info, 'last_seen': time.time()}
        self.cm.register_peer_info(info)
        log.info("Discovered peer %s at %s (tcp=%s udp=%s)", pid, info['ip'], info['tcp_port'], info['udp_port'])

    def _on_message(self, msg: dict):
        sender = msg.get('drone_id', 'Unknown')
        if sender == self.drone_id:
            return
        with self._lock:
            self._last_rx[sender] = time.time()
        proto = msg.get('protocol', 'N/A')
        if proto == "PING":
            # immediate PONG on same channel
            self.cm.send_message(sender, {"protocol": "PONG", "ts": time.time()})
            return
        # Log everything else
        log.info("RECV from %s via %s: %s", sender, proto, json.dumps(msg))

# ---------- CLI ----------
def main():
    ap = argparse.ArgumentParser(description="Swarm controller: WEXT ad-hoc + telemetry broadcast + discovery + TCP/UDP links")
    ap.add_argument('--drone-id', required=True, help='Unique ID (e.g., drone_1)')
    ap.add_argument('--interface', default=None, help='Wi-Fi interface (auto-detected if omitted)')
    ap.add_argument('--ssid', default='drone-swarm', help='Ad-Hoc ESSID to join/create')
    ap.add_argument('--channel', type=int, default=6, help='Channel (2.4 GHz recommended for WEXT ad-hoc)')
    ap.add_argument('--tcp-port', type=int, default=20000)
    ap.add_argument('--udp-port', type=int, default=20001)
    ap.add_argument('--connect-protocol', choices=['tcp', 'udp'], default='tcp', help='Transport for peer links')
    ap.add_argument('--hb-interval', type=float, default=3.0, help='Heartbeat interval seconds')
    ap.add_argument('--hb-timeout', type=float, default=12.0, help='Drop peer if no message seen for this many seconds')
    ap.add_argument('--telemetry-hz', type=float, default=1.0, help='Telemetry broadcast rate (Hz)')
    args = ap.parse_args()

    iface = args.interface or detect_wifi_interface()
    if not iface:
        log.critical("No Wi-Fi interface found. Pass --interface explicitly.")
        return

    ctrl = Controller(args.drone_id, iface, args.ssid, args.channel,
                      args.tcp_port, args.udp_port, args.connect_protocol,
                      args.hb_interval, args.hb_timeout,
                      args.telemetry_hz)
    try:
        if ctrl.start():
            while True:
                time.sleep(1)
    except KeyboardInterrupt:
        log.info("Shutdown initiated by user.")
    finally:
        ctrl.stop()

if __name__ == '__main__':
    main()
