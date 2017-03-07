#include "test.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


#define EX_NOT_FINISHED 60
#define EX_NOT_STARTED 61


static const char *current_t = NULL;


void
t_start (const char *name)
{
    if (current_t != NULL)
    {
        printf ("current test: %s not finished\n", current_t);
        exit (EX_NOT_FINISHED);
    }
    current_t = name;
}


void
t_end (const char *name)
{
    if (strcmp (name, current_t) != 0)
    {
        printf ("invalid current test: %s\n", name);
        exit (EX_NOT_STARTED);
    }
    current_t = NULL;
}


void
t_log (const char *fmt, ...)
{
    va_list ap;
    va_start (ap, fmt);
    printf ("%s: ", current_t);
    vprintf (fmt, ap);
    va_end (ap);
}


void
t_check (int status, const char *errmsg)
{
    if (status > 0)
    {
        printf ("%s: %s\n", current_t, errmsg);
        exit (status);
    }
}
