#ifndef EMPLOYEE_CONTROLLER_H
#define EMPLOYEE_CONTROLLER_H
#pragma once
#include "../Services/employeeService.h"
#include <string>
class EmployeeController {
public:
    EmployeeController(EmployeeService *employeeService);

    void addEmployee(int id, const std::string &password, const std::string &lastName, const std::string &firstName,
                     const std::string &email, const std::string &position, const std::string &birthDate, int salary);

    Employee getEmployeeByEmail(const std::string& email) const;

    Employee getEmployeeById(int id) const;

    void updateEmployee(int id, const std::string& password, const std::string& lastName, const std::string& firstName,
                        const std::string& position, const std::string& birthDate, int salary, const std::string& abbreviation);

    void deleteEmployee(int id);

    std::vector<Employee> getAllEmployees() const;
private:
    EmployeeService *employeeService;
};


#endif // EMPLOYEE_CONTROLLER_H