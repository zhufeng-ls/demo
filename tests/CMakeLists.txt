include(${CMAKE_SOURCE_DIR}/cmake/find.cmake)

SUBDIRLIST(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})

set(curdir ${CMAKE_CURRENT_SOURCE_DIR})
message("subdirs ${SUBDIRS}")
foreach(dir ${SUBDIRS})
    message("test subdir: " ${curdir}/${dir})
    add_subdirectory(${curdir}/${dir})
endforeach()


