#include "../lib/lib/xmalloc.c"
#include "../lib/lib/xrealloc.c"
#include "test.h"
#include <string.h>


void
xrealloc_t (void)
{
    t_start ("xrealloc");
    char *p = (char *) xmalloc (50);
    t_check (EQ (p[49], '\0'), "xrealloc: initial p[49] != \\0");

    p = (char *) xrealloc (p, 60);
    memset (p + 50, 'T', 10);

    t_check (EQ (p[49], '\0'), "xrealloc: p[49] != \\0");
    t_check (EQ (p[59], 'T'), "xrealloc: p[59] != T");

    free (p);
    t_end ("xrealloc");
}


void
xmalloc_t (void)
{
    t_start ("xmalloc");
    char *p = (char *) xmalloc (50);

    t_check (EQ (p[0], '\0'), "xmalloc: p[0] != \\0");
    t_check (EQ (p[24], '\0'), "xmalloc: p[24] != \\0");
    t_check (EQ (p[49], '\0'), "xmalloc: p[49] != \\0");

    free (p);
    t_end ("xmalloc");
}


int
main (void)
{
    xmalloc_t ();
    xrealloc_t ();
    return (0);
}
