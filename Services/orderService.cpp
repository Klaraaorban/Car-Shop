//
// Created by User on 5/17/2024.
//

#include "orderService.h"
#include "../json/single_include/nlohmann/json.hpp"
#include <algorithm>
using json = nlohmann::json;
using namespace std;
orderService::orderService(string dbOrderFilePath,string dbCarFilePath,string dbCustomerFilePath,string dbEmployeeFilePath):dbOrderFilePath(dbOrderFilePath), dbCarFilePath(dbCarFilePath),dbCustomerFilePath(dbCustomerFilePath),dbEmployeeFilePath(dbEmployeeFilePath) {
    loadFromJson(dbCarFilePath,dbCustomerFilePath,dbEmployeeFilePath);
}

void orderService::loadFromJson(string &path_car,string &path_customer,string &path_employee) {
    ifstream inFile(dbOrderFilePath);
    if (inFile.is_open()) {
        json j;
        inFile >> j;
        customerService customerService(path_customer);
        customerController custController(&customerService);
        CarService carService(path_car);
        CarController carController(&carService);
        EmployeeService employeeService(path_employee);
        EmployeeController employeeController(&employeeService);
        for (const auto &item : j) {


            Order ord(item["_id_Order"], item["_date_Order"], item["_status_Order"], item["_begin_Order"],
                         item["_end_Order"], stof(item["_bill_Order"].dump()), item["_observations_Order"],
                         carController.returnCarbyID(item["_car_Order"]), custController.FindCustomerByID(item["_customer_Order"]),
                         employeeController.getEmployeeById(item["_worker_Order"]));
            orders.push_back(ord);

        }
        inFile.close();

    }
}

/*
 * int _id_Order;
    string _date_Order;
    string _status_Order;
    string _begin_Order;
    string _end_Order;
    float _bill_Order;
    string _observations_Order;

    // TO DO, 3 objects
    // obiect de tip Auto
    Car _car_Order;
    // obiect de tip Kunde
    customer _customer_Order;
    // obiect de tip Arbeiter
    Employee _worker_Order;
 * */

void orderService::saveToJson() const {
    json j;
    for (Order order : orders) {
        j.push_back({
                            {"_id_Order", order.getIdOrder()},
                            {"_date_Order", order.getDateOrder()},
                            {"_status_Order", order.getStatusOrder()},
                            {"_begin_Order", order.getBeginOrder()},
                            {"_end_Order", order.getEndOrder()},
                            {"_bill_Order", order.getBillOrder()},
                            {"_observations_Order", order.getObservationsOrder()},
                            {"_car_Order", order.getCarOrder().get_id()},
                            {"_customer_Order", order.getCustomerOrder().getCustomerID()},
                            {"_worker_Order", order.getWorkerOrder().getId()}
                    });
    }
    ofstream outFile(dbOrderFilePath);
    if (outFile.is_open()) {
        outFile << j.dump(4);
        outFile.close();
    }
}

int orderService::createId() {
    return orders.size();
}

void orderService::addOrder(Order &order) {
    orders.push_back(order);
    saveToJson();
}
void orderService::deleteOrder(int &order_id) {
    for (auto it = orders.begin(); it != orders.end(); ++it) {
        if (it->getIdOrder() == order_id) {
            orders.erase(it);
            saveToJson();
            return;
        }
    }
    throw runtime_error("Order not found");
}

void orderService::updateOrder(int &order_id, Order &updatedOrder) {
    for (auto &ord : orders) {
        if (ord.getIdOrder() == order_id) {
            ord = updatedOrder;
            saveToJson();
            return;
        }
    }
    throw runtime_error("Order not found");
}

Order orderService::getOrderById(int &order_id) {
    for(auto &ord: orders){
        if(order_id == ord.getIdOrder()){
            return ord;
        }
    }
    throw runtime_error("Order not found");
}

vector<Order> orderService::getAllOrders(){
    return orders;
}

void orderService::takeOverOrder(int order_id,  Employee &newWorker) {
    for (auto &order : orders) {
        if (order.getIdOrder() == order_id) {
            order.setWorkerOrder(newWorker);
            saveToJson();
            return;
        }
    }
    throw std::runtime_error("Order not found");
}

void orderService::assignOrder(int order_id,Employee &newWorker) {
    for (auto &order : orders) {
        if (order.getIdOrder() == order_id) {
            order.setWorkerOrder(newWorker);
            saveToJson();
            return;
        }
    }
    throw std::runtime_error("Order not found");
}

std::vector<Order> orderService::getOrdersByDate( std::string &startDate,  std::string &endDate)  {
    std::vector<Order> filteredOrders;
    for ( auto &order : orders) {
        if (order.getDateOrder() >= startDate && order.getDateOrder() <= endDate) {
            filteredOrders.push_back(order);
        }
    }
    std::sort(filteredOrders.begin(), filteredOrders.end(), []( Order &a,Order &b) {
        return a.getBillOrder() < b.getBillOrder();
    });
    return filteredOrders;
}
float orderService::getTotalSumOfADate(string &date)  {
    float totalSum = 0;
    for (auto &order : orders) {
        if (order.getDateOrder()==date) {
            totalSum += order.getBillOrder();
        }
    }
    return totalSum;
}

bool orderService::isReservation(int order_id){
    for (auto &order : orders) {
        if (order.getIdOrder() == order_id && order.getStatusOrder() == "Reservation") {
            return true;
        }
    }
    return false;
}