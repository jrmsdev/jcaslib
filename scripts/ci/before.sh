#!/bin/sh -ex

CC=${CC:-"gcc"}
CHECK_VG=${CHECK_VG:-"false"}

apt-get -qq update && apt-get -qq -y $APTARGS install $DEBPKGS $CC

test "true" = "$CHECK_VG" && apt-get -qq -y $APTARGS install valgrind

$CC --version

test "true" = "$CHECK_VG" && valgrind --version

bmake distclean
./configure --use-gdbm

bmake depend
bmake -j2

./build/bin/jcaslib.static
exit $?
