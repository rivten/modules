cmake_minimum_required(VERSION 3.0)

project(modules)


add_library(modules_gameplay MODULE code/gameplay/gameplay.c)
# This is here that you allow gameplay to include engine headers
# but we do not allow the opposite
target_include_directories(modules_gameplay PRIVATE "code/engine")

add_executable(modules code/engine/engine.c)
target_link_libraries(modules ${CMAKE_DL_LIBS})
