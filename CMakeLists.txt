cmake_minimum_required(VERSION 3.30)
project(Zadanie1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Zadanie1 main.cpp myfloat.cpp
        SaturationFloat.h SaturationFloat.cpp
        vector.h
        vector.cpp
)
