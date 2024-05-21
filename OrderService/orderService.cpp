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