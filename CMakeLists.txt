cmake_minimum_required(VERSION 2.8)
project(CppEverydayChallenge)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(CppEverydayChallenge ${SOURCE_FILES} first-day/first_day.cpp second-day/second_day.cpp commons/utils.cpp commons/utils.cpp commons/utils.h main.cpp first-day/first_day.h second-day/second_day.h third-day/third_day.cpp third-day/third_day.h fourth-day/fourth_day.cpp fourth-day/fourth_day.h fifth-day/fifth_day.cpp fifth-day/fifth_day.h sixth-eighth-day/sixth_eighth_day.cpp sixth-eighth-day/sixth_eighth_day.h libs/rlutil.h)