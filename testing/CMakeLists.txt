include_directories(${GTEST_INCLUDE_DIRS} ${COMMON_INCLUDES})


#
# Unittest
#
set(PROJECT_TEST_NAME ${PROJECT_LIB_NAME}_test)

set(TEST_SRC_FILES unittest.cc)

file(GLOB TEST_SRC_FILES ${TEST_SRC_FILES} rd/base/video/*.cc)


# file(GLOB TEST_SRC_FILES ${TEST_SRC_FILES} data_struct/*.cc)
# file(GLOB TEST_SRC_FILES ${TEST_SRC_FILES} effective_cxx/*.cc)
# file(GLOB TEST_SRC_FILES ${TEST_SRC_FILES} effective_modern_cxx/*.cc)
# file(GLOB TEST_SRC_FILES ${TEST_SRC_FILES} the_cxx_stl_a_tutorial_and_reference_2012/*.cc)
# file(GLOB TEST_SRC_FILES ${TEST_SRC_FILES} algorithm/*.cc)

add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES})
add_dependencies(${PROJECT_TEST_NAME} googletest)
target_link_libraries(${PROJECT_TEST_NAME} 
    ${PROJECT_LIB_EFFECTIVE}
    ${PROJECT_LIB_EFFECTIVE_MODERN}
    ${PROJECT_LIB_STL}
    ${PROJECT_LIB_DS}
    ${PROJECT_LIB_ALGORITHM}
    ${PROJECT_LIB_RD}
    ${EXT_LIBS})

if(NOT WIN32)
    target_link_libraries(${PROJECT_TEST_NAME}
        ${GTEST_LIBS_DIR}/libgtest.a
        ${GTEST_LIBS_DIR}/libgtest_main.a
        )
else()
    target_link_libraries(${PROJECT_TEST_NAME}
        debug ${GTEST_LIBS_DIR}/DebugLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${CMAKE_FIND_LIBRARY_SUFFIXES}
        optimized ${GTEST_LIBS_DIR}/ReleaseLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${CMAKE_FIND_LIBRARY_SUFFIXES}
        )
    target_link_libraries(${PROJECT_TEST_NAME}
        debug ${GTEST_LIBS_DIR}/DebugLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest_main${CMAKE_FIND_LIBRARY_SUFFIXES}
        optimized ${GTEST_LIBS_DIR}/ReleaseLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest_main${CMAKE_FIND_LIBRARY_SUFFIXES}
        )
endif()


target_link_libraries(${PROJECT_TEST_NAME} ${CMAKE_THREAD_LIBS_INIT})
add_test(NAME ${PROJECT_TEST_NAME} COMMAND ${PROJECT_TEST_NAME})

install(TARGETS ${PROJECT_TEST_NAME} DESTINATION bin)
