add_executable(threadpool main.cpp)
target_link_libraries(threadpool pthread)

add_executable(ctpl ctpl_test.cc)
target_link_libraries(ctpl pthread)