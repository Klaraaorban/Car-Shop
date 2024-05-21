#ifndef EMPLOYEE_CONTROLLER_H
#define EMPLOYEE_CONTROLLER_H
#pragma once

#include "../EmployeeService/employeeService.h"

class EmployeeController {
private:
    EmployeeService &employeeService;

public:
    EmployeeController(EmployeeService &service);

    void addEmployee();
    void getEmployeeByEmail();
    void updateEmployee();
    void deleteEmployee();
    void listAllEmployees();
};

#endif // EMPLOYEE_CONTROLLER_H

