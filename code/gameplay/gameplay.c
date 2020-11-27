#include <stdio.h>

#include "interface.h"

void update_gameplay(engine_interface* interface)
{
    if(interface != 0)
    {
        printf("Calling engine from gameplay : %d\n", interface->engine_sum(3, 2));
        function_gameplay_cannot_call(); // this should produce a link error
    }
}
