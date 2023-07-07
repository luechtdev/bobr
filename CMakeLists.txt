cmake_minimum_required(VERSION 3.22)
project(rolling-log C)

set(CMAKE_C_STANDARD 23)

add_executable(rolling-log main.c rolling.h ansi.h)
