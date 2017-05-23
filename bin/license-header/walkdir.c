#define _WITH_GETLINE

#include <jcaslib/log.h>
#include <jcaslib/os.h>
#include <jcaslib/path.h>

#include <stdio.h>
#include <stdlib.h>

#include "license-header.h"

void
walkdir (const char *basedir, const char *filename_ext)
{
    str_array_type *dlist = str_array_alloc ();

    if (!path_exists (basedir))
        log_exit (1, "dir not found: %s", basedir);

    os_lsdir (dlist, basedir, -1);

    for (size_t i = 0; i < str_array_len (dlist); i++)
    {
        str_type *fpath = str_array_get (dlist, i);
        if (fpath == NULL)
            log_warn ("NULL fname");
        else
            check_file (str_get (fpath), filename_ext);
    }

    str_array_free (dlist);
}
