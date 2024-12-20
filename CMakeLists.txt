cmake_minimum_required(VERSION 3.22)
project(Project C)

enable_testing()

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_REQUIRED ON)

add_subdirectory(src)
add_subdirectory(tests)

