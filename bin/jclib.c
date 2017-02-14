#include <jclib/build_info.h>
#include <jclib/version.h>
#include <jclib/log.h>

int main()
{
    log_print("%s", "lalala");
    log_print("lalala2");
    print_version();
    print_build_info();
    log_dbg("%s", "end...");
    return 0;
}
