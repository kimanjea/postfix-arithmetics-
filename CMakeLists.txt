cmake_minimum_required(VERSION 3.10)
project(postfix_kimanjea)

set(CMAKE_CXX_STANDARD 14)

add_executable(postfix_kimanjea main.cpp
        evaluator.cpp)