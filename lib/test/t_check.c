#include <jcaslib/test.h>

void
t_check (test_T *t, int status, const char *errmsg)
{
    t->run++;
    if (status > 0)
    {
        t->failed++;
        errx (status, "%s: %s\n", t->name, errmsg);
    }
}
