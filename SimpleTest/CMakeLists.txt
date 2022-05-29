cmake_minimum_required(VERSION 3.13)
project(misc)

set(CMAKE_CXX_STANDARD 14)

include_directories(./src)

aux_source_directory(${PROJECT_SOURCE_DIR}/src DIR_SRCS)
message("name ")
message(${DIR_SRCS})

add_executable(misc main.cpp ${DIR_SRCS} )