#include <jcaslib/os.h>
#include <dirent.h>
#include <string.h>


void
_os_lsdir (str_array_type *dst, const char *dpath)
{
    struct dirent **dlist;
    int entries = scandir (dpath, &dlist, NULL, alphasort);
    for (int i = 0; i < entries; i++)
    {
        struct dirent *f = dlist[i];
        size_t nlen = strlen (f->d_name);
        if ((nlen == 1) && (memcmp (f->d_name, ".", 1) == 0))
        {
            free (dlist[i]);
            continue;
        }
        if ((nlen == 2) && (memcmp (f->d_name, "..", 2) == 0))
        {
            free (dlist[i]);
            continue;
        }
        str_array_append (dst, f->d_name);
        free (dlist[i]);
    }
    free (dlist);
}


void
os_lsdir (str_array_type *dst, const char *dpath, int maxdepth)
{
    if (maxdepth < 1)
        maxdepth = OS_MAXDEPTH;
    _os_lsdir (dst, dpath);
}
