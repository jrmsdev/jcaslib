/* license-header.c */

#include <jcaslib/os.h>
#include <stdio.h>
#include <stdlib.h>

int
main (void)
{
    struct dirent **dlist;
    int entries = os_lsdir (&dlist, "./");

    printf ("dlist entries: %d\n", entries);

    for (int idx = 0; idx < entries; idx++)
    {
        struct dirent *f = dlist[idx];
        printf ("f->d_name: %s\n", f->d_name);

        free (dlist[idx]);
    }

    free (dlist);
    return (0);
}
