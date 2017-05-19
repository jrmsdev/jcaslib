#include <jcaslib/path.h>

int
path_lsdir (struct dirent ***dst, const char *dpath)
{
    return (scandir (dpath, dst, NULL, alphasort));
}
