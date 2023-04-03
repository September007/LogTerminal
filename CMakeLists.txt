cmake_minimum_required(VERSION 3.20)

project(LogTerminal)

    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/$<IF:$<CONFIG:Release>,Release,Debug>)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
    set(CMAKE_PDB_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

# options
option(BUILD_SHARED "build shared lib" OFF)

# influence of options
if(BUILD_SHARED)
    set(BUILD_FORM shared)
else()
    set(BUILD_FORM static)
endif()
set(Boost_DEBUG 1) 
# custom setting
include(${CMAKE_CURRENT_LIST_DIR}/cmake/custom.env.cmake)
# third libs
find_library(Qt5Core NAMES Qt5Core REQUIRED)
message("CMAKE_PREFIX_PATH:${CMAKE_PREFIX_PATH}")
# find_library(boost_assert NAMES boost_assert Boost_assert Boost_Assert REQUIRED)
find_package(Boost  REQUIRED)
find_package(Boost)
# global options
add_link_options($<IF:$<CXX_COMPILER_ID:GNU>,"-Wl$<COMMA>--unresolved-symbols=report-all",>)
include_directories(${CMAKE_CURRENT_LIST_DIR}/src/include)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src/ArithCodec)
add_subdirectory(src/ConnectionProtocal)
add_subdirectory(src/ClientManager)
add_subdirectory(src/HostManager)
