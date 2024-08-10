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
        Pointers/pointer3.h
        Pointers/pointer4.h
        Pointers/pointer5.h
        Pointers/pointer6.h
        Pointers/pointer7.h
        Pointers/pointer8.h
        Primitives/sizeof.h
        Primitives/Test_0.h
        "File Processing/FileProcessing.h"
        "File Processing/Files2.h")
