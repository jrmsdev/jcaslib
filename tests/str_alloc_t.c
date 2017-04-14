#include "../lib/log/log.c"
#include "../lib/log/log_exit.c"
#include "../lib/lib/xmalloc.c"
#include "../lib/lib/xrealloc.c"
#include "../lib/str/str_alloc.c"
#include "../lib/str/str_realloc.c"
#include "../lib/str/str_free.c"
#include "test.h"


void
str_alloc_t (void)
{
    test_T *t = t_start ("str_alloc");
    str_type *s = str_alloc ();

    t_log (t, "sizeof -> %zu", sizeof (*s));
    t_check (t, EQ (sizeof (*s), 24), "sizeof != 24");

    t_log (t, "STR_ALLOC -> %d", STR_ALLOC);
    t_log (t, "size -> %zu", str_size (s));
    t_check (t, EQ (str_size (s), STR_ALLOC), "size != STR_ALLOC");

    t_log (t, "str_len -> %zu", str_len (s));
    t_check (t, EQ (str_len (s), 0), "str_len != 0");

    str_free (s);
    t_end (t);
}


void
str_realloc_t (void)
{
    test_T *t = t_start ("str_realloc");
    str_type *s = str_alloc ();

    t_log (t, "sizeof -> %zu", sizeof (*s));
    t_check (t, EQ (sizeof (*s), 24), "sizeof != 24");

    t_log (t, "STR_ALLOC -> %d", STR_ALLOC);
    t_log (t, "size -> %zu", str_size (s));
    t_check (t, EQ (str_size (s), STR_ALLOC), "size != STR_ALLOC");

    str_realloc (s);
    t_log (t, "resized -> %zu", str_size (s));
    t_check (t, EQ (str_size (s), (STR_ALLOC * 2)),
                    "resized != (STR_ALLOC * 2)");

    str_free (s);
    t_end (t);
}


int
main (void)
{
    str_alloc_t ();
    str_realloc_t ();
    return (0);
}
