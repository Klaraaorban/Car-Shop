#include "customer_service.h"

customerService::customerService(const std::string &path) : path(path) {
    loadJson();
}

void customerService::loadJson() {
    ifstream file(path);
    if(file.is_open()){
        json x;
        file >> x;
        std::vector<int> ids;
        for(const auto &i : x) {
            int customerID = i["ID"];
            ids.push_back(customerID);

            std::string fullName = i["Name"];
            CustomerName newStruct;
            newStruct.firstName = fullName.substr(0, fullName.find(" "));
            newStruct.lastName = fullName.substr(fullName.find(" ") + 1);

            std::string fullMail = i["Mail"];
            E_mail newMail;
            newMail.mailAddress = fullMail.substr(0, fullMail.find(" "));
            newMail.mailPassword = fullMail.substr(fullMail.find(" ") + 1);

            std::string fullAddress = i["Address"];
            int citySpace = fullAddress.find(" ");
            int countrySpace = fullAddress.find(" ", citySpace + 1);
            int streetSpace = fullAddress.find(" ", countrySpace + 1);
            Address newAddress;
            newAddress.city = fullAddress.substr(0, citySpace);
            newAddress.country = fullAddress.substr(citySpace + 1, countrySpace - citySpace - 1);
            newAddress.street = fullAddress.substr(countrySpace + 1, streetSpace - countrySpace - 1);
            newAddress.streetNumber = stoi(fullAddress.substr(streetSpace + 1));

            vector<int> favorites;
            for (const auto& fav : i["Favorites"]) {
                favorites.push_back(fav);
            }

            customer cus(newStruct, newMail, newAddress, i["Phone number"], i["Notes"], i["GDPR"], favorites);
            customers.push_back(cus);
        }
        for (int idx = 0; idx < customers.size(); idx++)
            customers[idx].setCustomerID(ids[idx]);

        file.close();
    }
}


void customerService::saveJson() const {
    json x = json::array();
    for (const auto &cus: customers) {
        json customerJson = {
                            {"ID",           cus.getCustomerID()},
                            {"Name",         cus.getCustomerName().firstName + " " + cus.getCustomerName().lastName},
                            {"Mail",         cus.getCustomerMail().mailAddress + " " + cus.getCustomerMail().mailPassword},
                            {"Address",      cus.getCustomerAddress().city + " " + cus.getCustomerAddress().country + " " +
                                             cus.getCustomerAddress().street + " " + to_string(cus.getCustomerAddress().streetNumber)},
                            {"Phone number", cus.getCustomerPhoneNr()},
                            {"Notes",        cus.getCustomerNote()},
                            {"GDPR",         cus.isGdprDeleted()},
                            {"Favorites",    cus.getFavorites()}
                };
        x.push_back(customerJson);
    }

    ofstream fileout(path);
    if(fileout.is_open()){
        fileout << x.dump(4);
        fileout.close();
    }
}


void customerService::addCostumer(const customer &_customer) {
    customers.push_back(_customer);
    saveJson();
}


void customerService::updateCustomer(std::string mail, vector<int> favorites) {
    for(auto cus : customers){
        if(cus.getCustomerMail().mailAddress == mail){
            cus.setFavoriteCar(favorites);
            saveJson();
            return;
        }
    }
    throw runtime_error("Customer not found");
}


void customerService::deleteCustomer(std::string &email) {
    for(auto i = customers.begin(); i < customers.end(); i++){
        if(i->getCustomerMail().mailAddress == email){
            customers.erase(i);
            saveJson();
            return;
        }
    }
    throw runtime_error("Customer not found");
}


vector<customer> customerService::getAllCustomers() const{
    return customers;
}
