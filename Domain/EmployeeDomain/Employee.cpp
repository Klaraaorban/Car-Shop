#include "../EmployeeDomain/Employee.h"

Employee::Employee(int id, const std::string &password, const std::string nickname, const std::string &lastName, const std::string &firstName,
                   const std::string &email, const std::string &position, const std::string &birthDate, int salary, const std::string remarks): User(email, password), id(id), nickname(nickname), lastName(lastName), firstName(firstName), position(position),
                                                                                                                     birthDate(birthDate), salary(salary),remarks(remarks) {}

std::string Employee::getLastName() const {
    return lastName;
}

std::string Employee::getFirstName() const {
    return firstName;
}

std::string Employee::getNickname() const {
    return nickname;
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

std::size_t Employee::getPassword() const {
    return User::getPassword();


}

std::string Employee::getRemarks() const {
    return remarks;
}

void Employee::setRemarks(const std::string &remarks) {
    this->remarks = remarks;
}
