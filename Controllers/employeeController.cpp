
#include "employeeController.h"

EmployeeController::EmployeeController(EmployeeService *employeeService) : employeeService(employeeService) {}

void EmployeeController::addEmployee(int id, const std::string &password, const std::string &lastName, const std::string &firstName,
                                     const std::string &email, const std::string &position, const std::string &birthDate, int salary) {
    Employee employee(id, password, lastName, firstName, email, position, birthDate, salary);
    employeeService->addEmployee(employee);
}

Employee EmployeeController::getEmployeeByEmail(const std::string& email) const {
    return employeeService->getEmployeeByEmail(email);
}

Employee EmployeeController::getEmployeeById(int id) const {
    return employeeService->getEmployeeById(id);
}

void EmployeeController::updateEmployee(int id, const std::string& password, const std::string& lastName, const std::string& firstName,
                                        const std::string& position, const std::string& birthDate, int salary, const std::string& abbreviation) {
    Employee updatedEmployee(id, password, lastName, firstName, "", position, birthDate, salary);
    employeeService->updateEmployee(id, updatedEmployee);
}

void EmployeeController::deleteEmployee(int id) {
    employeeService->deleteEmployee(id);
}

std::vector<Employee> EmployeeController::getAllEmployees() const {
    return employeeService->getAllEmployees();
}

Employee EmployeeController::authenticateEmployee(const std::string& email, const std::string& password) const {
    return employeeService->authenticateEmployee(email, password);
}

std::vector<Employee> EmployeeController::getEmployeesByName(const std::string &name) const {
    return employeeService->getEmployeesByName(name);
}

std::vector<Employee> EmployeeController::getEmployeesByBirthdate(const std::string &birthdate) const {
    return employeeService->getEmployeesByBirthdate(birthdate);
}

void EmployeeController::changeRemarks(int id, const std::string &remarks) {
    employeeService->changeRemarks(id, remarks);
}