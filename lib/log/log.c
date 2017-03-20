#include <jclib/log.h>

int _logfp(FILE *fp, const char *tag, char *fmt, va_list ap) {
    int ret;
    if (tag != NULL)
        fprintf (fp, "%s: ", tag);
    ret = vfprintf(fp, fmt, ap);
    va_end(ap);
    ret += fprintf(fp, "%s\n", "");
    return ret;
}
