find_package(OpenCV REQUIRED)

add_executable(draw_test opencv/draw_test.cc)
target_link_libraries(draw_test ${OpenCV_LIBS})

include_directories(/usr/include/freetype2)
add_executable(chinese_test opencv/chinese_test.cc opencv/chinese/puttext.cc)
target_link_libraries(chinese_test ${OpenCV_LIBS} freetype)

add_executable(draw_background opencv/draw_background.cc)
target_link_libraries(draw_background ${OpenCV_LIBS})

add_executable(strrchr_test grammer/char/strrchr_test.cc)
add_executable(string_c_str_test grammer/string/string_c_str_test.cc)

add_executable(md5_test check/md5/md5_test.cc)

add_executable(fork_test fork/fork_test.cc)

add_executable(queue_test stl/queue_test.cc)

