#include <jcaslib/test.h>

void
t_check (test_T *t, int status, const char *errmsg)
{
    t->run++;
    if (status > 0)
    {
        t->failed++;
        warnx ("[FAIL] %s: %s (%d)", t->name, errmsg, status);
    }
}
