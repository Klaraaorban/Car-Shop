//
// Created by raulm on 4/24/2024.
//

#include "Order.h"

int Order::getIdOrder() const {
    return _id_Order;
}

void Order::setIdOrder(int idOrder) {
    _id_Order = idOrder;
}

const string &Order::getDateOrder() const {
    return _date_Order;
}

void Order::setDateOrder(const string &dateOrder) {
    _date_Order = dateOrder;
}

const string &Order::getStatusOrder() const {
    return _status_Order;
}

void Order::setStatusOrder(const string &statusOrder) {
    _status_Order = statusOrder;
}

const string &Order::getBeginOrder() const {
    return _begin_Order;
}

void Order::setBeginOrder(const string &beginOrder) {
    _begin_Order = beginOrder;
}

const string &Order::getEndOrder() const {
    return _end_Order;
}

void Order::setEndOrder(const string &endOrder) {
    _end_Order = endOrder;
}

float Order::getBillOrder() const {
    return _bill_Order;
}

void Order::setBillOrder(float billOrder) {
    _bill_Order = billOrder;
}

const string &Order::getObservationsOrder() const {
    return _observations_Order;
}

void Order::setObservationsOrder(const string &observationsOrder) {
    _observations_Order = observationsOrder;
}

Order::Order(int idOrder, const string &dateOrder, const string &statusOrder,
                                     const string &beginOrder, const string &endOrder, float billOrder,
                                     const string &observationsOrder, const Car &carOrder, const customer &customerOrder,
                                     const Employee &workerOrder) : _id_Order(idOrder), _date_Order(dateOrder),_status_Order(statusOrder),_begin_Order(beginOrder), _end_Order(endOrder),
                                     _bill_Order(billOrder),_observations_Order(observationsOrder),_car_Order(carOrder),_customer_Order(customerOrder),_worker_Order(workerOrder) {}
