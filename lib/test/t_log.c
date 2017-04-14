#include <jcaslib/test.h>
#include <stdarg.h>

static void addline (test_T *t, char *msg);

void
t_log (test_T *t, const char *fmt, ...)
{
    if (t->fatal_error)
        return;
    va_list ap;
    va_start (ap, fmt);
    char *msg;
    vasprintf (&msg, fmt, ap);
    va_end (ap);
    addline (t, msg);
}

void
addline (test_T *t, char *msg)
{
    char **newlog = (char **) realloc (t->log,
            sizeof (char *) * (t->loglines + 1));

    if (newlog == NULL)
        errx (1, "%s: t_log newlog realloc failed!", t->name);

    t->log = newlog;
    t->log[t->loglines] = msg;
    t->loglines++;
}
