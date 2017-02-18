#!/bin/sh

set -e

addline() {
    local _NAME="$1"
    shift
    local _VAL="$@"
    echo "#define ${_NAME} \"${_VAL}\"" >>.build_info.h
}

test -s lib.c || {
    echo "ERR: ${0} not running from source lib dir" >&2
    exit 1
}

rm -f .build_info.h
addline JCL_BUILD_TIME "`date -R`"
addline JCL_BUILD_BY "`id -un`@`uname -n`"
addline JCL_BUILD_EPOCH "`date '+%s'`"
addline JCL_BUILD_OS "`uname -snrm`"
addline JCL_CC_VERSION "`${CC} --version | head -n 1`"
addline JCL_MODULES "`ls ${INCD}/*.h | grep -Ev '^uselib\.' | sort | \
            sed "s#${INCD}/##" | sed 's/\.h//' | xargs echo`"

exit 0
