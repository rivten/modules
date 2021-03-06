#include <stdio.h>
#if DYNAMIC_LINKING
#include <dlfcn.h>
#endif

#include "interface.h"

// You cannot do this include:
//#include "cant_include_this_from_engine.h"

int engine_sum(int a, int b)
{
    return(a + b);
}

int main(void)
{
    engine_interface interface = {
        .engine_sum = engine_sum,
    };

#if DYNAMIC_LINKING
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
#else
    update_gameplay(&interface);
#endif

    return(0);
}

static void function_gameplay_cannot_call(void)
{
    printf("Hello from engine\n");
}
