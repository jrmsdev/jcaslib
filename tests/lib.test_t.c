#include <jcaslib/test.h>
#include "../lib/test/tsuite_start.c"


void
tsuite_start_t (test_suite_T *ts)
{
    int expect = 1;
    test_T *t = t_start (ts, "tsuite_start", expect);

    t_check (t, 0, "");

    t_end (t);
}


int
main (int argc, char *argv[])
{
    if (argc < 1)
        errx (1, "ERROR: argc < 1???");

    int expect = 1;
    test_suite_T *ts = tsuite_start (argv[0], expect);

    tsuite_start_t (ts);

    return (tsuite_end (ts));
}
