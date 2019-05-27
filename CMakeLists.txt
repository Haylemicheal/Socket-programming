cmake_minimum_required(VERSION 3.9.1)

project(socket)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(server newserver.cpp newserver.h)
add_executable(client client.cpp newclient.h)
