#!/bin/sh -ex

CC=${CC:-"gcc"}
CHECK_VG=${CHECK_VG:-"false"}

export DEBIAN_FRONTEND=noninteractive

if test "--no-apt" != "$1"; then
    apt-get -qq update && apt-get -qq -y $APTARGS install $DEBPKGS $CC
    test "true" = "$CHECK_VG" && apt-get -qq -y $APTARGS install valgrind
fi

$CC --version
test "true" = "$CHECK_VG" && valgrind --version

bmake distclean
./configure --use-gdbm
