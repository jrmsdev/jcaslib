#include <stdio.h>
#include <stdarg.h>
#include <jclib/log.h>

static int __logfp(FILE *fp, char *fmt, va_list ap) {
    int ret;
    ret = vfprintf(fp, fmt, ap);
    va_end(ap);
    return ret;
}

int log_printf(char * fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    return __logfp(stdout, fmt, ap);
}

int log_dbg(char * fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    return __logfp(stderr, fmt, ap);
}
