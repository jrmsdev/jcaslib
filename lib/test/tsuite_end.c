#include <jcaslib/test.h>

static void free_ts (test_suite_T *ts);

int
tsuite_end (test_suite_T *ts)
{
    int stat = ts->failed;
    free_ts (ts);
    return (stat);
}

void
free_ts (test_suite_T *ts)
{
    free (ts);
    ts = NULL;
}
