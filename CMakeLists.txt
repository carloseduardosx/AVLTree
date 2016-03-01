cmake_minimum_required(VERSION 3.3)
project(AVL_Tree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/model/Node.cpp src/model/Node.h src/model/Tree.cpp src/model/Tree.h src/runner/Runner.cpp src/runner/Runner.h)
add_executable(AVL_Tree ${SOURCE_FILES})