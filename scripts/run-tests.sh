#!/bin/sh

test -z "${TEST_SUITE}" && {
    echo "ERR: no test suite" >&2
    exit 1
}

test -s test.c || {
    echo "ERR: not running from tests dir" >&2
    exit 1
}

echo "jclib test start: `date -R`"
echo

t_total=0
t_ok=0
t_fail=0

for t in ${TEST_SUITE}
do
    tn=`echo "$t" | sed 's#\.run##'`
    echo -n "${tn}..."
    ../build/tests/${t} >../build/tests/${tn}.fail 2>../build/tests/${tn}.fail
    stat=$?
    t_total=`expr $t_total + 1`
    if test $stat -eq 0
    then
        echo " OK"
        t_ok=`expr $t_ok + 1`
        rm -f ../build/tests/${tn}.fail
    else
        echo " FAIL"
        echo "STATUS: ${stat}" >>../build/tests/${tn}.fail
        t_fail=`expr $t_fail + 1`
    fi
done

for t in ${TEST_SUITE}
do
    tn=`echo "$t" | sed 's#\.run##'`
    outf=../build/tests/${tn}.fail
    test -s $outf && {
        echo
        echo "FAIL: ${tn}"
        cat $outf
    }
done

echo
echo -n "Tests:${t_total}"
echo -n " OK:${t_ok}"
echo " FAIL:${t_fail}"
echo "jclib test end: `date -R`"

exit 0
