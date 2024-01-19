cmake_minimum_required(VERSION 3.14)
project(testaocd2023_01)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the compiler options
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)


include(FetchContent)
FetchContent_Declare(
  googletest
  DOWNLOAD_EXTRACT_TIMESTAMP
  URL https://github.com/google/googletest/archive/dddb219c3eb96d7f9200f09b0a381f016e6b4562.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

include_directories(
  ../source/
)

add_library(
  solverobj
  OBJECT
  ../source/solverlib.cpp
)

add_executable(
  testall
  source/solvertest.cpp
)

target_link_libraries(
  testall
  solverobj
  GTest::gtest_main
)

add_executable(
  solver
  ../source/solver.cpp
)

target_link_libraries(
  solver
  solverobj
)

# Integration Tests
add_test(
  NAME test_solver_as_reader
  COMMAND solver --help
)

set_tests_properties(
  test_solver_as_reader
  PROPERTIES PASS_REGULAR_EXPRESSION "Advent of code 2023 day 1 solver"
)

add_test(
  NAME test_solver1_example
  COMMAND solver input_example1.txt
  WORKING_DIRECTORY ${testaocd2023_01_SOURCE_DIR}/input_files/
)

set_tests_properties(
  test_solver1_example
  PROPERTIES PASS_REGULAR_EXPRESSION "^142\n$"
)

add_test(
  NAME test_solver1_example_part
  COMMAND solver --part 1 input_example1.txt
  WORKING_DIRECTORY ${testaocd2023_01_SOURCE_DIR}/input_files/
)

set_tests_properties(
  test_solver1_example_part
  PROPERTIES PASS_REGULAR_EXPRESSION "^142\n$"
)

add_test(
  NAME test_solver1
  COMMAND solver input.txt
  WORKING_DIRECTORY ${testaocd2023_01_SOURCE_DIR}/input_files/
)

set_tests_properties(
  test_solver1
  PROPERTIES PASS_REGULAR_EXPRESSION "^53334\n$"
)

add_test(
  NAME test_solver2_example
  COMMAND solver -p 2 input_example2.txt
  WORKING_DIRECTORY ${testaocd2023_01_SOURCE_DIR}/input_files/
)

set_tests_properties(
  test_solver2_example
  PROPERTIES PASS_REGULAR_EXPRESSION "^281\n$"
)

add_test(
  NAME test_solver2
  COMMAND solver --part 2 input.txt
  WORKING_DIRECTORY ${testaocd2023_01_SOURCE_DIR}/input_files/
)

set_tests_properties(
  test_solver2
  PROPERTIES PASS_REGULAR_EXPRESSION "^52834\n$"
)

# End Integration Tests
include(GoogleTest)
gtest_discover_tests(testall)

set(OBJECT_DIR ${CMAKE_BINARY_DIR}/CMakeFiles/testall.dir/source)
message("-- Object files will be output to: ${OBJECT_DIR}")

# Create the gcov target. Run coverage tests with 'make gcov'
add_custom_target(gcov
    COMMAND mkdir -p gcoverage
    COMMAND ${CMAKE_MAKE_PROGRAM} test
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )
add_custom_command(TARGET gcov
    COMMAND echo "=================== GCOV ===================="
    COMMAND gcov -b ${CMAKE_SOURCE_DIR}/source/*.cpp -o ${OBJECT_DIR}
    COMMAND echo "-- Source diretory: ${CMAKE_SOURCE_DIR}/source/"
    COMMAND echo "-- Coverage files have been output to ${CMAKE_BINARY_DIR}/gcoverage"
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/gcoverage
    )
add_dependencies(gcov testall)

# Create the lcov target. Run result tests with 'make lcov'
add_custom_target(lcov
    COMMAND mkdir -p lcoverage
    )
add_custom_command(TARGET lcov
    COMMAND echo "=================== LCOV ===================="
    COMMAND echo "-- Passing lcov tool under code coverage"
    COMMAND lcov --capture --directory ../ --output-file lcoverage/main_coverage.info
    COMMAND echo "-- Generating HTML output files"
    COMMAND genhtml lcoverage/main_coverage.info --output-directory lcoverage
    )
