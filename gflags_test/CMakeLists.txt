cmake_minimum_required(VERSION 3.13)
project(gflags_test)


set(CMAKE_CXX_STANDARD 14)
aux_source_directory(${PROJECT_SOURCE_DIR}/ SRC_LIST_C)
include_directories(${PROJECT_SOURCE_DIR}/)
#find_package(glog REQUIRED)

set(INC_DIR /usr/local/include)
set(LINK_DIR /usr/local/lib)
include_directories(${INC_DIR})
link_directories(${LINK_DIR})
link_directories(third_party/gtest/lib)
include_directories(third_party/gtest/googletest/include)
#link_libraries(glog)


set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

add_executable(gflags_demo ${SRC_LIST_C})
target_link_libraries(gflags_demo glog)
target_link_libraries(gflags_demo gflags)
target_link_libraries(gflags_demo gtest)


#target_link_directories(gflags_test,"/usr/local/lib/gflags")
#target_link_directories(gflags_test,"/usr/local/lib/glog")
#target_link_libraries(gflags_demo gflags)
#target_link_libraries(gflags_demo glog)
