#include <jcaslib/test.h>

#include <stdarg.h>

void
t_log (test_T *t, const char *fmt, ...)
{
    va_list ap;
    va_start (ap, fmt);
    warnx ("%s: ", t->name);
    vwarnx (fmt, ap);
    warnx ("\n");
    va_end (ap);
}
