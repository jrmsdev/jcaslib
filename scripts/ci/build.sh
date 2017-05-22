#!/bin/sh -ex

bmake depend
bmake -j2
./build/bin/jcaslib.static

bmake examples
bmake dist

export LD_LIBRARY_PATH=./build/lib
export DYLD_LIBRARY_PATH=./build/lib
./build/bin/jcaslib
