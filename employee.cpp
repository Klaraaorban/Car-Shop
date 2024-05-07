#include "employee.h"
using namespace std;
Employee::Employee(string lastName, string firstName, string email, string position,
                   string birthDate, string abbreviation, int salary, string remarks)
        : lastName(lastName), firstName(firstName), email(email), position(position),
          birthDate(birthDate), abbreviation(abbreviation), salary(salary), remarks(remarks) {}


string Employee::getLastName() const {
    return lastName;
}

string Employee::getFirstName() const {
    return firstName;
}

string Employee::getAbbreviation() const {
    return abbreviation;
}

string Employee::getBirthDate() const {
    return birthDate;
}

string Employee::getPosition() const {
    return position ;
}

string Employee::getEmail() const {
    return email;
}

int Employee::getSalary() const {
    return salary;
}

string Employee::getRemarks() const {
    return remarks;
}

void Employee::setSalary(int salary) {
    this->salary = salary;
}

void Employee::setRemarks(string remarks) {
    this->remarks = remarks;
}