cmake_minimum_required(VERSION 2.8)

PROJECT(demo)
add_subdirectory(tests)

add_definitions(-g -Wall -std=c++11)

# SET(INCLUDE_PATH
#     ./include
#     ./
#     ../)
# include_directories(${INCLUDE_PATH})

set(CMAKE_EX)

#指定源文件目录
#link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)
#add_library(robot robot.c)
#link_libraries(event pthread rt event_pthreads)

# add_executable(test_multi_thread  test_multi_thread.c)
# target_link_libraries(test_multi_thread  event pthread rt event_pthreads)

# add_executable(evthread_make_base  evthread_make_base.c)
#add_executable(test_robot_interface  test_robot_interface.c robot.c)
#target_link_libraries(test_robot_interface robot)


