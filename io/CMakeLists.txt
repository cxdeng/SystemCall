cmake_minimum_required(VERSION 3.22.1)

project(io)

set(CMAKE_BUILD_TYPE Debug)

add_executable(01_open 01_open.c)
add_executable(02_read 02_read.c)
add_executable(03_write 03_write.c)
add_executable(04_lseek 04_lseek.c)
add_executable(05_stdin 05_stdin.c)
add_executable(06_stdout 06_stdout.c)
add_executable(07_shared_file 07_shared_file.c)
add_executable(08_dup 08_dup.c)
add_executable(09_dup2 09_dup2.c)
add_executable(10_fcntl_dup 10_fcntl_dup.c)
add_executable(11_fcntl_fget_fset 11_fcntl_fget_fset.c)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/file DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
