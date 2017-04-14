#include <jcaslib/test.h>

void
t_fatal (test_T *t, int status, const char *errmsg)
{
    if (t->fatal_error || t->ts->error)
        return;
    t->run++;
    if (status > 0)
    {
        t->failed++;
        t->fatal_error = 1;
        warnx ("[FAIL] %s: FATAL - %s (%d)", t->name, errmsg, status);
    }
}
