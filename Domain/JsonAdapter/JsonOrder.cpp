//
// Created by raulm on 5/15/2024.
//

#include "JsonOrder.h"

json JsonOrder::ModelToJson(Order& order) {
    json j;
    j["_id_Order"] = order.getIdOrder();
    j["_date_Order"] = order.getDateOrder();
    j["_status_Order"] = order.getStatusOrder();
    j["_begin_Order"] = order.getBeginOrder();
    j["_end_Order"] = order.getEndOrder();
    j["_bill_Order"] = order.getBillOrder();
    j["_observations_Order"] = order.getObservationsOrder();
    j["_car_Order"] = order.getCarOrder().get_id();
    j["_customer_Order"] = order.getCustomerOrder().getCustomerID();
    j["_worker_Order"] = order.getWorkerOrder().getId();
    return j;
}