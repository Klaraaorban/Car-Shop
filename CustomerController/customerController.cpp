//
// Created by nagyb on 5/18/2024.
//

#include "customerController.h"
#include "exception"

customerController::customerController(customer_service &customerService) : customerService(customerService) {}


void customerController::CustomerAdd(CustomerName customerName,E_mail customerMail,Address costumerAddress,
                                     std::string customerPhoneNr,std::string customerNote,bool GdprDeleted) {
    customer customerToBeAdded(customerName,customerMail,costumerAddress,customerPhoneNr,customerNote,GdprDeleted);
    customerService.addCostumer(customerToBeAdded);
}


void customerController::CustomerDelete(E_mail email)  {
    std::string emailAdress = email.mailAddress;
    customerService.delete_customer(emailAdress);
}


customer customerController::FindCustomerByEmail(const E_mail &email) {
    std::string emailAdress = email.mailAddress;
    customer customerNeeded = customerService.get_customerby_email(emailAdress);
    return customerNeeded;
}


void customerController::ChangeCustomerEmailPassword(E_mail email,std::string newPassword) {
    std::string emailAdress, oldPassword;
    emailAdress = email.mailAddress;

    std::vector<customer> allCostumers = customerService.getAllCustomers();

    E_mail newMail;
    newMail.mailAddress = emailAdress;
    newMail.mailPassword = newPassword;

    for(auto i : allCostumers) {
        if (i.getCustomerMail().mailAddress == emailAdress) {
            i.setCustomerMail(newMail);
            break;
        }
    }

    //! customerService-UPDATE NEEDED: we need a method in the service which updates a specific customer based on the email
    //!                                and saves it in the vector and in the json
}


void customerController::ChangeCustomerNote(E_mail email, std::string newNote) {
    std::string emailAdress = email.mailAddress;

    for(auto i : customerService.getAllCustomers()) {
        if (i.getCustomerMail().mailAddress == emailAdress) {
            i.setCustomerNote(newNote);
            break;
        }
    }

    //!  customerService-UPDATE NEEDED: same as in the previous method, we need to update it based on email
}


customer customerController::FindCustomerByName(CustomerName name) {
    for(auto i : customerService.getAllCustomers()){
        if(i.getCustomerName().firstName == name.firstName && i.getCustomerName().lastName == name.lastName)
            return i;
    }
    throw logic_error("Customer with this name not existing!");
}   


bool customerController::PhoneNumberFormatCorrect(std::string PhoneNR) {   //privat methode
    if(PhoneNR[0] != '+' )
        if(!isdigit(PhoneNR[0]))
            return false;

    for (int i = 1; i < PhoneNR.length(); i++) {
        if (!isdigit(PhoneNR[i]))
            return false;
    }
    return true;

}


customer customerController::FindCustomerByMobilePhone(const std::string& PhoneNr) {
    if(!PhoneNumberFormatCorrect(PhoneNr))
        throw std::runtime_error("Customer not found.");

    for(auto i : customerService.getAllCustomers()){
        if(i.getCustomerPhoneNr() == PhoneNr)
            return i;
    }
    throw logic_error("Customer with this phone number not found!");
}


std::vector<customer> customerController::ListAllCostumersSortedByFirstName() {
    std::vector<customer> allCustomers = customerService.getAllCustomers();

    std::sort(allCustomers.begin(), allCustomers.end(), [](const customer& a, const customer& b) {
        return a.getCustomerName().firstName < b.getCustomerName().firstName;
    });

    return allCustomers;
}


std::vector<customer> customerController::ListAllCostumersSortedByLastName() {
    std::vector<customer> allCustomers = customerService.getAllCustomers();

    std::sort(allCustomers.begin(), allCustomers.end(), [](const customer& a, const customer& b) {
        return a.getCustomerName().lastName < b.getCustomerName().lastName;
    });

    return allCustomers;
}


void customerController::ModifyCustomer(E_mail old_email, CustomerName customerName, E_mail customerMail,
                                        Address costumerAddress, std::string customerPhoneNr, std::string customerNote,
                                        bool GdprDeleted) {
    customer modifiedCustomer(customerName,customerMail,costumerAddress,customerPhoneNr,customerNote,GdprDeleted);
    customerService.update_customer(old_email.mailAddress,modifiedCustomer);
}


void customerController::CustomerAnonymisation(E_mail &email) {

    int id = -1;

    for(auto i : customerService.getAllCustomers())
        if(i.getCustomerMail().mailAddress == email.mailAddress)
            id = i.getCustomerID();

    CustomerName anonymName;
    anonymName.lastName = "Customer - " + std::to_string(id);
    anonymName.firstName = "Unknown";

    E_mail anonymEmail;
    anonymEmail.mailAddress = "Null";
    anonymEmail.mailPassword = "Null";

    Address anonymAdress;
    anonymAdress.city = "Null";
    anonymAdress.country = "Null";
    anonymAdress.street = "Null";
    anonymAdress.streetNumber= 0;

    for(auto &i : customerService.getAllCustomers()){
        if(i.getCustomerMail().mailAddress == email.mailAddress){
            i.setCustomerName(anonymName);
            i.setCustomerNote("Null");
            i.setCustomerMail(anonymEmail);
            i.setCustomerAddress(anonymAdress);
            i.setCustomerPhoneNr("Null");
            i.setGdprDeleted(true);
        }
    }
}


bool customerController::IsEmailStructureCorrect(const E_mail& email) {
    int oki = 0;

    for(int i = 0; i < email.mailAddress.length();i++){
        if (email.mailAddress[i] == '@' || (email.mailAddress[i] == '.' && isalpha(email.mailAddress[i+1])))
            oki++;
    }
    if(oki == 2)
        return true;
    return false;

}


bool customerController::IsEmailUnique(const E_mail& email) {
    bool unique = true;

    for(auto i : customerService.getAllCustomers())
        if(i.getCustomerMail().mailAddress == email.mailAddress)
            unique = false;

    return unique;
}


std::vector<int> customerController::SeeFavorites(E_mail &email) {
    for (auto i : customerService.getAllCustomers()) {
        if (i.getCustomerMail().mailAddress == email.mailAddress) {
            return i.getFavorites();
        }
    }
    throw logic_error("Customer with this email not existing!");
}


void customerController::AddToFavorite(E_mail &email, int carID) {
    for (auto i : customerService.getAllCustomers()) {
        if (i.getCustomerMail().mailAddress == email.mailAddress) {
            for (int id : i.getFavorites()) {
                if (id == carID) 
                    throw runtime_error("CarID already existing!");
            }
            i.addFavoriteCar(carID);
            return;
        }
    }
    throw logic_error("Customer with this email not existing!");

    //! customerService-UPDATE NEEDED: to load/save the favorites too
}