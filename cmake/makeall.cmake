# suffix 为后缀
macro(BUILDALL dir suffix)
    file(GLOB APP_LIST  ${dir}/${suffix})
    FOREACH(CHILD ${APP_LIST})
        string(REPLACE "${dir}/" "" app_main ${CHILD})
        string(REPLACE ".cpp" "" APP_NAME ${app_main})
        add_executable(${APP_NAME} ${app_main})
    endforeach()
endmacro()
