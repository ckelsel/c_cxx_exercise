cmake_minimum_required(VERSION 3.0)
project (rootproject C CXX)
 
set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
 
include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")
 
add_subdirectory(pointer)
add_subdirectory(project2)
