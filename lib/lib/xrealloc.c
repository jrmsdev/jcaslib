#include <jcaslib/lib.h>
#include <jcaslib/log.h>

void *
xrealloc (void *ptr, size_t size)
{
    void *newp = realloc (ptr, size);
    if (newp == NULL)
        log_exit (1, "could not realloc");
    return (newp);
}
