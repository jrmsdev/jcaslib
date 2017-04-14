#include <jcaslib/test.h>

test_suite_T *
tsuite_start (const char *name)
{
    test_suite_T *ts = (test_suite_T *) malloc (sizeof (test_suite_T));
    if (ts == NULL)
        errx (1, "%s: t_start malloc failed!", name);

    ts->name = name;
    ts->failed = 0;

    return (ts);
}
