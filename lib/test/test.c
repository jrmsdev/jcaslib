#include <jcaslib/test.h>

#include <err.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


test_T *
t_start (const char *name)
{
    test_T *t = (test_T *) malloc (sizeof (test_T));
    if (t == NULL)
        errx (1, "t_start malloc failed!");
    t->name = name;
    t->end = 0;
    return (t);
}


void
t_end (test_T *t)
{
    free (t);
    t = NULL;
}


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


void
t_check (test_T *t, int status, const char *errmsg)
{
    if (status > 0)
    {
        printf ("%s: %s\n", t->name, errmsg);
        exit (status);
    }
}
