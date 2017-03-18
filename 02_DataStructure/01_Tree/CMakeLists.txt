cmake_minimum_required(VERSION 3.5)

project(02_DataStructure_Tree)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES BTNode.h BTNode.cpp BinaryTree.cpp) 

add_executable(binary_tree ${SOURCE_FILES})
