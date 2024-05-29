//
// Created by nagyb on 5/18/2024.
//

#include "customerController.h"
#include "exception"

customerController::customerController(customerService *service) : service(service) {}


void customerController::customerAdd(CustomerName customerName, E_mail customerMail, Address costumerAddress,
                                     std::string customerPhoneNr, std::string customerNote, bool GdprDeleted, vector<int> favorites) {
    customer customerToBeAdded(customerName, customerMail, costumerAddress, customerPhoneNr, customerNote, GdprDeleted, favorites);
    service->addCostumer(customerToBeAdded);
}


void customerController::customerDelete(std::string email)  {
    service->deleteCustomer(email);
}


customer customerController::FindCustomerByEmail(const E_mail &email) {
    for (auto cus : service->getAllCustomers()) {
        if (email.mailAddress == cus.getCustomerMail().mailAddress && email.mailPassword == cus.getCustomerMail().mailPassword) {
            return cus;
        }
    }
    throw logic_error("Customer with this mail not existing!");
}


customer customerController::FindCustomerByID(const int& id) {
    for (auto cus : service->getAllCustomers()) {
        if (cus.getCustomerID() == id) {
            return cus;
        }
    }
    throw logic_error("Customer with this ID not existing!");
}


customer customerController::FindCustomerByName(CustomerName name) {
    for(auto cus : service->getAllCustomers()){
        if(cus.getCustomerName().firstName == name.firstName && cus.getCustomerName().lastName == name.lastName)
            return cus;
    }
    throw logic_error("Customer with this name not existing!");
}  


bool customerController::PhoneNumberFormatCorrect(std::string PhoneNR) {
    if(PhoneNR[0] != '+' )
        if(!isdigit(PhoneNR[0]))
            return false;

    for (int i = 1; i < PhoneNR.length(); i++) {
        if (!isdigit(PhoneNR[i]))
            return false;
    }
    return true;
}


customer customerController::FindCustomerByPhoneNr(const std::string& PhoneNr) {
    if(!PhoneNumberFormatCorrect(PhoneNr))
        throw std::runtime_error("Phone number not correct!");

    for(auto cus : service->getAllCustomers()){
        if(cus.getCustomerPhoneNr() == PhoneNr)
            return cus;
    }
    throw logic_error("Customer with this phone number not found!");
}


std::vector<customer> customerController::ListAllCostumersSortedByName(std::string option) {
    std::vector<customer> customers = service->getAllCustomers();

    if (option == "first") {
        std::sort(customers.begin(), customers.end(), [](const customer& a, const customer& b) {
            return a.getCustomerName().firstName < b.getCustomerName().firstName;
        });
        return customers;
    }
    else if (option == "last") {
        std::sort(customers.begin(), customers.end(), [](const customer& a, const customer& b) {
            return a.getCustomerName().lastName < b.getCustomerName().lastName;
        });
        return customers;
    }
    else throw logic_error("Option chosen not existing!");
}


void customerController::ChangeCustomer(std::string old_mail, std::string option, E_mail mail, CustomerName name, Address address,
                                        std::string phoneNr, std::string note, bool GdprDeleted, std::vector<int> favorites) {
    for(auto cus : service->getAllCustomers()) {
        if (cus.getCustomerMail().mailAddress == old_mail) {
            if (option == "password") {
                E_mail newMail;
                newMail.mailAddress = old_mail;
                newMail.mailPassword = mail.mailPassword;
                customer updatedCustomer(cus.getCustomerName(), newMail, cus.getCustomerAddress(), cus.getCustomerPhoneNr(),
                                         cus.getCustomerNote(), cus.isGdprDeleted(), cus.getFavorites());
                updatedCustomer.setCustomerID(cus.getCustomerID());
                customerDelete(cus.getCustomerMail().mailAddress);
                service->addCostumer(updatedCustomer);
                cus.setCustomerMail(newMail);
                return;
            }
            else if (option == "note") {
                customer updatedCustomer(cus.getCustomerName(), cus.getCustomerMail(), cus.getCustomerAddress(),
                                         cus.getCustomerPhoneNr(), note, cus.isGdprDeleted(), cus.getFavorites());
                updatedCustomer.setCustomerID(cus.getCustomerID());
                customerDelete(cus.getCustomerMail().mailAddress);
                service->addCostumer(updatedCustomer);
                cus.setCustomerNote(note);
                return;
            }
            else if (GdprDeleted == true) {
                CustomerName anonymName;
                anonymName.lastName = "Customer - " + std::to_string(cus.getCustomerID());
                anonymName.firstName = "Unknown";

                E_mail anonymEmail;
                anonymEmail.mailAddress = "Null";
                anonymEmail.mailPassword = "Null";

                Address anonymAddress;
                anonymAddress.city = "Null";
                anonymAddress.country = "Null";
                anonymAddress.street = "Null";
                anonymAddress.streetNumber = 0;

                std::vector<int> anonymFavorites;
                for (int i = 0; i < cus.getFavorites().size(); i++) {
                    anonymFavorites.push_back(0);
                }

                cus.setCustomerAddress(anonymAddress);
                cus.setCustomerMail(anonymEmail);
                cus.setCustomerName(anonymName);
                cus.setCustomerNote("Null");
                cus.setCustomerPhoneNr("Null");
                cus.setFavoriteCar(anonymFavorites);
                cus.setGdprDeleted(true);
                return;
            }
            else {
                customer updatedCustomer(name, mail, address, phoneNr, note, GdprDeleted, favorites);
                updatedCustomer.setCustomerID(cus.getCustomerID());
                customerDelete(cus.getCustomerMail().mailAddress);
                service->addCostumer(updatedCustomer);
                cus.setCustomerAddress(address);
                cus.setCustomerMail(mail);
                cus.setCustomerName(name);
                cus.setCustomerNote(note);
                cus.setCustomerPhoneNr(phoneNr);
                cus.setFavoriteCar(favorites);
                cus.setGdprDeleted(GdprDeleted);
                return;
            }
        }
    }
    throw logic_error("Customer with this mail not existing!");
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

    for(auto i : service->getAllCustomers())
        if(i.getCustomerMail().mailAddress == email.mailAddress)
            unique = false;

    return unique;
}


std::vector<int> customerController::SeeFavorites(E_mail email) {
    for (auto i : service->getAllCustomers()) {
        if (i.getCustomerMail().mailAddress == email.mailAddress) {
            return i.getFavorites();
        }
    }
    throw logic_error("Customer with this email not existing!");
}


void customerController::AddToFavorite(E_mail email, Car &newCar) {
    for (auto i : service->getAllCustomers()) {
        if (i.getCustomerMail().mailAddress == email.mailAddress) {
            vector<int> favorites = i.getFavorites();
            for (int id = 0; id < favorites.size(); id) {
                if (favorites[id] == newCar.get_id()) 
                    throw runtime_error("CarID already existing!");
            }
            favorites.push_back(newCar.get_id());
            service->changeFavorite(email.mailAddress, favorites);
            return;
        }
    }
    throw logic_error("Customer with this email not existing!");
}

customer customerController::ReturnCustomerByID(int id) {
    for(auto i : service->getAllCustomers())
        if(i.getCustomerID() == id)
            return i;
}

std::vector<customer> customerController::getAllCustomer()  {
    std::vector<customer> allCustomers = service->getAllCustomers();
    return  allCustomers;
}