cmake_minimum_required(VERSION 3.14)
project(aocd2023_01 VERSION 1.0)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(
  solverobj
  OBJECT
  source/solverlib.cpp
)

add_executable(
  solver
  source/solver.cpp
)

target_link_libraries(
  solver
  solverobj
)
