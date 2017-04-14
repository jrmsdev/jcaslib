#include <jcaslib/test.h>

#include <stdarg.h>

void
t_log (test_T *t, const char *fmt, ...)
{
    va_list ap;
    va_start (ap, fmt);
    char *msg;
    vasprintf (&msg, fmt, ap);
    va_end (ap);
    warnx ("       %s: %s", t->name, msg);
    free (msg);
    msg = NULL;
}
