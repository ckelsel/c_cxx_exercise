cmake_minimum_required(VERSION 3.0)
project (${PROJECT_EXE_CPP11})
 
set (PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

file(GLOB_RECURSE SRCS *.c *.cc *.cpp)
 
include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_INCLUDE_DIR}")
 
add_executable(${PROJECT_EXE_CPP11} ${SRCS})

install (TARGETS ${PROJECT_NAME} DESTINATION bin)
