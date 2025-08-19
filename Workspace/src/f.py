# universal_standalone_controller.py (hardened)
# Brings up peer-to-peer Wi-Fi using the best mode supported by the driver:
# 1) 802.11s mesh (nl80211 "mesh point"),
# 2) IBSS ad-hoc (nl80211),
# 3) Legacy ad-hoc (WEXT/iwconfig).
# Then runs UDP discovery + TCP/UDP comms (test/live).

import socket
import threading
import json
import time
import subprocess
import logging
import argparse
from collections import deque
import ipaddress

logging.basicConfig(level=logging.INFO,
                    format='%(asctime)s - %(name)s - %(levelname)s - %(message)s')
logger = logging.getLogger("DroneController")

# ---------- Helpers / RF tables ----------
CHAN_TO_FREQ_24 = {
    1:2412, 2:2417, 3:2422, 4:2427, 5:2432, 6:2437, 7:2442,
    8:2447, 9:2452, 10:2457, 11:2462, 12:2467, 13:2472
}
# Limit 5 GHz to commonly IBSS-initiable (U-NII-3) by default
CHAN_TO_FREQ_5 = {149:5745, 153:5765, 157:5785, 161:5805, 165:5825}

def detect_wifi_interface() -> str | None:
    try:
        out = subprocess.check_output(['iw', 'dev'], stderr=subprocess.DEVNULL).decode()
        for line in out.splitlines():
            line = line.strip()
            if line.startswith('Interface '):
                return line.split()[1]
    except Exception:
        pass
    try:
        out = subprocess.check_output(['nmcli', '-t', '-f', 'DEVICE,TYPE', 'device'],
                                      stderr=subprocess.DEVNULL).decode()
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

def ch_to_freq_mhz(ch: int) -> int:
    """Return frequency MHz for a given channel. Defaults to 2437 (ch 6) if unknown."""
    ch = int(ch)
    if ch in CHAN_TO_FREQ_24: return CHAN_TO_FREQ_24[ch]
    if ch in CHAN_TO_FREQ_5:  return CHAN_TO_FREQ_5[ch]
    return 2437  # safe default

def mesh_supported() -> bool:
    try:
        txt = subprocess.check_output(['iw', 'list'], stderr=subprocess.DEVNULL).decode()
        return ('Supported interface modes:' in txt) and ('* mesh point' in txt)
    except Exception:
        return False

def ibss_supported() -> bool:
    try:
        txt = subprocess.check_output(['iw', 'list'], stderr=subprocess.DEVNULL).decode()
        return ('Supported interface modes:' in txt) and ('* IBSS' in txt)
    except Exception:
        return False

# ---------- Discovery (radio bring-up + UDP peer discovery) ----------
class Discovery:
    def __init__(self, drone_id, tcp_port, udp_port, discovery_port=19999):
        self._drone_id = drone_id
        self._port = discovery_port
        self._tcp_port = tcp_port
        self._udp_port = udp_port
        self.on_peer_discovered = None
        self._running = True

        self.cfg = {
            "interface": "wlo1",            # overridden by controller
            "ssid": "drone-swarm",          # meshid or IBSS SSID
            "channel": 6,                   # channel; mapping handles freq
            "ip_base": "192.168.1.",
            "self_ip_ending": self._get_ip_ending_from_id(),
        }
        self._original_connection = self._get_active_connection()
        self._threads = []
        self.mode_used = None   # 'mesh' | 'ibss' | 'adhoc'

        # IP guard is kept but disabled by default (it can fight normal transitions)
        self._ip_guard_running = False
        self._ip_guard_thread = None

    # ----- helpers -----
    def _get_ip_ending_from_id(self):
        try:
            return str(int(''.join(filter(str.isdigit, self._drone_id))))
        except (ValueError, IndexError):
            return str(abs(hash(self._drone_id)) % 254 + 1)

    def _run_command(self, command):
        logger.info(f"Running command: {' '.join(command)}")
        try:
            p = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
            _, stderr = p.communicate()
            if p.returncode != 0:
                err = stderr.decode(errors='ignore').strip()
                if err:
                    logger.error(f"Command failed: {err}")
                return False
            return True
        except Exception as e:
            logger.error(f"Exception running command: {e}")
            return False

    def _get_active_connection(self):
        try:
            result = subprocess.check_output(
                ['nmcli', '-t', '-f', 'NAME,DEVICE', 'con', 'show', '--active'],
                stderr=subprocess.DEVNULL
            ).decode()
            for line in result.strip().split('\n'):
                if not line.strip(): continue
                name, dev = line.split(':')
                if dev == self.cfg["interface"]:
                    return name
        except Exception:
            return None
        return None

    # ----- radio bring-up variants -----
    def _prep_iface_unmanaged(self, iface):
        # Best-effort neutralize NM/supplicant and clear state; leave iface DOWN
        self._run_command(['sudo', 'nmcli', 'dev', 'disconnect', iface])
        self._run_command(['sudo', 'nmcli', 'dev', 'set', iface, 'managed', 'no'])
        self._run_command(['sudo', 'killall', 'wpa_supplicant'])
        # Leave any prior roles
        self._run_command(['sudo', 'iw', 'dev', iface, 'ibss', 'leave'])
        self._run_command(['sudo', 'iw', 'dev', iface, 'mesh', 'leave'])
        self._run_command(['sudo', 'ip', 'addr', 'flush', 'dev', iface])
        self._run_command(['sudo', 'ip', 'link', 'set', iface, 'down'])

    def setup_mesh(self):
        iface  = self.cfg["interface"]; ssid = self.cfg["ssid"]
        ch     = int(self.cfg["channel"]); freq = str(ch_to_freq_mhz(ch))
        logger.info("Configuring 802.11s mesh...")
        self._prep_iface_unmanaged(iface)
        if not self._run_command(['sudo', 'iw', 'dev', iface, 'set', 'type', 'mp']):
            logger.error("Driver refused mesh point mode."); return False
        if not self._run_command(['sudo', 'ip', 'link', 'set', iface, 'up']):
            logger.error(f"Failed to bring {iface} up."); return False
        subprocess.Popen(['sudo', 'iw', 'dev', iface, 'mesh', 'leave'],
                         stdout=subprocess.PIPE, stderr=subprocess.PIPE).communicate()
        if not self._run_command(['sudo', 'iw', 'dev', iface, 'mesh', 'join', ssid, 'freq', freq]):
            logger.error("Mesh join failed."); return False

        # Try to disable power saving (best effort)
        self._run_command(['sudo', 'iw', 'dev', iface, 'set', 'power_save', 'off'])
        self._run_command(['sudo', 'iwconfig', iface, 'power', 'off'])

        try:
            out = subprocess.check_output(['iw', 'dev', iface, 'link'], stderr=subprocess.DEVNULL).decode()
            if ('mesh' not in out) or (ssid not in out) or (f'freq: {freq}' not in out):
                logger.error("Mesh link not as expected:\n%s", out); return False
        except Exception:
            pass
        self.mode_used = 'mesh'; return True

    def setup_ibss(self):
        iface  = self.cfg["interface"]; ssid = self.cfg["ssid"]
        ch     = int(self.cfg["channel"]); freq = str(ch_to_freq_mhz(ch))
        logger.info("Configuring IBSS (nl80211)...")
        self._prep_iface_unmanaged(iface)

        # Ensure we're in the correct iftype
        self._run_command(['sudo', 'iw', 'dev', iface, 'ibss', 'leave'])
        self._run_command(['sudo', 'iw', 'dev', iface, 'mesh', 'leave'])
        self._run_command(['sudo', 'iw', 'dev', iface, 'set', 'type', 'ibss'])

        if not self._run_command(['sudo', 'ip', 'link', 'set', iface, 'up']):
            logger.error(f"Failed to bring {iface} up."); return False

        # Prefer HT20 for widest compatibility; fixed-freq optional
        if not self._run_command(['sudo', 'iw', 'dev', iface, 'ibss', 'join', ssid, freq, 'HT20']):
            logger.error("IBSS join failed."); return False

        # Power save off (matches stable broadcaster)
        self._run_command(['sudo', 'iw', 'dev', iface, 'set', 'power_save', 'off'])
        self._run_command(['sudo', 'iwconfig', iface, 'power', 'off'])

        try:
            out = subprocess.check_output(['iw', 'dev', iface, 'link'], stderr=subprocess.DEVNULL).decode()
            if ('IBSS' not in out) or (ssid not in out) or (f'freq: {freq}' not in out):
                logger.error("IBSS link not as expected:\n%s", out); return False
        except Exception:
            pass
        self.mode_used = 'ibss'; return True

    def setup_adhoc_wext(self):
        iface  = self.cfg["interface"]; ssid = self.cfg["ssid"]
        ch     = int(self.cfg["channel"])
        logger.info("Configuring legacy ad-hoc (WEXT/iwconfig)...")
        self._prep_iface_unmanaged(iface)
        ok = True
        ok &= self._run_command(['sudo', 'iwconfig', iface, 'mode', 'ad-hoc'])
        ok &= self._run_command(['sudo', 'iwconfig', iface, 'essid', ssid])
        ok &= self._run_command(['sudo', 'iwconfig', iface, 'channel', str(ch)])
        ok &= self._run_command(['sudo', 'ip', 'link', 'set', iface, 'up'])
        if not ok:
            logger.error("WEXT ad-hoc bring-up failed."); return False

        # Power save off (best effort)
        self._run_command(['sudo', 'iw', 'dev', iface, 'set', 'power_save', 'off'])
        self._run_command(['sudo', 'iwconfig', iface, 'power', 'off'])

        time.sleep(0.3)
        try:
            out = subprocess.check_output(['iwconfig', iface], stderr=subprocess.DEVNULL).decode()
            if ('Mode:Ad-Hoc' not in out) or (f'ESSID:"{ssid}"' not in out):
                logger.error("WEXT state not as expected:\n%s", out); return False
        except Exception:
            pass
        self.mode_used = 'adhoc'; return True

    def setup_radio(self, preference: str = 'auto') -> bool:
        """Bring up the best available peer-to-peer mode; set self.mode_used."""
        iface = self.cfg["interface"]
        if preference == 'mesh':
            if not mesh_supported():
                logger.critical("Mesh requested but not supported by driver."); return False
            return self.setup_mesh()
        if preference == 'ibss':
            if ibss_supported():
                return self.setup_ibss()
            logger.warning("IBSS (nl80211) not supported, falling back to legacy ad-hoc.")
            return self.setup_adhoc_wext()
        if preference == 'adhoc':
            return self.setup_adhoc_wext()

        # auto
        if mesh_supported():
            if self.setup_mesh(): return True
        if ibss_supported():
            if self.setup_ibss(): return True
        return self.setup_adhoc_wext()

    # ----- IP handling / teardown -----
    def _assign_ip_address(self):
        logger.info("Assigning IP address...")
        ip_address = f"{self.cfg['ip_base']}{self.cfg['self_ip_ending']}/24"
        iface = self.cfg["interface"]
        if not self._run_command(['sudo', 'ip', 'addr', 'add', ip_address, 'dev', iface]):
            logger.error(f"Failed to assign IP {ip_address} to {iface}."); return False
        logger.info(f"Assigned IP {ip_address} to {iface}."); return True

    def _ip_guard(self):
        """Disabled by default to avoid fighting normal transitions."""
        iface = self.cfg["interface"]
        own_ip = f"{self.cfg['ip_base']}{self.cfg['self_ip_ending']}"
        cidr = f"{own_ip}/24"
        miss_count = 0
        while self._ip_guard_running:
            time.sleep(3)
            try:
                out = subprocess.check_output(['ip', '-br', 'addr', 'show', iface],
                                              stderr=subprocess.DEVNULL).decode()
                if own_ip not in out:
                    miss_count += 1
                    if miss_count >= 3:
                        logger.warning("IP vanished from %s; re-adding %s", iface, cidr)
                        self._run_command(['sudo', 'ip', 'addr', 'add', cidr, 'dev', iface])
                        miss_count = 0
                else:
                    miss_count = 0
            except Exception:
                pass

    def start_threads(self):
        logger.info(f"Starting discovery threads on port {self._port}...")
        self._running = True
        t1 = threading.Thread(target=self._broadcast_presence, daemon=True)
        t2 = threading.Thread(target=self._listen_for_peers, daemon=True)
        self._threads.extend([t1, t2])
        t1.start(); t2.start()
        # IP guard intentionally not started by default

    def stop_threads(self):
        if not self._running: return
        logger.info("Stopping discovery threads...")
        self._running = False
        try:
            with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
                s.sendto(b'stop', ('127.0.0.1', self._port))
        except Exception:
            pass
        for t in self._threads: t.join(timeout=2.0)
        self._threads.clear()
        self._ip_guard_running = False
        if self._ip_guard_thread: self._ip_guard_thread.join(timeout=1.0)
        logger.info("Discovery threads stopped.")

    def teardown_radio(self):
        """Restore NIC to managed Wi-Fi and try to reconnect to the previous AP."""
        logger.info("Restoring original network state...")
        iface = self.cfg["interface"]
        # best-effort leave
        if self.mode_used == 'mesh':
            subprocess.Popen(['sudo', 'iw', 'dev', iface, 'mesh', 'leave'],
                             stdout=subprocess.PIPE, stderr=subprocess.PIPE).communicate()
        elif self.mode_used == 'ibss':
            subprocess.Popen(['sudo', 'iw', 'dev', iface, 'ibss', 'leave'],
                             stdout=subprocess.PIPE, stderr=subprocess.PIPE).communicate()
        # common cleanup
        self._run_command(['sudo', 'ip', 'addr', 'flush', 'dev', iface])
        self._run_command(['sudo', 'ip', 'link', 'set', iface, 'down'])
        if not self._run_command(['sudo', 'iw', 'dev', iface, 'set', 'type', 'managed']):
            self._run_command(['sudo', 'iwconfig', iface, 'mode', 'managed'])
        self._run_command(['sudo', 'nmcli', 'dev', 'set', iface, 'managed', 'yes'])
        # do NOT restart NetworkManager mid-run; just bring it back up cleanly
        self._run_command(['nmcli', 'radio', 'wifi', 'on'])
        self._run_command(['sudo', 'ip', 'link', 'set', iface, 'up'])
        time.sleep(2)
        if self._original_connection:
            logger.info(f"Attempting to reconnect to '{self._original_connection}'...")
            self._run_command(['nmcli', 'con', 'up', 'id', self._original_connection])
        else:
            logger.warning("No known previous connection to restore.")

    # ----- UDP discovery -----
    def _broadcast_presence(self):
        own_ip = f"{self.cfg['ip_base']}{self.cfg['self_ip_ending']}"
        bcast_ip = str(ipaddress.IPv4Interface(f"{own_ip}/24").network.broadcast_address)
        payload = {"id": self._drone_id, "ip": own_ip,
                   "tcp_port": self._tcp_port, "udp_port": self._udp_port}
        msg = json.dumps(payload).encode("utf-8")

        sock_subnet = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        sock_subnet.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)

        try:
            while self._running:
                try:
                    sock_subnet.sendto(msg, (bcast_ip, self._port))
                except OSError as e:
                    logger.error(f"Subnet broadcast to {bcast_ip}:{self._port} failed: {e}")
                time.sleep(1)
        finally:
            sock_subnet.close()

    def _listen_for_peers(self):
        with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as sock:
            sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
            try:
                sock.bind(('', self._port))
            except socket.error as e:
                logger.error(f"Socket bind failed on port {self._port}: {e}")
                return
            sock.settimeout(1.0)
            while self._running:
                try:
                    data, addr = sock.recvfrom(1024)
                    message = json.loads(data.decode())
                    peer_id = message.get("id")
                    if peer_id and message.get("ip") and peer_id != self._drone_id:
                        if self.on_peer_discovered:
                            self.on_peer_discovered(message)
                except socket.timeout:
                    continue
                except Exception:
                    if not self._running: break

# ---------- Connection Manager ----------
class ConnectionManager:
    def __init__(self, drone_id, on_message_received_callback, tcp_port, udp_port,
                 discovered_peers_ref, bind_iface: str | None = None):
        self._drone_id = drone_id
        self.on_message_received = on_message_received_callback
        self._tcp_port = tcp_port
        self._udp_port = udp_port
        self._discovered_peers = discovered_peers_ref
        self._running = True
        self._threads = []
        self._clients = {}
        self._peers = {}
        self.message_queue = deque()
        self._lock = threading.Lock()
        self._bind_iface = bind_iface  # retained for compatibility; not used to bind sockets

    def start(self):
        logger.info(f"Starting connection manager for {self._drone_id}")
        self._running = True
        for target in (self._tcp_server_loop, self._udp_server_loop, self._process_message_queue):
            t = threading.Thread(target=target, daemon=True)
            t.start(); self._threads.append(t)

    def stop(self):
        if not self._running: return
        logger.info("Stopping connection manager...")
        self._running = False
        with self._lock:
            for _, s in list(self._clients.items()):
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
        logger.info("Connection manager stopped.")

    def get_connected_peers(self):
        with self._lock: return list(self._clients.keys())

    def broadcast_message(self, message_dict):
        with self._lock: peers = list(self._peers.items())
        if not peers:
            logger.debug("Broadcast requested, but no peers are registered."); return
        logger.info(f"Broadcasting message to {len(peers)} peers.")
        for peer_id, info in peers:
            self.send_message(info, message_dict)

    def connect_to_peer(self, peer_info: dict, protocol="TCP"):
        peer_id = peer_info['id']
        with self._lock:
            if peer_id in self._clients: return
            logger.info(f"Connecting to {peer_id} at {peer_info['ip']} via {protocol}...")
            try:
                if protocol == "TCP":
                    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                    sock.setsockopt(socket.SOL_SOCKET, socket.SO_KEEPALIVE, 1)
                    # TCP keepalive knobs (best-effort)
                    try:
                        sock.setsockopt(socket.IPPROTO_TCP, socket.TCP_KEEPIDLE, 5)
                        sock.setsockopt(socket.IPPROTO_TCP, socket.TCP_KEEPINTVL, 3)
                        sock.setsockopt(socket.IPPROTO_TCP, socket.TCP_KEEPCNT, 3)
                    except (AttributeError, OSError):
                        pass
                    sock.settimeout(3.0)
                    sock.connect((peer_info['ip'], peer_info['tcp_port']))
                    sock.settimeout(None)
                    hello = {"protocol": "HELLO", "drone_id": self._drone_id}
                    sock.sendall((json.dumps(hello) + "\n").encode("utf-8"))
                    t = threading.Thread(target=self._handle_tcp_receive, args=(peer_id, sock), daemon=True)
                    t.start(); self._threads.append(t)
                else:
                    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
                self._clients[peer_id] = sock
                self._peers[peer_id] = peer_info
                logger.info(f"Connected to {peer_id} via {protocol}.")
            except Exception as e:
                logger.error(f"Failed to connect to {peer_id}: {e}")

    def disconnect_from_peer(self, peer_id):
        with self._lock:
            if peer_id in self._clients:
                logger.info(f"Disconnecting from peer {peer_id}.")
                try: self._clients[peer_id].close()
                except Exception: pass
                finally:
                    self._clients.pop(peer_id, None)
                    self._peers.pop(peer_id, None)

    def send_message(self, peer_info: dict, message_dict: dict):
        peer_id = peer_info['id']
        with self._lock: sock = self._clients.get(peer_id)
        if not sock: return
        try:
            protocol = "TCP" if sock.type == socket.SOCK_STREAM else "UDP"
            if 'drone_id' not in message_dict: message_dict['drone_id'] = self._drone_id
            payload = (json.dumps(message_dict) + ('\n' if protocol == "TCP" else '')).encode('utf-8')
            if protocol == "TCP":
                sock.sendall(payload)
            else:
                sock.sendto(payload, (peer_info['ip'], peer_info['udp_port']))
        except Exception as e:
            logger.error(f"Error sending message to {peer_id}: {e}")
            self._handle_disconnection(peer_id)

    def _handle_disconnection(self, peer_id):
        logger.warning(f"Peer {peer_id} disconnected unexpectedly.")
        self.disconnect_from_peer(peer_id)

    def _tcp_server_loop(self):
        server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        try:
            server.bind(('', self._tcp_port))
        except OSError as e:
            logger.error(f"TCP server bind failed on port {self._tcp_port}: {e}"); return
        server.listen(5); server.settimeout(1.0)
        logger.info(f"TCP server listening on port {self._tcp_port}")
        while self._running:
            try:
                client, addr = server.accept()
                logger.info(f"Accepted TCP connection from {addr}")
                client.setsockopt(socket.SOL_SOCKET, socket.SO_KEEPALIVE, 1)
                try:
                    client.setsockopt(socket.IPPROTO_TCP, socket.TCP_KEEPIDLE, 5)
                    client.setsockopt(socket.IPPROTO_TCP, socket.TCP_KEEPINTVL, 3)
                    client.setsockopt(socket.IPPROTO_TCP, socket.TCP_KEEPCNT, 3)
                except (AttributeError, OSError):
                    pass
                t = threading.Thread(target=self._handle_tcp_receive, args=(None, client), daemon=True)
                t.start(); self._threads.append(t)
            except socket.timeout:
                continue
            except Exception as e:
                if self._running: logger.error(f"TCP Server error: {e}")
        server.close()

    def _handle_tcp_receive(self, peer_id, client_socket):
        buffer = ""
        is_identified = peer_id is not None
        client_socket.settimeout(None)
        while self._running:
            try:
                data = client_socket.recv(4096)
                if not data: break
                buffer += data.decode('utf-8', errors='ignore')
                while '\n' in buffer:
                    message_json, buffer = buffer.split('\n', 1)
                    if not message_json: continue
                    message = json.loads(message_json)
                    if not is_identified:
                        with self._lock:
                            pid = message.get('drone_id')
                            if pid:
                                self._clients[pid] = client_socket
                                peer_full = self._discovered_peers.get(pid)
                                if peer_full: self._peers[pid] = peer_full
                                else: logger.warning(f"Incoming TCP peer {pid} not in discovered list.")
                                is_identified = True; peer_id = pid
                    self.message_queue.append(message)
            except (ConnectionResetError, BrokenPipeError, OSError):
                break
            except Exception as e:
                logger.error(f"Error handling TCP client {peer_id}: {e}"); break
        if peer_id: self._handle_disconnection(peer_id)
        try: client_socket.close()
        except Exception: pass

    def _udp_server_loop(self):
        server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        server.bind(('', self._udp_port)); server.settimeout(1.0)
        logger.info(f"UDP server listening on port {self._udp_port}")
        while self._running:
            try:
                data, addr = server.recvfrom(4096)
                try:
                    message = json.loads(data.decode('utf-8', errors='ignore'))
                    self.message_queue.append(message)
                except json.JSONDecodeError:
                    logger.debug(f"Received non-JSON UDP data from {addr}, ignoring.")
            except socket.timeout:
                continue
            except Exception as e:
                if self._running: logger.error(f"UDP Server error: {e}")
        server.close()

    def _process_message_queue(self):
        while self._running:
            try:
                message = self.message_queue.popleft()
                self.on_message_received(message)
            except IndexError:
                time.sleep(0.01)
            except Exception as e:
                logger.error(f"Error processing message queue: {e}")

# ---------- Controller ----------
class DroneController:
    def __init__(self, drone_id, interface, ssid, tcp_port, udp_port, should_setup_net,
                 mode: str, channel: int, radio_mode: str):
        self.drone_id = drone_id
        self.should_setup_net = should_setup_net
        self.mode = mode  # 'test' or 'live'
        self.discovered_peers = {}
        self.tested_peers = set()
        self._app_running = True
        self._app_threads = []
        self.PEER_TIMEOUT = 20

        self.discovery = Discovery(drone_id, tcp_port, udp_port)
        self.discovery.cfg["interface"] = interface
        self.discovery.cfg["ssid"] = ssid
        self.discovery.cfg["channel"] = channel
        self.discovery.on_peer_discovered = self._handle_peer_discovery
        self.radio_mode = radio_mode

        class PeerInfoView:
            def __init__(self, full_peer_dict, lock):
                self._source = full_peer_dict
                self._lock = lock
            def get(self, key):
                with self._lock: peer_data = self._source.get(key)
                return peer_data['info'] if peer_data else None
            def __contains__(self, key):
                with self._lock: return key in self._source

        self._discovered_lock = threading.Lock()
        self.connection_manager = ConnectionManager(
            self.drone_id, self._handle_message_received,
            tcp_port, udp_port,
            PeerInfoView(self.discovered_peers, self._discovered_lock),
            bind_iface=interface,
        )

    def start(self):
        logger.info(f"--- Starting Drone Controller for {self.drone_id} ---")
        logger.info("Step 1a: Bringing up peer-to-peer radio...")
        if not self.discovery.setup_radio(self.radio_mode):
            logger.critical("Radio bring-up failed. Aborting.")
            self.discovery.teardown_radio(); return False

        logger.info("Step 1b: Assigning self IP address...")
        if not self.discovery._assign_ip_address():
            logger.critical("Could not assign IP address. Aborting."); return False

        time.sleep(1.0)
        logger.info("Step 2: Starting Connection Manager..."); self.connection_manager.start()
        logger.info("Step 3: Starting Discovery Service..."); self.discovery.start_threads()

        logger.info("Step 4: Starting Application Logic Threads...")
        self._app_running = True
        for target in (self._prune_peers_loop, self._periodic_reconnection_check,
                       self._periodic_status_broadcast, self._heartbeat_loop):
            t = threading.Thread(target=target, daemon=True); t.start(); self._app_threads.append(t)

        logger.info(f"--- Controller is Running (mode_used={self.discovery.mode_used}) ---")
        return True

    def stop(self):
        logger.info(f"--- Stopping Drone Controller for {self.drone_id} ---")
        logger.info("Step 1: Stopping Application Logic Threads...")
        self._app_running = False
        for t in self._app_threads: t.join(timeout=2.0)

        logger.info("Step 2: Stopping Discovery Service..."); self.discovery.stop_threads()
        logger.info("Step 3: Stopping Connection Manager..."); self.connection_manager.stop()

        if self.should_setup_net or not self.discovered_peers:
            logger.info("Tearing down radio."); self.discovery.teardown_radio()
        else:
            logger.info(f"Leaving radio up for {len(self.discovered_peers)} other peer(s).")

        logger.info("--- Controller Stopped ---")

    def _prune_peers_loop(self):
        while self._app_running:
            time.sleep(10)
            now = time.time()
            with self._discovered_lock:
                peers_to_prune = [pid for pid, data in list(self.discovered_peers.items())
                                  if now - data['last_seen'] > self.PEER_TIMEOUT]
                for pid in peers_to_prune:
                    logger.info(f"Peer {pid} timed out. Removing from discovered list.")
                    self.discovered_peers.pop(pid, None)
            # also disconnect pruned peers
            for pid in peers_to_prune:
                self.connection_manager.disconnect_from_peer(pid)

    def _handle_peer_discovery(self, peer_info: dict):
        peer_id = peer_info['id']
        with self._discovered_lock:
            self.discovered_peers[peer_id] = {'info': peer_info, 'last_seen': time.time()}

        if self.mode == 'test':
            if peer_id not in self.tested_peers:
                self.tested_peers.add(peer_id)
                if id_num(self.drone_id) > id_num(peer_id):
                    logger.info(f"New peer '{peer_id}' discovered. Initiating test sequence.")
                    t = threading.Thread(target=self._run_comm_sequence, args=(peer_info,), daemon=True)
                    t.start()
                else:
                    logger.info(f"New peer '{peer_id}' discovered. Waiting for their connection.")
        else:  # live
            if id_num(self.drone_id) > id_num(peer_id):
                self.connection_manager.connect_to_peer(peer_info, protocol="TCP")

    def _periodic_reconnection_check(self):
        while self._app_running:
            time.sleep(15)
            with self._discovered_lock:
                peers_to_check = list(self.discovered_peers.items())
            connected = set(self.connection_manager.get_connected_peers())
            for peer_id, data in peers_to_check:
                if peer_id not in connected:
                    if id_num(self.drone_id) > id_num(peer_id):
                        logger.info(f"Peer '{peer_id}' not connected. Attempting TCP connection.")
                        self.connection_manager.connect_to_peer(data['info'], protocol="TCP")

    def _periodic_status_broadcast(self):
        pkg = 0
        while self._app_running:
            time.sleep(10)
            if not self._app_running: break
            pkg += 1
            self.connection_manager.broadcast_message({
                "protocol": "STATUS_BROADCAST",
                "package_number": pkg,
                "energy_level": 98.5,
                "position": {"x": 1.0, "y": 2.0, "z": 3.0}
            })

    def _heartbeat_loop(self):
        while self._app_running:
            time.sleep(5)
            self.connection_manager.broadcast_message({"protocol": "PING", "ts": time.time()})

    def _handle_message_received(self, message):
        sender = message.get('drone_id', 'Unknown')
        if sender == self.drone_id: return
        proto = message.get('protocol', 'N/A')
        if proto == "PING":
            peer = self.connection_manager._peers.get(sender)
            if peer:
                self.connection_manager.send_message(peer, {"protocol": "PONG"})
            return
        logger.info(f"RECEIVED from {sender} via {proto}: {json.dumps(message)}")

    def _run_comm_sequence(self, peer_info: dict):
        peer_id = peer_info['id']
        try:
            logger.info(f"[{peer_id}] === Starting UDP Test ===")
            self.connection_manager.connect_to_peer(peer_info, protocol="UDP"); time.sleep(1)
            for i in range(3):
                self.connection_manager.send_message(peer_info, {"protocol": "UDP_TEST", "count": i + 1}); time.sleep(0.5)
            self.connection_manager.disconnect_from_peer(peer_id); time.sleep(1)
            logger.info(f"[{peer_id}] === Starting TCP Test ===")
            self.connection_manager.connect_to_peer(peer_info, protocol="TCP"); time.sleep(1)
            for i in range(3):
                self.connection_manager.send_message(peer_info, {"protocol": "TCP_TEST", "count": i + 1}); time.sleep(0.5)
            logger.info(f"[{peer_id}] === Initial communication test finished. TCP connection will be maintained. ===")
        except Exception as e:
            logger.error(f"Error in communication sequence with {peer_id}: {e}", exc_info=True)

# ---------- Entry ----------
def main():
    parser = argparse.ArgumentParser(description='Universal Standalone Drone Controller (mesh/ibss/adhoc auto)')
    parser.add_argument('--drone-id', required=True, help='Unique ID for this drone (e.g., drone_1)')
    parser.add_argument('--interface', default=None, help='Wireless interface (e.g., wlp1s0). Auto-detected if omitted.')
    parser.add_argument('--ssid', default='drone-swarm', help='Mesh ID or IBSS SSID')
    parser.add_argument('--channel', type=int, default=6, help='Channel (2.4 GHz typical; U-NII-3 only for 5 GHz IBSS).')
    parser.add_argument('--tcp-port', type=int, default=20000, help='TCP port (default: 20000)')
    parser.add_argument('--udp-port', type=int, default=20001, help='UDP port (default: 20001)')
    parser.add_argument('--setup-net', action='store_true', help='Restore managed Wi-Fi on exit.')
    parser.add_argument('--mode', choices=['test', 'live'], default='test',
                        help='test = run UDP/TCP self-test; live = persistent links')
    parser.add_argument('--radio-mode', choices=['auto','mesh','ibss','adhoc'], default='auto',
                        help='Preferred radio mode. auto=try mesh→ibss→adhoc (WEXT).')
    args = parser.parse_args()

    iface = args.interface or detect_wifi_interface()
    if not iface:
        logger.critical("No Wi-Fi interface found. Pass --interface explicitly."); return

    controller = DroneController(
        args.drone_id, iface, args.ssid, args.tcp_port, args.udp_port,
        args.setup_net, args.mode, args.channel, args.radio_mode
    )

    try:
        if controller.start():
            while True: time.sleep(1)
    except KeyboardInterrupt:
        logger.info("Shutdown initiated by user.")
    finally:
        controller.stop()

if __name__ == "__main__":
    main()
