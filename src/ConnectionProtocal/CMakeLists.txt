
file(GLOB_RECURSE CP_SOURCES "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp" )
file(GLOB_RECURSE CP_HEADERS "${CMAKE_CURRENT_LIST_DIR}/include/*.h" )
file(GLOB_RECURSE CP_INTERNAL_HEADERS "${CMAKE_CURRENT_LIST_DIR}/src/internal/*.h" )

add_library(ConnectionProtocal ${BUILD_FORM})

target_compile_definitions(ConnectionProtocal PRIVATE CONNECTION_PROTOCAL_EXPORT)
target_link_libraries(ConnectionProtocal PRIVATE ArithCodec)
target_include_directories(ConnectionProtocal PUBLIC include )
target_include_directories(ConnectionProtocal PRIVATE "${BOOST_INCLUDE_DIR}")
target_sources(ConnectionProtocal PRIVATE ${CP_SOURCES} ${CP_INTERNAL_HEADERS} PUBLIC ${CP_HEADERS})


source_group(Header ${CP_HEADERS})
source_group(Source ${CP_SOURCES})
source_group(Internal_Header ${CP_INTERNAL_HEADERS})

get_target_property(INC_DIR ConnectionProtocal INCLUDE_DIRECTORIES)

message("CP_HEADERS:${CP_HEADERS}")
message("BOOST_INCLUDE_DIR:${BOOST_INCLUDE_DIR}")
message("INC_DIR:${INC_DIR}")