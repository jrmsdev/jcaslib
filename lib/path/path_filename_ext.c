#include <jcaslib/path.h>

#include <libgen.h>
#include <string.h>

char *
path_filename_ext (const char *path)
{
    char *fname = basename (path);
    char *dot = strrchr (fname, '.');
    if (!dot || dot == fname)
        return ("");
    return (dot);
}
