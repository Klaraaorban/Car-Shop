//
// Created by User on 5/17/2024.
//

#include "orderService.h"
void orderService::loadFromJson() {
    ifstream inFile(dbFilePath);
    if (inFile.is_open()) {
        json j;
        inFile >> j;
        inFile.close();
    }
}

void orderService::saveToJson() const {
    json j;
    ofstream outFile(dbFilePath);
    if (outFile.is_open()) {
        outFile << j.dump(4);
        outFile.close();
    }
}