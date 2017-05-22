#!/bin/sh -ex

CHECK_COVERAGE=${CHECK_COVERAGE:-"false"}
CHECK_VG=${CHECK_VG:-"false"}

echo CHECK_COVERAGE="$CHECK_COVERAGE" >/dev/null
echo CHECK_VG="$CHECK_VG" >/dev/null

bmake -j2
./build/bin/jcaslib.static

bmake examples
bmake dist

(test "true" = "$CHECK_VG" || test "true" = "$CHECK_COVERAGE") || bmake check
test "true" = "$CHECK_VG" && bmake check-valgrind
test "true" = "$CHECK_COVERAGE" && bmake check-coverage

export LD_LIBRARY_PATH=./build/lib
export DYLD_LIBRARY_PATH=./build/lib
./build/bin/jcaslib

exit $?
