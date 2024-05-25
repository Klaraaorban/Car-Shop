#include <iostream>
#include "UI/UI.h"
#include "MainController/Controller.h"


int main() {
    Controller *ctrl = nullptr;
    UI ui(ctrl);
    ui.run();
    cout<<"aici";
    return 0;

}
