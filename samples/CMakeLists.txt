find_package(OpenCV REQUIRED)
add_executable(draw_test draw_test.cc)
target_link_libraries(draw_test ${OpenCV_LIBS})

add_executable(strrchr_test grammer/char/strrchr_test.cc)

add_executable(md5_test check/md5/md5_test.cc)