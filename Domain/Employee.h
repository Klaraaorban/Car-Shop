#ifndef CARSHARING_EMPLOYEE_H
#define CARSHARING_EMPLOYEE_H
#pragma once

#include <string>
#include <chrono>
#include "User.h"

using namespace std;
class Employee: public  User {
private:
    string lastName;
    string firstName;
    string email;
    string position;
    string birthDate;
    string abbreviation;
    int salary;
    string remarks;

public:
    Employee(const string &password, string lastName, string firstName, string email,
             string position, string birthDate, string abbreviation, int salary, string remarks);
    string getLastName() const;
    string getFirstName() const;
    string getPosition() const;
    string getBirthDate() const;
    string getAbbreviation() const;
    int getSalary() const;
    string getRemarks() const;
    void setSalary(int salary);
    void setRemarks(string remarks);
};

#endif //CARSHARING_EMPLOYEE_H
