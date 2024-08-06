cmake_minimum_required(VERSION 3.26)
project(CS316_Summer2024)

set(CMAKE_CXX_STANDARD 23)

add_executable(CS316_Summer2024 main.cpp
        OOP/Test_OOP.cpp
        OOP/GradeBook.cpp
        OOP/Course.cpp
        OOP/Array.cpp
        Pointers/pointer1.h
        Pointers/pointer2.h
        Pointers/pointer3.h)
