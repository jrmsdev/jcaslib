#include "test.h"
#include <stdlib.h>
#include <stdio.h>

void
t_check (int status, const char *errmsg)
{
    if (status > 0)
    {
        printf ("%s\n", errmsg);
        exit (status);
    }
}
