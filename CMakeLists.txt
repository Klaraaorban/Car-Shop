cmake_minimum_required(VERSION 3.27)
project(CarShop)

set(CMAKE_CXX_STANDARD 17)



add_executable(car_sharing main.cpp
        Domain/CarDomain/Car.cpp
        Domain/CarDomain/Car.h
        Domain/CustomerDomian/Customer.cpp
        Domain/CustomerDomian/Customer.h
        Domain/EmployeeDomain/Employee.h
        Domain/EmployeeDomain/Employee.cpp
        Domain/User.h
        Domain/User.cpp
        Domain/JsonAdapter/JsonAdapter.h
        Domain/JsonAdapter/JsonAdapter.cpp
        Domain/JsonAdapter/JsonEmployee.h
        Domain/JsonAdapter/JsonEmployee.cpp
        Services/employeeService.cpp
        Services/employeeService.h
        Controllers/employeeController.cpp
        Controllers/employeeController.h
        Services/customerService.h
        Services/customerService.cpp
        Controllers/customerController.h
        Controllers/customerController.cpp
        CustomerUI/customerUI.h
        CustomerUI/customerUI.cpp
        Domain/JsonAdapter/JsonOrder.cpp
        Domain/OrderDomain/Order.cpp
        Controllers/orderController.h
        Controllers/orderController.cpp
        Services/orderService.h
        Services/orderService.cpp
        Controllers/carController.cpp

        UI/UI.h
        UI/UI.cpp
        MainController/Controller.h
        MainController/Controller.cpp
        Services/carService.cpp
        Domain/JsonAdapter/JsonCar.h
        Domain/JsonAdapter/JsonCar.cpp
        Tests/carTest.cpp
        Tests/carTest.h
)
