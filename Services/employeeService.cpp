#include "employeeService.h"
#include <fstream>
#include <stdexcept>
#include "../json/single_include/nlohmann/json.hpp"

using json = nlohmann::json;

EmployeeService::EmployeeService(const std::string &dbFilePath) : dbFilePath(dbFilePath) {
    loadFromJson();
}

void EmployeeService::loadFromJson() {
    std::ifstream inFile(dbFilePath);
    if (inFile.is_open()) {
        json j;
        inFile >> j;
        for (const auto &item : j) {
            Employee emp(item["id"], item["password"], item["lastName"], item["firstName"], item["email"],
                         item["position"], item["birthDate"], item["salary"]);
            employees.push_back(emp);
        }
        inFile.close();
    }
}

void EmployeeService::saveToJson() const {
    json j;
    for (const auto &emp : employees) {
        j.push_back({
                            {"id", emp.getId()},
                            {"password", emp.getPassword()},
                            {"lastName", emp.getLastName()},
                            {"firstName", emp.getFirstName()},
                            {"email", emp.getEmail()},
                            {"position", emp.getPosition()},
                            {"birthDate", emp.getBirthDate()},
                            {"salary", emp.getSalary()}
                    });
    }
    std::ofstream outFile(dbFilePath);
    if (outFile.is_open()) {
        outFile << j.dump(4);
        outFile.close();
    }
}

void EmployeeService::addEmployee(const Employee &employee) {
    employees.push_back(employee);
    saveToJson();
}

Employee EmployeeService::getEmployeeByEmail(const std::string &email) const {
    for (const auto &emp : employees) {
        if (emp.getEmail() == email) {
            return emp;
        }
    }
    throw std::runtime_error("Employee not found");
}

Employee EmployeeService::getEmployeeById(const int &id) const {
    for (const auto &emp : employees) {
        if (emp.getId() == id) {
            return emp;
        }
    }
    throw std::runtime_error("Employee not found");
}

void EmployeeService::updateEmployee(const int &id, const Employee &updatedEmployee) {
    for (auto &emp : employees) {
        if (emp.getId() == id) {
            emp = updatedEmployee;
            saveToJson();
            return;
        }
    }
    throw std::runtime_error("Employee not found");
}

void EmployeeService::deleteEmployee(const int &id) {
    for (auto it = employees.begin(); it != employees.end(); ++it) {
        if (it->getId() == id) {
            employees.erase(it);
            saveToJson();
            return;
        }
    }
    throw std::runtime_error("Employee not found");
}

std::vector<Employee> EmployeeService::getAllEmployees() const {
    return employees;
}