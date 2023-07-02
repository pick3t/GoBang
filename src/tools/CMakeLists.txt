add_subdirectory(enum_str_map)

add_library(tools INTERFACE)

target_include_directories(tools INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/enum_str_map)
target_link_libraries(tools INTERFACE enum_str_map)