#!/usr/bin/env bash

g++ -std=c++11 ../src/main.cpp \
../src/model/Tree.cpp \
../src/model/Node.cpp \
../src/runner/Runner.cpp \
-o avltree.out && ./avltree.out