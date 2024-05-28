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
#include "json/single_include/nlohmann/json.hpp"
using json = nlohmann::json;

int main() {
    std::unique_ptr<customerService> custSrv = std::make_unique<customerService>("JsonDB/Customer.json");
    std::unique_ptr<customerController> custCtrl = std::make_unique<customerController>(custSrv.get());
    std::unique_ptr<EmployeeService> emplSrv = std::make_unique<EmployeeService>("JsonDB/Employee.json");
    std::unique_ptr<EmployeeController> emplCtrl = std::make_unique<EmployeeController>(emplSrv.get());
    std::unique_ptr <CarService> carSrv = std::make_unique <CarService> ("JsonDB/Car.json");
    std::unique_ptr <CarController> carCtrl = std::make_unique <CarController> (carSrv.get());
    std::unique_ptr <orderService> ordSrv = std::make_unique<orderService>("JsonDB/Order.json", "JsonDB/Car.json", "JsonDB/Customer.json", "JsonDB/Employee.json");
    std::unique_ptr <orderController> ordCtrl = std::make_unique<orderController>(ordSrv.get());
    std::unique_ptr <Controller> ctrl = std::make_unique <Controller> (custCtrl.get(), carCtrl.get(), emplCtrl.get(), ordCtrl.get());
    std::unique_ptr <UI> ui = std::make_unique <UI> (ctrl.get());
    ui->run();
    cout<<"aici";
    return 0;

}
