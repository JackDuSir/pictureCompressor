cmake_minimum_required(VERSION 3.3)
project(HuffmanTree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Compressor.h HuffmanTree.h MinHeap.h HCode.h Compressor.cpp MaxHeap.h)
add_executable(HuffmanTree ${SOURCE_FILES})