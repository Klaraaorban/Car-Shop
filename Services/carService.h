#ifndef CARSHOP_CARSERVICE_H
#define CARSHOP_CARSERVICE_H
#pragma once

#include <vector>
#include <string>
#include <fstream>
#include "../Domain/CarDomain/Car.h"

using namespace std;

class CarService {
private:
    vector<Car> cars;
    string dbFilePath;

    void loadFromJson();
    void saveToJson() const;
public:
    CarService(const string &dbFilePath);
    int createID();
    void addCar(const Car &car);
    void updateCar(const int &car_id, const Car &updatedCar);
    void deleteCar(const int &car_id);
    void activate(const int &car_id);
    void deactivate(const int &car_id);
    vector<Car> getAllCars() const;
    Car findCarByLicensePlate(const string& licensePlate1);
};

#endif //CARSHOP_CARSERVICE_H
