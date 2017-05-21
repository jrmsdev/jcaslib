#include <jcaslib/os.h>
#include <jcaslib/path.h>

#include <dirent.h>
#include <string.h>


static void
_os_scandir (str_array_type *dst, const char *basedir, int maxdepth, int level)
{
    if (level > maxdepth)
        return;

    struct dirent **dlist;
    int entries = scandir (basedir, &dlist, NULL, alphasort);

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

        str_type *fpath = NULL;

        if ((strlen (basedir) == 1) && (memcmp (basedir, ".", 1) == 0))
            fpath = str_alloc (NULL);
        else
            fpath = str_alloc (basedir);

        path_join (fpath, 1, f->d_name);
        str_array_append (dst, str_get (fpath));

        if (path_isdir (str_get (fpath)))
            _os_scandir (dst, str_get (fpath), maxdepth, level + 1);

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

    _os_scandir (dst, dpath, maxdepth, 0);
}
