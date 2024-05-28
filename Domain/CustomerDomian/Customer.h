#pragma once
#ifndef CAR_SHARING_CUSTOMER_H
#define CAR_SHARING_CUSTOMER_H
#include <string>
#include <vector>
#include <algorithm>

struct Address{
    std::string country;
    std::string city;
    std::string street;
    int streetNumber;
};

struct E_mail{
    std::string mailAddress;
    std::string mailPassword;
};

struct CustomerName{
    std::string lastName;
    std::string firstName;
};

class customer {

private:
    static int customerID;
    CustomerName customerName;
    E_mail customerMail;
    Address customerAddress;
    std::string customerPhoneNr;
    std::string customerNote;
    bool GdprDeleted;          //if true --> costumer data is private
    std::vector<int> favorites;


public:
    customer(CustomerName customerName, E_mail customerMail, Address costumerAddress,
             std::string customerPhoneNr, std::string customerNote, bool GdprDeleted, std::vector<int> favorites);
    /*tested*/  int getCustomerID() const;
    /*tested*/  void setCustomerID(int customerId);
    /*tested*/ const CustomerName &getCustomerName() const;
    /*tested*/ void setCustomerName(const CustomerName &customerName);
    /*tested*/ const E_mail &getCustomerMail() const;
    /*tested*/ void setCustomerMail(const E_mail &customerMail);
    /*tested*/ const Address &getCustomerAddress() const;
    /*tested*/ void setCustomerAddress(const Address &costumerAddress);
    /*tested*/ const std::string &getCustomerPhoneNr() const;
    /*tested*/ void setCustomerPhoneNr(const std::string &customerPhoneNr);
    /*tested*/ const std::string &getCustomerNote() const;
    /*tested*/ void setCustomerNote(const std::string &customerNote);
    /*tested*/ bool isGdprDeleted() const;
    /*tested*/ void setGdprDeleted(bool gdprDeleted);
    /*tested*/ void setFavoriteCar(std::vector<int>& favs);
    /*tested*/ std::vector<int> getFavorites() const;
};


#endif //CAR_SHARING_CUSTOMER_H
