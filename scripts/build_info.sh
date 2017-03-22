#!/bin/sh

set -e

addline() {
    local _NAME="$1"
    shift
    local _VAL="$@"
    if test -n "$REPRODUCIBLE_BUILD"
    then
        _VAL="REPRODUCIBLE_BUILD"
    fi
    echo "#define ${_NAME} \"${_VAL}\"" >>.build_info.h
}

test -s build_info.c || {
    echo "ERR: ${0} not running from source lib dir" >&2
    exit 1
}

rm -f .build_info.h
addline JCASLIB_BUILD_TIME "`date`"
addline JCASLIB_BUILD_BY "`id -un`@`uname -n`"
addline JCASLIB_BUILD_OS "`uname -snrm`"
addline JCASLIB_CC_VERSION "`${CC} --version | head -n 1`"
addline JCASLIB_MODULES "`ls ../../lib/*/Makefile | sed 's#/Makefile##' |
        sed 's#^\.\./\.\./lib/##' | sort | xargs echo`"

exit 0
