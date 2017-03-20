#include "../lib/log/log.c"
#include "../lib/log/log_exit.c"
#include "../lib/lib/xmalloc.c"
#include "../lib/lib/xrealloc.c"
#include "../lib/str/str_alloc.c"
#include "../lib/str/str_realloc.c"
#include "../lib/str/str_free.c"
#include "../lib/str/str_cat.c"
#include "../lib/str/str_ncat.c"
#include "../lib/str/str_join.c"
#include "../lib/str/str_vjoin.c"
#include "../lib/path/path_join.c"
#include "test.h"


void
path_join_t (void)
{
    t_start ("path_join");
    str_type *p = str_alloc ();

    path_join (p, 3, "/path", "join", "test");

    t_log ("path len: %zu", str_len (p));
    t_log ("path: %s", str_get (p));

    t_check (EQ (str_len (p), 15), "path len != 15");
    t_check (strcmp (str_get (p), "/path/join/test"), "path != /path/join/test");

    str_free (p);
    t_end ("path_join");
}


int
main (void)
{
    path_join_t ();
    return (0);
}
