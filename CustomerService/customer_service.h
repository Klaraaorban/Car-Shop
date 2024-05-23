//
// Created by raulm on 5/22/2024.
//

#ifndef CARSHOP_CUSTOMER_SERVICE_H
#define CARSHOP_CUSTOMER_SERVICE_H
#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "../Domain/CustomerDomian/Customer.h"
#include "../json/single_include/nlohmann/json.hpp"

using json = nlohmann::json;
using namespace std;

class customer_service {
private:
    vector<customer> customers;
    string path;

    void loadJson();
    void saveJson() const;

public:
    customer_service(const string &path);
    void addCostumer(const customer &_customer);
    void update_customer(const string &email, const customer &updated_customer);
    void delete_customer(const string& email);
    vector<customer> getAllCustomers() const;
};


#endif //CARSHOP_CUSTOMER_SERVICE_H
