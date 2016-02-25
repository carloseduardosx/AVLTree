cmake_minimum_required(VERSION 3.3)
project(AVL_Tree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp header/Node.h avl_function/insertNode.cpp avl_function/searchNode.cpp header/avlFunctions.h avl_function/balanceNode.cpp avl_function/removeNode.cpp avl_function/showTree.cpp avl_function/util.cpp)
add_executable(AVL_Tree ${SOURCE_FILES})