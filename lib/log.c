#include <stdlib.h>
#include <stdarg.h>
#include <jclib/log.h>

int __logfp(FILE *fp, char *fmt, va_list ap) {
    int ret;
    ret = vfprintf(fp, fmt, ap);
    va_end(ap);
    ret += fprintf(fp, "%s\n", "");
    return ret;
}
