cmake_minimum_required(VERSION 3.16)
project(checkboard)

set(CMAKE_C_STANDARD 11)

add_executable(checkboard src/main.c src/library.c src/utils.c inc/library.h)
include_directories(inc)
