cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(demo LANGUAGES C CXX)

add_definitions("-std=c++11")
add_definitions(-fPIC)
add_definitions(-g)

add_subdirectory(samples bin)
add_subdirectory(tests)


