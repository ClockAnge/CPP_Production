project(calculator)

set(CALC_SRC_FILES
    src/main_calc.cpp
)

add_executable(calculator ${CALC_SRC_FILES})
target_link_libraries(calculator PRIVATE calc_lib)

set_target_properties(calculator PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)