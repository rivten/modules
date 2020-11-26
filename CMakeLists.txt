cmake_minimum_required(VERSION 3.0)

project(modules)


add_library(modules_gameplay MODULE code/gameplay.c)
add_executable(modules code/engine.c)

target_link_libraries(modules ${CMAKE_DL_LIBS})
