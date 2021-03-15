#include <stdio.h>
#include <module.h>

int main()
{
    module_init();
    input_event();
    module_deinit();

    return 0;
}

