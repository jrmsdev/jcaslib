#!/bin/sh
MK_ACTION=${1:?'no make action'}
test -z "${MK_ACTION}" && {
    echo "empty make action" >&2
    exit 1
}
for d in `ls */Makefile | sed 's#/Makefile$##'`; do
    make -C ${d} ${MK_ACTION}
done
exit 0
