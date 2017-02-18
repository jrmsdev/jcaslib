#include <jclib/str.h>
#include <stdlib.h>
#include <err.h>

int main(int argc, char *argv[])
{
    char *s = str_join (4, "||", "0", "1", "2", "3");
    printf ("str: '%s'\n", s);

    free (s);

    if (argc > 2)
    {
        s = str_init ();
        char *sep = argv[1];
        for (int idx = 2; idx < argc; idx++)
        {
            size_t slen = strlen (s);
            char *olds = str_init_len (slen);
            memcpy (olds, s, slen);
            free (s);
            printf ("argv[%d]: '%s' (%zu) - slen: %zu\n", idx, argv[idx], strlen(argv[idx]), slen);
            s = str_join (2, sep, olds, argv[idx]);
            free (olds);
        }
        printf ("str2: '%s'\n", s);
        free (s);
    }

    return 0;
}
