//
// Created by User on 5/17/2024.
//

#include "orderController.h"
#include "../OrderService/orderService.h"
#include <iostream>
#include <string>

orderController::orderController(orderService &orderservice) : orderService(orderservice) {}

void orderController::addOrder() {
    int id;
    std::string date;
    std::string status;
    std::string begin;
    std::string end;
    float bill;
    std::string observations;
    Car car;
    customer customer;
    Employee worker;

    int car_id=car.get_id();
    //int customer_id=customer.get_id();
    //int worker_id=worker.get_id();

    std::cout << "Enter the id of the order: ";
    std::cin >> id;
    std::cout << "Enter the date of the order: ";
    std::cin >> date;
    std::cout << "Enter the status of the order: ";
    std::cin >> status;
    std::cout << "Enter the begin of the order: ";
    std::cin >> begin;
    std::cout << "Enter the end of the order: ";
    std::cin >> end;
    std::cout << "Enter the bill of the order: ";
    std::cin >> bill;
    std::cout << "Enter the observations of the order: ";
    std::cin >> observations;

//    orderService.addOrder(id, date, status, begin, end, bill, observations, car, customer, worker);
}

void orderController::getOrderById() {
    int id;
    std::cout << "Enter the id of the order: ";
    std::cin >> id;

    try {
        Order order = orderService.getOrderById(id);
        std::cout << "Id: " << order.getIdOrder() << "\n";
        std::cout << "Date: " << order.getDateOrder() << "\n";
        std::cout << "Status: " << order.getStatusOrder() << "\n";
        std::cout << "Begin: " << order.getBeginOrder() << "\n";
        std::cout << "End: " << order.getEndOrder() << "\n";
        std::cout << "Bill: " << order.getBillOrder() << "\n";
        std::cout << "Observations: " << order.getObservationsOrder() << "\n";
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
}


void orderController::updateOrder() {
    int id;
    std::cout << "Enter the id of the order to update: ";
    std::cin >> id;

    std::string date;
    std::string status;
    std::string begin;
    std::string end;
    float bill;
    std::string observations;
    Car car;
//    customer customer;
//    Employee worker;

    int car_id=car.get_id();
    //int customer_id=customer.get_id();
    //int worker_id=worker.get_id();

    std::cout << "Enter the date of the order: ";
    std::cin >> date;
    std::cout << "Enter the status of the order: ";
    std::cin >> status;
    std::cout << "Enter the begin of the order: ";
    std::cin >> begin;
    std::cout << "Enter the end of the order: ";
    std::cin >> end;
    std::cout << "Enter the bill of the order: ";
    std::cin >> bill;
    std::cout << "Enter the observations of the order: ";
    std::cin >> observations;

    orderService.updateOrder(id, date, status, begin, end, bill, observations, car, customer, worker);
}

void orderController::deleteOrder() {
    int id;
    std::cout << "Enter the id of the order to delete: ";
    std::cin >> id;

    try {
        orderService.deleteOrder(id);
        std::cout << "Order deleted successfully.\n";
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
}

void orderController::listAllOrders() {
//    auto orders = orderService.getAllOrders();
    for (const auto &order : orders) {
        std::cout << "Id: " << order.getIdOrder() << "\n";
        std::cout << "Date: " << order.getDateOrder() << "\n";
        std::cout << "Status: " << order.getStatusOrder() << "\n";
        std::cout << "Begin: " << order.getBeginOrder() << "\n";
        std::cout << "End: " << order.getEndOrder() << "\n";
        std::cout << "Bill: " << order.getBillOrder() << "\n";
        std::cout << "Observations: " << order.getObservationsOrder() << "\n";
    }
}
