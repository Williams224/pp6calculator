cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

project(pp6calculator)

include_directories(PP6Lib)

add_library(pp6lib PP6Lib/Math.hpp PP6Lib/Math.cpp)

add_executable(Input Input.cpp PP6Lib/Math.cpp PP6Lib/Math.hpp)

target_link_libraries(Input pp6lib)
