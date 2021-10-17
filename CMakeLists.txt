cmake_minimum_required(VERSION 3.15)
project(patterns)

set(CMAKE_CXX_STANDARD 14)

add_executable(patterns main.cpp Proxy/RealFilter.cpp RealFilter.h Delegation/Algorithm.h Delegation/Algorithms.cpp Delegation/Algorithms.h Filter.h Proxy/ProxyFilter.h Delegation/Delegate.h Proxy/Proxy.h Adapter/Adapter.h Adapter/OutsideProtection.h)