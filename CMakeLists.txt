cmake_minimum_required(VERSION 3.8)
project(PCSC2017_Group5)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        AbstractNumericalApproximation.cpp
        AbstractNumericalApproximation.h
        main.cpp
        MultMat.cpp
        MultMat.h
        readFile.cpp
        readFile.h
        super_cool_class.h LeastSquare.cpp LeastSquare.h DivMat.cpp DivMat.h Lagrange.cpp Lagrange.h)

add_executable(PCSC2017_Group5 ${SOURCE_FILES} LeastSquare.cpp LeastSquare.h Lagrange.cpp Lagrange.h)