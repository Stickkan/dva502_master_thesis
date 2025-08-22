#!/usr/bin/env python3

import argparse
import ipaddress
import json
import logging
import os
import re
import socket
import subprocess
import threading
import time
from collections import deque
from typing import Optional, Dict, List

# ---------- Logging ----------
logging.basicConfig(
    level=logging.INFO,
    format="%(asctime)s - %(name)s - %(levelname)s - %(message)s"
)
logger = logging.getLogger("Swarm")

# ---------- Constants ----------
SCAN_INTERVAL_S = 1.0
FOUNDERS_SHORT_SCAN_S = 2.0
DISCOVERY_PORT = 19999
TELEMETRY_PORT = 29999

# ---------- Helpers ----------
def run(cmd: List[str], ignore_rc: bool = False) -> bool:
    logger.info("RUN: %s", " ".join(cmd))
    try:
        p = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        out, err = p.communicate()
        if out:
            out = out.strip()
            if out:
                logger.debug(out)
        if p.returncode != 0 and not ignore_rc:
            em = (err or "").strip()
            if em:
                logger.error(em)
            return False
        if err and ignore_rc:
            logger.debug(err.strip())
        return True
    except Exception as e:
        if not ignore_rc:
            logger.error("Exception running command: %s", e)
        return False


def detect_wifi_interface() -> Optional[str]:
    # Try 'iw dev'
    try:
        out = subprocess.check_output(["iw", "dev"], stderr=subprocess.DEVNULL, text=True)
        for line in out.splitlines():
            line = line.strip()
            if line.startswith("Interface "):
                return line.split()[1]
    except Exception:
        pass
    # Fallback 'nmcli device'
    try:
        out = subprocess.check_output(["nmcli", "-t", "-f", "DEVICE,TYPE", "device"],
                                      stderr=subprocess.DEVNULL, text=True)
        for line in out.splitlines():
            dev, typ = line.split(":")
            if typ == "wifi":
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
    d = "".join(filter(str.isdigit, s))
    return int(d) if d else 0


def bind_to_iface(sock: socket.socket, iface: str) -> None:
    """Try to bind socket to interface (needs CAP_NET_RAW/CAP_NET_ADMIN)."""
    try:
        sock.setsockopt(socket.SOL_SOCKET, socket.SO_BINDTODEVICE, iface.encode())
        logger.debug("Bound socket to iface %s", iface)
    except (OSError, AttributeError, PermissionError):
        # Non-fatal; continue without SO_BINDTODEVICE
        logger.debug("SO_BINDTODEVICE not set (non-root or unsupported); continuing.")


# ---------- WEXT Ad-Hoc Join/Create ----------
class WextAdhoc:
    def __init__(self, iface: str, ssid: str, channel: int):
        self.iface = iface
        self.ssid = ssid
        self.channel = int(channel)
        self._original_connection = self._get_active_connection()

    def _get_active_connection(self) -> Optional[str]:
        try:
            res = subprocess.check_output(
                ["nmcli", "-t", "-f", "NAME,DEVICE", "con", "show", "--active"],
                stderr=subprocess.DEVNULL, text=True
            )
            for line in res.strip().split("\n"):
                if not line.strip():
                    continue
                name, dev = line.split(":")
                if dev == self.iface:
                    return name
        except Exception:
            pass
        return None

    def _scan_once(self) -> List[Dict]:
        """Return list of matching ad-hoc cells [{'bssid':..,'channel':..}] for our ESSID."""
        try:
            out = subprocess.check_output(
                ["sudo", "iwlist", self.iface, "scan"],
                stderr=subprocess.DEVNULL, text=True, timeout=5
            )
        except Exception:
            return []
        cells = out.split("Cell ")
        matches: List[Dict] = []
        for blob in cells[1:]:
            m_addr = re.search(r"Address:\s*([0-9A-Fa-f:]{17})", blob)
            m_mode = re.search(r"Mode:\s*Ad-Hoc", blob)
            m_ess = re.search(r'ESSID:"([^"]+)"', blob)
            m_ch = re.search(r"Channel\s*:\s*(\d+)", blob)
            if not m_ch:
                m_ch = re.search(r"Frequency:\s*[\d\.]+\s*GHz\s*\(Channel\s*(\d+)\)", blob)
            if not (m_addr and m_mode and m_ess and m_ch):
                continue
            if m_ess.group(1) != self.ssid:
                continue
            try:
                matches.append({"bssid": m_addr.group(1).lower(), "channel": int(m_ch.group(1))})
            except ValueError:
                continue
        return matches

    def _scan_until(self, seconds: float) -> Optional[Dict]:
        deadline = time.time() + seconds
        run(["sudo", "ip", "link", "set", self.iface, "up"], ignore_rc=True)
        while time.time() < deadline:
            ms = self._scan_once()
            if ms:
                return ms[0]
            time.sleep(SCAN_INTERVAL_S)
        return None

    def bring_up(self) -> bool:
        logger.info("Preparing interface for WEXT Ad-Hoc (scan-first): %s", self.iface)
        # Neutralize managers & clear state
        run(["sudo", "nmcli", "dev", "disconnect", self.iface], ignore_rc=True)
        run(["sudo", "nmcli", "dev", "set", self.iface, "managed", "no"], ignore_rc=True)
        run(["sudo", "systemctl", "stop", "iwd"], ignore_rc=True)  # iwd can hold iface
        run(["sudo", "killall", "wpa_supplicant"], ignore_rc=True)
        run(["sudo", "iw", "dev", self.iface, "ibss", "leave"], ignore_rc=True)
        run(["sudo", "iw", "dev", self.iface, "mesh", "leave"], ignore_rc=True)
        run(["sudo", "ip", "addr", "flush", "dev", self.iface], ignore_rc=True)
        run(["sudo", "ip", "link", "set", self.iface, "down"], ignore_rc=True)

        # Scan for existing cell (iface must be up for scan)
        logger.info('Scanning up to %.1fs for existing ad-hoc cell ESSID="%s"...',
                    FOUNDERS_SHORT_SCAN_S, self.ssid)
        run(["sudo", "ip", "link", "set", self.iface, "up"], ignore_rc=True)
        _ = run(["sudo", "ip", "link", "set", self.iface, "up"], ignore_rc=True)  # double-up helps on some drivers
        found = self._scan_until(FOUNDERS_SHORT_SCAN_S)
        if found:
            use_channel = int(found["channel"])
            logger.info("Found existing cell on channel %d; will join.", use_channel)
        else:
            use_channel = self.channel
            logger.info("No existing cell; will create on channel %d.", use_channel)

        # Bring down again for iftype change + WEXT config
        run(["sudo", "ip", "link", "set", self.iface, "down"], ignore_rc=True)
        time.sleep(0.15)
        run(["sudo", "iw", "dev", self.iface, "set", "type", "managed"], ignore_rc=True)
        time.sleep(0.05)

        # Configure via WEXT
        if not run(["sudo", "iwconfig", self.iface, "mode", "ad-hoc"]):  # WEXT legacy
            return False
        if not run(["sudo", "iwconfig", self.iface, "essid", self.ssid]):
            return False
        if not run(["sudo", "iwconfig", self.iface, "channel", str(use_channel)]):
            return False
        if not run(["sudo", "ip", "link", "set", self.iface, "up"]):
            return False

        # Verify (not all drivers show cell/channel; don't fail hard on that)
        try:
            out = subprocess.check_output(["iwconfig", self.iface], stderr=subprocess.DEVNULL, text=True)
            ok_mode = ("Mode:Ad-Hoc" in out)
            ok_ess = (f'ESSID:"{self.ssid}"' in out)
            if not (ok_mode and ok_ess):
                logger.error("WEXT state not as expected:\n%s", out.strip())
                return False
            cell = re.search(r"Cell\s*[:=]\s*([0-9A-Fa-f:]{17})", out)
            ch = re.search(r"Channel\s*:(\d+)", out) or re.search(r"Frequency:.*\(Channel\s*(\d+)\)", out)
            logger.info("Ad-Hoc up. %s %s",
                        f"Cell={cell.group(1).lower()}" if cell else "Cell=unknown",
                        f"Channel={ch.group(1)}" if ch else "Channel=unknown")
        except subprocess.CalledProcessError:
            logger.error("Cannot read iwconfig state.")
            return False
        return True

    def add_ip(self, ip_cidr: str) -> bool:
        if not run(["sudo", "ip", "addr", "add", ip_cidr, "dev", self.iface]):
            logger.error("Failed to assign IP %s to %s.", ip_cidr, self.iface)
            return False
        logger.info("Assigned IP %s to %s.", ip_cidr, self.iface)
        return True

    def teardown(self):
        logger.info("Restoring original network state...")
        run(["sudo", "ip", "addr", "flush", "dev", self.iface], ignore_rc=True)
        run(["sudo", "ip", "link", "set", self.iface, "down"], ignore_rc=True)
        if not run(["sudo", "iw", "dev", self.iface, "set", "type", "managed"], ignore_rc=True):
            run(["sudo", "iwconfig", self.iface, "mode", "managed"], ignore_rc=True)
        run(["sudo", "nmcli", "dev", "set", self.iface, "managed", "yes"], ignore_rc=True)
        run(["nmcli", "radio", "wifi", "on"], ignore_rc=True)
        run(["sudo", "ip", "link", "set", self.iface, "up"], ignore_rc=True)
        time.sleep(2)
        if self._original_connection:
            logger.info("Attempting to reconnect to '%s'...", self._original_connection)
            run(["nmcli", "con", "up", "id", self._original_connection], ignore_rc=True)
        else:
            logger.info("No previous connection recorded.")


# ---------- Telemetry (always broadcast, RX+TX) ----------
class Telemetry:
    def __init__(self, iface: str, ip_cidr: str, drone_id: str,
                 port: int = TELEMETRY_PORT, period_s: float = 1.0,
                 on_rx=None):
        self.iface = iface
        self.drone_id = drone_id
        self.period_s = period_s
        self.port = port
        self.on_rx = on_rx
        self._running = False
        ipif = ipaddress.IPv4Interface(ip_cidr)
        self.ip = str(ipif.ip)
        self.bcast = str(ipif.network.broadcast_address)
        logger.info("Telemetry TX to %s:%d", self.bcast, self.port)

    def start(self):
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
            n += 1
            self.cm.broadcast_message({"protocol": "STATUS", "seq": n})

    def _heartbeat(self):
        while self._app_running:
            time.sleep(self.hb_interval)
            self.cm.broadcast_message({"protocol": "PING", "ts": time.time()})

    def _prune_loop(self):
        while self._app_running:
            time.sleep(2)
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

    def _on_msg(self, msg: Dict):
        # messages coming from ConnectionManager (TCP/UDP)
        sender = msg.get("drone_id", "Unknown")
        if sender == self.drone_id:
            return
        # bump last-seen for heartbeats/drop logic
        self._on_any_msg(msg)

        proto = msg.get("protocol", "N/A")
        if proto == "PING":
            # reply directly over the chosen link
            with self._lock:
                peer = self._discovered.get(sender)
            if peer:
                self.cm.send_message(peer["info"], {"protocol": "PONG", "ts": time.time()})
        else:
            logger.info("RECV from %s via %s: %s", sender, proto, json.dumps(msg))

    # ----- small util -----
    @staticmethod
    def _active_conn_name(iface: str) -> Optional[str]:
        try:
            res = subprocess.check_output(
                ["nmcli", "-t", "-f", "NAME,DEVICE", "con", "show", "--active"],
                stderr=subprocess.DEVNULL, text=True
            )
            for line in res.strip().split("\n"):
                if not line.strip():
                    continue
                name, dev = line.split(":")
                if dev == iface:
                    return name
        except Exception:
            pass
        return None

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
        if ctrl.start():
            while True:
                time.sleep(1)
    except KeyboardInterrupt:
        logger.info("Shutdown initiated by user.")
    finally:
        ctrl.stop()


if __name__ == "__main__":
    main()
