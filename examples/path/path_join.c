#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <err.h>
#include <jclib/path.h>

int main()
{
    path_type p;
    path_join(p, 4, "/etc", "1", "2", "3");
    printf("p: '%s'\n", p);
    return 0;
}
