cmake_minimum_required(VERSION 3.0)
project (c_cxx_effective)
 
set (PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
 
file(GLOB_RECURSE POINTER_SRCS *.cc)
 
include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_INCLUDE_DIR}")
 
add_library(${PROJECT_NAME} STATIC ${POINTER_SRCS})

install (TARGETS ${PROJECT_NAME} DESTINATION bin)