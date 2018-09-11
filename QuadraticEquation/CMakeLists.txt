cmake_minimum_required(VERSION 3.6)
project(QuadraticEquation)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp test.cpp main.h)
add_executable(QuadraticEquation ${SOURCE_FILES})