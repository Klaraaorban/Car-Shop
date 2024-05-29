#include <iostream>
#include <memory>
#include "Tests/carTest.h"
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
#include <filesystem>
using json = nlohmann::json;

void runTests() {
    CarTests t1;
    t1.testAllFunctions();
}

int main() {
    filesystem::path p=filesystem::current_path();
    std::unique_ptr<customerService> custSrv = std::make_unique<customerService>(p.string()+"\\..\\JsonDB\\Customer.json");
    std::unique_ptr<customerController> custCtrl = std::make_unique<customerController>(custSrv.get());
    std::unique_ptr<EmployeeService> emplSrv = std::make_unique<EmployeeService>(p.string()+"\\..\\JsonDB\\Employee.json");
    std::unique_ptr<EmployeeController> emplCtrl = std::make_unique<EmployeeController>(emplSrv.get());
    std::unique_ptr <CarService> carSrv = std::make_unique <CarService> (p.string()+"\\..\\JsonDB\\Car.json");
    std::unique_ptr <CarController> carCtrl = std::make_unique <CarController> (carSrv.get());
    std::shared_ptr <orderService> ordSrv = std::make_shared<orderService>(p.string()+"\\..\\JsonDB\\Order.json", p.string()+"\\..\\JsonDB\\Car.json", p.string()+"\\..\\JsonDB\\Customer.json", p.string()+"\\..\\JsonDB\\Employee.json");
    std::unique_ptr <orderController> ordCtrl = std::make_unique<orderController>(ordSrv.get());
    std::unique_ptr <Controller> ctrl = std::make_unique <Controller> (custCtrl.get(), carCtrl.get(), emplCtrl.get(), ordCtrl.get());
    std::unique_ptr <UI> ui = std::make_unique <UI> (ctrl.get());
    ui->run();
    return 0;

}
