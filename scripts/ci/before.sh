#!/bin/sh -ex

apt-get -qq update && apt-get -qq -y $APTARGS install $DEBPKGS $CC

test "true" = "$CHECK_VG" && apt-get -qq -y $APTARGS install valgrind

$CC --version

./configure --use-gdbm

bmake depend

exit $?
