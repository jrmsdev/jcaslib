#include <jclib/path.h>
#include <stdio.h>

int
main (int argc, char *argv[])
{
    str_type *p = str_alloc ();

    path_join (p, 4, "/etc", "1", "2", "3");
    printf ("path: '%s'\n", str_get (p));

    if (argc > 1)
    {
        str_free (p);
        p = str_alloc();
        for (int idx = 1; idx < argc; idx++)
        {
            path_join (p, 1, argv[idx]);
        }
        printf ("path: '%s'\n", str_get (p));
    }

    str_free (p);
    return (0);
}
