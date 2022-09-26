cmake_minimum_required(VERSION 3.23)
project(lists C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -O2")

add_executable(lists main.c test.h test.c List.c List.h utils.h)
