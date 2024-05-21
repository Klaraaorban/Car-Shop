//
// Created by User on 5/17/2024.
//

#ifndef CARSHOP_ORDERCONTROLLER_H
#define CARSHOP_ORDERCONTROLLER_H

#include "../OrderService/orderService.h"
#include "../Car/Car.h"
#include "../Customer/customer.h"
#include "../Employee/Employee.h"

class orderController {
private:
    orderService &orderService;
public:
    orderController(orderController &orderService);
    void addOrder();
    void getOrderById();
    void updateOrder();
    void deleteOrder();
    void listAllOrders();
};


#endif //CARSHOP_ORDERCONTROLLER_H
