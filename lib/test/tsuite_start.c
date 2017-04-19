#include <jcaslib/test.h>

test_suite_T *
tsuite_start (const char *progname)
{
    test_suite_T *ts = (test_suite_T *) malloc (sizeof (test_suite_T));
    if (ts == NULL)
        errx (1, "%s: t_start malloc failed!", progname);

    ts->progname = progname;
    ts->failed = 0;
    ts->error = 0;

    warnx ("DEBUG: ts->progname: %s", ts->progname);

    return (ts);
}
