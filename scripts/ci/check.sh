#!/bin/sh -ex

CHECK_COV=${CHECK_COV:-"false"}
CHECK_VG=${CHECK_VG:-"false"}

(test "true" = "$CHECK_COV" || test "true" = "$CHECK_VG") || bmake check
test "true" = "$CHECK_VG" && bmake check-valgrind
test "true" = "$CHECK_COV" && bmake check-coverage

export LD_LIBRARY_PATH=./build/lib
export DYLD_LIBRARY_PATH=./build/lib
./build/bin/jcaslib

exit $?
