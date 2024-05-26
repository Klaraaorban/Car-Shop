//
// Created by nagyb on 5/23/2024.
//

#ifndef CARSHOP_UI_H
#define CARSHOP_UI_H

#include "../MainController/Controller.h"
#include <string>

class UI {
private:
    Controller *ctrl = nullptr;
    void greeting();
    std::pair<std::string, std::string> autentification();  //add the password of the customer to proceed
    int options();
public:
    UI(Controller *ctrl);
    void run();
};


#endif //CARSHOP_UI_H
