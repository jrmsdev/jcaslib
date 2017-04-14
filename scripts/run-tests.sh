#!/bin/sh

TESTSD=../build/tests

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

echo "jcaslib tests start: `date`"
echo

t_fail=0

for t in ${TEST_SUITE}
do
    #valgrind --leak-check=full ${TESTSD}/${t}
    ${TESTSD}/${t}
    t_fail=`expr $t_fail + $?`
done

echo
echo "check(s) failed: ${t_fail}"
echo "jcaslib tests end: `date`"

exit ${t_fail}
