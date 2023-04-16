
aux_source_directory("${CMAKE_CURRENT_LIST_DIR}/src" T_SOURCES)
aux_source_directory("${CMAKE_CURRENT_LIST_DIR}/include" T_HEADERS)


add_library(Util SHARED)

target_include_directories(Util PUBLIC include)
set_boost_deps(Util)

target_compile_definitions(Util PRIVATE UTIL_EXPORT)
target_sources(Util PRIVATE ${T_SOURCES} PUBLIC ${T_HEADERS})
target_link_libraries(Util 
    PRIVATE Helper::log
    PUBLIC fmt::fmt-header-only
)