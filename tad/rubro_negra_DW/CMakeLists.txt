cmake_minimum_required(VERSION 3.13)
project(rubro_negra)

set(CMAKE_CXX_STANDARD 14)

add_library(rubro_negra rubro_negra.cpp rubro_negra.h)
add_executable(exec.cpp)