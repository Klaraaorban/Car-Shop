//
// Created by miruna on 24.05.2024.
//

#ifndef CARSHOP_CONTROLLER_H
#define CARSHOP_CONTROLLER_H
#include "../Controllers/carController.h"
#include "../Controllers/customerController.h"
#include "../Controllers/employeeController.h"
#include "../Controllers/orderController.h"
#include <string>

class Controller {
private:
    //controllerele mici
    customerController custController;
    CarController *carController = nullptr;
    EmployeeController emplController;
    orderController *ordController= nullptr;
public:
    Controller(customerController *custController, CarController *carController, EmployeeController *emplController, orderController *ordController);

    customer findCustomerByEmailandPassword(string email, string password);
    Employee findEmployeeByEmailandPassword(string email, string password);

    void addCar(bool active, string licensePlate, string model,string brand,int registrationYear, int mileage,int dailyPrice,string fuelType,string gearbox,string color,string remark);
    void updateCar(int car_id, bool active, string licensePlate, string model,string brand,int registrationYear, int mileage,int dailyPrice,string fuelType,string gearbox,string color,string remark);
    void deleteCar(int car_id);
    void activate(int car_id);
    void deactivate(int car_id);
    vector<Car> notOrderedCars(string from, string to);
    Car findCarByLicensePlate(string licensePlate);
    vector<Car> orderedCars(int custID);

    bool validateLicensePlate(string licensePlate);
    bool validateRegistrationYear(int registrationYear);
    bool validateMileage(int mileage);
    bool validateDailyPrice(int dailyPrice);
    bool validateID(int id);
    string modifyLicensePlate(string licensePlate);
};

#endif //CARSHOP_CONTROLLER_H
