#ifndef EMPLOYEE_SERVICE_H
#define EMPLOYEE_SERVICE_H
#pragma once

#include <vector>
#include <string>
#include <fstream>
#include "../Domain/Employee.h"
#include "../json/json.hpp"

using json = nlohmann::json;
using namespace std;

class EmployeeService {
private:
    vector<Employee> employees;
    string dbFilePath;

    void loadFromJson();
    void saveToJson() const;

public:
    EmployeeService(const string &dbFilePath);
    void addEmployee(const Employee &employee);
    Employee getEmployeeByEmail(const string &email) const;
    void updateEmployee(const string &email, const Employee &updatedEmployee);
    void deleteEmployee(const string &email);
    vector<Employee> getAllEmployees() const;
};

#endif // EMPLOYEE_SERVICE_H
