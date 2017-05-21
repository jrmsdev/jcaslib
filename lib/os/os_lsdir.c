#include <jcaslib/os.h>
#include <jcaslib/path.h>

#include <err.h>
#include <dirent.h>
#include <string.h>


static void
_os_scandir (str_array_type *dst, str_type *basedir)
{
    struct dirent **dlist;
    int entries = scandir (str_get (basedir), &dlist, NULL, alphasort);

    for (int i = 0; i < entries; i++)
    {
        struct dirent *f = dlist[i];

        size_t nlen = strlen (f->d_name);
        if (((nlen == 1) && (memcmp (f->d_name, ".", 1) == 0))
            || ((nlen == 2) && (memcmp (f->d_name, "..", 2) == 0)))
        {
            free (dlist[i]);
            continue;
        }

        str_type *fpath = str_alloc (str_get (basedir));
        path_join (fpath, 1, f->d_name);
        warnx ("fpath: %s", str_get (fpath));

        str_array_append (dst, f->d_name);

        str_free (fpath);
        free (dlist[i]);
    }

    free (dlist);
}


void
os_lsdir (str_array_type *dst, const char *dpath, int maxdepth)
{
    if (dpath == NULL)
        return;

    if (maxdepth < 0)
        maxdepth = OS_MAXDEPTH;

    str_type *basedir = str_alloc (dpath);
    _os_scandir (dst, basedir);
    str_free (basedir);
}
