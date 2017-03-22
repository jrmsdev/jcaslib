#!/bin/sh

srch=${1:?'search string?'}
repl=${2:?'replace string?'}
echo "$srch -> $repl"
for fpath in `grep -Frl --exclude='.git/*' $srch * .??* | sort`
do
    sed "s/${srch}/${repl}/g" $fpath >${fpath}.new
    diff -q $fpath ${fpath}.new
    if test $? -eq 1
    then
        cat ${fpath}.new >${fpath}
    fi
    rm -f ${fpath}.new
done

exit 0
