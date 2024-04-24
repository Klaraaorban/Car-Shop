#ifndef CAR_SHARING_CUSTOMER_MODEL_H
#define CAR_SHARING_CUSTOMER_MODEL_H
#include <string>

struct Adress{
    std::string country;
    std::string city;
    std::string street;
    int street_number;
};

struct E_mail{
    std::string mail_adress;
    std::string mail_password;
};

struct Customer_name{
    std::string name;
    std::string first_name;
};
class customer {

private:
    int customer_ID;
    Customer_name customer_name;
    E_mail customer_mail;
    Adress customer_adress;
    std::string customer_phoneNR;
    std::string customer_remarks; //something special about the customer
    bool GDPR_deleted;          //if true -- costumer dates private



public:
    customer(Customer_name customer_name,E_mail customer_mail,Adress costumer_adress,
             std::string customer_phoneNR,std::string customer_remarks,bool GDPR_deleted);

    int getCustomerId() const;

    void setCustomerId(int customerId);

    const Customer_name &getCustomerName() const;

    void setCustomerName(const Customer_name &customerName);

    const E_mail &getCustomerMail() const;

    void setCustomerMail(const E_mail &customerMail);

    const Adress &getCustomerAdress() const;

    void setCustomerAdress(const Adress &costumerAdress);

    const std::string &getCustomerPhoneNr() const;

    void setCustomerPhoneNr(const std::string &customerPhoneNr);

    const std::string &getCustomerRemarks() const;

    void setCustomerRemarks(const std::string &customerRemarks);

    bool isGdprDeleted() const;

    void setGdprDeleted(bool gdprDeleted);

};


#endif //CAR_SHARING_CUSTOMER_MODEL_H
