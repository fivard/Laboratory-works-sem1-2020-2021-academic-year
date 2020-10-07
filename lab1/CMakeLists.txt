cmake_minimum_required(VERSION 3.15)
project(lab1)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab1 main.cpp graph.h date.cpp date.h tests/doctest.h tests/doctest_main.cpp tests/tests.cpp)