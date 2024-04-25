cmake_minimum_required(VERSION 3.27)
project(car_sharing)

set(CMAKE_CXX_STANDARD 17)

add_executable(car_sharing main.cpp
        customer_model.h
        customer_model.cpp)
