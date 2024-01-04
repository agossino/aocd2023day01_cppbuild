cmake_minimum_required(VERSION 3.14)
project(aocd2023_01 VERSION 1.0)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include(FetchContent)
FetchContent_Declare(
  googletest
  DOWNLOAD_EXTRACT_TIMESTAMP
  URL https://github.com/google/googletest/archive/dddb219c3eb96d7f9200f09b0a381f016e6b4562.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(
  solverobj
  OBJECT
  solverlib.cpp
)

add_executable(
  solver1
  solver1.cpp
)

add_executable(
  testall
  solvertest.cpp
)

target_link_libraries(
  solver1
  solverobj
)

target_link_libraries(
  testall
  solverobj
  GTest::gtest_main
)

add_test(
  NAME test_solver1_as_reader
  COMMAND solver1
  WORKING_DIRECTORY ${aocd2023_01_01_SOURCE_DIR}
)

set_tests_properties(
  test_solver1_as_reader
  PROPERTIES PASS_REGULAR_EXPRESSION "Advent of Code solver"
)

add_test(
  NAME test_solver1_example
  COMMAND solver1 input_example1.txt
  WORKING_DIRECTORY ${aocd2023_01_01_SOURCE_DIR}
)

set_tests_properties(
  test_solver1_example
  PROPERTIES PASS_REGULAR_EXPRESSION "^142\n$"
)


include(GoogleTest)
gtest_discover_tests(testall)
