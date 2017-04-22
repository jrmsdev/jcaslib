#include <jcaslib/lib.h>
#include <jcaslib/test.h>

#include <string.h>


void
xrealloc_t (test_suite_T *ts)
{
    test_T *t = t_start (ts, "xrealloc", 3);

    t->DEBUG = 0;
    if (t->DEBUG)
    {
        t_debug (t, "LALALA");
        t_check (t, 15, "TEST: initial p[49] != \\0");
    }

    char *p = (char *) xmalloc (50);
    t_check (t, EQ (p[49], '\0'), "initial p[49] != \\0");

    p = (char *) xrealloc (p, 60);
    memset (p + 50, 'T', 10);

    t_check (t, EQ (p[49], '\0'), "p[49] != \\0");
    t_check (t, EQ (p[59], 'T'), "p[59] != T");

    free (p);
    t_end (t);
}


void
xmalloc_t (test_suite_T *ts)
{
    test_T *t = t_start (ts, "xmalloc", 3);
    char *p = (char *) xmalloc (50);

    t_check (t, EQ (p[0], '\0'), "xmalloc: p[0] != \\0");
    t_check (t, EQ (p[24], '\0'), "xmalloc: p[24] != \\0");
    t_check (t, EQ (p[49], '\0'), "xmalloc: p[49] != \\0");

    free (p);
    t_end (t);
}


int
main (int argc, char *argv[])
{
    if (argc < 1)
        errx (1, "ERROR: argc < 1???");

    int expect = 2;
    test_suite_T *ts = tsuite_start (argv[0], expect);

    xmalloc_t (ts);
    xrealloc_t (ts);

    return (tsuite_end (ts));
}
