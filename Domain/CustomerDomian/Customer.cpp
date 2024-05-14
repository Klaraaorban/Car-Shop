#include "Customer.h"

customer::customer(CustomerName customerName, E_mail customerMail, Address customerAddress,
                   std::string customerPhoneNr, std::string customerNote, bool GdprDeleted) {
    this->customerName = customerName;
    this->customerMail = customerMail;
    this->customerAddress = customerAddress;
    this->customerPhoneNr = customerPhoneNr;
    this->customerNote = customerNote;
    this->GdprDeleted = GdprDeleted;
}

int customer::getCustomerID() const {
    return customerID;
}

void customer::setCustomerID(int customerID) {
    this->customerID = customerID;
}

const CustomerName &customer::getCustomerName() const {
    return customerName;
}

void customer::setCustomerName(const CustomerName &customerName) {
    this->customerName = customerName;
}

const E_mail &customer::getCustomerMail() const {
    return customerMail;
}

void customer::setCustomerMail(const E_mail &customerMail) {
    this->customerMail = customerMail;
}

const Address &customer::getCustomerAddress() const {
    return customerAddress;
}

void customer::setCustomerAddress(const Address &customerAddress) {
    this->customerAddress = customerAddress;
}

const std::string &customer::getCustomerPhoneNr() const {
    return customerPhoneNr;
}

void customer::setCustomerPhoneNr(const std::string &customerPhoneNr) {
    this->customerPhoneNr = customerPhoneNr;
}

const std::string &customer::getCustomerNote() const {
    return customerNote;
}

void customer::setCustomerNote(const std::string &customerNote) {
    this->customerNote = customerNote;
}

bool customer::isGdprDeleted() const {
    return GdprDeleted;
}

void customer::setGdprDeleted(bool gdprDeleted) {
    this->GdprDeleted = gdprDeleted;
}