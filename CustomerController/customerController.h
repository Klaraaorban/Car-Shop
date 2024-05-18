//
// Created by nagyb on 5/18/2024.
//

#ifndef CARSHOP_CUSTOMERCONTROLLER_H
#define CARSHOP_CUSTOMERCONTROLLER_H

#include "../CustomerService/customer_service.h"

class customerController {
private:
    bool IsEmailUnique;
    bool IsEmailStructureCorrect();
    bool PhoneNumberFormatCorrect();


public:
    customerController();
    void CustomerAnonymisation();
    void CustomerByAuto();
    void ListCustomersSortedByName();
    void FindCustomerByEmail();
    void FindCustomerByMobilePhone();
    void FindCustomerByName();
    void ChangeCustomerEmailPassword();
    void ChangeCustomerNote();
    void SeeFavotites();
    void AddToFavorite();

};


#endif //CARSHOP_CUSTOMERCONTROLLER_H
