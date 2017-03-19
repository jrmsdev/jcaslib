#!/bin/sh

version_h=include/jclib/version.h

test -s $version_h || {
    echo "$version_h file not found" >&2
    exit 1
}

vmajor=`grep -F JCL_VERSION_MAJOR include/jclib/version.h | cut -d ' ' -f 3`
vminor=`grep -F JCL_VERSION_MINOR include/jclib/version.h | cut -d ' ' -f 3`
vpatch=`grep -F JCL_VERSION_PATCH include/jclib/version.h | cut -d ' ' -f 3`

if test "$vpatch" -gt 0; then
    echo "${vmajor}.${vminor}.${vpatch}"
else
    echo "${vmajor}.${vminor}"
fi
exit 0
