cmake_minimum_required(VERSION 3.5)

project(01_DynamicProgramming)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES_1 main.cpp CoinsValue.cpp CoinsValue.h)

add_executable(binary_dp ${SOURCE_FILES_1})

