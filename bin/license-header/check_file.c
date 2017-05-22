#include <jcaslib/path.h>
#include <string.h>
#include <stdio.h>
#include "license-header.h"

void
check_file (char *fpath, const char *check_ext)
{
    char *fext = path_filename_ext (fpath);
    if (memcmp (check_ext, fext, strlen (check_ext)) == 0)
        printf ("check: %s\n", fpath);
}
