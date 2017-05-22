#!/bin/sh -ex

bmake examples
bmake dist

export LD_LIBRARY_PATH=./build/lib
export DYLD_LIBRARY_PATH=./build/lib
./build/bin/jcaslib

exit $?
