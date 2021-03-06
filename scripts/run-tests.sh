#!/bin/sh

TESTSD=../build/tests
CHECK_VALGRIND=false
CHECK_COVERAGE=${CHECK_COVERAGE:-'false'}

test -z "${TEST_SUITE}" && {
    echo "ERR: no test suite" >&2
    exit 1
}

test -d ../lib/test || {
    echo "ERR: not running from inside tests dir?" >&2
    exit 1
}

test -d ${TESTSD} || {
    echo "ERR: not running from inside tests dir?" >&2
    exit 1
}

if test "--valgrind" = "$1"
then
    CHECK_VALGRIND=true
    which valgrind >/dev/null 2>/dev/null || {
        echo "ERR: valgrind command not found" >&2
        exit 1
    }
fi

echo "jcaslib tests start: `date`"
echo "jcaslib check valgrind:$CHECK_VALGRIND coverage:$CHECK_COVERAGE"
echo
t_START=`date '+%s'`

t_FAIL=0
t_FILES=0

for t in ${TEST_SUITE}
do
    tname=${t}_t
    t_FILES=`expr 1 + $t_FILES`
    if $CHECK_VALGRIND
    then
        vgout=${TESTSD}/${tname}.vgout.$$
        valgrind --quiet --leak-check=full --log-file=${vgout} ${TESTSD}/${tname}.run
        vgstat=$?
        t_FAIL=`expr $t_FAIL + $vgstat`
        if test -s ${vgout}
        then
            echo "${tname}: [FAIL] valgrind report not empty"
            echo "${tname}: [....] ${vgout}"
            if test 0 -eq $vgstat
            then
                t_FAIL=`expr 1 + $t_FAIL`
            fi
        else
            rm -f ${vgout}
        fi
    else
        ${TESTSD}/${tname}.run
        t_FAIL=`expr $t_FAIL + $?`
    fi
done

t_END=`date '+%s'`
echo
echo "_t files: ${t_FILES} - check(s) failed: ${t_FAIL} - in $(expr $t_END - $t_START) second(s)"
echo "jcaslib tests end: `date`"

exit ${t_FAIL}
