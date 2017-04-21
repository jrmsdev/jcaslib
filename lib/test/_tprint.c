#include <jcaslib/test.h>
#include "_test.h"

void
_tprint (test_T *t, const char *tag, const char *fmt, va_list ap)
{
    printf (_COLUMS_FORMAT, tag, t->ts->name, t->name);
    printf (" ");
    vprintf (fmt, ap);
    printf ("\n");
}
