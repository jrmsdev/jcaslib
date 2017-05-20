#include <jcaslib/os.h>

#include <err.h>
#include <stdlib.h>
#include <sys/stat.h>

int
os_islink (const char *path)
{
    struct stat *sb = calloc (1, sizeof (struct stat));
    int s = stat (path, sb);
    if (s == -1)
    {
        warn ("stat error");
        free (sb);
        return (s);
    }
    mode_t m = sb->st_mode;
    free (sb);
    return (S_ISLNK (m));
}
