cmake_minimum_required(VERSION 3.27)
project(CarShop)

set(CMAKE_CXX_STANDARD 17)

add_executable(CarShop main.cpp
        Domain/Bestellung_Domain.h
        Domain/Bestellung_Domain.cpp
        Repo/Bestellung_Repo.cpp
        Service/Bestellung_Service.cpp)
