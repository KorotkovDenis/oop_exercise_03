cmake_minimum_required(VERSION 3.2)

project(lab3)

add_executable(lab3
        main.cpp
        Polygon.hpp
        Polygon.cpp
        )

set_property(TARGET lab3 PROPERTY CXX_STANDARD` 17)