cmake_minimum_required(VERSION 3.0)

project(modules)

if(DYNAMIC_LINKING)
    add_library(modules_gameplay MODULE code/gameplay/gameplay.c)
else()
    add_library(modules_gameplay STATIC code/gameplay/gameplay.c)
endif()

# This is here that you allow gameplay to include engine headers
# but we do not allow the opposite
target_include_directories(modules_gameplay PRIVATE "code/engine")

add_executable(modules code/engine/engine.c)

# This is here that you allow engine to link to gameplay
# but we do not allow the opposite
if(DYNAMIC_LINKING)
    add_compile_definitions(DYNAMIC_LINKING=1)
    target_link_libraries(modules ${CMAKE_DL_LIBS})
else()
    add_compile_definitions(DYNAMIC_LINKING=0)
    target_link_libraries(modules LINK_PRIVATE modules_gameplay)
endif()
