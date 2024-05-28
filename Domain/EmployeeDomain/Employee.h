#ifndef CARSHARING_EMPLOYEE_H
#define CARSHARING_EMPLOYEE_H
#pragma once
#include <string>
#include "../User.h"

class Employee : public User {
public:
    Employee(int id, const std::string &password, const std::string &lastName, const std::string &firstName,
             const std::string &email, const std::string &position, const std::string &birthDate, int salary);


    std::string getLastName() const;
    std::string getFirstName() const;
    std::string getAbbreviation() const;
    std::string getBirthDate() const;
    std::string getPosition() const;
    std::string getRemarks() const;
    std::size_t getPassword() const override;
    int getSalary() const;

    void setSalary(int salary);
    void setRemarks(const std::string &remarks);

    int getId() const;

private:
    int id;
    std::string lastName;
    std::string firstName;
    std::string position;
    std::string birthDate;
    std::string abbreviation;
    std::string remarks;
    int salary;
};

#endif //CARSHARING_EMPLOYEE_H