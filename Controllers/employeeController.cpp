
#include "employeeController.h"

EmployeeController::EmployeeController(EmployeeService &service) : employeeService(service) {}

void EmployeeController::addEmployee(int id, const std::string &password, const std::string &lastName, const std::string &firstName,
                                     const std::string &email, const std::string &position, const std::string &birthDate, int salary) {
    Employee employee(id, password, lastName, firstName, email, position, birthDate, salary);
    employeeService.addEmployee(employee);
}

Employee EmployeeController::getEmployeeByEmail(const std::string& email) const {
    return employeeService.getEmployeeByEmail(email);
}

Employee EmployeeController::getEmployeeById(int id) const {
    return employeeService.getEmployeeById(id);
}

void EmployeeController::updateEmployee(int id, const std::string& password, const std::string& lastName, const std::string& firstName,
                                        const std::string& position, const std::string& birthDate, int salary, const std::string& abbreviation) {
    Employee updatedEmployee(id, password, lastName, firstName, "", position, birthDate, salary);
    employeeService.updateEmployee(id, updatedEmployee);
}

void EmployeeController::deleteEmployee(int id) {
    employeeService.deleteEmployee(id);
}

std::vector<Employee> EmployeeController::getAllEmployees() const {
    return employeeService.getAllEmployees();
}