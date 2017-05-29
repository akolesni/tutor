cmake_minimum_required(VERSION 2.8.4)
project(NxTest)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp FileTest.cpp FileTest.h)
add_executable(NxTest ${SOURCE_FILES})