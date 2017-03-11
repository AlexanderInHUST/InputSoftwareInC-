cmake_minimum_required(VERSION 3.6)
project(InputSoftwareCpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp model/PinyinTireTree.cpp model/PinyinTireTree.h model/PinyinNode.cpp model/PinyinNode.h)
add_executable(InputSoftwareCpp ${SOURCE_FILES})