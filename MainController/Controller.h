
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
    customerController *custController = nullptr;
    CarController *carController = nullptr;
    EmployeeController *emplController = nullptr;
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

    void changePassword(customer logedCust, string newPassword);
    void changeNote(customer logedCust, string newNote);
    void changeFavorite(customer logedCust, Car newCar);
    vector<Car> getFavoritesList(customer logedCust);
    void createCustomer(CustomerName name, E_mail mail, Address address, string phoneNr, string note, bool GdprDeleted,
                            vector<int> favorites);
    void addOrder(string &dateOrder,  string &statusOrder,  string &beginOrder,
                              string &endOrder, float billOrder, string &observationsOrder, Car &carOrder,
                              customer &customerOrder, Employee &workerOrder);
    Order getOrderById(int idOrder);
    void updateOrder(int orderId,Order &updatedOrder);
    void deleteOrder(int orderId);
    std::vector<Order> listAllOrders();
    bool ID_is_valid(int id);
    void takeOverOrder(int orderId, Employee &newWorker);
    void assignOrder(int orderId, Employee &newWorker);
    std::vector<Order> getOrdersByDate( std::string &startDate,  std::string &endDate);
    float getTotalSumOfADate(string &date);
    void completeOrder(int orderId);
    void convertReservationToOrder(int reservationId);
    void deleteReservation(int reservationId,  int userId, std::string& userRole);
    void updateReservation(int reservationId, int userId,  std::string &userRole,  Order &updatedReservation);

};

#endif //CARSHOP_CONTROLLER_H
