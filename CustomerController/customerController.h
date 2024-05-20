//
// Created by nagyb on 5/18/2024.
//

#ifndef CARSHOP_CUSTOMERCONTROLLER_H
#define CARSHOP_CUSTOMERCONTROLLER_H

#include "../CustomerService/customer_service.h"

class customerController {
private:
    customer_service &customerService;

    bool IsEmailUnique(const E_mail& email);  //finished
    bool IsEmailStructureCorrect(const E_mail& email); //finished
    bool PhoneNumberFormatCorrect(std::string PhoneNR); //finished



public:
    explicit customerController(customer_service &customerService);          //finished

    void CustomerAdd(CustomerName customerName,E_mail customerMail,Address costumerAddress,
                     std::string customerPhoneNr,std::string customerNote,bool GdprDeleted); //finished
    void CustomerDelete(E_mail email); //finished
    void ModifyCustomer(E_mail old_email,CustomerName customerName,E_mail customerMail,Address costumerAddress,
                        std::string customerPhoneNr,std::string customerNote,bool GdprDeleted);  //finished

    void CustomerAnonymisation(E_mail &email);  // finished
    void CustomerByAuto();
    std::vector<customer> ListAllCostumersSortedByFirstName();       // the cout will be in the UI  //finished
    std::vector<customer> ListAllCostumersSortedByLastName();       // the cout will be in the UI  //finished

    customer FindCustomerByEmail(const E_mail &email);  //finished
    customer FindCustomerByMobilePhone(const std::string& PhoneNr);   //finished
    customer FindCustomerByName(CustomerName name);  // finished (without exceptions)
    void ChangeCustomerEmailPassword(E_mail email,std::string newPassword);   // partially finished
    void ChangeCustomerNote(E_mail email, std::string newNote);       // partially finished
    void SeeFavorites();
    void AddToFavorite();

};


#endif //CARSHOP_CUSTOMERCONTROLLER_H
