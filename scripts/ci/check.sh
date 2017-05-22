#!/bin/sh -ex

($CHECK_COV || $CHECK_VG) || bmake check
$CHECK_VG && bmake check-valgrind
$CHECK_COV && bmake check-coverage

export LD_LIBRARY_PATH=./build/lib
export DYLD_LIBRARY_PATH=./build/lib
./build/bin/jcaslib

exit $?
