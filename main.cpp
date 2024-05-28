#include <iostream>
#include <memory>
#include "UI/UI.h"
#include "MainController/Controller.h"
#include "Controllers/customerController.h"
#include "Controllers/employeeController.h"
#include "Controllers/carController.h"
#include "Services/customerService.h"
#include "Services/employeeService.h"
#include "Services/carService.h"
#include "Services/orderService.h"

int main() {
    customerService custSrv("JsonDB/Customer.json");
    customerController custCtrl(custSrv);
    EmployeeService emplSrv("JsonDB/Employee.json");
    EmployeeController emplCtrl(emplSrv);
    std::unique_ptr <CarService> carSrv = std::make_unique <CarService> ("JsonDB/Car.json");
    std::unique_ptr <CarController> carCtrl = std::make_unique <CarController> (carSrv.get());
//    orderService ordSrv("JsonDB/Order.json", "JsonDB/Car.json", "JsonDB/Customer.json", "JsonDB/Employee.json");
    std::unique_ptr<orderService> ordSrv = std::make_unique<orderService>("JsonDB/Order.json", "JsonDB/Car.json", "JsonDB/Customer.json", "JsonDB/Employee.json");
    orderController ordCtrl(ordSrv.get());
    std::unique_ptr <Controller> ctrl = std::make_unique <Controller> (&custCtrl, carCtrl.get(), &emplCtrl, &ordCtrl);
    std::unique_ptr <UI> ui = std::make_unique <UI> (ctrl.get());
    ui->run();
    cout<<"aici";
    return 0;

}
