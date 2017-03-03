#!/bin/sh

if test -z "${TEST_SUITE}"
then
    TEST_SUITE="*_t.run"
fi

echo "jclib test start: `date -R`"
echo

t_total=0
t_ok=0
t_fail=0

for t in ${TEST_SUITE}
do
    tn=`basename $t .run`
    echo -n "${tn}..."
    ./${t} >./${tn}.fail 2>./${tn}.fail
    stat=$?
    t_total=`expr $t_total + 1`
    if test $stat -eq 0
    then
        echo " OK"
        t_ok=`expr $t_ok + 1`
        rm -f ./${tn}.fail
    else
        echo " FAIL"
        t_fail=`expr $t_fail + 1`
    fi
done

for t in ${TEST_SUITE}
do
    tn=`basename $t .run`
    outf=${tn}.fail
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
