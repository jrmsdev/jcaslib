#include <jcaslib/test.h>

static void free_log (test_T *t);
static void show_log (test_T *t);

int
t_end (test_T *t)
{
    int stat = t->failed;
    if (stat == 0)
    {
        warnx ("[ OK ] %s: %d check(s)", t->name, t->run);
    }
    else
    {
        t_log (t, "check(s) ran: %d - failed: %d", t->run, stat);
        show_log (t);
    }
    free_log (t);
    free (t);
    t = NULL;
    return stat;
}

void
free_log (test_T *t)
{
    for (size_t i = 0; i < t->loglines; i++)
    {
        free (t->log[i]);
        t->log[i] = NULL;
    }
    free (t->log);
    t->log = NULL;
}

void
show_log (test_T *t)
{
    for (size_t i = 0; i < t->loglines; i++)
        warnx ("[....] %s: %s", t->name, t->log[i]);
}
