cmake_minimum_required(VERSION 3.5)
project(PA3)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CXXFLAGS "-Wall -Wextra -pedantic -pipe -O2")

set(PA3_SOURCES main.cpp simulation.cpp protocols.cpp)
list(TRANSFORM PA3_SOURCES PREPEND "src/")

add_executable(pa3 ${PA3_SOURCES})
