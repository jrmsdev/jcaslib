#include <jcaslib/test.h>

void
t_check (test_T *t, int status, const char *errmsg)
{
    if (status > 0)
    {
        errx (status, "%s: %s\n", t->name, errmsg);
    }
}
