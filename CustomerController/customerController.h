//
// Created by nagyb on 5/18/2024.
//

#ifndef CARSHOP_CUSTOMERCONTROLLER_H
#define CARSHOP_CUSTOMERCONTROLLER_H

#include "../CustomerService/customer_service.h"

class customerController {
private:
    customer_service &customerService;

    bool IsEmailUnique;
    bool IsEmailStructureCorrect();
    bool PhoneNumberFormatCorrect(std::string PhoneNR);



public:
    explicit customerController(customer_service &customerService);          //finished

    void CustomerAdd(CustomerName customerName,E_mail customerMail,Address costumerAddress,
                     std::string customerPhoneNr,std::string customerNote,bool GdprDeleted); //finished
    void CustomerDelete(E_mail email); //finished
    void ModifyCustomer();

    void CustomerAnonymisation();
    void CustomerByAuto();
    std::vector<customer> ListAllCostumersSortedByFirstName();       // the cout will be in the UI  //finished
    std::vector<customer> ListAllCostumersSortedByLastName();       // the cout will be in the UI  //finished

    customer FindCustomerByEmail(const E_mail &email);  //finished
    customer FindCustomerByMobilePhone(const std::string& PhoneNr);   //finished
    customer FindCustomerByName(CustomerName name);  // finished (without exceptions)
    void ChangeCustomerEmailPassword(E_mail email,std::string newPassword);   // partially finished
    void ChangeCustomerNote(E_mail email, std::string newNote);       // partially finished
    void SeeFavotites();
    void AddToFavorite();

};


#endif //CARSHOP_CUSTOMERCONTROLLER_H
