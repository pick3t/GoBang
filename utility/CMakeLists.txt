set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

set(SOURCES
    player.cpp
    server.cpp
)

add_library(gobang_server OBJECT ${SOURCES})

target_include_directories(gobang_server PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(gobang_server PRIVATE
    pthreads
)

add_executable(gobang-server ${SOURCES})

set(CLIENT_SRC
    client.cpp
)

add_library(gobang_client OBJECT ${CLIENT_SRC})

target_link_libraries(gobang_client PRIVATE
)

add_executable(gobang-client ${CLIENT_SRC})
