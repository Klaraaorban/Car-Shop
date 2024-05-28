
//
// Created by User on 5/17/2024.
//
#include "../Domain/OrderDomain/Order.h"
#include "../Controllers/customerController.h"
#include "../Controllers/carController.h"
#include "../Controllers/employeeController.h"
#include <vector>
#include <string>
#include <fstream>
#ifndef CARSHOP_ORDERSERVICE_H
#define CARSHOP_ORDERSERVICE_H
using namespace std;

class orderService {
public:
//    void addOrder();
//    void getOrderById();
//    void updateOrder();
//    void deleteOrder();
//    void listAllOrders();
private:
    vector<Order> orders;
    string dbOrderFilePath;
    string dbCarFilePath;
    string dbCustomerFilePath;
    string dbEmployeeFilePath;

    void loadFromJson(string &path_car,string &path_customer,string &path_employee);
    void saveToJson() const;

public:
    orderService( string dbOrderFilePath,string dbCarFilePath,  string dbCustomerFilePath, string dbEmployeeFilePath);
    void addOrder(Order &order);
    int createId();
    void updateOrder(int &order_id, Order &updatedOrder);
    Order getOrderById(int &order_id);
    void deleteOrder(int &order_id);
    vector<Order> getAllOrders();
    void takeOverOrder(int order_id, Employee &newWorker);
    void assignOrder(int order_id,  Employee &newWorker);
    std::vector<Order> getOrdersByDate( std::string &startDate,  std::string &endDate) ;
    float getTotalSumOfADate(string &date);
    bool isReservation(int order_id);

    };


#endif //CARSHOP_ORDERSERVICE_H
