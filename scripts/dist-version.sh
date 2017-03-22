#!/bin/sh

version_h=version.h

test -s $version_h || {
    echo "$version_h file not found" >&2
    exit 1
}

vmajor=`grep -F JCASLIB_VERSION_MAJOR $version_h | cut -d ' ' -f 3`
vminor=`grep -F JCASLIB_VERSION_MINOR $version_h | cut -d ' ' -f 3`
vpatch=`grep -F JCASLIB_VERSION_PATCH $version_h | cut -d ' ' -f 3`

if test "$vpatch" -gt 0; then
    echo "${vmajor}.${vminor}.${vpatch}"
else
    echo "${vmajor}.${vminor}"
fi

exit 0
