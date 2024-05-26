#include <iostream>
#include <algorithm>
#include <optional>
#include "carController.h"

//Constructor
CarController::CarController(CarService *service) : carService(service){}

//Add a new car
void CarController::addCar(bool active, string licensePlate, string model,string brand,int registrationYear,
int mileage,int dailyPrice,string fuelType,string gearbox,string color,string remark) {
    try {
        int car_id = carService->createID();
        Car car(car_id, licensePlate, model, brand, registrationYear, mileage, dailyPrice, fuelType, gearbox, color, remark);
        carService->addCar(car);
    } catch (const std::exception &e) {
        cerr << "Failed to add car: " << e.what() << '\n';
    }
}

// Delete a car by ID
void CarController::deleteCar(int car_id) {
    try {
        if (! validateID(car_id)) {
            throw invalid_argument("Invalid car ID");
        }
        carService->deleteCar(car_id);
    } catch (const std::exception &e) {
        cerr << "Failed to delete car: " << e.what() << '\n';
    }
}

// Update a car by ID
void CarController::updateCar(int car_id, bool active, string licensePlate, string model,string brand,int registrationYear,
                              int mileage,int dailyPrice,string fuelType,string gearbox,string color,string remark) {

    try {
        Car newCar(car_id, licensePlate, model, brand, registrationYear, mileage, dailyPrice, fuelType, gearbox, color, remark);
        carService->updateCar(car_id, newCar);
    } catch (const std::exception &e) {
        cerr << "Failed to update car: " << e.what() << '\n';
    }

}

// Activate a car by ID
void CarController::activate(int car_id) {
    try {
        carService->activate(car_id);
    } catch (const std::runtime_error &e) {
        cerr << "Failed to activate car: " << e.what() << '\n';
    }
}

// Deactivate a car by ID
void CarController::deactivate(int car_id) {
    try {
        carService->deactivate(car_id);
    } catch (const std::runtime_error &e) {
        cerr << "Failed to deactivate car: " << e.what() << '\n';
    }
}

// List all active cars sorted by daily price
vector<Car> CarController::listallCars() {
    // only save active cars
    vector<Car> activeCars;
    for (Car car : carService->getAllCars()) {
        if (car.get_active() ) {
            activeCars.push_back(car);
        }
    }

   // sort by daily price
    sort(activeCars.begin(), activeCars.end(), []( Car a, Car b) {
        return a.get_dailyPrice() < b.get_dailyPrice();
    });
    return activeCars;

}

// Find a car by license plate
Car CarController::findCarByLicensePlate(string licensePlate) {
    Car found_car = carService->findCarByLicensePlate(licensePlate);
    return found_car;
}

// Return a car by ID
Car CarController::returnCarbyID(int car_id) {
    vector<Car> cars;
    cars = carService->getAllCars();
    for (Car car : cars)
        if(car.get_id() == car_id)
            return car;
    throw std::runtime_error("Car not found");
}

// Validate licence plate
bool CarController::validateLicensePlate(string licensePlate) {

    if (licensePlate.empty())
        return false;

    bool valid = true;
    for (char c : licensePlate) {
        if (!isalnum(c)) { // Only letters and digits allowed
            valid = false;
            break;
        }
    }
    if (!valid) {
         return false;
    }
    // is unique
    vector<Car> cars;
    cars = carService->getAllCars();
    int found = 1;
    for (Car car : cars) {
        if (car.get_lincensePlate() == licensePlate)found ++;
    }
    if ( found > 1)
        return false;

}

// Validate registration year
bool CarController::validateRegistrationYear(int registrationYear) {
    if (registrationYear < 2000 || registrationYear > 2024) {
        return false;
    }
    else return true;
}

// Validate mileage
bool CarController::validateMileage(int mileage) {
    if (mileage < 0 )
        return false;
    else return true;
}

// Validate daily price
bool CarController::validateDailyPrice(int dailyPrice) {
    if (dailyPrice < 0 )
        return false;
    else return true;
}

// Validate ID
bool CarController::validateID(int id) {
    if (id < 0 )
        return false;
    else return true;
}

string CarController::modifyLicensePlate(string licensePlate) {
    // converting letters to uppercase
    for (char &c : licensePlate) {
        if (isalpha(c)) {
            c = toupper(c);
        }
    }
    return licensePlate;
}
