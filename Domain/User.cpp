//
// Created by andreiasnico 
//

#include "User.h"
#include <iostream>


User::User(const std::string &email, const std::string &password) {
    this->email = email;
    static std::hash<std::string> hasher;
    this->password = hasher(password);
}

const std::string &User::getEmail() const {
    return email;
}

void User::setEmail(const std::string &email) {
    User::email = email;
}

size_t User::getPassword() const {
    return password;
}

void User::setPassword(size_t password) {
    User::password = password;
}

User::~User() {

}



