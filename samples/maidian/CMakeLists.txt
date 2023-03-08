include_directories(${CMAKE_CURRENT_SOURCE_DIR}/3rd/sa/include)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/3rd/sa/lib)

add_executable(demo demo.c)
target_link_libraries(demo sensorsanalytics)