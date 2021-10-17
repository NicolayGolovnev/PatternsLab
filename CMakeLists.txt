cmake_minimum_required(VERSION 3.15)
project(patterns)

set(CMAKE_CXX_STANDARD 14)

add_executable(patterns main.cpp System/RealFilter.h Delegation/Algorithm.h Delegation/Algorithms.h System/Filter.h Proxy/ProxyFilter.h Delegation/Delegate.h Proxy/Proxy.h Adapter/Adapter.h Adapter/OutsideProtection.h Decorator/Decorator.h System/Letter.h Content/Content.h Decorator/DecoratorFile.h Decorator/ContentFile.h Content/Picture.h Content/Audio.h Content/Text.h)