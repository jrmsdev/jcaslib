#include <jcaslib/test.h>

test_T *
t_start (const char *name, int expect)
{
    test_T *t = (test_T *) malloc (sizeof (test_T));
    if (t == NULL)
        errx (1, "t_start malloc failed!");
    t->name = name;
    t->expect = expect;
    return (t);
}
