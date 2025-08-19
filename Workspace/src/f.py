# wext_adhoc_controller.py
# Peer-to-peer Wi-Fi using legacy WEXT Ad-Hoc only + UDP discovery + TCP/UDP comms.
# Clean NM/wpa_supplicant neutralization and restore on exit.

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
logger = logging.getLogger("WEXTController")

# ---------- helpers ----------
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

def run(cmd: list[str], ignore_rc: bool = False) -> bool:
    logger.info("Running command: %s", ' '.join(cmd))
    try:
        p = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        out, err = p.communicate()
        if p.returncode != 0 and not ignore_rc:
            err = (err or '').strip()
            if err:
                logger.error("Command failed: %s", err)
            return False
        return True
    except Exception as e:
        if not ignore_rc:
            logger.error("Exception running command: %s", e)
        return False

# ---------- WEXT ad-hoc bring-up / teardown ----------
class WextAdhoc:
    def __init__(self, iface: str, ssid: str, channel: int):
        self.iface = iface
        self.ssid = ssid
        self.channel = int(channel)
        self._original_connection = self._get_active_connection()

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
                if dev == self.iface:
                    return name
        except Exception:
            pass
        return None

    def bring_up(self) -> bool:
        logger.info("Configuring WEXT Ad-Hoc on %s SSID='%s' ch=%s",
                    self.iface, self.ssid, self.channel)

        # Neutralize NM/supplicant & clear state
        run(['sudo', 'nmcli', 'dev', 'disconnect', self.iface], ignore_rc=True)
        run(['sudo', 'nmcli', 'dev', 'set', self.iface, 'managed', 'no'], ignore_rc=True)
        run(['sudo', 'killall', 'wpa_supplicant'], ignore_rc=True)
        run(['sudo', 'ip', 'addr', 'flush', 'dev', self.iface], ignore_rc=True)
        run(['sudo', 'ip', 'link', 'set', self.iface, 'down'], ignore_rc=True)

        # Legacy ad-hoc configuration
        if not run(['sudo', 'iwconfig', self.iface, 'mode', 'ad-hoc']): return False
        if not run(['sudo', 'iwconfig', self.iface, 'essid', self.ssid]): return False
        if not run(['sudo', 'iwconfig', self.iface, 'channel', str(self.channel)]): return False
        if not run(['sudo', 'ip', 'link', 'set', self.iface, 'up']): return False

        # Verify link state
        try:
            out = subprocess.check_output(['iwconfig', self.iface],
                                          stderr=subprocess.DEVNULL).decode()
            if ('Mode:Ad-Hoc' not in out) or (f'ESSID:"{self.ssid}"' not in out):
                logger.error("WEXT state not as expected:\n%s", out.strip())
                return False
            logger.info("Ad-Hoc up:\n%s", '\n'.join(line for line in out.splitlines() if line.strip()))
        except subprocess.CalledProcessError:
            logger.error("Cannot read iwconfig state.")
            return False
        return True

    def add_ip(self, ip_cidr: str) -> bool:
        if not run(['sudo', 'ip', 'addr', 'add', ip_cidr, 'dev', self.iface]):
            logger.error("Failed to assign IP %s to %s.", ip_cidr, self.iface)
            return False
        logger.info("Assigned IP %s to %s.", ip_cidr, self.iface)
        return True

    def teardown(self):
        logger.info("Restoring original network state...")
        run(['sudo', 'ip', 'addr', 'flush', 'dev', self.iface], ignore_rc=True)
        run(['sudo', 'ip', 'link', 'set', self.iface, 'down'], ignore_rc=True)
        # back to managed Wi-Fi
        if not run(['sudo', 'iw', 'dev', self.iface, 'set', 'type', 'managed'], ignore_rc=True):
            run(['sudo', 'iwconfig', self.iface, 'mode', 'managed'], ignore_rc=True)
        run(['sudo', 'nmcli', 'dev', 'set', self.iface, 'managed', 'yes'], ignore_rc=True)
        run(['nmcli', 'radio', 'wifi', 'on'], ignore_rc=True)
        run(['sudo', 'ip', 'link', 'set', self.iface, 'up'], ignore_rc=True)
        time.sleep(2)
        if self._original_connection:
            logger.info("Attempting to reconnect to '%s'...", self._original_connection)
            run(['nmcli', 'con', 'up', 'id', self._original_connection], ignore_rc=True)
        else:
            logger.info("No previous connection recorded.")

# ---------- Discovery (UDP) ----------
class Discovery:
    def __init__(self, drone_id, tcp_port, udp_port, ip_base: str, ip_end: int, port=19999):
        self._drone_id = drone_id
        self._port = port
        self._tcp_port = tcp_port
        self._udp_port = udp_port
        self._ip = f"{ip_base}{ip_end}"
        self._bcast_ip = str(ipaddress.IPv4Interface(f"{self._ip}/24").network.broadcast_address)
        self._running = False
        self.on_peer_discovered = None
        self._threads = []

    def start(self):
        self._running = True
        tx = threading.Thread(target=self._tx_loop, daemon=True)
        rx = threading.Thread(target=self._rx_loop, daemon=True)
        self._threads = [tx, rx]
        tx.start(); rx.start()

    def stop(self):
        self._running = False
        try:
            with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
                s.sendto(b'stop', ('127.0.0.1', self._port))
        except Exception:
            pass
        for t in self._threads:
            t.join(timeout=2.0)

    def _tx_loop(self):
        msg = json.dumps({"id": self._drone_id, "ip": self._ip,
                          "tcp_port": self._tcp_port, "udp_port": self._udp_port}).encode("utf-8")
        s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        s.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
        try:
            while self._running:
                try:
                    s.sendto(msg, (self._bcast_ip, self._port))
                except OSError as e:
                    logger.error("Broadcast failed: %s", e)
                time.sleep(1)
        finally:
            s.close()

    def _rx_loop(self):
        s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        try:
            s.bind(('', self._port))
        except OSError as e:
            logger.error("Discovery bind failed: %s", e); return
        s.settimeout(1.0)
        while self._running:
            try:
                data, _ = s.recvfrom(1024)
                msg = json.loads(data.decode('utf-8', errors='ignore'))
                pid = msg.get("id"); pip = msg.get("ip")
                if pid and pip and pid != self._drone_id and self.on_peer_discovered:
                    self.on_peer_discovered(msg)
            except socket.timeout:
                continue
            except Exception:
                if not self._running: break
        s.close()

# ---------- Connections ----------
class ConnectionManager:
    def __init__(self, drone_id, on_message, tcp_port, udp_port):
        self._drone_id = drone_id
        self._on_message = on_message
        self._tcp_port = tcp_port
        self._udp_port = udp_port
        self._running = False
        self._threads = []
        self._clients = {}  # peer_id -> socket
        self._peers = {}    # peer_id -> info
        self._lock = threading.Lock()
        self._queue = deque()

    def start(self):
        self._running = True
        for target in (self._tcp_server, self._udp_server, self._worker):
            t = threading.Thread(target=target, daemon=True)
            t.start(); self._threads.append(t)
        logger.info("TCP server listening on port %d", self._tcp_port)
        logger.info("UDP server listening on port %d", self._udp_port)

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
        for t in self._threads:
            t.join(timeout=2.0)
        self._threads.clear()

    def get_connected_peers(self):
        with self._lock:
            return list(self._clients.keys())

    def connect_to_peer(self, info: dict, protocol="TCP"):
        pid = info['id']
        with self._lock:
            if pid in self._clients: return
        logger.info("Connecting to %s at %s via %s...", pid, info['ip'], protocol)
        try:
            if protocol == "TCP":
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
            logger.info("Connected to %s via %s.", pid, protocol)
        except Exception as e:
            logger.error("Failed to connect to %s: %s", pid, e)

    def disconnect_from_peer(self, pid):
        with self._lock:
            s = self._clients.pop(pid, None)
            self._peers.pop(pid, None)
        if s:
            try: s.close()
            except Exception: pass

    def broadcast_message(self, message: dict):
        with self._lock:
            peers = list(self._peers.items())
        if not peers:
            logger.debug("No peers to broadcast to."); return
        logger.info("Broadcasting message to %d peers.", len(peers))
        for pid, info in peers:
            self.send_message(info, message)

    def send_message(self, info: dict, message: dict):
        pid = info['id']
        with self._lock:
            s = self._clients.get(pid)
        if not s:
            return
        try:
            proto = "TCP" if s.type == socket.SOCK_STREAM else "UDP"
            if 'drone_id' not in message:
                message['drone_id'] = self._drone_id
            payload = (json.dumps(message) + ('\n' if proto == "TCP" else '')).encode('utf-8')
            if proto == "TCP":
                s.sendall(payload)
            else:
                s.sendto(payload, (info['ip'], info['udp_port']))
        except Exception as e:
            logger.error("Error sending to %s: %s", pid, e)
            self.disconnect_from_peer(pid)

    # servers/worker
    def _tcp_server(self):
        srv = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        srv.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        try:
            srv.bind(('', self._tcp_port))
        except OSError as e:
            logger.error("TCP bind failed: %s", e); return
        srv.listen(5); srv.settimeout(1.0)
        while self._running:
            try:
                c, addr = srv.accept()
                logger.info("Accepted TCP connection from %s", addr)
                c.setsockopt(socket.SOL_SOCKET, socket.SO_KEEPALIVE, 1)
                try:
                    c.setsockopt(socket.IPPROTO_TCP, socket.TCP_KEEPIDLE, 5)
                    c.setsockopt(socket.IPPROTO_TCP, socket.TCP_KEEPINTVL, 3)
                    c.setsockopt(socket.IPPROTO_TCP, socket.TCP_KEEPCNT, 3)
                except (AttributeError, OSError):
                    pass
                t = threading.Thread(target=self._tcp_reader, args=(None, c), daemon=True)
                t.start(); self._threads.append(t)
            except socket.timeout:
                continue
            except Exception as e:
                if self._running: logger.error("TCP server error: %s", e)
        srv.close()

    def _tcp_reader(self, pid, c):
        buf = ""
        identified = pid is not None
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
                            with self._lock:
                                self._clients[new_id] = c
                            identified = True
                            pid = new_id
                    self._queue.append(msg)
            except (ConnectionResetError, BrokenPipeError, OSError):
                break
            except Exception as e:
                logger.error("TCP reader error (%s): %s", pid, e); break
        if pid: self.disconnect_from_peer(pid)
        try: c.close()
        except Exception: pass

    def _udp_server(self):
        srv = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        try:
            srv.bind(('', self._udp_port))
        except OSError as e:
            logger.error("UDP bind failed: %s", e); return
        srv.settimeout(1.0)
        while self._running:
            try:
                data, _ = srv.recvfrom(4096)
                try:
                    msg = json.loads(data.decode('utf-8', errors='ignore'))
                    self._queue.append(msg)
                except json.JSONDecodeError:
                    logger.debug("Ignoring non-JSON UDP payload.")
            except socket.timeout:
                continue
            except Exception as e:
                if self._running: logger.error("UDP server error: %s", e)
        srv.close()

    def _worker(self):
        while self._running:
            try:
                msg = self._queue.popleft()
                self._on_message(msg)
            except IndexError:
                time.sleep(0.01)
            except Exception as e:
                logger.error("Worker error: %s", e)

# ---------- Controller ----------
class Controller:
    def __init__(self, drone_id, iface, ssid, channel, tcp_port, udp_port, restore_net):
        self.drone_id = drone_id
        self.iface = iface
        self.ssid = ssid
        self.channel = int(channel)
        self.tcp_port = int(tcp_port)
        self.udp_port = int(udp_port)
        self.restore_net = restore_net

        ip_end = self._ip_octet_from_id(drone_id)
        self.ip_base = "192.168.1."
        self.ip_cidr = f"{self.ip_base}{ip_end}/24"

        self.wext = WextAdhoc(iface, ssid, self.channel)
        self.discovery = Discovery(drone_id, self.tcp_port, self.udp_port,
                                   self.ip_base, ip_end, port=19999)
        self.discovery.on_peer_discovered = self._on_peer
        self._discovered = {}
        self._lock = threading.Lock()
        self.cm = ConnectionManager(drone_id, self._on_msg, self.tcp_port, self.udp_port)
        self._app_running = False
        self._threads = []
        self.PEER_TIMEOUT = 20

    @staticmethod
    def _ip_octet_from_id(s: str) -> int:
        d = ''.join(filter(str.isdigit, s))
        return int(d) if d else (abs(hash(s)) % 254 + 1)

    def start(self) -> bool:
        logger.info("--- Starting Controller for %s ---", self.drone_id)
        logger.info("Step 1a: WEXT ad-hoc bring-up...")
        if not self.wext.bring_up():
            logger.critical("Ad-hoc bring-up failed.")
            return False
        logger.info("Step 1b: Assigning IP address...")
        if not self.wext.add_ip(self.ip_cidr):
            logger.critical("Could not assign IP address."); return False

        time.sleep(1.0)
        logger.info("Step 2: Starting Connection Manager..."); self.cm.start()
        logger.info("Step 3: Starting Discovery Service..."); self.discovery.start()

        logger.info("Step 4: Starting Application Threads...")
        self._app_running = True
        for target in (self._prune_loop, self._reconnect_loop, self._status_broadcast, self._heartbeat):
            t = threading.Thread(target=target, daemon=True); t.start(); self._threads.append(t)

        logger.info("--- Controller is Running (WEXT ch=%s) ---", self.channel)
        return True

    def stop(self):
        logger.info("--- Stopping Controller for %s ---", self.drone_id)
        self._app_running = False
        for t in self._threads: t.join(timeout=2.0)
        self.discovery.stop()
        self.cm.stop()
        if self.restore_net or not self._discovered:
            self.wext.teardown()
        logger.info("--- Controller Stopped ---")

    # --- app loops ---
    def _prune_loop(self):
        while self._app_running:
            time.sleep(10)
            now = time.time()
            with self._lock:
                stale = [pid for pid, d in list(self._discovered.items())
                         if now - d['last'] > self.PEER_TIMEOUT]
                for pid in stale:
                    logger.info("Peer %s timed out; removing.", pid)
                    self._discovered.pop(pid, None)
            for pid in stale:
                self.cm.disconnect_from_peer(pid)

    def _reconnect_loop(self):
        while self._app_running:
            time.sleep(15)
            with self._lock:
                peers = list(self._discovered.values())
            connected = set(self.cm.get_connected_peers())
            for d in peers:
                pid = d['info']['id']
                if pid not in connected and id_num(self.drone_id) > id_num(pid):
                    logger.info("Peer '%s' not connected. Attempting TCP connect.", pid)
                    self.cm.connect_to_peer(d['info'], protocol="TCP")

    def _status_broadcast(self):
        n = 0
        while self._app_running:
            time.sleep(10)
            n += 1
            self.cm.broadcast_message({"protocol": "STATUS", "seq": n, "drone_id": self.drone_id})

    def _heartbeat(self):
        while self._app_running:
            time.sleep(5)
            self.cm.broadcast_message({"protocol": "PING", "ts": time.time(), "drone_id": self.drone_id})

    # --- callbacks ---
    def _on_peer(self, info: dict):
        pid = info['id']
        with self._lock:
            self._discovered[pid] = {'info': info, 'last': time.time()}
        if id_num(self.drone_id) > id_num(pid):
            self.cm.connect_to_peer(info, protocol="TCP")

    def _on_msg(self, msg: dict):
        sender = msg.get('drone_id', 'Unknown')
        if sender == self.drone_id:
            return
        proto = msg.get('protocol', 'N/A')
        if proto == "PING":
            with self._lock:
                peer = self._discovered.get(sender)
            if peer:
                self.cm.send_message(peer['info'], {"protocol": "PONG", "ts": time.time()})
        else:
            logger.info("RECV from %s via %s: %s", sender, proto, json.dumps(msg))

# ---------- CLI ----------
def main():
    p = argparse.ArgumentParser(description='WEXT Ad-Hoc Drone Controller (legacy ad-hoc only)')
    p.add_argument('--drone-id', required=True, help='Unique ID (e.g., drone_1)')
    p.add_argument('--interface', default=None, help='Wi-Fi interface (auto-detected if omitted)')
    p.add_argument('--ssid', default='drone-swarm', help='Ad-Hoc ESSID')
    p.add_argument('--channel', type=int, default=6, help='Channel (2.4 GHz typical; 5 GHz ad-hoc often unsupported)')
    p.add_argument('--tcp-port', type=int, default=20000)
    p.add_argument('--udp-port', type=int, default=20001)
    p.add_argument('--setup-net', action='store_true', help='Restore managed Wi-Fi on exit')
    args = p.parse_args()

    iface = args.interface or detect_wifi_interface()
    if not iface:
        logger.critical("No Wi-Fi interface found. Pass --interface explicitly."); return

    ctrl = Controller(args.drone_id, iface, args.ssid, args.channel,
                      args.tcp_port, args.udp_port, args.setup_net)
    try:
        if ctrl.start():
            while True:
                time.sleep(1)
    except KeyboardInterrupt:
        logger.info("Shutdown initiated by user.")
    finally:
        ctrl.stop()

if __name__ == '__main__':
    main()
