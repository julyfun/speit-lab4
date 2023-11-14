cmake_minimum_required(VERSION 3.2)
project(wow)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2")

# set(CMAKE_BUILD_TYPE "Debug")
include_directories("include")
add_executable(run "src/main.c")
add_library(lib "src/lib.c")

target_link_libraries(run lib)
