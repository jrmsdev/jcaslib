#include <libgen.h>
#include "_log.h"

int
_logfp(FILE *fp, const char *tag, char *fmt, va_list ap)
{
    int ret;
    if (tag != NULL)
        fprintf (fp, "%s: ", tag);
    ret = vfprintf(fp, fmt, ap);
    ret += fprintf(fp, "%s\n", "");
    return ret;
}
