//
// Created by andreiasnico 
//
#pragma once
#ifndef CARSHOP_JSONADAPTER_H
#define CARSHOP_JSONADAPTER_H
#include "../../json/single_include/nlohmann/json.hpp"
#include <typeinfo>

#include <fstream>

#include "JsonEmployee.h"
#include "JsonOrder.h"
#include "JsonCar.h"

using json = nlohmann::json;


template <class T> class JsonAdapter{
public:
    static void writeToJson(T instance);
    static void writeToJsonOrder(T instance);

public:

};

template<class T>
void JsonAdapter<T>::writeToJson(T instance) {
    json j;

//todo check this for everytype
    if( std::is_same<T,Employee>::value){
        ofstream i("../JsonDB/Employee.json");
        i<< JsonEmployee::ModelToJson(instance);

    }
    if( std::is_same<T,Car>::value){
        ofstream i("../JsonDB/Car.json");
        i<< JsonCar::ModelToJson(instance);
    }
}

template<class T>
void JsonAdapter<T>::writeToJsonOrder(T instance)
{
    json j;

    if (std::is_same<T, Order>::value) {
        ofstream i("../JsonDB/Order.json");
        i << JsonOrder::ModelToJson(instance);
    }
}

#endif //CARSHOP_JSONADAPTER_H
