cmake_minimum_required(VERSION 3.15)
project(patterns)

set(CMAKE_CXX_STANDARD 14)

add_executable(patterns main.cpp RealFilter.cpp RealFilter.h Algorithm.h Algorithms.cpp Algorithms.h Filter.h ProxyFilter.h)