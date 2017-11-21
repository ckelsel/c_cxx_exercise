cmake_minimum_required(VERSION 3.0)
project (c_cxx_list)
 
set (PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
 
set(LIST_SRCS 
    ${PROJECT_SOURCE_DIR}/list.c
)
 
include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_INCLUDE_DIR}")
 
add_library(${PROJECT_NAME} STATIC ${LIST_SRCS})

install (TARGETS ${PROJECT_NAME} DESTINATION bin)