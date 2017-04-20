#!/bin/sh

GCOV_CC=${GCOV_CC:-"gcc"}
GCOV_CMD=${GCOV_CMD:-"gcov"}
GCOV_ARGS=${GCOV_ARGS:-"-b -f -p"}

which $GCOV_CC >/dev/null 2>/dev/null || {
    echo "${GCOV_CC} command not found" >&2
    exit 1
}
which $GCOV_CMD >/dev/null 2>/dev/null || {
    echo "${GCOV_CMD} command not found" >&2
    exit 1
}

gcov_cc_version=`$GCOV_CC --version | head -n1 | cut -d')' -f'2-'`
gcov_cmd_version=`$GCOV_CMD --version | head -n1 | cut -d')' -f'2-'`

if test "$gcov_cc_version" != "$gcov_cmd_version"
then
    echo "gcov cc and cmd versions missmatch" >&2
    echo "CC=$GCOV_CC CMD=$GCOV_CMD" >&2
    exit 1
fi

for src_f in *.c
do
    run_cmd="$GCOV_CMD $GCOV_ARGS $src_f"
    echo $run_cmd
    $run_cmd >/dev/null
done

exit 0
