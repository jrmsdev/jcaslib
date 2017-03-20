#include "build_info.h"
#include "version.h"
#include <jclib/log.h>

int main(void)
{
    print_version();
    log_print("");
    print_build_info();
    return 0;
}
