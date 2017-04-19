#include <jcaslib/test.h>

test_T *
t_start (test_suite_T *ts, const char *name, int expect)
{
    test_T *t = (test_T *) malloc (sizeof (test_T));
    if (t == NULL)
        errx (1, "%s: t_start malloc failed!", name);

    t->DEBUG = 0;
    t->name = name;
    t->expect = expect;
    t->run = 0;
    t->failed = 0;
    t->log = NULL;
    t->loglines = 0;
    t->fatal_error = 0;
    t->ts = ts;

    return (t);
}
