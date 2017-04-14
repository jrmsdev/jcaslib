#!/bin/sh

test -z "${TEST_SUITE}" && {
    echo "ERR: no test suite" >&2
    exit 1
}

test -s ../lib/test/test.c || {
    echo "ERR: running from invalid dir?" >&2
    echo "ERR: ../lib/test/test.c file not found" >&2
    exit 1
}

TESTSD=../build/tests

echo "jcaslib tests start: `date`"
echo

t_total=0
t_ok=0
t_fail=0

for t in ${TEST_SUITE}
do
    tn=`echo "$t" | sed 's#\.run##'`
    printf "%s..." ${tn}
    ${TESTSD}/${t} >${TESTSD}/${tn}.fail 2>${TESTSD}/${tn}.fail
    stat=$?
    t_total=`expr $t_total + 1`
    if test $stat -eq 0
    then
        echo " OK"
        t_ok=`expr $t_ok + 1`
        rm -f ${TESTSD}/${tn}.fail
    else
        echo " FAIL"
        echo "STATUS: ${stat}" >>${TESTSD}/${tn}.fail
        t_fail=`expr $t_fail + 1`
    fi
done

for t in ${TEST_SUITE}
do
    tn=`echo "$t" | sed 's#\.run##'`
    outf=${TESTSD}/${tn}.fail
    test -s $outf && {
        echo
        echo "FAIL: ${tn}"
        cat $outf
    }
done

echo
echo "Tests:${t_total} OK:${t_ok} FAIL:${t_fail}"
echo "jcaslib tests end: `date`"

exit 0
