//
// Created by User on 5/17/2024.
//

#include "orderController.h"
//#include "../OrderService/orderService.h"
#include <iostream>
#include <string>

orderController::orderController(orderService *Orderservice): OrderService(Orderservice) {}

void orderController::addOrder(string &dateOrder,  string &statusOrder,  string &beginOrder,
                               string &endOrder, float billOrder, string &observationsOrder, Car &carOrder,
                               customer &customerOrder, Employee &workerOrder) {
    try{
        int idOrder=OrderService->createId();
        Order order_to_be_added(idOrder,dateOrder,statusOrder, beginOrder,
                                endOrder,  billOrder,  observationsOrder,  carOrder,
                                customerOrder,  workerOrder);
        OrderService->addOrder(order_to_be_added);
    }catch (const std::exception &e) {
        cerr << "Failed to add car: " << e.what() << '\n';
    }
//    int id;
//    std::string date;
//    std::string status;
//    std::string begin;
//    std::string end;
//    float bill;
//    std::string observations;
//    Car car;
//    customer customer;
//    Employee worker;
//
//    int car_id=car.get_id();
//    //int customer_id=customer.get_id();
//    //int worker_id=worker.get_id();
//
//    std::cout << "Enter the id of the order: ";
//    std::cin >> id;
//    std::cout << "Enter the date of the order: ";
//    std::cin >> date;
//    std::cout << "Enter the status of the order: ";
//    std::cin >> status;
//    std::cout << "Enter the begin of the order: ";
//    std::cin >> begin;
//    std::cout << "Enter the end of the order: ";
//    std::cin >> end;
//    std::cout << "Enter the bill of the order: ";
//    std::cin >> bill;
//    std::cout << "Enter the observations of the order: ";
//    std::cin >> observations;

//    orderService.addOrder(id, date, status, begin, end, bill, observations, car, customer, worker);
}

Order orderController::getOrderById(int idOrder) {
    if (! ID_is_valid(idOrder)) {
        throw invalid_argument("Invalid order ID");
    }
    else{
        Order ord= OrderService->getOrderById(idOrder);
        return ord;
    }



//    int id;
//    std::cout << "Enter the id of the order: ";
//    std::cin >> id;
//
//    try {
//        Order order = OrderService.getOrderById(id);
//        std::cout << "Id: " << order.getIdOrder() << "\n";
//        std::cout << "Date: " << order.getDateOrder() << "\n";
//        std::cout << "Status: " << order.getStatusOrder() << "\n";
//        std::cout << "Begin: " << order.getBeginOrder() << "\n";
//        std::cout << "End: " << order.getEndOrder() << "\n";
//        std::cout << "Bill: " << order.getBillOrder() << "\n";
//        std::cout << "Observations: " << order.getObservationsOrder() << "\n";
//    } catch (const std::exception &e) {
//        std::cerr << e.what() << '\n';
//    }
}

void orderController::updateOrder(int orderId,Order &updatedOrder) {
    try{
        if (! ID_is_valid(orderId)) {
            throw invalid_argument("Invalid order ID");}
        OrderService->updateOrder(orderId,updatedOrder);
    }
    catch (const std::exception &e) {
        cerr << "Failed to update order: " << e.what() << '\n';
    }
//    int id;
//    std::cout << "Enter the id of the order to update: ";
//    std::cin >> id;
//
//    std::string date;
//    std::string status;
//    std::string begin;
//    std::string end;
//    float bill;
//    std::string observations;
//    Car car;
////    customer customer;
////    Employee worker;
//
//    int car_id=car.get_id();
//    //int customer_id=customer.get_id();
//    //int worker_id=worker.get_id();
//
//    std::cout << "Enter the date of the order: ";
//    std::cin >> date;
//    std::cout << "Enter the status of the order: ";
//    std::cin >> status;
//    std::cout << "Enter the begin of the order: ";
//    std::cin >> begin;
//    std::cout << "Enter the end of the order: ";
//    std::cin >> end;
//    std::cout << "Enter the bill of the order: ";
//    std::cin >> bill;
//    std::cout << "Enter the observations of the order: ";
//    std::cin >> observations;
//
//    OrderService.updateOrder(id, date, status, begin, end, bill, observations, car, customer, worker);
}

void orderController::deleteOrder(int orderId) {
    try{
        if (! ID_is_valid(orderId)) {
            throw invalid_argument("Invalid order ID");}
        OrderService->deleteOrder(orderId);
    }catch (const std::exception &e) {
        cerr << "Failed to delete order: " << e.what() << '\n';
    }
}

std::vector<Order> orderController::listAllOrders() {
    auto orders = OrderService->getAllOrders();
    return orders;
}

bool orderController::ID_is_valid(int id) {
    if (id < 0 )
        return false;
    return true;
}

void orderController::takeOverOrder(int orderId, Employee &newWorker) {
    try {
        OrderService->takeOverOrder(orderId, newWorker);
    } catch (const std::exception &e) {
        std::cerr << "Failed to take over order: " << e.what() << '\n';
    }
}

void orderController::assignOrder(int orderId, Employee &newWorker) {
    try {
        OrderService->assignOrder(orderId, newWorker);
    } catch (const std::exception &e) {
        std::cerr << "Failed to assign order: " << e.what() << '\n';
    }
}
std::vector<Order> orderController::getOrdersByDate( std::string &startDate,  std::string &endDate) {
    try {
        return OrderService->getOrdersByDate(startDate, endDate);
    } catch (const std::exception &e) {
        std::cerr << "Failed to get orders by date range: " << e.what() << '\n';
    }
}

float orderController::getTotalSumOfADate(string &date) {
    try {
        return OrderService->getTotalSumOfADate(date);
    } catch (const std::exception &e) {
        std::cerr << "Failed to get total sum by date: " << e.what() << '\n';
    }
}

void orderController::completeOrder(int orderId) {
    try {
        Order orderToUpdate = OrderService->getOrderById(orderId);
        orderToUpdate.setStatusOrder((string &) "Completed");
        OrderService->updateOrder(orderId, orderToUpdate);
    }catch (const std::exception &e) {
            std::cerr << "Failed to complete order " << e.what() << '\n';
        }
}

void orderController::convertReservationToOrder(int reservationId) {
    Order reservation = getOrderById(reservationId);
    if (reservation.getStatusOrder() == "Reservation") {
        reservation.setStatusOrder((string &)"Order");
        updateOrder(reservationId, reservation);
    } else {
        throw runtime_error("Only reservations can be converted to orders.");
    }
}

void orderController::deleteReservation(int reservationId,  int userId, std::string& userRole) {
    try {

        if (!OrderService->isReservation(reservationId)) {
            throw std::runtime_error("Only reservations can be deleted.");
        }
        Order reservation = OrderService->getOrderById(reservationId);
        if (userRole == "Employee" || (userRole == "Customer" && reservation.getCustomerOrder().getCustomerID() == userId)) {
            OrderService->deleteOrder(reservationId);
            std::cout << "Reservation deleted successfully.\n";
        } else {
            throw std::runtime_error("You do not have permission to delete this reservation.");
        }
    } catch (const std::exception &e) {
        std::cerr << "Failed to delete reservation: " << e.what() << '\n';
    }
}

void orderController::updateReservation(int reservationId, int userId,  std::string &userRole,  Order &updatedReservation) {
    try {
        if (!OrderService->isReservation(reservationId)) {
            throw std::runtime_error("Only reservations can be updated.");
        }
        Order reservation = OrderService->getOrderById(reservationId);
        if (userRole == "Employee" || (userRole == "Customer" && reservation.getCustomerOrder().getCustomerID() == userId)) {
            OrderService->updateOrder(reservationId, updatedReservation);
            std::cout << "Reservation updated successfully.\n";
        } else {
            throw std::runtime_error("You do not have permission to update this reservation.");
        }
    } catch (const std::exception &e) {
        std::cerr << "Failed to update reservation: " << e.what() << '\n';
    }
}