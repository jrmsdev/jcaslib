#!/bin/sh

if test -z "${TEST_SUITE}"
then
    TEST_SUITE="*.test"
fi

t_total=0
t_ok=0
t_fail=0

for t in ${TEST_SUITE}
do
    echo -n "${t}..."
    ./${t} >./${t}.fail 2>./${t}.fail
    stat=$?
    t_total=`expr $t_total + 1`
    if test $stat -eq 0
    then
        echo " OK"
        t_ok=`expr $t_ok + 1`
        rm -f ./${t}.fail
    else
        echo " FAIL"
        t_fail=`expr $t_fail + 1`
    fi
done

for t in ${TEST_SUITE}
do
    outf=${t}.fail
    test -s $outf && {
        echo
        echo "FAIL: `basename ${outf} .fail`"
        cat $outf
    }
done

echo
echo "Tests: ${t_total}"
echo "   OK: ${t_ok}"
echo " FAIL: ${t_fail}"

exit 0
