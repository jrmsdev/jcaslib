#include <jcaslib/test.h>
#include "__t_print.h"

void
t_debug (test_T *t, const char *fmt, ...)
{
    if (t->fatal_error || t->ts->error)
        return;

    if (!t->ts->DEBUG && !t->DEBUG)
        return;

    va_list ap;
    va_start (ap, fmt);

    __t_print (t, "DEBUG:", fmt, ap);

    va_end (ap);
}
