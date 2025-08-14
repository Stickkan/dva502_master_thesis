# enhanced_standalone_controller_hybrid.py

from html import parser
import socket
import threading
import json
import time
import subprocess
import logging
import argparse
from collections import deque
import ipaddress
import os

logging.basicConfig(level=logging.INFO,
                    format='%(asctime)s - %(name)s - %(levelname)s - %(message)s')
logger = logging.getLogger("DroneController")

# -------- Utilities --------
def detect_wifi_interface() -> str | None:
    """Best-effort detection of a Wi-Fi NIC."""
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
    digits = ''.join(filter(str.isdigit, s))
    return int(digits) if digits else 0

# -------- Discovery --------
class Discovery:
    def __init__(self, drone_id, tcp_port, udp_port, discovery_port=19999):
        self._drone_id = drone_id
        self._port = discovery_port
        self._tcp_port = tcp_port
        self._udp_port = udp_port
        self.on_peer_discovered = None
        self._running = True

        self.adhoc_config = {
            "interface": "wlo1",     # will be overridden by controller
            "ssid": "drone-swarm-net",
            "channel": 6,            # 2.4 GHz ch 6 (2437 MHz)
            "ip_base": "192.168.1.",
            "self_ip_ending": self._get_ip_ending_from_id(),
        }
        self._original_connection = self._get_active_connection()
        self._threads = []

    def _get_ip_ending_from_id(self):
        try:
            return str(int(''.join(filter(str.isdigit, self._drone_id))))
        except (ValueError, IndexError):
            return str(abs(hash(self._drone_id)) % 254 + 1)

    def _run_command(self, command):
        logger.info(f"Running command: {' '.join(command)}")
        try:
            proc = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
            stdout, stderr = proc.communicate()
            if proc.returncode != 0:
                err = stderr.decode(errors='ignore').strip()
                if err:
                    logger.error(f"Command failed: {err}")
                return False
            return True
        except Exception as e:
            logger.error(f"Exception running command: {e}")
            return False

    def _wait_nm_running(self, timeout=8):
        t0 = time.time()
        while time.time() - t0 < timeout:
            try:
                out = subprocess.check_output(
                    ['nmcli', '-t', '-f', 'RUNNING', 'general', 'status'],
                    stderr=subprocess.DEVNULL
                ).decode().strip()
                if out == 'running':
                    return True
            except Exception:
                pass
            time.sleep(0.2)
        return False

    def setup_adhoc_network(self):
        """Bring NIC to IBSS on a fixed frequency; robust sequence with fallback."""
        logger.info("Configuring ad-hoc (IBSS) network...")
        iface = self.adhoc_config["interface"]
        ssid = self.adhoc_config["ssid"]
        channel = int(self.adhoc_config.get("channel", 6))
        freq_mhz = str({1:2412,6:2437,11:2462}.get(channel, 2437))

        # Ensure NM is responsive (non-fatal if not)
        self._wait_nm_running()

        steps = [
            ['sudo', 'nmcli', 'dev', 'disconnect', iface],            # non-fatal
            ['sudo', 'nmcli', 'dev', 'set', iface, 'managed', 'no'],  # non-fatal if already unmanaged
            ['sudo', 'ip', 'link', 'set', iface, 'down'],
            ['sudo', 'ip', 'addr', 'flush', 'dev', iface],
        ]
        for cmd in steps:
            ok = self._run_command(cmd)
            if not ok and cmd[:4] == ['sudo', 'nmcli', 'dev', 'disconnect']:
                logger.warning("Non-fatal: device already disconnected.")
            elif not ok and cmd[:5] == ['sudo', 'nmcli', 'dev', 'set', iface, 'managed']:
                logger.warning("Non-fatal: device already unmanaged.")
            elif not ok:
                logger.critical(f"A critical setup command failed: {' '.join(cmd)}.")
                return False
            time.sleep(0.2)

        # Preferred: modern iw ibss join with fixed frequency
        if self._run_command(['sudo', 'iw', 'dev', iface, 'ibss', 'join', ssid, freq_mhz, 'HT20', 'fixed-freq']):
            logger.info(f"Joined IBSS '{ssid}' on {iface} @ {freq_mhz} MHz (HT20).")
        else:
            logger.warning("iw ibss join failed; falling back to iwconfig (legacy).")
            legacy = [
                ['sudo', 'iwconfig', iface, 'mode', 'ad-hoc'],
                ['sudo', 'iwconfig', iface, 'essid', ssid],
                ['sudo', 'iwconfig', iface, 'channel', str(channel)],
            ]
            for cmd in legacy:
                if not self._run_command(cmd):
                    logger.critical(f"Legacy ad-hoc setup failed: {' '.join(cmd)}.")
                    return False
                time.sleep(0.2)

        if not self._run_command(['sudo', 'ip', 'link', 'set', iface, 'up']):
            logger.critical(f"Failed to set {iface} up.")
            return False

        # Power-save toggles are best-effort; many drivers N/A in IBSS
        for pcmd in (
            ['sudo', 'iw', 'dev', iface, 'set', 'power_save', 'off'],
            ['sudo', 'iwconfig', iface, 'power', 'off'],
        ):
            if self._run_command(pcmd):
                logger.info("Disabled Wi-Fi power saving.")
                break
        return True

    def _assign_ip_address(self):
        logger.info("Assigning IP address...")
        ip_address = f"{self.adhoc_config['ip_base']}{self.adhoc_config['self_ip_ending']}/24"
        iface = self.adhoc_config["interface"]
        if not self._run_command(['sudo', 'ip', 'addr', 'add', ip_address, 'dev', iface]):
            logger.error(f"Failed to assign IP {ip_address} to {iface}.")
            return False
        logger.info(f"Assigned IP {ip_address} to {iface}.")
        return True

    def teardown_adhoc_network(self):
        """Return NIC to managed mode and bring NetworkManager/wpa_supplicant back."""
        logger.info("Restoring original network state...")
        iface = self.adhoc_config["interface"]

        # Leave IBSS and flush state
        self._run_command(['sudo', 'ip', 'addr', 'flush', 'dev', iface])
        self._run_command(['sudo', 'ip', 'link', 'set', iface, 'down'])

        # Put device back to managed mode (try iw then legacy)
        if not self._run_command(['sudo', 'iw', 'dev', iface, 'set', 'type', 'managed']):
            self._run_command(['sudo', 'iwconfig', iface, 'mode', 'managed'])

        # Hand control back to NetworkManager and restart it
        self._run_command(['sudo', 'nmcli', 'dev', 'set', iface, 'managed', 'yes'])
        self._run_command(['sudo', 'systemctl', 'restart', 'NetworkManager'])
        time.sleep(3)
        self._run_command(['nmcli', 'radio', 'wifi', 'on'])
        self._run_command(['sudo', 'ip', 'link', 'set', iface, 'up'])
        time.sleep(2)

        if self._original_connection:
            logger.info(f"Attempting to reconnect to '{self._original_connection}'...")
            # nmcli up often works fine without sudo
            self._run_command(['nmcli', 'con', 'up', 'id', self._original_connection])
        else:
            logger.warning("No known previous connection to restore.")

    def start_threads(self):
        logger.info(f"Starting discovery threads on port {self._port}...")
        self._running = True
        t1 = threading.Thread(target=self._broadcast_presence, daemon=True)
        t2 = threading.Thread(target=self._listen_for_peers, daemon=True)
        self._threads.extend([t1, t2])
        t1.start(); t2.start()

    def stop_threads(self):
        if not self._running:
            return
        logger.info("Stopping discovery threads...")
        self._running = False
        try:
            with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
                s.sendto(b'stop', ('127.0.0.1', self._port))
        except Exception:
            pass
        for t in self._threads:
            t.join(timeout=2.0)
        self._threads.clear()
        logger.info("Discovery threads stopped.")

    def _get_active_connection(self):
        try:
            result = subprocess.check_output(
                ['nmcli', '-t', '-f', 'NAME,DEVICE', 'con', 'show', '--active'],
                stderr=subprocess.DEVNULL
            ).decode()
            for line in result.strip().split('\n'):
                if not line.strip():
                    continue
                name, dev = line.split(':')
                if dev == self.adhoc_config["interface"]:
                    return name
        except Exception:
            return None
        return None

    def _broadcast_presence(self):
        iface = self.adhoc_config["interface"]
        own_ip = f"{self.adhoc_config['ip_base']}{self.adhoc_config['self_ip_ending']}"
        bcast_ip = str(ipaddress.IPv4Interface(f"{own_ip}/24").network.broadcast_address)

        payload = {
            "id": self._drone_id,
            "ip": own_ip,
            "tcp_port": self._tcp_port,
            "udp_port": self._udp_port,
        }
        msg = json.dumps(payload).encode("utf-8")

        sock_subnet = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        sock_subnet.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)

        sock_limited = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        sock_limited.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
        try:
            # bind so kernel has a route for 255.255.255.255
            sock_limited.bind((own_ip, 0))
            limited_ok = True
        except OSError as e:
            logger.debug(f"Limited-broadcast bind skipped ({e}); using subnet only.")
            limited_ok = False

        try:
            while self._running:
                try:
                    sock_subnet.sendto(msg, (bcast_ip, self._port))
                except OSError as e:
                    logger.error(f"Subnet broadcast to {bcast_ip}:{self._port} failed: {e}")
                if limited_ok:
                    try:
                        sock_limited.sendto(msg, ("255.255.255.255", self._port))
                    except OSError as e:
                        logger.debug(f"Limited broadcast failed: {e}")
                time.sleep(1)
        finally:
            sock_subnet.close()
            sock_limited.close()

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
                    if not self._running:
                        break

# -------- Connection Manager --------
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
        self._bind_iface = bind_iface

    def start(self):
        logger.info(f"Starting connection manager for {self._drone_id}")
        self._running = True
        for target in (self._tcp_server_loop, self._udp_server_loop, self._process_message_queue):
            t = threading.Thread(target=target, daemon=True)
            t.start()
            self._threads.append(t)

    def stop(self):
        if not self._running:
            return
        logger.info("Stopping connection manager...")
        self._running = False
        with self._lock:
            for _, client_socket in list(self._clients.items()):
                try:
                    client_socket.close()
                except Exception:
                    pass
        try:
            socket.create_connection(('127.0.0.1', self._tcp_port), timeout=0.5).close()
            with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
                s.sendto(b'stop', ('127.0.0.1', self._udp_port))
        except Exception:
            pass
        for t in self._threads:
            t.join(timeout=2.0)
        self._threads.clear()
        logger.info("Connection manager stopped.")

    def get_connected_peers(self):
        with self._lock:
            return list(self._clients.keys())

    def broadcast_message(self, message_dict):
        with self._lock:
            peers_to_broadcast = list(self._peers.items())
        if not peers_to_broadcast:
            logger.debug("Broadcast requested, but no peers are registered.")
            return
        logger.info(f"Broadcasting message to {len(peers_to_broadcast)} peers.")
        for peer_id, peer_info in peers_to_broadcast:
            self.send_message(peer_info, message_dict)

    def connect_to_peer(self, peer_info: dict, protocol="TCP"):
        peer_id = peer_info['id']
        with self._lock:
            if peer_id in self._clients:
                return
            logger.info(f"Connecting to {peer_id} at {peer_info['ip']} via {protocol}...")
            try:
                if protocol == "TCP":
                    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                    sock.setsockopt(socket.SOL_SOCKET, socket.SO_KEEPALIVE, 1)
                    try:
                        sock.setsockopt(socket.IPPROTO_TCP, socket.TCP_KEEPIDLE, 5)
                        sock.setsockopt(socket.IPPROTO_TCP, socket.TCP_KEEPINTVL, 3)
                        sock.setsockopt(socket.IPPROTO_TCP, socket.TCP_KEEPCNT, 3)
                    except (AttributeError, OSError):
                        pass
                    try:
                        if self._bind_iface:
                            sock.setsockopt(socket.SOL_SOCKET, 25, self._bind_iface.encode())  # SO_BINDTODEVICE
                    except OSError:
                        pass
                    sock.settimeout(3.0)  # connect timeout only
                    sock.connect((peer_info['ip'], peer_info['tcp_port']))
                    sock.settimeout(None)  # <<< back to blocking after connect

                    # Identify immediately
                    hello = {"protocol": "HELLO", "drone_id": self._drone_id}
                    sock.sendall((json.dumps(hello) + "\n").encode("utf-8"))

                    t = threading.Thread(target=self._handle_tcp_receive, args=(peer_id, sock), daemon=True)
                    t.start()
                    self._threads.append(t)
                else:
                    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
                    try:
                        if self._bind_iface:
                            sock.setsockopt(socket.SOL_SOCKET, 25, self._bind_iface.encode())
                    except OSError:
                        pass
                self._clients[peer_id] = sock
                self._peers[peer_id] = peer_info
                logger.info(f"Connected to {peer_id} via {protocol}.")
            except Exception as e:
                logger.error(f"Failed to connect to {peer_id}: {e}")

    def disconnect_from_peer(self, peer_id):
        with self._lock:
            if peer_id in self._clients:
                logger.info(f"Disconnecting from peer {peer_id}.")
                try:
                    self._clients[peer_id].close()
                except Exception:
                    pass
                finally:
                    self._clients.pop(peer_id, None)
                    self._peers.pop(peer_id, None)

    def send_message(self, peer_info: dict, message_dict: dict):
        peer_id = peer_info['id']
        with self._lock:
            sock = self._clients.get(peer_id)
        if not sock:
            return
        try:
            protocol = "TCP" if sock.type == socket.SOCK_STREAM else "UDP"
            if 'drone_id' not in message_dict:
                message_dict['drone_id'] = self._drone_id
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
            logger.error(f"TCP server bind failed on port {self._tcp_port}: {e}")
            return
        server.listen(5)
        server.settimeout(1.0)
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
                t.start()
                self._threads.append(t)
            except socket.timeout:
                continue
            except Exception as e:
                if self._running:
                    logger.error(f"TCP Server error: {e}")
        server.close()

    def _handle_tcp_receive(self, peer_id, client_socket):
        buffer = ""
        is_identified = peer_id is not None
        client_socket.settimeout(None)  # blocking read
        while self._running:
            try:
                data = client_socket.recv(4096)
                if not data:
                    break
                buffer += data.decode('utf-8', errors='ignore')
                while '\n' in buffer:
                    message_json, buffer = buffer.split('\n', 1)
                    if not message_json:
                        continue
                    message = json.loads(message_json)
                    if not is_identified:
                        with self._lock:
                            pid = message.get('drone_id')
                            if pid:
                                self._clients[pid] = client_socket
                                peer_full = self._discovered_peers.get(pid)
                                if peer_full:
                                    self._peers[pid] = peer_full
                                    logger.info(f"Identified and registered incoming TCP peer {pid}")
                                else:
                                    logger.warning(f"Incoming TCP peer {pid} not in discovered list.")
                                is_identified = True
                                peer_id = pid
                    self.message_queue.append(message)
            except socket.timeout:
                # benign idle; keep connection
                continue
            except (ConnectionResetError, BrokenPipeError, OSError):
                break
            except Exception as e:
                logger.error(f"Error handling TCP client {peer_id}: {e}")
                break
        if peer_id:
            self._handle_disconnection(peer_id)
        try:
            client_socket.close()
        except Exception:
            pass

    def _udp_server_loop(self):
        server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        server.bind(('', self._udp_port))
        server.settimeout(1.0)
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
                if self._running:
                    logger.error(f"UDP Server error: {e}")
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

# -------- Main Controller --------
class DroneController:
    def __init__(self, drone_id, interface, ssid, tcp_port, udp_port, should_setup_net, mode: str):
        self.drone_id = drone_id
        self.should_setup_net = should_setup_net
        self.mode = mode  # 'test' or 'live'
        self.discovered_peers = {}
        self.tested_peers = set()
        self._app_running = True
        self._app_threads = []
        self.PEER_TIMEOUT = 20

        self.discovery = Discovery(drone_id, tcp_port, udp_port)
        self.discovery.adhoc_config["interface"] = interface
        self.discovery.adhoc_config["ssid"] = ssid
        self.discovery.on_peer_discovered = self._handle_peer_discovery

        class PeerInfoView:
            def __init__(self, full_peer_dict, lock):
                self._source = full_peer_dict
                self._lock = lock
            def get(self, key):
                with self._lock:
                    peer_data = self._source.get(key)
                return peer_data['info'] if peer_data else None
            def __contains__(self, key):
                with self._lock:
                    return key in self._source

        self._discovered_lock = threading.Lock()
        self.connection_manager = ConnectionManager(
            self.drone_id,
            self._handle_message_received,
            tcp_port,
            udp_port,
            PeerInfoView(self.discovered_peers, self._discovered_lock),
            bind_iface=interface,
        )

    def start(self):
        logger.info(f"--- Starting Drone Controller for {self.drone_id} ---")
        logger.info("Step 1a: Setting up Ad-Hoc Network Mode...")
        if not self.discovery.setup_adhoc_network():
            logger.critical("Could not set up ad-hoc network. Aborting.")
            self.discovery.teardown_adhoc_network()
            return False

        logger.info("Step 1b: Assigning self IP address...")
        if not self.discovery._assign_ip_address():
            logger.critical("Could not assign IP address. Aborting.")
            return False

        time.sleep(2)
        logger.info("Step 2: Starting Connection Manager...")
        self.connection_manager.start()
        logger.info("Step 3: Starting Discovery Service...")
        self.discovery.start_threads()

        logger.info("Step 4: Starting Application Logic Threads...")
        self._app_running = True
        for target in (self._prune_peers_loop, self._periodic_reconnection_check,
                       self._periodic_status_broadcast, self._heartbeat_loop):
            t = threading.Thread(target=target, daemon=True)
            t.start()
            self._app_threads.append(t)

        logger.info("--- Controller is Running ---")
        return True

    def stop(self):
        logger.info(f"--- Stopping Drone Controller for {self.drone_id} ---")
        logger.info("Step 1: Stopping Application Logic Threads...")
        self._app_running = False
        for t in self._app_threads:
            t.join(timeout=2.0)

        logger.info("Step 2: Stopping Discovery Service...")
        self.discovery.stop_threads()
        logger.info("Step 3: Stopping Connection Manager...")
        self.connection_manager.stop()

        # Teardown if we own it or if nobody else is around
        if self.should_setup_net or not self.discovered_peers:
            logger.info("Tearing down the ad-hoc network.")
            self.discovery.teardown_adhoc_network()
        else:
            logger.info(f"Leaving ad-hoc network running for {len(self.discovered_peers)} other peer(s).")

        logger.info("--- Controller Stopped ---")

    def _prune_peers_loop(self):
        while self._app_running:
            time.sleep(10)
            now = time.time()
            peers_to_prune = [pid for pid, data in list(self.discovered_peers.items())
                              if now - data['last_seen'] > self.PEER_TIMEOUT]
            for pid in peers_to_prune:
                logger.info(f"Peer {pid} timed out. Removing from discovered list.")
                with self.connection_manager._lock:
                    self.discovered_peers.pop(pid, None)
                self.connection_manager.disconnect_from_peer(pid)

    def _handle_peer_discovery(self, peer_info: dict):
        peer_id = peer_info['id']
        with self.connection_manager._lock:
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
            if not self._app_running:
                break
            pkg += 1
            msg = {
                "protocol": "STATUS_BROADCAST",
                "package_number": pkg,
                "energy_level": 98.5,
                "position": {"x": 1.0, "y": 2.0, "z": 3.0}
            }
            self.connection_manager.broadcast_message(msg)

    def _heartbeat_loop(self):
        while self._app_running:
            time.sleep(5)
            self.connection_manager.broadcast_message({"protocol": "PING", "ts": time.time()})

    def _handle_message_received(self, message):
        sender = message.get('drone_id', 'Unknown')
        if sender == self.drone_id:
            logger.debug(f"Ignoring own message: {json.dumps(message)}")
            return
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
            self.connection_manager.connect_to_peer(peer_info, protocol="UDP")
            time.sleep(1)
            for i in range(3):
                self.connection_manager.send_message(peer_info, {"protocol": "UDP_TEST", "count": i + 1})
                time.sleep(0.5)
            self.connection_manager.disconnect_from_peer(peer_id)
            time.sleep(1)

            logger.info(f"[{peer_id}] === Starting TCP Test ===")
            self.connection_manager.connect_to_peer(peer_info, protocol="TCP")
            time.sleep(1)
            for i in range(3):
                self.connection_manager.send_message(peer_info, {"protocol": "TCP_TEST", "count": i + 1})
                time.sleep(0.5)
            logger.info(f"[{peer_id}] === Initial communication test finished. TCP connection will be maintained. ===")
        except Exception as e:
            logger.error(f"Error in communication sequence with {peer_id}: {e}", exc_info=True)

# -------- Entry Point --------
def main():
    parser = argparse.ArgumentParser(description='Decentralized Standalone Ad-Hoc Drone Controller')
    parser.add_argument('--drone-id', required=True, help='Unique ID for this drone (e.g., drone_1)')
    parser.add_argument('--interface', default=None, help='Wireless interface for ad-hoc mode (e.g., wlp1s0)')
    parser.add_argument('--ssid', default='drone-swarm-net', help='Ad-hoc network SSID')
    parser.add_argument('--tcp-port', type=int, default=20000,
                    help='TCP port for the connection manager (default: 20000)')
    parser.add_argument('--udp-port', type=int, default=20001,
                    help='UDP port for the connection manager (default: 20001)')
    parser.add_argument('--setup-net', action='store_true', help='Designate this drone as the master for network cleanup in local tests.')
    parser.add_argument('--mode', choices=['test', 'live'], default='test',
                        help='test = run UDP/TCP self-test; live = maintain persistent links')
    args = parser.parse_args()

    iface = args.interface or detect_wifi_interface()
    if not iface:
        logger.critical("No Wi-Fi interface found. Pass --interface explicitly.")
        return

    controller = DroneController(
        args.drone_id,
        iface,
        args.ssid,
        args.tcp_port,
        args.udp_port,
        args.setup_net,
        args.mode
    )

    try:
        if controller.start():
            while True:
                time.sleep(1)
    except KeyboardInterrupt:
        logger.info("Shutdown initiated by user.")
    finally:
        controller.stop()

if __name__ == "__main__":
    main()
