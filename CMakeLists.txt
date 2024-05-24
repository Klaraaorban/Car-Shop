cmake_minimum_required(VERSION 3.27)
project(CarShop)

set(CMAKE_CXX_STANDARD 17)



add_executable(car_sharing main.cpp
        Domain/CarDomain/Car.cpp
        Domain/CarDomain/Car.h
        Domain/CustomerDomian/Customer.cpp
        Domain/CustomerDomian/Customer.h
        Domain/Employee.h
        Domain/Employee.cpp
        Domain/User.h
        Domain/User.cpp
        Domain/JsonAdapter/JsonAdapter.h
        Domain/JsonAdapter/JsonAdapter.cpp
        Domain/JsonAdapter/JsonEmployee.h
        Domain/JsonAdapter/JsonEmployee.cpp
        EmployeeService/employeeService.cpp
        EmployeeService/employeeService.h
        EmployeeController/employeeController.cpp
        EmployeeController/employeeController.h
        UI/UI.h
        UI/UI.cpp
        Controller/Controller.h
        Controller/Controller.cpp
)
