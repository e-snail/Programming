cmake_minimum_required(VERSION 3.5)

project(04_Oops)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp MyClass.cpp MyClass.h)

add_executable(binary_oops ${SOURCE_FILES})
