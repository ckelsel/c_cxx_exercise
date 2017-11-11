cmake_minimum_required(VERSION 2.6)
project (main)
 
set (PROJECT_INCLUDE_DIR ../pointer/include)
set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
 
set(MAIN_SRCS
    ${PROJECT_SOURCE_DIR}/main.cpp 
)
 
include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_INCLUDE_DIR}")

add_executable(${PROJECT_NAME} ${MAIN_SRCS})

TARGET_LINK_LIBRARIES(${PROJECT_NAME} pointer)

install (TARGETS ${PROJECT_NAME} DESTINATION bin)