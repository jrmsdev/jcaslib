#include <jcaslib/test.h>

void
__t_print (test_T *t, const char *tag, const char *fmt, va_list ap)
{
    if (t->fatal_error || t->ts->error)
        return;

    if (!t->ts->DEBUG && !t->DEBUG)
        return;

    printf ("%s: %s %s: ", t->ts->progname, tag, t->name);
    vprintf (fmt, ap);
    printf ("\n");
}
