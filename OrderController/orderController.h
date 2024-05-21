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
    void addOrder();
    void getOrderById();
    void updateOrder();
    void deleteOrder();
    void listAllOrders();
};


#endif //CARSHOP_ORDERCONTROLLER_H
