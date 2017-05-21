#define _WITH_GETLINE

#include <jcaslib/os.h>
#include <jcaslib/path.h>

#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *scan_dirname = NULL;
char *filename_ext = NULL;
size_t filename_ext_len = 0;

static void
parse_args (int argc, char *argv[])
{
    if (argc < 3)
        errx (1, "invalid number of parameters");
    scan_dirname = argv[1];
    filename_ext = argv[2];
    filename_ext_len = strlen (filename_ext);
}


static void
check_file (char *fname)
{
    char *fext = path_filename_ext (fname);
    if (memcmp (filename_ext, fext, filename_ext_len) == 0)
        printf ("check: %s\n", fname);
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
        str_type *fname = str_array_get (dlist, i);
        check_file (str_get (fname));
    }
    str_array_free (dlist);
}
