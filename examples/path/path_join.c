#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <err.h>
#include <jclib/path.h>

int main(int argc, char *argv[])
{
    path_type p;
    memset(p, '\0', PATH_MAX_LEN);

    path_join(p, 4, "/etc", "1", "2", "3");
    printf("path: '%s'\n", p);

    if (argc > 1)
    {
        memset(p, '\0', PATH_MAX_LEN);
        for (int idx = 1; idx < argc; idx++)
        {
            path_join(p, 2, p, argv[idx]);
       }
       printf("path: '%s'\n", p);
    }

    return 0;
}
