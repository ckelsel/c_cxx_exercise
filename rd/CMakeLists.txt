cmake_minimum_required(VERSION 3.0)
project (${PROJECT_LIB_RD})
 
set (PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

file(GLOB_RECURSE SRCS *.c *.cc)
 
include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_INCLUDE_DIR}")
 
add_library(${PROJECT_NAME} STATIC ${SRCS})

install (TARGETS ${PROJECT_NAME} DESTINATION bin)
