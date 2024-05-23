//
// Created by nagyb on 5/23/2024.
//

#ifndef CARSHOP_MAIN_UI_H
#define CARSHOP_MAIN_UI_H

#include <string>

class main_ui {
private:



public:
    void greeting();
    int whoIsUsing(); // return a number 1 - Customer | 2 - Employee
    std::string customerAutentification();  //add the password of the customer to proceed

};


#endif //CARSHOP_MAIN_UI_H
