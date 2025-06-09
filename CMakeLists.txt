cmake_minimum_required(VERSION 3.25)
project(leetForCpp)

set(CMAKE_CXX_STANDARD 11)

# Boost 库
set(BOOST_HOME "/opt/homebrew/Cellar/boost/1.81.0_1")
include_directories(${BOOST_HOME}/include)
link_directories(${BOOST_HOME}/lib)

# PCRE++ 库
set(PCRE_HOME "/opt/homebrew/Cellar/pcre/8.45")
include_directories(${PCRE_HOME}/include)
link_directories(${PCRE_HOME}/lib)

add_executable(leetForCpp test/main.cpp)