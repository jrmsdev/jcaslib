#!/bin/sh
set -e
for t in *.test
do
    echo -n "${t}..."
    ./${t} >./${t}.out
    stat=$?
    if test $stat -eq 0
    then
        echo " OK"
        rm -f ./${t}.out
    else
        echo " FAIL"
    fi
done
