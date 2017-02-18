#include <jclib/lib.h>
#include <err.h>
#include <string.h>

void * xmalloc (size_t size)
{
    void *p = malloc (size);
    if (p == NULL)
        err(1, "could not malloc");
    memset (p, 0, size);
    return (p);
}

void * xrealloc (void *ptr, size_t size)
{
    void *newp = realloc (ptr, size);
    if (newp == NULL)
        err(1, "could not realloc");
    return (newp);
}

