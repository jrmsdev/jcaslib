#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <err.h>
#include <jclib/str.h>

int main(int argc, char *argv[])
{
    char *s = str_join(4, "||", "0", "1", "2", "3");
    printf("str: '%s'\n", s);

    free(s);

    if (argc > 2)
    {
        char *sep = argv[1];
        for (int idx = 2; idx < argc; idx++)
        {
            printf("argv[%d]: '%s' (%zu)\n", idx, argv[idx], strlen(argv[idx]));
            s = str_join(2, sep, s, argv[idx]);
        }
        printf("str2: '%s'\n", s);
        free(s);
    }

    return 0;
}
