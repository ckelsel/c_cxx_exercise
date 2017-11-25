include_directories(${GTEST_INCLUDE_DIRS} ${COMMON_INCLUDES})


#
# Unittest
#
set(PROJECT_TEST_NAME ${PROJECT_LIB_NAME}_test)

set(TEST_SRC_FILES unittest.cc)
set(TEST_SRC_FILES ${TEST_SRC_FILES} pointer_unittest.cc)
set(TEST_SRC_FILES ${TEST_SRC_FILES} list_unittest.cc)
set(TEST_SRC_FILES ${TEST_SRC_FILES} tree_unittest.cc)


add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES})
add_dependencies(${PROJECT_TEST_NAME} googletest)
target_link_libraries(${PROJECT_TEST_NAME} ${PROJECT_LIB_POINTER}
    ${PROJECT_LIB_LIST} ${EXT_LIBS})

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
add_test(test0 ${PROJECT_TEST_NAME})

install(TARGETS ${PROJECT_TEST_NAME} 
    DESTINATION bin)

