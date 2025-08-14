#!/usr/bin/env bash
# Usage: ./install_drone_requirements.sh [requirements-file]
# Default file: drone_app_system_requirements.txt

set -euo pipefail

REQ_FILE="${1:-drone_app_system_requirements.txt}"

if [[ ! -f "$REQ_FILE" ]]; then
  echo "Requirements file not found: $REQ_FILE" >&2
  exit 1
fi

sudo apt-get update
# Strip comments and blank lines, then install
xargs -a <(sed -e 's/#.*//' -e '/^\s*$/d' "$REQ_FILE") -r sudo apt-get install -y

echo "Done. Verify tools:"
echo "  nmcli --version"
echo "  iw --version"
echo "  iwconfig --version || true"
echo "  ip -V"
echo "  python3 --version"
