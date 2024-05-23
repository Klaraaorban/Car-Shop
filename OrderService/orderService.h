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
    orderService(string &dbFilePath);
    void addOrder(Order &order);
    int createId();
    void updateOrder(int &order_id, Order &updatedOrder);
    Order getOrderById(int &order_id);
    void deleteOrder(int &order_id);
    vector<Order> getAllOrders();
    };


#endif //CARSHOP_ORDERSERVICE_H
