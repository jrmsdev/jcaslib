#!/bin/sh

test -s test.c || {
    echo "ERR: not runnin from tests dir" >&2
    exit 1
}

test -z "${CC}" && {
    echo "ERR: no CC var set" >&2
    exit 1
}

test -z "${INCD}" && {
    echo "ERR: no INCD var set" >&2
    exit 1
}

for t in ../lib/*/*_t.c
do
    tn=`echo ${t} | sed 's#^\.\./lib\/##'`
    tp=../build/tests/$(echo $tn | sed 's/\.c/.run/')
    ${CC} -I${INCD} -E -MM ${t} | sed "s#^\(.*\)\.o:#${tp}:#"
done

exit 0
