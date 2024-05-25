#ifndef EMPLOYEE_SERVICE_H
#define EMPLOYEE_SERVICE_H
#pragma once
#include <vector>
#include <string>
#include "../Domain/EmployeeDomain/Employee.h"

class EmployeeService {
public:
    EmployeeService(const std::string &dbFilePath);

    void addEmployee(const Employee &employee);
    Employee getEmployeeById(const int &id) const;
    void updateEmployee(const int &id, const Employee &updatedEmployee);
    void deleteEmployee(const int &id);
    std::vector<Employee> getAllEmployees() const;
    Employee getEmployeeByEmail(const std::string &email) const;

private:
    std::vector<Employee> employees;
    std::string dbFilePath;

    void loadFromJson();
    void saveToJson() const;
};


#endif // EMPLOYEE_SERVICE_H