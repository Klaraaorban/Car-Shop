//
// Created by miruna on 24.05.2024.
//

#include "Controller.h"

Controller::Controller(customerController custController, CarController carController, EmployeeController emplController, orderController ordController) :
        custController(custController), carController(carController), emplController(emplController), ordController(ordController)
{

}
