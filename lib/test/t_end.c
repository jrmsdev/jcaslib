#include <jcaslib/test.h>
#include "_test.h"

static void free_log (test_T *t);
static void show_log (test_T *t);
static void free_t (test_T *t);

void
t_end (test_T *t)
{
    t->ts->run++;
    if (EQ (t->run, t->expect) != 0)
    {
        _tfail (t, "check(s) run(%d) != expect(%d)", t->run, t->expect);
        t->failed++;
    }
    if (t->failed == 0)
    {
        _tpass (t, "%d/%d check(s)", t->run, t->expect);
    }
    else
    {
        _tinfo (t, "check(s) run: %d/%d - fail: %d",
                t->run, t->expect, t->failed);
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
        _tinfo (t, "%s", t->log[i]);
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
