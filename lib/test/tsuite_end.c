#include <jcaslib/test.h>
#include "_test.h"

static void free_ts (test_suite_T *ts);

int
tsuite_end (test_suite_T *ts)
{
    int stat = ts->failed;

    if (ts->expect == 0)
    {
        printf (_COLUMS_FORMAT, "[FAIL]", ts->name, "expects not to run any test\n");
        stat++;
    }
    else if (ts->run == 0)
    {
        printf (_COLUMS_FORMAT, "[FAIL]", ts->name, "no tests ran\n");
        stat++;
    }
    else if (EQ (ts->run, ts->expect) != 0)
    {
        printf (_COLUMS_FORMAT, "[FAIL]", ts->name, "tests count");
        printf (" run(%d) != expect(%d)\n", ts->run, ts->expect);
        stat++;
    }

    free_ts (ts);
    return (stat);
}

void
free_ts (test_suite_T *ts)
{
    ts->progname = NULL;
    ts->failed = 0;
    ts->error = 0;
    ts->name = NULL;
    ts->namelen = 0;
    ts->expect = 0;
    ts->run = 0;

    free (ts);
    ts = NULL;
}
