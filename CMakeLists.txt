cmake_minimum_required(VERSION 3.27)
project(car_sharing)

set(CMAKE_CXX_STANDARD 17)

add_executable(car_sharing main.cpp
        Customer.h
        Customer.cpp
        Car.h
        Car.cpp
        Employee.h
        Employee.cpp
        Order.h
        Order.cpp)
