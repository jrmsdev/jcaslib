#include <jclib/lib.h>
#include <jclib/log.h>
#include <strings.h>

void *
xmalloc (size_t size)
{
    void *p = malloc (size);
    if (p == NULL)
        log_exit (1, "could not malloc");
    bzero (p, size);
    return (p);
}
