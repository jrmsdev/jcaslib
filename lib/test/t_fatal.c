#include <jcaslib/test.h>

void
t_fatal (test_T *t, int status, const char *errmsg)
{
    t->run++;
    if (status > 0)
    {
        t->failed++;
        t->fatal_error = 1;
        warnx ("[FAIL] FATAL %s: %s (%d)", t->name, errmsg, status);
    }
}
