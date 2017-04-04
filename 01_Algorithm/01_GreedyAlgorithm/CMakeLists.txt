cmake_minimum_required(VERSION 3.5)

project(01_GreedyAlgorithm)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES_1 GreedyAlgorithm.cpp KnapsackProblem.cpp KnapsackProblem.h)

add_executable(greedy_algorithm ${SOURCE_FILES_1})

