#include <err.h>
#include "license-header.h"

int
main (int argc, char *argv[])
{
    if (argc < 3)
        errx (1, "invalid number of parameters");
    const char *basedir = argv[1];
    const char *filename_ext = argv[2];
    walkdir (basedir, filename_ext);
    return (0);
}
