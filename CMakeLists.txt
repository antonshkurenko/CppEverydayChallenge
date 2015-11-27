cmake_minimum_required(VERSION 3.3)
project(CppEverydayChallenge)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(CppEverydayChallenge ${SOURCE_FILES} first-day/first_day.cpp second-day/second_day.cpp commons/utils.cpp commons/utils.cpp commons/utils.h main.cpp first-day/first_day.h second-day/second_day.h third-day/third_day.cpp third-day/third_day.h)