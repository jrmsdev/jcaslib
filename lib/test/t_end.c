#include <jcaslib/test.h>

int
t_end (test_T *t)
{
    int stat = t->failed;
    if (stat == 0)
        warnx ("[ OK ] %s: %d check(s)", t->name, t->run);
    else
        t_log (t, "check(s) ran: %d - failed: %d", t->run, stat);
    free (t);
    t = NULL;
    return stat;
}
