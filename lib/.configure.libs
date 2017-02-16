#!/bin/sh

checklib()
{
    local lname=$1
    local srcf=.checklib-${lname}.c
    local objf=.checklib-${lname}.o
    echo "#include <${lname}.h>" >${srcf}
    echo "int main(void){return 0;}" >>${srcf}
    ${CC} ${CFLAGS} -o ${objf} ${srcf} 2>/dev/null
    ok=$?
    rm -f ${srcf} ${objf}
    if test "${ok}" -eq 0; then
        echo "checklib ${lname} OK"
        return 0
    else
        echo "checklib ${lname} FAIL"
        return 1
    fi
}


uselib_gdbm()
{
    echo "should use gdbm..."
}


check_dbm()
{
    checklib ndbm || {
        (checklib gdbm && uselib_gdbm) || {
            echo "ERR: could not found ndbm nor gdbm libraries..."
            exit 1
        }
    }
}


# MAIN
check_dbm

exit 0
