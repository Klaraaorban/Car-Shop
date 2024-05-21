//
// Created by User on 5/17/2024.
//
#include "../Domain/OrderDomain/Order.h"
#include <vector>
#include <string>
#include <fstream>
#ifndef CARSHOP_ORDERSERVICE_H
#define CARSHOP_ORDERSERVICE_H
using namespace std;

class orderService {
public:
//    void addOrder();
//    void getOrderById();
//    void updateOrder();
//    void deleteOrder();
//    void listAllOrders();
private:
    vector<Order> orders;
    string dbFilePath;

    void loadFromJson();
    void saveToJson() const;

public:
    orderService(const string &dbFilePath);
    void addOrder(const Order &order);
    void updateOrder(const int &order_id, const Order &updatedOrder);
    void deleteOrder(const int &order_id);
    void activate(const int &order_id);
    void deactivate(const int &order_id);
    vector<Order> getAllOrders() const;
    };


#endif //CARSHOP_ORDERSERVICE_H
