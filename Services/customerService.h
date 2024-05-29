#ifndef CARSHOP_CUSTOMER_SERVICE_H
#define CARSHOP_CUSTOMER_SERVICE_H
#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "../Domain/CustomerDomian/Customer.h"
#include "../json/single_include/nlohmann/json.hpp"
#include "../Domain/CarDomain/Car.h"

using json = nlohmann::json;
using namespace std;

class customerService {
private:
    vector<customer> customers;
    string path;

    void loadJson();
    void saveJson() const;

public:
    customerService(const string &path);
    void addCostumer(const customer &_customer);
    void changeFavorite(std::string mail, std::vector<int> favorite);
    void deleteCustomer(string& email);
    vector<customer> getAllCustomers();
};


#endif //CARSHOP_CUSTOMER_SERVICE_H
