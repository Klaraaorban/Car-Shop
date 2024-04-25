#ifndef CAR_SHARING_CUSTOMER_H
#define CAR_SHARING_CUSTOMER_H
#include <string>

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
    int customerID;
    CustomerName customerName;
    E_mail customerMail;
    Address customerAddress;
    std::string customerPhoneNr;
    std::string customerNote; //something special about the customer
    bool GdprDeleted;          //if true -- costumer dates private



public:
    customer(CustomerName customerName,E_mail customerMail,Address costumerAddress,
             std::string customerPhoneNr,std::string customerNote,bool GdprDeleted);

    int getCustomerID() const;

    void setCustomerID(int customerId);

    const CustomerName &getCustomerName() const;

    void setCustomerName(const CustomerName &customerName);

    const E_mail &getCustomerMail() const;

    void setCustomerMail(const E_mail &customerMail);

    const Address &getCustomerAddress() const;

    void setCustomerAddress(const Address &costumerAddress);

    const std::string &getCustomerPhoneNr() const;

    void setCustomerPhoneNr(const std::string &customerPhoneNr);

    const std::string &getCustomerNote() const;

    void setCustomerNote(const std::string &customerNote);

    bool isGdprDeleted() const;

    void setGdprDeleted(bool gdprDeleted);

};


#endif //CAR_SHARING_CUSTOMER_H
