#include <jcaslib/os.h>

int
os_lsdir (struct dirent ***dst, const char *dpath)
{
    return (scandir (dpath, dst, NULL, alphasort));
}
