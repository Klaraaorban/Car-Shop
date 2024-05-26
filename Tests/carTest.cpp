//
// Created by aleol on 26-May-24.
//
#include "../Domain/CarDomain/Car.h"
#include "../Services/carService.h"
#include "../Controllers/carController.h"

#include "carTest.h"
#include <iostream>
#include <cassert>

using namespace std;

void CarTests::testCreate() {
    Car car(1, "SM45ALE", "Model S", "Tesla", 2020, 10000, 200, "Electric", "Automatic", "Red", "Remark");
    assert(car.get_id() == 1);
    assert(car.get_lincensePlate() == "SM45ALE");
    assert(car.get_model() == "Model S");
    assert(car.get_brand() == "Tesla");
    assert(car.get_registrationYear() == 2020);
    assert(car.get_mileage() == 10000);
    assert(car.get_dailyPrice() == 200);
    assert(car.get_fuelType() == "Electric");
    assert(car.get_gearbox() == "Automatic");
    assert(car.get_color() == "Red");
    assert(car.get_remark() == "Remark");

}

void CarTests::testAddCar() {
    CarService *carService ;
    CarController controller(carService);

    controller.addCar(true, "SM45ALE", "Model S", "Tesla", 2020, 10000, 200, "Electric", "Automatic", "Red", "Remark");
    auto cars = carService->getAllCars();

    assert(cars.size() == 1);
    assert(cars[0].get_lincensePlate() == "SM45ALE");
    assert(cars[0].get_model() == "Model S");
    assert(cars[0].get_brand() == "Tesla");
    assert(cars[0].get_registrationYear() == 2020);
    assert(cars[0].get_mileage() == 10000);
    assert(cars[0].get_dailyPrice() == 200);
    assert(cars[0].get_fuelType() == "Electric");
    assert(cars[0].get_gearbox() == "Automatic");
    assert(cars[0].get_color() == "Red");
    assert(cars[0].get_remark() == "Remark");
}

void CarTests::testDeleteCar() {
    CarService *carService;
    CarController controller(carService);

    controller.addCar(true, "SM45ALE", "Model S", "Tesla", 2020, 10000, 200, "Electric", "Automatic", "Red", "Remark");
    auto cars = carService->getAllCars();
    assert(cars.size() == 1);

    int car_id = cars[0].get_id();
    controller.deleteCar(car_id);
    cars = carService->getAllCars();
    assert(cars.size() == 0);
}


void CarTests::testUpdateCar() {
    CarService *carService;
    CarController controller(carService);

    controller.addCar(true, "SM45ALE", "Model S", "Tesla", 2020, 10000, 200, "Electric", "Automatic", "Red", "Remark");
    auto cars = carService->getAllCars();
    assert(cars.size() == 1);

    int car_id = cars[0].get_id();
    controller.updateCar(car_id, true, "SM45ALE", "Model X", "Tesla", 2021, 5000, 250, "Electric", "Automatic", "Blue", "Updated Remark");
    cars = carService->getAllCars();
    assert(cars[0].get_model() == "Model X");
    assert(cars[0].get_registrationYear() == 2021);
    assert(cars[0].get_mileage() == 5000);
    assert(cars[0].get_dailyPrice() == 250);
    assert(cars[0].get_color() == "Blue");
    assert(cars[0].get_remark() == "Updated Remark");

}

void CarTests::testActivateDeactivateCar() {
    CarService *carService;
    CarController controller(carService);

    controller.addCar(false, "SM45ALE", "Model S", "Tesla", 2020, 10000, 200, "Electric", "Automatic", "Red", "Remark");
    auto cars = carService->getAllCars();
    assert(cars[0].get_active() == false);

    int car_id = cars[0].get_id();
    controller.activate(car_id);
    assert(cars[0].get_active() == true);

    controller.deactivate(car_id);
    assert(cars[0].get_active() == false);
}

void CarTests::testListAllCars() {
    CarService *carService;
    CarController controller(carService);

    controller.addCar(true, "SM45ALE", "Model S", "Tesla", 2020, 10000, 200, "Electric", "Automatic", "Red", "Remark");
    controller.addCar(true, "SM46ALE", "Model X", "Tesla", 2021, 5000, 250, "Electric", "Automatic", "Blue", "Remark 2");

    auto activeCars = controller.listallCars();
    assert(activeCars.size() == 2);
    assert(activeCars[0].get_dailyPrice() == 200);
    assert(activeCars[1].get_dailyPrice() == 250);
}

void CarTests::testFindCarByLicensePlate() {
    CarService *carService;
    CarController controller(carService);

    controller.addCar(true, "SM45ALE", "Model S", "Tesla", 2020, 10000, 200, "Electric", "Automatic", "Red", "Remark");
    controller.addCar(true, "SM46ALE", "Model X", "Tesla", 2021, 5000, 250, "Electric", "Automatic", "Blue", "Remark 2");

    Car car = controller.findCarByLicensePlate("SM45ALE");
    assert(car.get_model() == "Model S");

    car = controller.findCarByLicensePlate("SM46ALE");
    assert(car.get_model() == "Model X");
}

void CarTests::testAllFunctions() {
    testCreate();
    testAddCar();
    testDeleteCar();
    testUpdateCar();
    testActivateDeactivateCar();
    testListAllCars();
    testFindCarByLicensePlate();

}
