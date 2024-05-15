#include "customer_service.h"

customer_service::customer_service(const std::string &path) : path(path) {
    loadJson();
}

//void customer_service::loadJson() {
//    ifstream file(path);
//    if(file.is_open()){
//        json x;
//        file >> x;
//        for(const auto &i : x){
//            customer cus(
//                    i["customerID"], i["customerName"], i["customerMail"],
//                    i["customerAddress"], i["customerPhoneNr"], i["customerNote"]);
//            customers.push_back(cus);
//        }
//        file.close();
//    }
//}

void customer_service::saveJson() const {
    json x = json::array();
    for (const auto &cus: customers) {
        json customerJson = {
                            {"ID",           cus.getCustomerID()},
                            {"Name",         cus.getCustomerName().firstName + cus.getCustomerName().lastName},
                            {"Mail",         cus.getCustomerMail().mailAddress},
                            {"Address",      cus.getCustomerAddress().city},
                            {"Phone number", cus.getCustomerPhoneNr()},
                            {"Remarks",      cus.getCustomerNote()}
                };
        x.push_back(customerJson);
    }

    ofstream fileout(path);
    if(fileout.is_open()){
        fileout << x.dump(4);
        fileout.close();
    }
}

void customer_service::addCostumer(const customer &_customer) {
    customers.push_back(_customer);
    saveJson();
}

customer customer_service::get_customerby_email(const std::string &email) const {
    for(const auto &cus: customers){
        if(email == cus.getCustomerMail().mailAddress){
            return cus;
        }
    }
    throw runtime_error("Customer not found");
}

void customer_service::update_customer(const std::string &email, const customer &updated_customer) {
    for(auto &cus: customers){
        if(cus.getCustomerMail().mailAddress == email){
            cus = updated_customer;
            saveJson();
            return;
        }
    }
    throw runtime_error("Customer not found");
}

void customer_service::delete_customer(const std::string &email) {
    for(auto i = customers.begin(); i != customers.end(); i++){
        if(i->getCustomerMail().mailAddress == email){
            customers.erase(i);
            saveJson();
            return;
        }
    }
    throw runtime_error("Customer not found");
}

vector<customer> customer_service::getAllCustomers() const{
    return customers;
}
