//
// Created by miruna on 26.05.2024.
//
#include "JsonCar.h"

json JsonCar::ModelToJson(Car car) {
    json j;
    j["car_id"] = car.get_id();
    j["licensePlate"] = car.get_lincensePlate();
    j["model"] = car.get_model();
    j["brand"] = car.get_brand();
    j["registrationYear"] = car.get_registrationYear();
    j["mileage"] = car.get_mileage();
    j["dailyPrice"] = car.get_dailyPrice();
    j["fuelType"] = car.get_fuelType();
    j["gearbox"] = car.get_gearbox();
    j["color"] = car.get_color();
    j["remark"] = car.get_remark();
    j["active"] = car.get_active();
    return j;
}