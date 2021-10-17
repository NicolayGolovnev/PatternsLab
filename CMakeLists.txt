cmake_minimum_required(VERSION 3.15)
project(patterns)

set(CMAKE_CXX_STANDARD 14)

add_executable(patterns main.cpp RealFilter.h Delegation/Algorithm.h Delegation/Algorithms.h Filter.h Proxy/ProxyFilter.h Delegation/Delegate.h Proxy/Proxy.h Adapter/Adapter.h Adapter/OutsideProtection.h Decorator/Decorator.h Letter.h)