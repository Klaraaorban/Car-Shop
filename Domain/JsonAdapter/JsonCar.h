//
// Created by miruna on 26.05.2024.
//
#pragma once
#ifndef CARSHOP_JSONCAR_H
#define CARSHOP_JSONCAR_H
#include "../CarDomain/Car.h"
#include "../../json/single_include/nlohmann/json.hpp"

using json = nlohmann::json;

class JsonCar {
    Car static JsonToModel();
public:
    json static ModelToJson(Car car);
};

#endif //CARSHOP_JSONCAR_H
