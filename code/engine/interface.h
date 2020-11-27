typedef struct engine_interface
{
    int (*engine_sum)(int, int);
} engine_interface;

// Entry point for gameplay
void update_gameplay(engine_interface* interface);

void function_gameplay_cannot_call(void); // this should not even be in the header in theory
