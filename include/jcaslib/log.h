#ifndef JCASLIB_LOG_H
#define JCASLIB_LOG_H

#include <stdio.h>
#include <stdarg.h>

extern int log_print (char *fmt, ...);
extern int log_dbg (char *fmt, ...);
extern int log_err (char *fmt, ...);
extern int log_warn (char *fmt, ...);
extern void log_exit (int stat, char *fmt, ...);
extern void log_set_progname (char *name);
int _logfp (FILE *fp, const char *tag, char *fmt, va_list ap);

#endif /* JCASLIB_LOG_H */
