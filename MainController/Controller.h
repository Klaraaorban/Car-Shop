//
// Created by miruna on 24.05.2024.
//

#ifndef CARSHOP_CONTROLLER_H
#define CARSHOP_CONTROLLER_H
#include "../Controllers/carController.h"
#include "../Controllers/customerController.h"
#include "../Controllers/employeeController.h"
#include "../Controllers/orderController.h"
#include <string>

class Controller {
private:
    //controllerele mici
    customerController custController;
    CarController carController;
    EmployeeController emplController;
    orderController ordController;
public:
    Controller(customerController custController, CarController carController, EmployeeController emplController, orderController ordController);
    vector<Car> notOrderedCars(string date);
    vector<Car> orderedCars(customer cust);
};

#endif //CARSHOP_CONTROLLER_H
