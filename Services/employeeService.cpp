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
        inFile.close();
        for (const auto item : j) {
            Employee emp(item["id"], item["password"],item["nickname"], item["lastName"], item["firstName"], item["email"],
                         item["position"], item["birthDate"], item["salary"], item["remarks"]);
            employees.push_back(emp);

        }

    }
}

void EmployeeService::saveToJson() const {
    json j;
    for (const auto &emp : employees) {
        j.push_back({
                            {"id", emp.getId()},
                            {"password", emp.getPassword()},
                            {"nickname", emp.getNickname()},
                            {"lastName", emp.getLastName()},
                            {"firstName", emp.getFirstName()},
                            {"email", emp.getEmail()},
                            {"position", emp.getPosition()},
                            {"birthDate", emp.getBirthDate()},
                            {"salary", emp.getSalary()},
                            {"remarks",emp.getRemarks()}
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
    std::cout<<id;
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

Employee EmployeeService::authenticateEmployee(const std::string &email, const std::string &password) const {
    static std::hash<std::string> hasher;
    size_t hashedPassword = hasher(password);
    for (const auto &emp : employees) {
        if (emp.getEmail() == email && emp.getPassword() == hashedPassword) {
            return emp;
        }
    }
    throw std::runtime_error("Authentication failed");
}


std::vector<Employee> EmployeeService::getAllEmployees() const {
    return employees;
}


std::vector<Employee> EmployeeService::getEmployeesByName(const std::string &name) const {
    std::vector<Employee> matchingEmployees;
    for (const auto &emp : employees) {
        if (emp.getLastName() == name || emp.getFirstName() == name) {
            matchingEmployees.push_back(emp);
        }
    }
    if (matchingEmployees.empty()) {
        throw std::runtime_error("Employee not found");
    }
    return matchingEmployees;
}

Employee EmployeeService::getEmployeeByNickname(const std::string &nickname) const {
    for (const auto &emp : employees) {
        if (emp.getNickname() == nickname) {
            return emp;
        }
    }
    throw std::runtime_error("Employee not found");
}

std::vector<Employee> EmployeeService::getEmployeesByBirthdate(const std::string &birthdate) const {
    std::vector<Employee> matchingEmployees;
    for (const auto &emp : employees) {
        if (emp.getBirthDate() == birthdate) {
            matchingEmployees.push_back(emp);
        }
    }
    if (matchingEmployees.empty()) {
        throw std::runtime_error("Employee not found");
    }
    return matchingEmployees;
}

void EmployeeService::changeRemarks(const int &id, const std::string &remarks) {
    for (auto &emp : employees) {
        if (emp.getId() == id) {
            emp.setRemarks(remarks);
            saveToJson();
            return;
        }
    }
    throw std::runtime_error("Employee not found");
}