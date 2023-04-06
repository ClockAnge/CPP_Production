cmake_minimum_required(VERSION 3.20)

project("HW1_calculator")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_compile_options(-Wall -Wpedantic -Werror)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(libsrc/calc)
add_subdirectory(projects/calculator)
add_subdirectory(testsuite/libsrc/calc)
