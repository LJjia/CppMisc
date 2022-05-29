cmake_minimum_required(VERSION 3.13)
project(ocrsdk_optimize)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR}/inc)
include_directories(${PROJECT_SOURCE_DIR}/)

aux_source_directory(${PROJECT_SOURCE_DIR}/src SRCS)
aux_source_directory(${PROJECT_SOURCE_DIR}/ SRCS)

add_executable(ocrsdk_optimize ${SRCS})