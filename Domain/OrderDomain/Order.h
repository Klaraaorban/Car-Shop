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
class Bestellung_Domain {
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

    Bestellung_Domain(int idOrder, const string &dateOrder, const string &statusOrder, const string &beginOrder,
                      const string &endOrder, float billOrder, const string &observationsOrder, const Car &carOrder,
                      const customer &customerOrder, const Employee &workerOrder);

    int getIdOrder() const;

    void setIdOrder(int idOrder);

    const string &getDateOrder() const;

    void setDateOrder(const string &dateOrder);

    const string &getStatusOrder() const;

    void setStatusOrder(const string &statusOrder);

    const string &getBeginOrder() const;

    void setBeginOrder(const string &beginOrder);

    const string &getEndOrder() const;

    void setEndOrder(const string &endOrder);

    float getBillOrder() const;

    void setBillOrder(float billOrder);

    const string &getObservationsOrder() const;

    void setObservationsOrder(const string &observationsOrder);

// private functions
private:
    Bestellung_Domain modify_Order();

};


#endif //CARSHOP_BESTELLUNG_DOMAIN_H
