cmake_minimum_required(VERSION 3.25)
project(csc212su_211project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(csc212su_211project
        gradebook.cpp
        gradebook.h
        main.cpp
        project_description.md
        readme.md)
