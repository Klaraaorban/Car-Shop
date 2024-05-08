#include <iostream>
#include "json/single_include/nlohmann/json.hpp"
#include "Domain/Employee.h"
#include "Domain/JsonAdapter/JsonAdapter.h"

using json = nlohmann::json;

int main() {
    Employee e = Employee("1111","asfasfsa","111","1111","asfasfsa","1111","111",1111,"asfasfsa");
    JsonAdapter<Employee>::writeToJson(e);

    std::cout << "Hello, World!" << std::endl;

    return 0;

}
