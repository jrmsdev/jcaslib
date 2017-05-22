#include <jcaslib/os.h>
#include "_os.h"

void
os_lsdir (str_array_type *dst, const char *dpath, int maxdepth)
{
    if (dpath == NULL)
        return;

    if (maxdepth < 0)
        maxdepth = OS_MAXDEPTH;

    _os_scandir (dst, dpath, maxdepth, 0);
}
