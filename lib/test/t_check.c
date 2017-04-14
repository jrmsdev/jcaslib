#include <jcaslib/test.h>

void
t_check (test_T *t, int status, const char *errmsg)
{
    t->run++;
    if (status > 0)
    {
        t->failed++;
        t_log (t, "[FAIL] %s: %s (%d)\n", t->name, errmsg, status);
    }
}
