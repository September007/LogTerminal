
aux_source_directory("${CMAKE_CURRENT_LIST_DIR}/src" HM_SOURCES)
aux_source_directory("${CMAKE_CURRENT_LIST_DIR}/include" HM_HEADERS)

if(NOT BUILD_FORM)
    set(BUILD_FORM SHARED)
endif()

add_library(HostMgr ${BUILD_FORM})

target_include_directories(HostMgr PUBLIC include)
target_link_libraries(HostMgr PUBLIC ConnectionProtocal )

target_compile_definitions(HostMgr PRIVATE HOSTMGR_EXPORT)
target_sources(HostMgr PRIVATE ${HM_SOURCES} PUBLIC ${HM_HEADERS})
