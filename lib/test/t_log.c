#include <jcaslib/test.h>
#include <stdarg.h>
#include <stdio.h>

void
t_log (test_T *t, const char *fmt, ...)
{
    va_list ap;
    va_start (ap, fmt);
    printf ("%s: ", t->name);
    vprintf (fmt, ap);
    printf ("\n");
    va_end (ap);
}
