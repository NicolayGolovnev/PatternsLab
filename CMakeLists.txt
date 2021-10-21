cmake_minimum_required(VERSION 3.15)
project(patterns)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

add_executable(patterns main.cpp System/RealFilter.h Delegation/Algorithm.h Delegation/Algorithms.h System/Filter.h Proxy/ProxyFilter.h Delegation/Delegate.h Proxy/Proxy.h Adapter/Adapter.h Adapter/OutsideProtection.h System/Letter.h Content/Content.h Content/Picture.h Content/Audio.h Content/Text.h Composite/Component.h Composite/User.h Composite/Composite.h Iterator/IterableCollection.h Iterator/IteratorContent.h Iterator/Iterator.h Decorator/DecoratorFilter.h Decorator/Decorator.h Decorator/FilterPercentWrapper.h System/FilterResult.h Decorator/FilterRecomendationWrapper.h)