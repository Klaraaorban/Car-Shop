#include "carService.h"
#include "../json/single_include/nlohmann/json.hpp"

using json = nlohmann::json;

CarService::CarService(const string &dbFilePath) : dbFilePath(dbFilePath) {
    loadFromJson();
}

void CarService::loadFromJson() {
    ifstream inFile(dbFilePath);
    if (inFile.is_open()) {
        json j;
        inFile >> j;
        for (const auto &item : j) {
            Car car(item["car_id"], item["licensePlate"], item["model"], item["brand"],
                         item["registrationYear"], item["mileage"], item["dailyPrice"],
                         item["fuelType"], item["gearbox"], item["color"], item["remark"]);
            car.set_active(item["active"]);
            cars.push_back(car);
        }
        inFile.close();
    }
}

void CarService::saveToJson() const {
    json j;
    for (Car car : cars) {
        j.push_back({
                            {"car_id", car.get_id()},
                            {"licensePlate", car.get_lincensePlate()},
                            {"model", car.get_model()},
                            {"brand", car.get_brand()},
                            {"registrationYear", car.get_registrationYear()},
                            {"mileage", car.get_mileage()},
                            {"dailyPrice", car.get_dailyPrice()},
                            {"fuelType", car.get_fuelType()},
                            {"gearbox", car.get_gearbox()},
                            {"color", car.get_color()},
                            {"remark", car.get_remark()},
                            {"active", car.get_active()}
                    });
    }
    ofstream outFile(dbFilePath);
    if (outFile.is_open()) {
        outFile << j.dump(4);
        outFile.close();
    }
}

int CarService::createID() {
    return cars.size();
}

void CarService::addCar(const Car &car) {
    cars.push_back(car);
    saveToJson();
}

void CarService::updateCar(const int &car_id, const Car &updatedCar) {
    for (auto &emp : cars) {
        if (emp.get_id() == car_id) {
            emp = updatedCar;
            saveToJson();
            return;
        }
    }
    throw runtime_error("Car not found");
}

void CarService::deleteCar(const int &car_id) {
    for (auto it = cars.begin(); it != cars.end(); ++it) {
        if (it->get_id() == car_id) {
            cars.erase(it);
            saveToJson();
            return;
        }
    }
    throw runtime_error("Car not found");
}

void CarService::activate(const int &car_id) {
    for (auto it = cars.begin(); it != cars.end(); ++it) {
        if (it->get_id() == car_id) {
            it->set_active(true);
            saveToJson();
            return;
        }
    }
    throw runtime_error("Car not found");
}

void CarService::deactivate(const int &car_id) {
    for (auto it = cars.begin(); it != cars.end(); ++it) {
        if (it->get_id() == car_id) {
            it->set_active(false);
            saveToJson();
            return;
        }
    }
    throw runtime_error("Car not found");
}

vector<Car> CarService::getAllCars() const {
    return cars;
}

Car CarService::findCarByLicensePlate(const string& licensePlate1) {
    for (Car car : cars) {
        if (car.get_lincensePlate() == licensePlate1) {
            return car;
        }
    }
    throw runtime_error("Car not found");
}


