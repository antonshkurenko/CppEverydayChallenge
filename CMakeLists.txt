cmake_minimum_required(VERSION 3.3)
project(CppEverydayChallenge)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(CppEverydayChallenge ${SOURCE_FILES} first-day/main.cpp commons/RuntimeException.cpp commons/RuntimeException.h)