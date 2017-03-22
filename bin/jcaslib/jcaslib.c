#include "build_info.h"
#include <jcaslib/version.h>
#include <jcaslib/log.h>

int main(void)
{
    print_version();
    print_build_info();
    return 0;
}
