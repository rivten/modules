#include <dlfcn.h>
#include <stdio.h>

#include "interface.h"

int engine_sum(int a, int b)
{
    return(a + b);
}

int main(void)
{
    engine_interface interface = {
        .engine_sum = engine_sum,
    };

    void* gameplay_handle = dlopen("build/libmodules_gameplay.so", RTLD_LAZY);

    if(gameplay_handle == 0)
    {
        printf("Gameplay module not found!\n");
        return(-1);
    }

    void (*update_gameplay_function)(engine_interface*) = dlsym(gameplay_handle, "update_gameplay");

    if(update_gameplay_function == 0)
    {
        printf("update_gameplay function not found!\n");
        return(-1);
    }

    update_gameplay_function(&interface);

    dlclose(gameplay_handle);

    return(0);
}
