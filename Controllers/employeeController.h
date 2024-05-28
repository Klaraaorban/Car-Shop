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

    Employee authenticateEmployee(const std::string& email, const std::string& password) const;

    void updateEmployee(int id, const std::string& password, const std::string& lastName, const std::string& firstName,
                        const std::string& position, const std::string& birthDate, int salary, const std::string& abbreviation);

    void deleteEmployee(int id);

    std::vector<Employee> getAllEmployees() const;

    std::vector<Employee> getEmployeesByName(const std::string &name) const;

    std::vector<Employee> getEmployeesByBirthdate(const std::string &birthdate) const;

    void changeRemarks(int id, const std::string &remarks);
private:
    EmployeeService *employeeService;
};


#endif // EMPLOYEE_CONTROLLER_H