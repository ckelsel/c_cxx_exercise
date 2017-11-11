cmake_minimum_required(VERSION 3.0)
project (c_cxx_pointer)
 
set (PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
 
set(POINTER_SRCS 
    ${PROJECT_SOURCE_DIR}/pointer.c
)
 
include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_INCLUDE_DIR}")
 
add_library(${PROJECT_NAME} STATIC ${POINTER_SRCS})

install (TARGETS ${PROJECT_NAME} DESTINATION bin)