cmake_minimum_required(VERSION 3.6)
project(InputSoftwareCpp)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_COMPILER "g++")

set(SOURCE_FILES main.cpp model/PinyinTrieTree.cpp model/PinyinTrieTree.h model/PinyinNode.cpp model/PinyinNode.h model/WordPair.cpp model/WordPair.h model/CharacterPair.cpp model/CharacterPair.h)
add_executable(InputSoftwareCpp ${SOURCE_FILES})