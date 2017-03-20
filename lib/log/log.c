#include <jclib/log.h>
#include <stdlib.h>

int _logfp(FILE *fp, const char *tag, char *fmt, va_list ap) {
    int ret;
    if (tag != NULL)
    {
        fprintf (fp, "%s: ", tag);
        const char *prog = getprogname ();
        if (prog != NULL)
            fprintf (fp, "%s: ", prog);
    }
    ret = vfprintf(fp, fmt, ap);
    va_end(ap);
    ret += fprintf(fp, "%s\n", "");
    return ret;
}
