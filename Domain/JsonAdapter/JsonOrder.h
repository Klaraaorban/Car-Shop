//
// Created by raulm on 5/15/2024.
//

#ifndef CARSHOP_JSONORDER_H
#define CARSHOP_JSONORDER_H
#include "../../json/single_include/nlohmann/json.hpp"
#include "../OrderDomain/Order.h"

using json = nlohmann::json;
class JsonOrder {
    Order static JsonToModel();
public:
    json static ModelToJson(Order& order);
};
#endif //CARSHOP_JSONORDER_H
