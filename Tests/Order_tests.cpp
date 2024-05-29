
#include "Order_tests.h"
#include <assert.h>
#include <iostream>
#include <string>
#include "../Services/orderService.h"
#include "../Domain/OrderDomain/Order.h"
#include "../Controllers/orderController.h"
#include "../Domain/EmployeeDomain/Employee.h" // Employee class
#include "../Services/employeeService.h" // Employee service
#include "../Controllers/employeeController.h" // Employee controller
#include "../Domain/CarDomain/Car.h" // Car class
#include "../Services/carService.h" // Car service
#include "../Controllers/carController.h" // Car controller
#include "../Domain/CustomerDomian/Customer.h" // Customer class
#include "../Services/customerService.h" // Customer service
#include "../Controllers/customerController.h" // Customer controller

void Tests_order()
{

    std::string dbEmployeepath = "../JsonDB/Employee.json";
    EmployeeService employeeServiceInstance(dbEmployeepath);
    EmployeeController employeeControllerInstance(&employeeServiceInstance);

    std::string dbCarPath = "path/to/your/database/file.json";//aici trebe file-ul din JsonDB de la car
    CarService carServiceInstance(dbCarPath);
    CarController carControllerInstance(&carServiceInstance);

    std::string dbCustomerPath = "path/to/your/database/file.json";//aici trebe file-ul din JsonDB de la customer
    customerService customerServiceInstance(dbCustomerPath);
    customerController customerControllerInstance(&customerServiceInstance);

    std::string dbOrderPath = "path/to/your/database/file.json";//aici trebe file-ul din JsonDB de la order
    orderService orderServiceInstance(dbOrderPath, dbCarPath, dbCustomerPath, dbEmployeepath);
    orderController orderControllerInstance(&orderServiceInstance);

    Employee employeeInstance(1,"password123", "Doe", "John", "Peter","john.doe@example.com", "Manager", "1990-01-01", 5000, "No remarks");
    Car carInstance(1, "AB123CD", "Model S", "Tesla", 2020, 10000, 500, "Electric", "Automatic", "Red", "No remarks");
    Address customerAddress = {"USA", "Anytown", "Main St", 123};
    E_mail customerMail = {"john.doe@example.com", "password123"};
    CustomerName customerName = {"John", "Doe"};
    std::string customerPhoneNr = "123-456-7890";
    std::string customerNote = "No remarks";
    bool GdprDeleted = false;

    customer customerInstance(customerName, customerMail, customerAddress, customerPhoneNr, customerNote, GdprDeleted, {1});

    std::string dateOrder = "2024-04-24";
    std::string statusOrder = "In Progress";
    std::string beginOrder = "2024-04-24";
    std::string endOrder = "2024-04-30";
    float billOrder = 500.0;
    std::string observationsOrder = "No remarks";

    Order orderInstance(1, dateOrder, statusOrder, beginOrder, endOrder, billOrder, observationsOrder, carInstance, customerInstance, employeeInstance);

    orderServiceInstance.addOrder(orderInstance);
    assert(orderServiceInstance.getAllOrders().size() == 1);
    assert(orderServiceInstance.getAllOrders()[0].getIdOrder()== 1);
    assert(orderServiceInstance.getAllOrders()[0].getDateOrder() == "2024-04-24");
    assert(orderServiceInstance.getAllOrders()[0].getStatusOrder() == "In Progress");
    assert(orderServiceInstance.getAllOrders()[0].getBeginOrder() == "2024-04-24");
    assert(orderServiceInstance.getAllOrders()[0].getEndOrder() == "2024-04-30");
    assert(orderServiceInstance.getAllOrders()[0].getBillOrder() == 500.0);
    assert(orderServiceInstance.getAllOrders()[0].getObservationsOrder() == "No remarks");
    assert(orderServiceInstance.getAllOrders()[0].getCarOrder().get_id() == 1);
    //assert(orderServiceInstance.getAllOrders()[0].getCustomerOrder().getCustomerID() == 1);
    assert(orderServiceInstance.getAllOrders()[0].getWorkerOrder().getId()== 1);
    int id=orderInstance.getIdOrder();
    orderServiceInstance.deleteOrder(id);
    assert(orderServiceInstance.getAllOrders().size() == 0);
    orderServiceInstance.addOrder(orderInstance);

    Order neworder(1, "2024-04-24", "In Progress", "2024-04-24", "2024-04-30", 500.0, "No remarks", carInstance, customerInstance, employeeInstance);

    orderServiceInstance.updateOrder(id, neworder);
    assert(orderServiceInstance.getAllOrders().size() == 1);
    assert(orderServiceInstance.getAllOrders()[0].getIdOrder()== 1);
    assert(orderServiceInstance.getAllOrders()[0].getDateOrder() == "2024-04-24");
    assert(orderServiceInstance.getAllOrders()[0].getStatusOrder() == "In Progress");
    assert(orderServiceInstance.getAllOrders()[0].getBeginOrder() == "2024-04-24");
    assert(orderServiceInstance.getAllOrders()[0].getEndOrder() == "2024-04-30");
    assert(orderServiceInstance.getAllOrders()[0].getBillOrder() == 500.0);
    assert(orderServiceInstance.getAllOrders()[0].getObservationsOrder() == "No remarks");
    assert(orderServiceInstance.getAllOrders()[0].getCarOrder().get_id() == 1);
    //assert(orderServiceInstance.getAllOrders()[0].getCustomerOrder().getCustomerID() == 1);
    assert(orderServiceInstance.getAllOrders()[0].getWorkerOrder().getId()== 1);
    orderServiceInstance.deleteOrder(id);
    assert(orderServiceInstance.getAllOrders().size() == 0);
    std::cout << "Order tests passed!" << std::endl;


}