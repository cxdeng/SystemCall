cmake_minimum_required(VERSION 3.22.1)

project(property)

set(CMAKE_BUILD_TYPE Debug)

add_executable(01_stat 01_stat.c)
add_executable(02_mask 02_mask.c)


file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/file DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
