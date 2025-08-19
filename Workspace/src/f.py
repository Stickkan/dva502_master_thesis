#!/usr/bin/env python3
# wext_adhoc_swarm.py
#
# - WEXT join-or-create after a short scan to avoid split cells
# - Always broadcast telemetry & discovery (even with zero links)
# - Connect to any discovered peer (TCP or UDP selectable via --peer-proto)
# - Heartbeats keep links alive; drop after configurable silence (--hb-timeout)
# - De-duplicate double connections deterministically
# - Restore original managed Wi-Fi on exit if --setup-net is passed
#
# Tested on adapters that still expose WEXT paths. Fallbacks included where sensible.

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
        threading.Thread(target=self._tx_loop, daemon=True).start()
        threading.Thread(target=self._rx_loop, daemon=True).start()

    def stop(self):
        self._running = False
        try:
            with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
                s.sendto(b"stop", ("127.0.0.1", self.port))
        except Exception:
            pass

    def _tx_loop(self):
        try:
            s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
            s.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
            bind_to_iface(s, self.iface)
        except Exception as e:
            logger.error("Telemetry TX socket error: %s", e)
            return

        pkt = 0
        while self._running:
            pkt += 1
            msg = {
                "protocol": "TELEMETRY",
                "drone_id": self.drone_id,
                "packet_number": pkt,
                "tx_ms": int(time.time() * 1000),
                "position": None,
            }
            try:
                data = json.dumps(msg).encode("utf-8")
                s.sendto(data, (self.bcast, self.port))
                logger.debug("TX TELEMETRY %s", json.dumps(msg))
            except OSError as e:
                logger.error("Telemetry broadcast failed: %s", e)
            time.sleep(self.period_s)
        try:
            s.close()
        except Exception:
            pass

    def _rx_loop(self):
        s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        try:
            s.bind(("", self.port))
        except OSError as e:
            logger.error("Telemetry bind failed: %s", e)
            return
        s.settimeout(1.0)
        while self._running:
            try:
                data, _ = s.recvfrom(4096)
                try:
                    msg = json.loads(data.decode("utf-8", errors="ignore"))
                except json.JSONDecodeError:
                    continue
                if msg.get("protocol") == "TELEMETRY":
                    src = msg.get("drone_id")
                    if src and src != self.drone_id:
                        logger.info("RX TELEMETRY from %s: %s", src, json.dumps(msg))
                        if self.on_rx:
                            self.on_rx(msg)  # let controller update last-seen
            except socket.timeout:
                continue
            except Exception:
                if not self._running:
                    break
        s.close()


# ---------- Discovery (always broadcast, RX+TX) ----------
class Discovery:
    def __init__(self, iface: str, my_id: str, my_ip: str, tcp_port: int, udp_port: int,
                 port: int = DISCOVERY_PORT, period_s: float = 1.0):
        self.iface = iface
        self.my_id = my_id
        self.my_ip = my_ip
        self.tcp_port = tcp_port
        self.udp_port = udp_port
        self.port = port
        self.period_s = period_s
        self._running = False
        self.on_peer_discovered = None

        ipif = ipaddress.ip_interface(f"{my_ip}/24")
        self.bcast = str(ipif.network.broadcast_address)

    def start(self):
        self._running = True
        logger.debug("Discovery TX bound to iface %s", self.iface)
        threading.Thread(target=self._tx_loop, daemon=True).start()
        threading.Thread(target=self._rx_loop, daemon=True).start()

    def stop(self):
        self._running = False
        try:
            with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
                s.sendto(b"stop", ("127.0.0.1", self.port))
        except Exception:
            pass

    def _tx_loop(self):
        try:
            s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
            s.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
            bind_to_iface(s, self.iface)
        except Exception as e:
            logger.error("Discovery TX socket error: %s", e)
            return

        payload = {
            "id": self.my_id,
            "ip": self.my_ip,
            "tcp_port": self.tcp_port,
            "udp_port": self.udp_port
        }
        data = json.dumps(payload).encode("utf-8")
        while self._running:
            try:
                s.sendto(data, (self.bcast, self.port))
            except OSError as e:
                logger.error("Discovery broadcast failed: %s", e)
            time.sleep(self.period_s)
        try:
            s.close()
        except Exception:
            pass

    def _rx_loop(self):
        s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        try:
            s.bind(("", self.port))
        except OSError as e:
            logger.error("Discovery bind failed: %s", e)
            return
        s.settimeout(1.0)
        while self._running:
            try:
                data, _ = s.recvfrom(1024)
                try:
                    msg = json.loads(data.decode("utf-8", errors="ignore"))
                except json.JSONDecodeError:
                    continue
                pid = msg.get("id")
                pip = msg.get("ip")
                if pid and pip and pid != self.my_id and self.on_peer_discovered:
                    logger.info("Discovered peer %s at %s (tcp=%s udp=%s)",
                                pid, pip, msg.get("tcp_port"), msg.get("udp_port"))
                    self.on_peer_discovered(msg)
            except socket.timeout:
                continue
            except Exception:
                if not self._running:
                    break
        s.close()


# ---------- Connection Manager (TCP/UDP) ----------
class ConnectionManager:
    def __init__(self, my_id: str, on_message, tcp_port: int, udp_port: int):
        self.my_id = my_id
        self._on_message = on_message
        self.tcp_port = tcp_port
        self.udp_port = udp_port

        self._running = False
        self._threads: List[threading.Thread] = []
        self._clients: Dict[str, socket.socket] = {}   # id -> socket
        self._peers: Dict[str, Dict] = {}              # id -> info {id, ip, tcp_port, udp_port}
        self._lock = threading.Lock()
        self._queue = deque()

    def start(self):
        self._running = True
        threading.Thread(target=self._tcp_server, daemon=True).start()
        threading.Thread(target=self._udp_server, daemon=True).start()
        threading.Thread(target=self._worker, daemon=True).start()
        logger.info("TCP server listening on %d; UDP server on %d", self.tcp_port, self.udp_port)

    def stop(self):
        if not self._running:
            return
        self._running = False
        with self._lock:
            for s in list(self._clients.values()):
                try:
                    s.close()
                except Exception:
                    pass
        try:
            socket.create_connection(("127.0.0.1", self.tcp_port), timeout=0.5).close()
        except Exception:
            pass
        try:
            with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
                s.sendto(b"stop", ("127.0.0.1", self.udp_port))
        except Exception:
            pass

    def get_connected_peers(self) -> List[str]:
        with self._lock:
            return list(self._clients.keys())

    def connect_to_peer(self, info: Dict, protocol: str = "TCP"):
        pid = info["id"]
        with self._lock:
            if pid in self._clients:
                return  # already connected
        logger.info("Connecting to %s at %s via %s...", pid, info["ip"], protocol.upper())
        try:
            if protocol.upper() == "TCP":
                s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                s.setsockopt(socket.SOL_SOCKET, socket.SO_KEEPALIVE, 1)
                try:
                    s.setsockopt(socket.IPPROTO_TCP, socket.TCP_KEEPIDLE, 5)
                    s.setsockopt(socket.IPPROTO_TCP, socket.TCP_KEEPINTVL, 3)
                    s.setsockopt(socket.IPPROTO_TCP, socket.TCP_KEEPCNT, 3)
                except (AttributeError, OSError):
                    pass
                s.settimeout(3.0)
                s.connect((info["ip"], info["tcp_port"]))
                s.settimeout(None)
                hello = {"protocol": "HELLO", "drone_id": self.my_id}
                s.sendall((json.dumps(hello) + "\n").encode("utf-8"))
                with self._lock:
                    # if another socket already exists now, prefer the existing one
                    if pid in self._clients and self._clients[pid] is not s:
                        try: s.close()
                        except: pass
                        return
                    self._clients[pid] = s
                    self._peers[pid] = info
                threading.Thread(target=self._tcp_reader, args=(pid, s), daemon=True).start()
                logger.info("Connected to %s via TCP.", pid)
            else:
                # UDP "connection": create a socket and keep peer info
                s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
                with self._lock:
                    self._clients[pid] = s
                    self._peers[pid] = info
                # Send a HELLO packet to seed last-seen on the other end
                self.send_message(info, {"protocol": "HELLO", "drone_id": self.my_id})
                logger.info("Connected to %s via UDP.", pid)
        except Exception as e:
            logger.error("Failed to connect to %s: %s", pid, e)

    def disconnect_from_peer(self, pid: str):
        with self._lock:
            s = self._clients.pop(pid, None)
            self._peers.pop(pid, None)
        if s:
            try:
                s.close()
            except Exception:
                pass

    def broadcast_message(self, message: Dict):
        with self._lock:
            peers = list(self._peers.items())
        if not peers:
            logger.debug("No peers to broadcast to.")
            return
        for _, info in peers:
            self.send_message(info, dict(message))  # copy to avoid mutation

    def send_message(self, info: Dict, message: Dict):
        pid = info["id"]
        with self._lock:
            s = self._clients.get(pid)
        if not s:
            return
        try:
            proto = "TCP" if s.type == socket.SOCK_STREAM else "UDP"
            if "drone_id" not in message:
                message["drone_id"] = self.my_id
            payload = (json.dumps(message) + ("\n" if proto == "TCP" else "")).encode("utf-8")
            if proto == "TCP":
                s.sendall(payload)
            else:
                s.sendto(payload, (info["ip"], info["udp_port"]))
        except Exception as e:
            logger.error("Error sending to %s: %s", pid, e)
            self.disconnect_from_peer(pid)

    # ----- Servers -----
    def _tcp_server(self):
        srv = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        srv.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        try:
            srv.bind(("", self.tcp_port))
        except OSError as e:
            logger.error("TCP bind failed: %s", e)
            return
        srv.listen(5)
        srv.settimeout(1.0)
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
                threading.Thread(target=self._tcp_reader, args=(None, c), daemon=True).start()
            except socket.timeout:
                continue
            except Exception as e:
                if self._running:
                    logger.error("TCP server error: %s", e)
        srv.close()

    def _tcp_reader(self, pid: Optional[str], c: socket.socket):
        buf = ""
        identified = pid is not None
        while self._running:
            try:
                data = c.recv(4096)
                if not data:
                    break
                buf += data.decode("utf-8", errors="ignore")
                while "\n" in buf:
                    line, buf = buf.split("\n", 1)
                    if not line:
                        continue
                    msg = json.loads(line)
                    if not identified:
                        new_id = msg.get("drone_id")
                        if new_id:
                            with self._lock:
                                existing = self._clients.get(new_id)
                                if existing and existing is not c:
                                    # Keep the existing connection; drop this newcomer.
                                    try: c.close()
                                    except: pass
                                    return
                                self._clients[new_id] = c
                                # leave _peers entry as-is if already present
                            identified = True
                            pid = new_id
                    self._queue.append(msg)
            except (ConnectionResetError, BrokenPipeError, OSError):
                break
            except Exception as e:
                logger.error("TCP reader error (%s): %s", pid, e)
                break
        if pid:
            self.disconnect_from_peer(pid)
        try:
            c.close()
        except Exception:
            pass

    def _udp_server(self):
        srv = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        try:
            srv.bind(("", self.udp_port))
        except OSError as e:
            logger.error("UDP bind failed: %s", e)
            return
        srv.settimeout(1.0)
        while self._running:
            try:
                data, _ = srv.recvfrom(4096)
                try:
                    self._queue.append(json.loads(data.decode("utf-8", errors="ignore")))
                except json.JSONDecodeError:
                    logger.debug("Ignoring non-JSON UDP payload.")
            except socket.timeout:
                continue
            except Exception as e:
                if self._running:
                    logger.error("UDP server error: %s", e)
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
    def __init__(self, drone_id: str, iface: str, ssid: str, channel: int,
                 tcp_port: int, udp_port: int, restore_net: bool,
                 peer_proto: str = "TCP", hb_interval: float = 3.0, hb_timeout: float = 12.0):
        self.drone_id = drone_id
        self.iface = iface
        self.ssid = ssid
        self.channel = int(channel)
        self.tcp_port = int(tcp_port)
        self.udp_port = int(udp_port)
        self.restore_net = restore_net

        ip_end = self._ip_octet_from_id(drone_id)
        self.ip_base = "192.168.1."
        self.my_ip = f"{self.ip_base}{ip_end}"
        self.ip_cidr = f"{self.my_ip}/24"

        self.peer_proto = peer_proto.upper()
        self.hb_interval = float(hb_interval)
        self.hb_timeout = float(hb_timeout)

        self.wext = WextAdhoc(iface, ssid, self.channel)
        self.cm = ConnectionManager(drone_id, self._on_msg, self.tcp_port, self.udp_port)
        self.discovery = Discovery(iface, drone_id, self.my_ip, self.tcp_port, self.udp_port,
                                   port=DISCOVERY_PORT, period_s=1.0)
        self.discovery.on_peer_discovered = self._on_peer

        self.telemetry = Telemetry(iface, self.ip_cidr, drone_id, port=TELEMETRY_PORT,
                                   period_s=1.0, on_rx=self._on_any_msg)

        self._app_running = False
        self._threads: List[threading.Thread] = []
        self._lock = threading.Lock()
        self._discovered: Dict[str, Dict] = {}     # id -> {info, last}
        self._last_seen: Dict[str, float] = {}     # id -> last ts (any protocol)

    @staticmethod
    def _ip_octet_from_id(s: str) -> int:
        d = ''.join(filter(str.isdigit, s))
        return int(d) if d else (abs(hash(s)) % 254 + 1)

    def start(self) -> bool:
        # Informational: what was active
        act = self._active_conn_name(self.iface)
        if act:
            logger.info("Detected active connection on %s: '%s'", self.iface, act)

        logger.info("--- Starting Swarm Controller for %s ---", self.drone_id)
        logger.info("Step 1a: Bring up WEXT ad-hoc (join-or-create)...")
        if not self.wext.bring_up():
            logger.critical("Ad-hoc bring-up failed.")
            return False

        logger.info("Step 1b: Assign IP...")
        if not self.wext.add_ip(self.ip_cidr):
            logger.critical("Could not assign IP address.")
            return False
        time.sleep(1.0)

        logger.info("Step 2: Start GPS + telemetry broadcaster...")
        self.telemetry.start()

        logger.info("Step 3: Start Connection Manager...")
        self.cm.start()

        logger.info("Step 4: Start Discovery...")
        self.discovery.start()

        logger.info("Step 5: Start app loops (status/heartbeat/prune)...")
        self._app_running = True
        for target in (self._status_broadcast, self._heartbeat, self._prune_loop, self._reconnect_loop):
            t = threading.Thread(target=target, daemon=True)
            t.start()
            self._threads.append(t)

        logger.info("--- Controller Running (proto=%s, hb=%.1fs/%.1fs) ---",
                    self.peer_proto, self.hb_interval, self.hb_timeout)
        return True

    def stop(self):
        logger.info("--- Stopping Controller ---")
        self._app_running = False
        for t in self._threads:
            t.join(timeout=2.0)
        self.discovery.stop()
        self.telemetry.stop()
        self.cm.stop()
        if self.restore_net or not self._discovered:
            self.wext.teardown()
        logger.info("--- Stopped ---")

    # ----- loops -----
    def _status_broadcast(self):
        n = 0
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
            with self._lock:
                stale = [pid for pid, ts in list(self._last_seen.items())
                         if now - ts > self.hb_timeout]
            for pid in stale:
                logger.info("Peer %s timed out; disconnecting.", pid)
                self.cm.disconnect_from_peer(pid)
                with self._lock:
                    self._last_seen.pop(pid, None)
                    self._discovered.pop(pid, None)

    def _reconnect_loop(self):
        while self._app_running:
            time.sleep(5)
            with self._lock:
                peers = list(self._discovered.values())
            connected = set(self.cm.get_connected_peers())
            for d in peers:
                pid = d["info"]["id"]
                if pid not in connected:
                    self.cm.connect_to_peer(d["info"], protocol=self.peer_proto)

    # ----- callbacks -----
    def _on_peer(self, info: Dict):
        pid = info["id"]
        now = time.time()
        with self._lock:
            self._discovered[pid] = {"info": info, "last": now}
            self._last_seen.setdefault(pid, now)
        # Always attempt to connect (no id tie-breaker)
        if pid not in self.cm.get_connected_peers():
            self.cm.connect_to_peer(info, protocol=self.peer_proto)

    def _on_any_msg(self, msg: Dict):
        """Called by Telemetry RX for any broadcast message we care about to bump last-seen."""
        sender = msg.get("drone_id")
        if not sender or sender == self.drone_id:
            return
        now = time.time()
        with self._lock:
            self._last_seen[sender] = now
            if sender in self._discovered:
                self._discovered[sender]["last"] = now

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


# ---------- CLI ----------
def main():
    p = argparse.ArgumentParser(description="WEXT Ad-Hoc Swarm Controller")
    p.add_argument("--drone-id", required=True, help="Unique id, e.g., drone_1")
    p.add_argument("--interface", default=None, help="Wi-Fi interface (auto-detected if omitted)")
    p.add_argument("--ssid", default="drone-swarm", help="Ad-Hoc ESSID")
    p.add_argument("--channel", type=int, default=6, help="Channel to create on if no cell exists")
    p.add_argument("--tcp-port", type=int, default=20000)
    p.add_argument("--udp-port", type=int, default=20001)
    p.add_argument("--peer-proto", choices=["TCP", "UDP"], default="TCP",
                   help="Protocol to use for peer links")
    p.add_argument("--hb-interval", type=float, default=3.0,
                   help="Seconds between heartbeats (PING)")
    p.add_argument("--hb-timeout", type=float, default=12.0,
                   help="Seconds of silence before dropping a peer")
    p.add_argument("--setup-net", action="store_true",
                   help="Restore managed Wi-Fi on exit")
    p.add_argument("--debug", action="store_true", help="Enable debug logging")

    args = p.parse_args()
    if args.debug:
        logger.setLevel(logging.DEBUG)

    iface = args.interface or detect_wifi_interface()
    if not iface:
        logger.critical("No Wi-Fi interface found. Pass --interface explicitly.")
        return

    ctrl = Controller(
        drone_id=args.drone_id,
        iface=iface,
        ssid=args.ssid,
        channel=args.channel,
        tcp_port=args.tcp_port,
        udp_port=args.udp_port,
        restore_net=args.setup_net,
        peer_proto=args.peer_proto,
        hb_interval=args.hb_interval,
        hb_timeout=args.hb_timeout
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
    # Ensure unbuffered output when run via sudo
    try:
        os.environ["PYTHONUNBUFFERED"] = "1"
    except Exception:
        pass
    main()
