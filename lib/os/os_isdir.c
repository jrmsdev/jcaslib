#include <jcaslib/os.h>

#include <err.h>
#include <stdlib.h>
#include <sys/stat.h>

int
os_isdir (const char *dpath)
{
    struct stat *sb = calloc (1, sizeof (struct stat));
    int s = stat (dpath, sb);
    if (s == -1)
    {
        warn ("os_isdir stat error");
        free (sb);
        return (s);
    }
    mode_t m = sb->st_mode;
    free (sb);
    return (S_ISDIR (m));
}
