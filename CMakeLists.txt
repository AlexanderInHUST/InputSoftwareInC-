cmake_minimum_required(VERSION 3.6)
project(InputSoftwareC__)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp model/PinyinTireTree.cpp model/PinyinTireTree.h model/PinyinNode.cpp model/PinyinNode.h)
add_executable(InputSoftwareC__ ${SOURCE_FILES})