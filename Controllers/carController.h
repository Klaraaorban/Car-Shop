#ifndef CARSHOP_CARCONTROLLER_H
#define CARSHOP_CARCONTROLLER_H

#pragma once
#include "../Services/carService.h"

using namespace std;

class CarController {
private:
    CarService &carService;
public:
    CarController(CarService &service);
    void addCar(bool active, string licensePlate, string model,string brand,int registrationYear, int mileage,int dailyPrice,string fuelType,string gearbox,string color,string remark);
    void updateCar(int car_id, bool active, string licensePlate, string model,string brand,int registrationYear, int mileage,int dailyPrice,string fuelType,string gearbox,string color,string remark);
    void deleteCar(int car_id);
    vector<Car> listallCars();
    void activate(int car_id);
    void deactivate(int car_id);
    Car findCarByLicensePlate(string licensePlate);
    Car returnCarbyID(int car_id);

    bool validateLicensePlate(string licensePlate);
    bool validateRegistrationYear(int registrationYear);
    bool validateMileage(int mileage);
    bool validateDailyPrice(int dailyPrice);
    bool validateID(int id);
    string modifyLicensePlate(string licensePlate);







};

#endif
