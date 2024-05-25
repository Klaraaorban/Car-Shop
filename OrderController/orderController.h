//
// Created by User on 5/17/2024.
//

#ifndef CARSHOP_ORDERCONTROLLER_H
#define CARSHOP_ORDERCONTROLLER_H

#include "../OrderService/orderService.h"
#include "../Domain/CarDomain/Car.h"
#include "../Domain/CustomerDomian/Customer.h"
#include "../Domain/Employee.h"

class orderController {
private:
    orderService &OrderService;
public:
    orderController(orderService &OrderService);
    void addOrder(string &dateOrder,  string &statusOrder,  string &beginOrder,
                  string &endOrder, float billOrder, string &observationsOrder, Car &carOrder,
                  customer &customerOrder, Employee &workerOrder);
    Order getOrderById(int idOrder);
    void updateOrder(int idOrder,Order &updatedOrder);
    void deleteOrder(int orderId);
    std::vector<Order> listAllOrders();
    bool ID_is_valid(int id);
    void takeOverOrder(int orderId, Employee &newWorker);
    void assignOrder(int orderId, Employee &newWorker);
    std::vector<Order> getOrdersByDate( std::string &startDate,  std::string &endDate);
    float getTotalSumOfADate(string &date) ;
    void completeOrder(int orderId);
};


#endif //CARSHOP_ORDERCONTROLLER_H
