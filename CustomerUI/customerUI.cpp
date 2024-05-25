////
//// Created by nagyb on 5/21/2024.
////
//
//#include "customerUI.h"
//#include <iostream>
//
//
//customerUI::customerUI(customerController &customer_controller) : customer_controller(customer_controller) {};
//
//void customerUI::addNewCustomer() {
//    std::string firstName,lastName,emailAdress,emailPassword,country,city,streetName,customerPhoneNr,customerNote;
//    int streetNumber;
//    bool GdprDeleted = false;
//
//    std::cout<<std::endl;
//    std::cout<<"\nFirst name: ";
//    std::cin>>firstName;
//    std::cout<<"\nLirst name: ";
//    std::cin>>lastName;
//    std::cout<<"\nE-Mail adress: ";
//    std::cin>>emailAdress;
//    std::cout<<"\nE-Mail password: ";
//    std::cin>>emailPassword;
//    std::cout<<"\nCountry: ";
//    std::cin>>country;
//    std::cout<<"\nCity: ";
//    std::cin>>city;
//    std::cout<<"\nStreet name: ";
//    std::cin>>streetName;
//    std::cout<<"\nStreet number: ";
//    std::cin>>streetNumber;
//    std::cout<<"\nPhone number: ";
//    std::cin>>customerPhoneNr;
//    std::cout<<"\nNote: ";
//    std::cin>>customerNote;
//    std::cout<<std::endl;
//
//    Address customerAdress;
//    customerAdress.country = country;
//    customerAdress.city = city;
//    customerAdress.street = streetName;
//    customerAdress.streetNumber = streetNumber;
//
//    E_mail customerEmail;
//    customerEmail.mailAddress = emailAdress;
//    customerEmail.mailPassword = emailPassword;
//
//    CustomerName customerName;
//    customerName.firstName = firstName;
//    customerName.lastName = lastName;
//
//    customer_controller.CustomerAdd(customerName,customerEmail,customerAdress,customerPhoneNr,
//                                    customerNote,GdprDeleted);
//
//    std::cout<<"New customer added\n";
//}
