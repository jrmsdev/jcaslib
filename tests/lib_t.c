#include "../lib/log/log.c"
#include "../lib/log/log_exit.c"
#include "../lib/lib/xmalloc.c"
#include "../lib/lib/xrealloc.c"
#include <jcaslib/test.h>
#include <string.h>


int
xrealloc_t (void)
{
    test_T *t = t_start ("xrealloc", 3);

    char *p = (char *) xmalloc (50);
    t_check (t, EQ (p[49], '\0'), "initial p[49] != \\0");

    p = (char *) xrealloc (p, 60);
    memset (p + 50, 'T', 10);

    t_check (t, EQ (p[49], '\0'), "p[49] != \\0");
    t_check (t, EQ (p[59], 'T'), "p[59] != T");

    t_log (t, "%s", "LOG TEST");
    t_check (t, 1, "LOG FAIL");

    free (p);
    return (t_end (t));
}


int
xmalloc_t (void)
{
    test_T *t = t_start ("xmalloc", 3);
    char *p = (char *) xmalloc (50);

    t_check (t, EQ (p[0], '\0'), "xmalloc: p[0] != \\0");
    t_check (t, EQ (p[24], '\0'), "xmalloc: p[24] != \\0");
    t_check (t, EQ (p[49], '\0'), "xmalloc: p[49] != \\0");

    free (p);
    return (t_end (t));
}


int
main (void)
{
    int failed = 0;
    failed += xmalloc_t ();
    failed += xrealloc_t ();
    return (failed);
}
