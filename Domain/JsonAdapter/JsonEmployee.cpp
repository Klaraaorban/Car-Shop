//
// Created by andreiasnico 
//

#include "JsonEmployee.h"


json JsonEmployee::ModelToJson(Employee employee) {
    json j;
    j["id"] = employee.getId();
    j["password"] = employee.getPassword();
    j["nickname"] = employee.getNickname();
    j["lastName"] = employee.getLastName();
    j["firstName"] = employee.getFirstName();
    j["email"] = employee.getEmail();
    j["position"] = employee.getPosition();
    j["birthDate"] = employee.getBirthDate();
    j["salary"] = employee.getSalary();
    j["remarks"] = employee.getRemarks();

//    j["abreviation"] = employee.getAbbreviation();
    return j;
}
