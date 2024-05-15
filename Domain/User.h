//
// Created by andreiasnico 
//
#pragma once
#include "iostream"
#ifndef CARSHOP_USER_H
#define CARSHOP_USER_H


class User {

private:

    int id;
    std::string email;
    std::size_t password;
public:
    User(const std::string &email, const std::string &password);
    const virtual std::string &getEmail() const;

    void  virtual setEmail(const std::string &email);

    size_t virtual getPassword() const;

    void virtual setPassword(size_t password);

    virtual ~User();

};


#endif //CARSHOP_USER_H
