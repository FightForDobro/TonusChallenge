cmake_minimum_required(VERSION 3.16)
project(vigenere)

set(CMAKE_C_STANDARD 11)

add_executable(vigenere src/main.c inc/library.h src/library.c src/utils.c)
include_directories(inc)
