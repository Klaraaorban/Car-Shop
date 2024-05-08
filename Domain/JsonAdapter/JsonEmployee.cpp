//
// Created by andreiasnico 
//

#include "JsonEmployee.h"


json JsonEmployee::ModelToJson(Employee employee) {
    json j;
    j["lastName"] = employee.getLastName();
    j["firstName"] = employee.getFirstName();
    j["email"] = employee.getEmail();
    j["position"] = employee.getPosition();
    j["birthDate"] = employee.getBirthDate();
    j["abreviation"] = employee.getAbbreviation();
    return j;
}
