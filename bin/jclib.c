#include <stdio.h>
#include <jclib/build_info.h>

int main()
{
    printf("%s\n", "jclib");
    print_build_info();
    return 0;
}
