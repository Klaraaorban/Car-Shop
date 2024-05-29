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

vector<Car> Controller::listallCars() {
    vector<Car> cars = carController->listallCars();
    return cars;
}

Car Controller::returnCarbyID(int car_id) {
    Car car = carController->returnCarbyID(car_id);
    return car;
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

Employee Controller::findEmployeeByEmailandPassword(std::string email, std::string password) {
    return emplController->getEmployeeByEmail(email);
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

std::vector<customer> Controller::getAllCustomer()  {
    return custController->getAllCustomer();
}

customer Controller::getCustomerByID(int id) {
    custController->ReturnCustomerByID(id);
}

void Controller::createCustomer(CustomerName name, E_mail mail, Address address, string phoneNr, string note, bool GdprDeleted,
                                vector<int> favorites) {
custController->customerAdd(name, mail, address, phoneNr, note, GdprDeleted, favorites);
}

customer Controller::FindCustomerByPhoneNr(const string &PhoneNr) {
    return custController->FindCustomerByPhoneNr(PhoneNr);
}

void Controller::customerDelete(std::string email) {
    E_mail mail;
    mail.mailAddress = email;
    customerDelete(email);
}


std::vector<customer> Controller::ListAllCostumersSortedByName(std::string option) {
    return std::vector<customer>();
}

customer Controller::FindCustomerByName(CustomerName name) {
    return custController->FindCustomerByName(name);
}
void Controller::ChangeCustomer(std::string old_email, std::string option, E_mail mail, CustomerName name, Address address,
                                std::string phoneNr, std::string note, bool GdprDeleted, std::vector<int> favorites) {
//    custController->ChangeCustomer(std::string old_email, std::string option, E_mail mail, CustomerName name, Address address,
//            std::string phoneNr, std::string note, bool GdprDeleted, std::vector<int> favorites);
}


void Controller::addEmployee(int id, const std::string& password,const std::string& nickname, const std::string& lastName, const std::string& firstName, const std::string& email,
                             const std::string& position, const std::string& birthDate, int salary, const std::string& remarks) {
    emplController->addEmployee(id, password, nickname, lastName, firstName, email, position, birthDate, salary, remarks);
}

Employee Controller::getEmployeeByEmail(const std::string& email) const {
    return emplController->getEmployeeByEmail(email);
}

Employee Controller::getEmployeeById(int id) const {
    return emplController->getEmployeeById(id);
}

void Controller::updateEmployee(int id, const std::string& password,const std::string& nickname, const std::string& lastName, const std::string& firstName,
                                const std::string& position, const std::string& birthDate, int salary, const std::string& remarks) {
    emplController->updateEmployee(id, password, nickname, lastName, firstName, position, birthDate, salary, remarks);
}

void Controller::deleteEmployee(int id) {
    emplController->deleteEmployee(id);
}

std::vector<Employee> Controller::getAllEmployees() const {
    return emplController->getAllEmployees();
}

Employee Controller::authenticateEmployee(const std::string& email, const std::string& password) {
    return emplController->authenticateEmployee(email, password);
}

std::vector<Employee> Controller::getEmployeesByName(const std::string &name) const {
    return emplController->getEmployeesByName(name);
}

std::vector<Employee> Controller::getEmployeesByBirthdate(const std::string &birthdate) const {
    return emplController->getEmployeesByBirthdate(birthdate);
}

void Controller::changeRemarks(int id, const std::string &remarks) {
    emplController->changeRemarks(id, remarks);
}

Employee Controller::getEmployeeByNickname(const std::string &nickanme) const{
    return emplController->getEmployeeByNickname(nickanme);
}
void Controller::addOrder(string &dateOrder,  string &statusOrder,  string &beginOrder,
                          string &endOrder, float billOrder, string &observationsOrder, Car &carOrder,
                          customer &customerOrder, Employee &workerOrder){
    ordController->addOrder(dateOrder,statusOrder,beginOrder,endOrder,billOrder,observationsOrder,carOrder,customerOrder,workerOrder);
}

Order Controller::getOrderById(int idOrder) {
    return ordController->getOrderById(idOrder);
}

void Controller::updateOrder(int orderId, Order &updatedOrder) {
    ordController->updateOrder(orderId,updatedOrder);
}

void Controller::deleteOrder(int orderId) {
    ordController->deleteOrder(orderId);
}

std::vector<Order> Controller::listAllOrders() {
    auto orders = ordController->listAllOrders();
    return orders;
}

bool Controller::ID_is_valid(int id) {
    return ordController->ID_is_valid(id);
}

void Controller::takeOverOrder(int orderId, Employee &newWorker) {
    ordController->takeOverOrder(orderId,newWorker);
}

void Controller::assignOrder(int orderId, Employee &newWorker) {
    ordController->assignOrder(orderId,newWorker);
}

std::vector<Order> Controller::getOrdersByDate(string &startDate, string &endDate) {
    return ordController->getOrdersByDate(startDate,endDate);
}

float Controller::getTotalSumOfADate(string &date) {
    return ordController->getTotalSumOfADate(date);
}

void Controller::completeOrder(int orderId) {
    ordController->completeOrder(orderId);
}

void Controller::deleteReservation(int reservationId, int userId, string &userRole) {
    ordController->deleteReservation(reservationId,userId,userRole);
}

void Controller::updateReservation(int reservationId, int userId, string &userRole, Order &updatedReservation) {
    ordController->updateReservation(reservationId,userId,userRole,updatedReservation);
}

void Controller::convertReservationToOrder(int reservationId) {
    ordController->convertReservationToOrder(reservationId);
}