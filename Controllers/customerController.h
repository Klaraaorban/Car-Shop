//
// Created by nagyb on 5/18/2024.
//

#ifndef CARSHOP_CUSTOMERCONTROLLER_H
#define CARSHOP_CUSTOMERCONTROLLER_H

#include "../CustomerService/customer_service.h"

class customerController {
private:
    customerService &service;

    bool IsEmailUnique(const E_mail& email);                //finished
    bool IsEmailStructureCorrect(const E_mail& email);      //finished
    bool PhoneNumberFormatCorrect(std::string PhoneNR);     //finished

public:
    explicit customerController(customerService &service);                             //finished
    void customerAdd(CustomerName customerName, E_mail customerMail, Address costumerAddress,
                     std::string customerPhoneNr, std::string customerNote, bool GdprDeleted, vector<int> favorites);    //finished
    void customerDelete(std::string email);                                          //finished
    customer FindCustomerByEmail(const E_mail &email);                          //finished
    customer FindCustomerByID(const int& id);                                   //finished
    customer FindCustomerByName(CustomerName name);                             //finished
    customer FindCustomerByPhoneNr(const std::string& PhoneNr);                 //finished
    std::vector<customer> ListAllCostumersSortedByName(std::string option);     //finished

    void ChangeCustomer(std::string old_email, std::string option, E_mail mail, CustomerName name, Address address, std::string phoneNr,
                        std::string note, bool GdprDeleted, std::vector<int> favorites);
    std::vector<int> SeeFavorites(E_mail &email);       //finished
    void AddToFavorite(E_mail email, int carID);        //finished

};

#endif //CARSHOP_CUSTOMERCONTROLLER_H
