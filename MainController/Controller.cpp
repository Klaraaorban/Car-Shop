//
// Created by miruna on 24.05.2024.
//

#include "Controller.h"

Controller::Controller(customerController *custController, CarController *carController, EmployeeController *emplController, orderController *ordController) :
        custController(custController), carController(carController), emplController(emplController), ordController(ordController)
{

}

void Controller::addCar(bool active, string licensePlate, string model, string brand, int registrationYear, int mileage, int dailyPrice, string fuelType, string gearbox, string color, string remark) {
    carController->addCar(active, licensePlate, model, brand, registrationYear, mileage, dailyPrice, fuelType, gearbox, color, remark);
}

void Controller::updateCar(int car_id, bool active, string licensePlate, string model, string brand, int registrationYear, int mileage, int dailyPrice, string fuelType, string gearbox, string color, string remark) {
    carController->updateCar(car_id, active, licensePlate, model, brand, registrationYear, mileage, dailyPrice, fuelType, gearbox, color, remark);

}

void Controller::deleteCar(int car_id) {
    carController->deleteCar(car_id);
}

void Controller::activate(int car_id) {
    carController->activate(car_id);
}

void Controller::deactivate(int car_id) {
    carController->deactivate(car_id);
}

vector<Car> Controller::notOrderedCars(string from, string to) {
    vector<Car> ordered, notOrdered;
    bool ok = true;
    for(auto &ord :ordController->getOrdersByDate(from, to)) {
        ordered.push_back(ord.getCarOrder());
    }
    for(auto &car: carController->listallCars()){
        ok = true;
        for(auto &orderdCar: ordered)
            if(car == orderdCar)
                ok = false;
        if(ok) notOrdered.push_back(car);
    }
    sort(notOrdered.begin(), notOrdered.end(), [](Car a, Car b) {return a < b;});
    return notOrdered;
}

Car Controller::findCarByLicensePlate(string licensePlate) {
    return carController->findCarByLicensePlate(licensePlate);
}

vector<Car> Controller::orderedCars(int custID) {
    vector<Car> ordered;
    vector<Order> allOrders = ordController->listAllOrders();
    sort(allOrders.begin(), allOrders.end(), [](Order a, Order b) {return a < b;});
    for(auto &ord: allOrders) {
        if(ord.getCustomerOrder().getCustomerID() == custID)
            ordered.push_back(ord.getCarOrder());
    }
    return ordered;
}

bool Controller::validateLicensePlate(string licensePlate) {
    return carController->validateLicensePlate(licensePlate);
}

bool Controller::validateRegistrationYear(int registrationYear) {
    return carController->validateRegistrationYear(registrationYear);
}

bool Controller::validateMileage(int mileage) {
    return carController->validateMileage(mileage);
}

bool Controller::validateDailyPrice(int dailyPrice) {
    return carController->validateDailyPrice(dailyPrice);
}

bool Controller::validateID(int id) {
    return carController->validateID(id);
}

string Controller::modifyLicensePlate(string licensePlate) {
    return carController->modifyLicensePlate(licensePlate);
}

customer Controller::findCustomerByEmailandPassword(string email, string password) {
    E_mail mail;
    mail.mailAddress = email;
    mail.mailPassword = password;
    return custController->FindCustomerByEmail(mail);
}

void Controller::changePassword(customer cus, string newPassword) {
    E_mail newMail;
    newMail.mailAddress = cus.getCustomerMail().mailAddress;
    newMail.mailPassword = newPassword;
    custController->ChangeCustomer(cus.getCustomerMail().mailAddress, "password", newMail, cus.getCustomerName(),
                cus.getCustomerAddress(), cus.getCustomerPhoneNr(), cus.getCustomerNote(), cus.isGdprDeleted(), cus.getFavorites());
}

void Controller::changeNote(customer cus, string newNote) {
    custController->ChangeCustomer(cus.getCustomerMail().mailAddress, "note", cus.getCustomerMail(), cus.getCustomerName(),
                cus.getCustomerAddress(), cus.getCustomerPhoneNr(), newNote, cus.isGdprDeleted(), cus.getFavorites());
}

void Controller::changeFavorite(customer cus, Car newCar) {
    custController->AddToFavorite(cus.getCustomerMail(), newCar);
}

vector<Car> Controller::getFavoritesList(customer cus) {
    vector<int> carIDs = custController->SeeFavorites(cus.getCustomerMail());
    vector<Car> cars;
    for (int i = 0; i < carIDs.size(); i++) {
        cars.push_back(carController->returnCarbyID(carIDs[i]));
    }
    return cars;
}

void Controller::createCustomer(CustomerName name, E_mail mail, Address address, string phoneNr, string note, bool GdprDeleted,
                                vector<int> favorites) {
custController->customerAdd(name, mail, address, phoneNr, note, GdprDeleted, favorites);
}