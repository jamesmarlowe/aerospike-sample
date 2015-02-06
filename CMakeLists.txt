cmake_minimum_required (VERSION 2.8)
project(aerospikesample)

add_definitions("-Wno-deprecated-declarations")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

#enable c++ 11
SET(CMAKE_CXX_FLAGS "-std=c++11 -O3 ${CMAKE_CXX_FLAGS}")

include_directories(${ZMQ_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_SOURCE_DIR})

set(client_sources
    client.cpp
)

add_executable(client ${client_sources})

target_link_libraries(client aerospike )
