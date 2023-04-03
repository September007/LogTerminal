
aux_source_directory("${CMAKE_CURRENT_LIST_DIR}/src" CP_SOURCES)
aux_source_directory("${CMAKE_CURRENT_LIST_DIR}/include" CP_HEADERS)

add_library(ConnectionProtocal ${BUILD_FORM})

target_compile_definitions(ConnectionProtocal PRIVATE CONNECTION_PROTOCAL_EXPORT)
target_link_libraries(ConnectionProtocal PRIVATE ArithCodec)
target_include_directories(ConnectionProtocal PUBLIC include)
target_sources(ConnectionProtocal PRIVATE ${CP_SOURCES} PUBLIC ${CP_HEADERS})

