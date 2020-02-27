cmake_minimum_required(VERSION 3.5)
project(SORT)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_executable(SORT sort.cpp main_sort.cpp )
target_link_libraries(SORT sort.h)


