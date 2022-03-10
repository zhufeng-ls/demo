find_package(OpenCV REQUIRED)

add_executable(draw_test opencv/draw_test.cc)
target_link_libraries(draw_test ${OpenCV_LIBS})

add_executable(chinese_test opencv/chinese_test.cc opencv/puttext.cc)
target_link_libraries(chinese_test ${OpenCV_LIBS} freetype)

include_directories(/usr/include/freetype2)

add_executable(strrchr_test grammer/char/strrchr_test.cc)
add_executable(string_c_str_test grammer/string/string_c_str_test.cc)

add_executable(md5_test check/md5/md5_test.cc)

add_executable(fork_test fork/fork_test.cc)

