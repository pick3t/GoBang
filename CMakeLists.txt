set(CMAKE_CXX_COMPILER g++)
set(CMAKE_BUILD_TYPE Debug)

cmake_minimum_required(VERSION 3.16.3)

project(GoBang VERSION 1.0 LANGUAGES CXX)

add_subdirectory(src)

add_executable(${PROJECT_NAME}
  ${CMAKE_CURRENT_SOURCE_DIR}/gobang.cpp
)

target_link_libraries(${PROJECT_NAME} golib)

target_include_directories(${PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)