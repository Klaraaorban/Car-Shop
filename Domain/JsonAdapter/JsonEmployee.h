//
// Created by andreiasnico 
//
#pragma once
#ifndef CARSHOP_JSONEMPLOYEE_H
#define CARSHOP_JSONEMPLOYEE_H
#include "../EmployeeDomain/Employee.h"
#include "../../json/single_include/nlohmann/json.hpp"

using json = nlohmann::json;
class JsonEmployee {
Employee static JsonToModel();
public:
json static ModelToJson(Employee employee);
};


#endif //CARSHOP_JSONEMPLOYEE_H
