#!/bin/sh
set -e
./configure --use-gdbm
bmake
bmake examples
bmake dist
exit 0
