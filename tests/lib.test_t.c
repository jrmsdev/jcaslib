#include <jcaslib/test.h>
#include "../lib/test/_tfail.c"
#include "../lib/test/_tinfo.c"
#include "../lib/test/_tpass.c"
#include "../lib/test/_tprint.c"
#include "../lib/test/t_check.c"
#include "../lib/test/t_debug.c"
#include "../lib/test/t_end.c"
#include "../lib/test/t_error.c"
#include "../lib/test/t_log.c"
#include "../lib/test/t_fatal.c"
#include "../lib/test/t_start.c"
#include "../lib/test/tsuite_end.c"
#include "../lib/test/tsuite_start.c"


void
fake_t (test_suite_T *ts)
{
    int expect = 1;
    test_T *t = t_start (ts, "fake", expect);

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

    fake_t (ts);

    return (tsuite_end (ts));
}
