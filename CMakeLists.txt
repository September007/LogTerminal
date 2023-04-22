cmake_minimum_required(VERSION 3.20)

project(LogTerminal)

    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/$<IF:$<CONFIG:Release>,Release,Debug>)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
    set(CMAKE_PDB_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
if(CMAKE_HOST_SYSTEM_NAME STREQUAL Windows)
    set(Windows ON)
elseif(CMAKE_HOST_SYSTEM_NAME STREQUAL Linux)
    set(Linux ON)
endif()
# options
option(BUILD_SHARED "build shared lib" OFF)

# influence of options
if(BUILD_SHARED)
    set(BUILD_FORM shared)
else()
    set(BUILD_FORM static)
endif()

# set(Boost_DEBUG 1) 
# custom setting
include(${CMAKE_CURRENT_LIST_DIR}/cmake/custom.env.cmake)
# third libs
# find_library(Qt5Core NAMEsS Qt5Core REQUIRED)

# global options
# add_link_options($<IF:$<CXX_COMPILER_ID:GNU>,"-Wl$<COMMA>--unresolved-symbols=report-all",>)
include_directories(${CMAKE_CURRENT_LIST_DIR}/src/include)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_subdirectory(extern/fmt)
add_subdirectory(extern/spdlog)
add_subdirectory(extern/Helper)

add_subdirectory(src/Util)
link_libraries(Util)
add_subdirectory(src/ArithCodec)
add_subdirectory(src/ConnectionProtocal)
add_subdirectory(src/ClientManager)
add_subdirectory(src/HostManager)

add_subdirectory(test)