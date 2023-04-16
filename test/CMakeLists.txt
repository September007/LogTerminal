
file(GLOB_RECURSE singles ${CMAKE_CURRENT_LIST_DIR}/SINGLES/*.cpp)
file(GLOB_RECURSE clients ${CMAKE_CURRENT_LIST_DIR}/Client/*.cpp)

foreach(src ${singles})
    STRING(REGEX REPLACE ".*/([^/]+)\\..*" "\\1" FILE_NAME ${src})
    add_executable(TEST_SINGLES_${FILE_NAME} ${src})
endforeach()

foreach(src ${clients})
    STRING(REGEX REPLACE ".*/([^/]+)\\..*" "\\1" FILE_NAME ${src})
    add_executable(C_${FILE_NAME} ${src})
    target_link_libraries(C_${FILE_NAME} PUBLIC ClientMgr)
endforeach()

set_boost_deps(TEST_SINGLES_boost_log)

