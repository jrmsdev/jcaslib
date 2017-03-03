#include "../lib/lib.c"
#include "test.h"
#include <stdlib.h>
#include <string.h>


void
xrealloc_t (void)
{
    char *p = (char *) xmalloc (50);
    p = (char *) xrealloc (p, 60);
    memset (p + 50, 'T', 10);
    t_check (EQ (p[49], '\0'), "xrealloc: p[49] != \\0");
    t_check (EQ (p[59], 'T'), "xrealloc: p[59] != T");
    free (p);
}


void
xmalloc_t (void)
{
    char *p = (char *) xmalloc (50);
    t_check (EQ (p[0], '\0'), "xmalloc: p[0] != \\0");
    t_check (EQ (p[24], '\0'), "xmalloc: p[24] != \\0");
    t_check (EQ (p[49], '\0'), "xmalloc: p[49] != \\0");
    free (p);
}


int
main (void)
{
    xmalloc_t ();
    xrealloc_t ();
    return (0);
}
