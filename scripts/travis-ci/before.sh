#!/bin/sh -ex
bmake distclean
./configure --use-gdbm
bmake depend
exit $?
