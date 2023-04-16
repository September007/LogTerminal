# https://github.com/nayuki/Reference-arithmetic-codin

aux_source_directory("${CMAKE_CURRENT_LIST_DIR}/include" ARI_HEADERS)
file(GLOB_RECURSE ARI_SOURCES "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp" )

add_library(ArithCodec ${BUILD_FORM})

target_compile_definitions(ArithCodec PRIVATE ARITHCODEC_EXPORT)
target_include_directories(ArithCodec 
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include 
    PRIVATE ${CMAKE_CURRENT_LIST_DIR}/src/internal)
target_sources(ArithCodec PRIVATE ${ARI_SOURCES} PUBLIC ${ARITH_HEADERS})
