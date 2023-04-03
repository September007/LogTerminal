
aux_source_directory("${CMAKE_CURRENT_LIST_DIR}/src" CM_SOURCES)
aux_source_directory("${CMAKE_CURRENT_LIST_DIR}/include" CM_HEADERS)

if(NOT BUILD_FORM)
    set(BUILD_FORM SHARED)
endif()

add_library(ClientMgr ${BUILD_FORM})

target_compile_definitions(ClientMgr PRIVATE CLIENTMGR_EXPORT)
target_include_directories(ClientMgr PUBLIC include)
target_link_libraries(ClientMgr PUBLIC ConnectionProtocal )

target_sources(ClientMgr PRIVATE ${CM_SOURCES} PUBLIC ${CM_HEADERS})