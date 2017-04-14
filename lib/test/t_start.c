#include <jcaslib/test.h>

test_T *
t_start (const char *name, int expect)
{
    test_T *t = (test_T *) malloc (sizeof (test_T));
    if (t == NULL)
        errx (1, "%s: t_start malloc failed!", name);
    t->name = name;
    t->expect = expect;
    t->run = 0;
    t->failed = 0;
    t->log = NULL;
    t->loglines = 0;
    return (t);
}
