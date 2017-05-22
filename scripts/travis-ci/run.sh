#!/bin/sh -ex

bmake depend
./build/bin/jcaslib.static

bmake -j2
bmake examples
bmake dist

(test "true" = "$CHECK_VG" || test "true" = "$CHECK_COVERAGE") || bmake check
test "true" = "$CHECK_VG" && bmake check-valgrind
test "true" = "$CHECK_COVERAGE" && bmake check-coverage

export LD_LIBRARY_PATH=./build/lib
export DYLD_LIBRARY_PATH=./build/lib
./build/bin/jcaslib

exit $?
