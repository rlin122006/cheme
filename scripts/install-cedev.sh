#!/usr/bin/env bash
set -euo pipefail

VERSION="v15.0" # pin version
URL="https://github.com/CE-Programming/toolchain/releases/download/${VERSION}/CEdev-Linux.tar.gz"

ROOT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/.." && pwd)"
TOOLCHAIN_DIR="$ROOT_DIR/.toolchain"
DEST="$TOOLCHAIN_DIR/CEdev"
TMP_DIR="$(mktemp -d)"

cleanup() {
  rm -rf -- "$TMP_DIR"
}
trap cleanup EXIT

mkdir -p "$TOOLCHAIN_DIR"

echo "Downloading CE C/C++ Toolchain ${VERSION}..."
curl --fail --location --retry 3 --output "$TMP_DIR/CEdev-Linux.tar.gz" "$URL"

echo "Extracting CEdev..."
tar -xzf "$TMP_DIR/CEdev-Linux.tar.gz" -C "$TMP_DIR"

if [[ ! -d "$TMP_DIR/CEdev" ]]; then
  echo "Error: the release archive did not contain a CEdev directory." >&2
  exit 1
fi

rm -rf -- "$DEST"
mv -- "$TMP_DIR/CEdev" "$DEST"

find "$DEST/bin" "$DEST/binutils/bin" -type f -exec chmod u+x {} +

for tool in \
  "$DEST/bin/ez80-clang" \
  "$DEST/bin/ez80-link" \
  "$DEST/bin/cedev-config" \
  "$DEST/binutils/bin/z80-none-elf-as" \
  "$DEST/binutils/bin/z80-none-elf-ld"; do
  if [[ ! -x "$tool" ]]; then
    echo "Error: expected CEdev executable was not found: $tool" >&2
    exit 1
  fi
done

echo
echo "CEdev ${VERSION} installed at: $DEST"
