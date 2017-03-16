#include <jclib/lib.h>
#include <err.h>
#include <strings.h>

void *
xmalloc (size_t size)
{
    void *p = malloc (size);
    if (p == NULL)
        err(1, "could not malloc");
    bzero (p, size);
    return (p);
}
