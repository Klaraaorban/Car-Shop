#include <iostream>
#include "EmployeeController.h"

EmployeeController::EmployeeController(EmployeeService &service) : employeeService(service) {}

void EmployeeController::addEmployee() {
    std::string password, lastName, firstName, email, position, birthDate, abbreviation, remarks;
    int salary;

    std::cout << "Enter password: ";
    std::cin >> password;
    std::cout << "Enter last name: ";
    std::cin >> lastName;
    std::cout << "Enter first name: ";
    std::cin >> firstName;
    std::cout << "Enter email: ";
    std::cin >> email;
    std::cout << "Enter position: ";
    std::cin >> position;
    std::cout << "Enter birth date: ";
    std::cin >> birthDate;
    std::cout << "Enter abbreviation: ";
    std::cin >> abbreviation;
    std::cout << "Enter salary: ";
    std::cin >> salary;
    std::cout << "Enter remarks: ";
    std::cin >> remarks;

    Employee employee(password, lastName, firstName, email, position, birthDate, abbreviation, salary, remarks);
    employeeService.addEmployee(employee);
    std::cout << "Employee added successfully.\n";
}

void EmployeeController::getEmployeeByEmail() {
    std::string email;
    std::cout << "Enter email: ";
    std::cin >> email;

    try {
        Employee employee = employeeService.getEmployeeByEmail(email);
        std::cout << "Last Name: " << employee.getLastName() << "\n";
        std::cout << "First Name: " << employee.getFirstName() << "\n";
        std::cout << "Email: " << employee.getEmail() << "\n";
        std::cout << "Position: " << employee.getPosition() << "\n";
        std::cout << "Birth Date: " << employee.getBirthDate() << "\n";
        std::cout << "Abbreviation: " << employee.getAbbreviation() << "\n";
        std::cout << "Salary: " << employee.getSalary() << "\n";
        std::cout << "Remarks: " << employee.getRemarks() << "\n";
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
}

void EmployeeController::updateEmployee() {
    std::string email;
    std::cout << "Enter email of the employee to update: ";
    std::cin >> email;

    std::string password, lastName, firstName, position, birthDate, abbreviation, remarks;
    int salary;

    std::cout << "Enter new password: ";
    std::cin >> password;
    std::cout << "Enter new last name: ";
    std::cin >> lastName;
    std::cout << "Enter new first name: ";
    std::cin >> firstName;
    std::cout << "Enter new position: ";
    std::cin >> position;
    std::cout << "Enter new birth date: ";
    std::cin >> birthDate;
    std::cout << "Enter new abbreviation: ";
    std::cin >> abbreviation;
    std::cout << "Enter new salary: ";
    std::cin >> salary;
    std::cout << "Enter new remarks: ";
    std::cin >> remarks;

    Employee updatedEmployee(password, lastName, firstName, email, position, birthDate, abbreviation, salary, remarks);
    try {
        employeeService.updateEmployee(email, updatedEmployee);
        std::cout << "Employee updated successfully.\n";
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
}

void EmployeeController::deleteEmployee() {
    std::string email;
    std::cout << "Enter email of the employee to delete: ";
    std::cin >> email;

    try {
        employeeService.deleteEmployee(email);
        std::cout << "Employee deleted successfully.\n";
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
}

void EmployeeController::listAllEmployees() {
    auto employees = employeeService.getAllEmployees();
    for (const auto &employee : employees) {
        std::cout << "Last Name: " << employee.getLastName() << "\n";
        std::cout << "First Name: " << employee.getFirstName() << "\n";
        std::cout << "Email: " << employee.getEmail() << "\n";
        std::cout << "Position: " << employee.getPosition() << "\n";
        std::cout << "Birth Date: " << employee.getBirthDate() << "\n";
        std::cout << "Abbreviation: " << employee.getAbbreviation() << "\n";
        std::cout << "Salary: " << employee.getSalary() << "\n";
        std::cout << "Remarks: " << employee.getRemarks() << "\n";
        std::cout << "------------------------\n";
    }
}
