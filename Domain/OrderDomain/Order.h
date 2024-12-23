//
// Created by raulm on 4/24/2024.
//

#ifndef CARSHOP_BESTELLUNG_DOMAIN_H
#define CARSHOP_BESTELLUNG_DOMAIN_H
#include <iostream>
#include <string>
#include <vector>
#include "../CarDomain/Car.h"
#include "../CustomerDomian/Customer.h"
#include "../EmployeeDomain/Employee.h"
// TO DO include 3 classes

using namespace std;
class Order {
private:
    int _id_Order;
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
public:
     Car &getCarOrder();

     int getIdCar();

    void setCarOrder(const Car &carOrder);

    customer &getCustomerOrder();

    void setCustomerOrder(customer &customerOrder);

    Employee &getWorkerOrder();

    void setWorkerOrder( Employee &workerOrder);

public:

    Order(int idOrder, const string &dateOrder,  const string &statusOrder, const string &beginOrder,
          const string &endOrder, float billOrder,const string &observationsOrder, Car carOrder,
          customer customerOrder, Employee workerOrder);

    int getIdOrder();

    void setIdOrder(int idOrder);

    string &getDateOrder();

    void setDateOrder(string &dateOrder);

    string &getStatusOrder();

    void setStatusOrder(string &statusOrder);

    string &getBeginOrder();

    void setBeginOrder(string &beginOrder);

    string &getEndOrder();

    void setEndOrder(string &endOrder);

    float getBillOrder();

    void setBillOrder(float billOrder);

    string &getObservationsOrder();

    void setObservationsOrder( string &observationsOrder);

    friend bool inline operator<(Order a, Order b){return a._date_Order < b._date_Order;}

// private functions
private:

};


#endif //CARSHOP_BESTELLUNG_DOMAIN_H
