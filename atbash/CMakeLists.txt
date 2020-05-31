cmake_minimum_required(VERSION 3.16)
project(atbash C)

set(CMAKE_C_STANDARD 99)

add_executable(atbash src/library.c inc/library.h main.c src/utils.c)
include_directories(inc)