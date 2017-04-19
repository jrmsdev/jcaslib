#include <jcaslib/test.h>
#include "_test.h"

void
t_fatal (test_T *t, int status, const char *fmt, ...)
{
    if (t->fatal_error || t->ts->error)
        return;
    t->run++;
    if (status > 0)
    {
        t->failed++;
        t->fatal_error = 1;
        va_list ap;
        va_start (ap, fmt);
        _tprint (t, "FATAL:", fmt, ap);
        va_end (ap);
    }
}
