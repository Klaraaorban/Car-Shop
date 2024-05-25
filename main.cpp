#include <iostream>
#include "Domain/Employee.h"
#include "Domain/JsonAdapter/JsonAdapter.h"
#include "EmployeeService/employeeService.h"
#include "Domain/OrderDomain/Order.h"
#include "json/single_include/nlohmann/json.hpp"
#include "UI/UI.h"

using json = nlohmann::json;

int main() {

    Employee e = Employee("1111","asfasfsa","111","1111","asfasfsa","1111","111",1111,"asfasfsa");
    JsonAdapter<Employee>::writeToJson(e);

//    Car car;
//    Customer customer;
//
//    Order o = Order(1111,"1111","1111","1111","1111",1111,car,customer,e);
//    JsonAdapter<Order>::writeToJsonOrder(o);

    std::cout << "Hello, World!" << std::endl;
    //Employee e = Employee("1111","asfasfsa","111","1111","asfasfsa","1111","111",1111,"asfasfsa");
    //JsonAdapter<Employee>::writeToJson(e);

    Controller *ctrl = nullptr;
    UI ui(ctrl);
    ui.run();
    cout<<"aici";
    return 0;

}
