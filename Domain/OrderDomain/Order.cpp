//
// Created by raulm on 4/24/2024.
//

#include "Order.h"

int Bestellung_Domain::getIdOrder() const {
    return _id_Order;
}

void Bestellung_Domain::setIdOrder(int idOrder) {
    _id_Order = idOrder;
}

const string &Bestellung_Domain::getDateOrder() const {
    return _date_Order;
}

void Bestellung_Domain::setDateOrder(const string &dateOrder) {
    _date_Order = dateOrder;
}

const string &Bestellung_Domain::getStatusOrder() const {
    return _status_Order;
}

void Bestellung_Domain::setStatusOrder(const string &statusOrder) {
    _status_Order = statusOrder;
}

const string &Bestellung_Domain::getBeginOrder() const {
    return _begin_Order;
}

void Bestellung_Domain::setBeginOrder(const string &beginOrder) {
    _begin_Order = beginOrder;
}

const string &Bestellung_Domain::getEndOrder() const {
    return _end_Order;
}

void Bestellung_Domain::setEndOrder(const string &endOrder) {
    _end_Order = endOrder;
}

float Bestellung_Domain::getBillOrder() const {
    return _bill_Order;
}

void Bestellung_Domain::setBillOrder(float billOrder) {
    _bill_Order = billOrder;
}

const string &Bestellung_Domain::getObservationsOrder() const {
    return _observations_Order;
}

void Bestellung_Domain::setObservationsOrder(const string &observationsOrder) {
    _observations_Order = observationsOrder;
}

Bestellung_Domain::Bestellung_Domain(int idOrder, const string &dateOrder, const string &statusOrder,
                                     const string &beginOrder, const string &endOrder, float billOrder,
                                     const string &observationsOrder, const Car &carOrder, const customer &customerOrder,
                                     const Employee &workerOrder) : _id_Order(idOrder), _date_Order(dateOrder),_status_Order(statusOrder),_begin_Order(beginOrder), _end_Order(endOrder),
                                     _bill_Order(billOrder),_observations_Order(observationsOrder),_car_Order(carOrder),_customer_Order(customerOrder),_worker_Order(workerOrder) {}
