#include <jcaslib/test.h>

void
_tprint (test_T *t, const char *tag, const char *fmt, va_list ap)
{
    //~ printf ("%s %20s: %15s: ", tag, basename (t->ts->progname), t->name);
    printf ("%s %-15s %-15s ", tag, t->ts->name, t->name);
    vprintf (fmt, ap);
    printf ("\n");
}
