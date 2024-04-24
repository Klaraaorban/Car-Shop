#include "customer_model.h"

customer::customer(Customer_name customer_name, E_mail customer_mail, Adress customer_adress,
                   std::string customer_phoneNR, std::string customer_remarks, bool GDPR_deleted) {
    this->customer_name = customer_name;
    this->customer_mail = customer_mail;
    this->customer_adress = customer_adress;
    this->customer_phoneNR = customer_phoneNR;
    this->customer_remarks = customer_remarks;
    this->GDPR_deleted = GDPR_deleted;
}

int customer::getCustomerId() const {
    return customer_ID;
}

void customer::setCustomerId(int customerId) {
    customer_ID = customerId;
}

const Customer_name &customer::getCustomerName() const {
    return customer_name;
}

void customer::setCustomerName(const Customer_name &customerName) {
    customer_name = customerName;
}

const E_mail &customer::getCustomerMail() const {
    return customer_mail;
}

void customer::setCustomerMail(const E_mail &customerMail) {
    customer_mail = customerMail;
}

const Adress &customer::getCustomerAdress() const {
    return customer_adress;
}

void customer::setCustomerAdress(const Adress &customerAdress) {
    customer_adress = customerAdress;
}

const std::string &customer::getCustomerPhoneNr() const {
    return customer_phoneNR;
}

void customer::setCustomerPhoneNr(const std::string &customerPhoneNr) {
    customer_phoneNR = customerPhoneNr;
}

const std::string &customer::getCustomerRemarks() const {
    return customer_remarks;
}

void customer::setCustomerRemarks(const std::string &customerRemarks) {
    customer_remarks = customerRemarks;
}

bool customer::isGdprDeleted() const {
    return GDPR_deleted;
}

void customer::setGdprDeleted(bool gdprDeleted) {
    GDPR_deleted = gdprDeleted;
}
