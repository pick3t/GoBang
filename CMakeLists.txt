set(CMAKE_CXX_COMPILER g++)
set(CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_STANDARD 20)

cmake_minimum_required(VERSION 3.16.3)

project(GoBang VERSION 1.0 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)
add_subdirectory(utility)

add_executable(${PROJECT_NAME}
  ${CMAKE_CURRENT_SOURCE_DIR}/gobang.cpp
)

target_link_libraries(${PROJECT_NAME} golib)

target_include_directories(${PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

add_custom_target(insrcclean
    COMMAND ${CMAKE_COMMAND} -E remove_directory "${CMAKE_BINARY_DIR}/CMakeFiles"
    COMMAND ${CMAKE_COMMAND} -E remove -f "${CMAKE_BINARY_DIR}/Makefile"
    COMMAND ${CMAKE_COMMAND} -E remove -f "${CMAKE_BINARY_DIR}/CMakeCache.txt"
    COMMAND ${CMAKE_COMMAND} -E remove -f "${CMAKE_BINARY_DIR}/cmake_install.cmake"
    COMMAND find "${CMAKE_BINARY_DIR}" -name "CMakeFiles" -type d -prune -exec rm -rf {} \\\;
    COMMAND find "${CMAKE_BINARY_DIR}" -type f -name "Makefile" -exec rm -f {} \\\;
    COMMAND find "${CMAKE_BINARY_DIR}" -type f -name "CMakeCache.txt" -exec rm -f {} \\\;
    COMMAND find "${CMAKE_BINARY_DIR}" -type f -name "cmake_install.cmake" -exec rm -f {} \\\;
)
