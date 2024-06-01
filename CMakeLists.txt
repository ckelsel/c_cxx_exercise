cmake_minimum_required(VERSION 3.1)
set(PROJECT_NAME_STR c_cxx)
project(${PROJECT_NAME_STR} C CXX)

# LINUX and APPLE
if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

find_package(Threads REQUIRED)

if(LINUX)
    INCLUDE(FindPkgConfig)
endif()

if(MSVC)
    #vc 2012 fix for vararg templates
    set(MSVC_COMPILER_DEFS "-D_VARIADIC_MAX=10")
    set(COMMON_CXX_FLAGS "/W4  /EHsc")
    #set(COMMON_CXX_FLAGS "/W4 /WX /EHsc")
    ADD_DEFINITIONS(-D_WIN32_WINNT=0x6000 -DUNICODE -D_UNICODE -DNOMINMAX)
else()
    set(COMMON_CXX_FLAGS "-Wall")
    #set(COMMON_CXX_FLAGS "-Wall -Werror")
    #locally defined but not used [-Wunused-local-typedefs]
    #set(COMMON_CXX_FLAGS ${COMMON_CXX_FLAGS} "-Wunused-local-typedefs")
endif() 
set(CMAKE_CXX_FLAGS ${COMMON_CXX_FLAGS})

#-------------------
# set common include folder for module
#-------------------
set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/data_struct)
set(COMMON_INCLUDES ${COMMON_INCLUDES} ${PROJECT_SOURCE_DIR}/effective_cxx)
set(COMMON_INCLUDES ${COMMON_INCLUDES} ${PROJECT_SOURCE_DIR}/effective_modern_cxx)
set(COMMON_INCLUDES ${COMMON_INCLUDES} ${PROJECT_SOURCE_DIR}/the_cxx_stl_a_tutorial_and_reference_2012)
set(COMMON_INCLUDES ${COMMON_INCLUDES} ${PROJECT_SOURCE_DIR}/algorithm)
set(COMMON_INCLUDES ${COMMON_INCLUDES} ${PROJECT_SOURCE_DIR}/rd)
set(EXT_PROJECTS_DIR ${PROJECT_SOURCE_DIR}/ext)

message(${COMMON_INCLUDES})

#-------------------
# Module source
#-------------------

set(PROJECT_EXE_CPP11 ${PROJECT_NAME_STR}_cpp11)
add_subdirectory(${PROJECT_SOURCE_DIR}/cpp11)

set(PROJECT_LIB_DS ${PROJECT_NAME_STR}_data_struct)
add_subdirectory(${PROJECT_SOURCE_DIR}/data_struct)

set(PROJECT_LIB_EFFECTIVE ${PROJECT_NAME_STR}_effective_cxx)
add_subdirectory(${PROJECT_SOURCE_DIR}/effective_cxx)

set(PROJECT_LIB_EFFECTIVE_MODERN ${PROJECT_NAME_STR}_effective_modern_cxx)
add_subdirectory(${PROJECT_SOURCE_DIR}/effective_modern_cxx)

set(PROJECT_LIB_STL ${PROJECT_NAME_STR}_the_cxx_stl_a_tutorial_and_reference_2012)
add_subdirectory(${PROJECT_SOURCE_DIR}/the_cxx_stl_a_tutorial_and_reference_2012)


set(PROJECT_LIB_ALGORITHM ${PROJECT_NAME_STR}_algorithm)
add_subdirectory(${PROJECT_SOURCE_DIR}/algorithm)



set(PROJECT_LIB_RD ${PROJECT_NAME_STR}_rd)
add_subdirectory(${PROJECT_SOURCE_DIR}/rd)

#-------------------
# Test
#-------------------

if(MSVC)
    add_definitions(${MSVC_COMPILER_DEFS})
endif(MSVC)

enable_testing()

add_subdirectory(${EXT_PROJECTS_DIR}/gtest)
add_subdirectory(${PROJECT_SOURCE_DIR}/testing)
