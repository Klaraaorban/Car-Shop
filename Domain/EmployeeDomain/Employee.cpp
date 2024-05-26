#include "../EmployeeDomain/Employee.h"

Employee::Employee(int id, const std::string &password, const std::string &lastName, const std::string &firstName,
                   const std::string &email, const std::string &position, const std::string &birthDate, int salary): User(email, password), id(id), lastName(lastName), firstName(firstName), position(position),
                                                                                                                     birthDate(birthDate), salary(salary) {}

std::string Employee::getLastName() const {
    return lastName;
}

std::string Employee::getFirstName() const {
    return firstName;
}

std::string Employee::getAbbreviation() const {
    return abbreviation;
}

std::string Employee::getBirthDate() const {
    return birthDate;
}

std::string Employee::getPosition() const {
    return position;
}

int Employee::getSalary() const {
    return salary;
}

void Employee::setSalary(int salary) {
    this->salary = salary;
}

int Employee::getId() const {
    return id;
}