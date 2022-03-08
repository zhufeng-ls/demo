find_package(OpenCV REQUIRED)
add_executable(draw_test opencv/draw_test.cc)
target_link_libraries(draw_test ${OpenCV_LIBS})

add_executable(strrchr_test grammer/char/strrchr_test.cc)

add_executable(md5_test check/md5/md5_test.cc)

add_executable(fork_test fork/fork_test.cc)