cmake_minimum_required(VERSION 3.2)
project(wow)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

include_directories("include")
add_executable(run "src/main.c")
add_library(lib "src/lib.c")

target_link_libraries(run lib)
