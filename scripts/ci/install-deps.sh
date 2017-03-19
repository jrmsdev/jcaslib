#!/bin/sh
set -e
export DEBIAN_FRONTEND="noninteractive"
apt-get update && apt-get install -y bmake libgdbm-dev
exit 0
