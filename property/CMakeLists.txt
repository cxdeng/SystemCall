cmake_minimum_required(VERSION 3.22.1)

project(property)

set(CMAKE_BUILD_TYPE Debug)

add_executable(01_stat 01_stat.c)
add_executable(02_mask 02_mask.c)
add_executable(03_chmod 03_chmod.c)
add_executable(04_symlink 04_symlink.c)
add_executable(05_lstat 05_lstat.c)
add_executable(06_fstat 06_fstat.c)
add_executable(07_umask 07_umask.c)
add_executable(08_truncate_ftruncate 08_truncate_ftruncate.c)
add_executable(09_getcwd_chdir 09_getcwd_chdir.c)
add_executable(10_link_unlink 10_link_unlink.c)
add_executable(11_remove 11_remove.c)
add_executable(12_rename 12_rename.c)
add_executable(13_readlink 13_readlink.c)
add_executable(14_mkdir 14_mkdir.c)
add_executable(15_rmdir 15_rmdir.c)


file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/file DESTINATION ${CMAKE_CURRENT_BINARY_DIR})