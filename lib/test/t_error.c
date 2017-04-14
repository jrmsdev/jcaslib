#include <jcaslib/test.h>

void
t_error (test_T *t, const char *errmsg)
{
    if (t->fatal_error || t->ts->error)
        return;
    t->failed++;
    t->ts->error++;
    warnx ("[FAIL] %s: ERROR - %s", t->name, errmsg);
}
