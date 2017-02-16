#include <err.h>
#include <string.h>
#include <jclib/lib.h>

void * xmalloc (size_t size)
{
    void *p = (void *) malloc (size);
    if (p == NULL)
        err(1, "could not malloc");
    memset (p, 0, size);
    return (p);
}

void * xrealloc (void *ptr, size_t size)
{
    char *newp = realloc (ptr, size);
    if (newp == NULL)
        err(1, "could not realloc");
    free (ptr);
    return (newp);
}

