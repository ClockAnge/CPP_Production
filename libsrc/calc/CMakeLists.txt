project(calc)

set(CALC_SRC_FILES
    src/calculator.cpp
)

add_library(calc_lib STATIC ${CALC_SRC_FILES})
