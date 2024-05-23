//
// Created by User on 5/17/2024.
//
#include "orderService.h"
#include "../json/single_include/nlohmann/json.hpp"
using json = nlohmann::json;

orderService::orderService(const string &dbFilePath):dbFilePath(dbFilePath) {
    loadFromJson();
}

void orderService::loadFromJson() {
    ifstream inFile(dbFilePath);
    if (inFile.is_open()) {
        json j;
        inFile >> j;

        for (const auto &item : j) {
            Order ord(item["_id_Order"], item["_date_Order"], item["_status_Order"], item["_begin_Order"],
                         item["_end_Order"], item["_bill_Order"], item["_observations_Order"], item["_car_Order"], item["_customer_Order"],
                         item["_worker_Order"]);
            orders.push_back(ord);

        }
        inFile.close();

    }
}

/*
 * int _id_Order;
    string _date_Order;
    string _status_Order;
    string _begin_Order;
    string _end_Order;
    float _bill_Order;
    string _observations_Order;

    // TO DO, 3 objects
    // obiect de tip Auto
    Car _car_Order;
    // obiect de tip Kunde
    customer _customer_Order;
    // obiect de tip Arbeiter
    Employee _worker_Order;
 * */

void orderService::saveToJson() const {
    json j;
    for (Order order : orders) {
        j.push_back({
                            {"_id_Order", order.getIdOrder()},
                            {"_date_Order", order.getDateOrder()},
                            {"_status_Order", order.getStatusOrder()},
                            {"_begin_Order", order.getBeginOrder()},
                            {"_end_Order", order.getEndOrder()},
                            {"_bill_Order", order.getBillOrder()},
                            {"_observations_Order", order.getObservationsOrder()},
                            {"_car_Order", order.getCarOrder().get_id()},
                            {"_customer_Order", order.getCustomerOrder().getCustomerID()},
                            {"_worker_Order", order.getWorkerOrder()}

                    });
    }
    ofstream outFile(dbFilePath);
    if (outFile.is_open()) {
        outFile << j.dump(4);
        outFile.close();
    }
}
void orderService::addOrder(const Order &order) {
    orders.push_back(order);
    saveToJson();
}
void orderService::deleteOrder(const int &order_id) {
    for (auto it = orders.begin(); it != orders.end(); ++it) {
        if (it->getIdOrder() == order_id) {
            orders.erase(it);
            saveToJson();
            return;
        }
    }
    throw runtime_error("Order not found");
}

void orderService::updateOrder(const int &order_id, const Order &updatedOrder) {
    for (auto &ord : orders) {
        if (ord.getIdOrder() == order_id) {
            ord = updatedOrder;
            saveToJson();
            return;
        }
    }
    throw runtime_error("Order not found");
}

Order orderService::getOrderById(const int &order_id) {
    for(auto &ord: orders){
        if(order_id == ord.getIdOrder()){
            return ord;
        }
    }
    throw runtime_error("Order not found");
}

vector<Order> orderService::getAllOrders() const {
    return orders;
}


