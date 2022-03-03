find_package(OpenCV REQUIRED)
add_executable(draw_test draw_test.cc)
target_link_libraries(draw_test ${OpenCV_LIBS})
