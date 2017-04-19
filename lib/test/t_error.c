#include <jcaslib/test.h>
#include "_test.h"

void
t_error (test_T *t, const char *fmt, ...)
{
    if (t->fatal_error || t->ts->error)
        return;
    t->failed++;
    t->ts->error++;
    va_list ap;
    va_start (ap, fmt);
    _tprint (t, "ERROR:", fmt, ap);
    va_end (ap);
}
