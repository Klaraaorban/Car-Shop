//
// Created by User on 5/17/2024.
//
#include "../Domain/OrderDomain/Order.h"
#ifndef CARSHOP_ORDERSERVICE_H
#define CARSHOP_ORDERSERVICE_H
using namespace std;

class orderService {

    private:
        vector<Order> orders;
        string dbFilePath;

        void loadFromJson();
        void saveToJson() const;

    public:
        OrderService(const string &dbFilePath);
        void addOrder(const Order &order);
        void updateOrder();
        void deleteOrder(const int &order_id);
        void activate(const int &order_id);
        void deactivate(const int &order_id);
        vector<Order> getAllrders() const;

    };


#endif //CARSHOP_ORDERSERVICE_H
