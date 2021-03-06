#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <stdio.h>
#include "includes_t.h"
#ifndef INCLUDED_FILES
#define INCLUDED_FILES "-1"
#endif
#include <jcaslib/test.h>

void includes_t (test_suite_T *ts) {
    int expect = 1;
    test_T *t = t_start (ts, INCLUDED_FILES " file(s)", expect);
    t_check (t, 0, "");
    t_end (t);
}

int main (int argc, char *argv[]) {
    if (argc < 1)
    errx (1, "ERROR: argc < 1???");
    int expect = 1;
    test_suite_T *ts = tsuite_start (argv[0], expect);
    includes_t (ts);
    return (tsuite_end (ts));
}
