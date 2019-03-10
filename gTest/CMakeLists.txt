cmake_minimum_required(VERSION 3.8)
project(gTest)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory (googletest)

set(SOURCE_FILES src/main.cpp)
add_executable(gTest ${SOURCE_FILES})