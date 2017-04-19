#include <jcaslib/test.h>

void
_tprint (test_T *t, const char *tag, const char *fmt, va_list ap)
{
    printf ("%s %s: %s: ", tag, t->ts->progname, t->name);
    vprintf (fmt, ap);
    printf ("\n");
}
