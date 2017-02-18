#!/bin/sh

checklib()
{
    local lname=$1
    shift
    local srcs=$@
    local libf=.checklib-${lname}.c
    rm -f ${libf}
    touch ${libf}
    for l in ${srcs}; do
        echo "#include <${l}>" >>${libf}
        echo "int main(void){return 0;}" >>${libf}
        ${CC} ${CFLAGS} -o /dev/null ${libf} 2>/dev/null
        ret=$?
        rm -f ${libf}
        if test "${ret}" -eq 0; then
            echo "checklib ${l} OK"
        else
            echo "checklib ${l} FAIL"
            return 1
        fi
    done
    return 0
}


uselib()
{
    local lname="$1"
    shift
    local srcs=$@
    local libf=uselib.${lname}.h
    rm -f ${libf}
    touch ${libf}
    for l in ${srcs}; do
        echo "#include <${l}>" >>${libf}
    done
}


check_dbm()
{
    uselib dbm ndbm.h
    checklib dbm ndbm.h || {
        (checklib dbm gdbm.h && uselib dbm gdbm.h) || {
            echo "ERR: could not found ndbm nor gdbm libraries..."
            exit 1
        }
    }
}


# MAIN
test -s lib.c || {
    echo "ERR: ${0} not running from source lib dir" >&2
    exit 1
}
check_dbm

exit 0
