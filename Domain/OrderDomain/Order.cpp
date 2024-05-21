//
// Created by raulm on 4/24/2024.
//

#include "Order.h"

int Order::getIdOrder(){
    return _id_Order;
}

void Order::setIdOrder(int idOrder) {
    _id_Order = idOrder;
}

string &Order::getDateOrder() {
    return _date_Order;
}

void Order::setDateOrder(string &dateOrder) {
    _date_Order = dateOrder;
}

string &Order::getStatusOrder(){
    return _status_Order;
}

void Order::setStatusOrder(string &statusOrder) {
    _status_Order = statusOrder;
}

string &Order::getBeginOrder(){
    return _begin_Order;
}

void Order::setBeginOrder(string &beginOrder) {
    _begin_Order = beginOrder;
}

string &Order::getEndOrder(){
    return _end_Order;
}

void Order::setEndOrder(string &endOrder) {
    _end_Order = endOrder;
}

float Order::getBillOrder(){
    return _bill_Order;
}

void Order::setBillOrder(float billOrder) {
    _bill_Order = billOrder;
}

string &Order::getObservationsOrder(){
    return _observations_Order;
}

void Order::setObservationsOrder(string &observationsOrder) {
    _observations_Order = observationsOrder;
}

Order::Order(int idOrder, string &dateOrder, string &statusOrder,
                                      string &beginOrder, string &endOrder, float billOrder,
                                      string &observationsOrder, Car &carOrder, customer &customerOrder,
                                      Employee &workerOrder) : _id_Order(idOrder), _date_Order(dateOrder),_status_Order(statusOrder),_begin_Order(beginOrder), _end_Order(endOrder),
                                     _bill_Order(billOrder),_observations_Order(observationsOrder),_car_Order(carOrder),_customer_Order(customerOrder),_worker_Order(workerOrder) {}

Car &Order::getCarOrder() {
    return _car_Order;
}

void Order::setCarOrder(const Car &carOrder) {
    _car_Order = carOrder;
}

customer &Order::getCustomerOrder(){
    return _customer_Order;
}

void Order::setCustomerOrder(customer &customerOrder) {
    _customer_Order = customerOrder;
}

Employee &Order::getWorkerOrder(){
    return _worker_Order;
}

void Order::setWorkerOrder(Employee &workerOrder) {
    _worker_Order = workerOrder;
}
