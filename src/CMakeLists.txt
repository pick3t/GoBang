add_subdirectory(tools)

add_library(golib SHARED board.cpp chess.cpp container.cpp)

set(INCLUDE
${CMAKE_CURRENT_SOURCE_DIR}
${CMAKE_CURRENT_SOURCE_DIR}/tools
${CMAKE_CURRENT_SOURCE_DIR}/tools/enum_str_map)

target_include_directories(golib PRIVATE ${INCLUDE})
target_link_libraries(golib tools)