#include <jcaslib/test.h>

static void free_log (test_T *t);
static void show_log (test_T *t);
static void free_t (test_T *t);

void
t_end (test_T *t)
{
    if (EQ (t->run, t->expect) != 0)
    {
        warnx ("[FAIL] %s: check(s) run(%d) != expect(%d)",
                t->name, t->run, t->expect);
        t->failed++;
    }
    if (t->failed == 0)
    {
        warnx ("[ OK ] %s: %d/%d check(s)", t->name, t->run, t->expect);
    }
    else
    {
        warnx ("[....] %s: check(s) run: %d/%d - fail: %d",
                t->name, t->run, t->expect, t->failed);
        show_log (t);
        t->ts->failed += t->failed;
    }
    free_log (t);
    free_t (t);
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

void
free_t (test_T *t)
{
    t->name = NULL;
    t->expect = 0;
    t->run = 0;
    t->failed = 0;
    t->log = NULL;
    t->loglines = 0;
    t->fatal_error = 0;
    t->ts = NULL;
    free (t);
    t = NULL;
}
