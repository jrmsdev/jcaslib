#ifndef JCASLIB_LOG__LOG_H
#define JCASLIB_LOG__LOG_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

char *_progname __attribute__((unused));

int _logfp (FILE *fp, const char *tag, char *fmt, va_list ap);

#endif /* JCASLIB_LOG__LOG_H */
