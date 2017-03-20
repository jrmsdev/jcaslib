#!/bin/sh
flist=/tmp/jclib-expand-tabs.flist

find * -type f -name '*.c' | sort >$flist
find * -type f -name '*.h' | sort >>$flist
find * -type f -name '*.sh' | sort >>$flist

for fpath in `cat $flist`
do
    expand -t4 $fpath >${fpath}.expand
    diff -q $fpath ${fpath}.expand
    if test $? -eq 1
    then
        cat ${fpath}.expand >${fpath}
    fi
    rm -f ${fpath}.expand
done

rm -f $flist
exit 0
