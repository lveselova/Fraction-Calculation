cmake_minimum_required(VERSION 3.22)
project(Fraction_Calculation)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Fraction_Calculation
        driver.cpp
        fraction.cpp
        fraction.h
        fraction_exception.h
        )


add_executable(Fraction-Testing
        fraction.cpp
        fraction.h
        fraction_exception.h
        fractionTesting.cpp
        )