#define _WITH_GETLINE

#include <jcaslib/os.h>
#include <jcaslib/path.h>

#include <err.h>
#include <stdio.h>
#include <stdlib.h>

#include "license-header.h"


char *scan_dirname = NULL;
char *filename_ext = NULL;

static void
parse_args (int argc, char *argv[])
{
    if (argc < 3)
        errx (1, "invalid number of parameters");
    scan_dirname = argv[1];
    filename_ext = argv[2];
}


int
main (int argc, char *argv[])
{
    str_array_type *dlist = str_array_alloc ();

    parse_args (argc, argv);
    printf ("scandir:'%s' file_ext:'%s'\n", scan_dirname, filename_ext);

    if (!path_exists (scan_dirname))
        errx (1, "dir not found: %s", scan_dirname);

    os_lsdir (dlist, scan_dirname, -1);

    for (size_t i = 0; i < str_array_len (dlist); i++)
    {
        str_type *fpath = str_array_get (dlist, i);
        if (fpath == NULL)
            warnx ("NULL fname");
        else
            check_file (str_get (fpath), filename_ext);
    }

    str_array_free (dlist);
}
