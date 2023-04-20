project(calc_test)

set(CALC_TEST_SRC_FILES
    src/tests.cpp
)

add_executable(calc_test ${CALC_TEST_SRC_FILES})
target_link_libraries(calc_test PRIVATE calc_lib
	GTest::gtest_main
)

set_target_properties(calc_test PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)