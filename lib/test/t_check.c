#include <jcaslib/test.h>
#include "_test.h"

void
t_check (test_T *t, int status, const char *errmsg)
{
    if (t->fatal_error || t->ts->error)
        return;
    t->run++;
    if (status > 0)
    {
        t->failed++;
        _tfail (t, "%s (%d)", errmsg, status);
    }
}
