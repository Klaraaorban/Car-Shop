//
// Created by User on 5/17/2024.
//
using json = nlohmann::json;
#include "orderService.h"
#include "../json/single_include/nlohmann/json.hpp"
using json = nlohmann::json;
void orderService::loadFromJson() {
    ifstream inFile(dbFilePath);
    if (inFile.is_open()) {
        json j;
        inFile >> j;
        inFile.close();

    }
}

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
                            {"_observations_Order", order.getObservationsOrder()}

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
    throw runtime_error("Car not found");
}

vector<Order> orderService::getAllrders() const {
    return orders;
}

