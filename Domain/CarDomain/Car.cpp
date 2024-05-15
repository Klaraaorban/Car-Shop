#include "Car.h"

using namespace std;

Car::Car(int car_id, string lincensePlate, string model, string brand, int registrationYear, int mileage, int dailyPrice, string fuelType, string gearbox, string color, string remark){
    this->car_id = car_id;
    this->lincensePlate = lincensePlate;
    this->model = model;
    this->brand = brand;
    this->registrationYear = registrationYear;
    this->mileage = mileage;
    this->dailyPrice = dailyPrice;
    this->fuelType = fuelType;
    this->gearbox = gearbox;
    this->color = color;
    this->remark = remark;
    this->active = true;
}
