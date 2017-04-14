#include <jcaslib/test.h>

void
t_error (test_T *t, const char *errmsg)
{
    t->failed++;
    int stat = t->failed;
    warnx ("[FAIL] %s: ERROR - %s", t->name, errmsg);
    t_end (t);
    exit (stat);
}
