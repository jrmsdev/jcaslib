#include <jcaslib/path.h>
#include <unistd.h>

int
path_exists (const char *path)
{
    int ret = access (path, F_OK);
    if (ret == 0)
        return (1);
    return (0);
}
