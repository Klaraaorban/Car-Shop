#include <cassert>
#include <iostream>
#include "customerTests.h"
#include "../Domain/CustomerDomian/Customer.h"
#include "../Controllers/customerController.h"
#include "../Services/customerService.h"
#include "../json/single_include/nlohmann/json.hpp"

using json = nlohmann::json;


//? tested if Object was created and if its attributes are valid and correct
customer testCreate() {
    CustomerName name;
    name.firstName = "Bence";
    name.lastName = "Molnar";
    E_mail mail;
    mail.mailAddress = "molnarbence@gmail.com";
    mail.mailPassword = "mb2014";
    Address str;
    str.city = "Satu Mare";
    str.country = "RO";
    str.street = "Lacramioarei";
    str.streetNumber = 11;
    std::vector<int> favorites;
    customer cus1 = customer{name, mail, str, "0757712657", "its a test", false, favorites};
    return cus1;
};


//? tested if setters and getters are working for the Object created before
void testSetters_GettersPart1(customer& customer) {
    std::cout << "Setters_Getters_Part1";
    assert(customer.getCustomerID() == 0);
    customer.setCustomerID(5);
    assert(customer.getCustomerID() == 5);

    assert(customer.getCustomerName().firstName == "Bence");
    assert(customer.getCustomerName().lastName == "Molnar");
    CustomerName testName;
    testName.firstName = "Balazs";
    testName.lastName = "Nagy";
    customer.setCustomerName(testName);
    assert(customer.getCustomerName().firstName == "Balazs");
    assert(customer.getCustomerName().lastName == "Nagy");

    assert(customer.getCustomerMail().mailAddress == "molnarbence@gmail.com");
    assert(customer.getCustomerMail().mailPassword == "mb2014");
    E_mail testMail;
    testMail.mailAddress = "nagybalazs@gmail.com";
    testMail.mailPassword = "nb2024";
    customer.setCustomerMail(testMail);
    assert(customer.getCustomerMail().mailAddress == "nagybalazs@gmail.com");
    assert(customer.getCustomerMail().mailPassword == "nb2024");

    assert(customer.getCustomerAddress().city == "Satu Mare");
    assert(customer.getCustomerAddress().country == "RO");
    assert(customer.getCustomerAddress().street == "Lacramioarei");
    assert(customer.getCustomerAddress().streetNumber == 11);
    Address testAddress;
    testAddress.city = "Cluj Napoca";
    testAddress.country = "RO";
    testAddress.street = "Baciului";
    testAddress.streetNumber = 20;
    customer.setCustomerAddress(testAddress);
    assert(customer.getCustomerAddress().city == "Cluj Napoca");
    assert(customer.getCustomerAddress().country == "RO");
    assert(customer.getCustomerAddress().street == "Baciului");
    assert(customer.getCustomerAddress().streetNumber == 20);
};


//? tested if setters and getters are working for the Object created before
void testSetters_GettersPart2(customer& customer) {
    std::cout << "Setters_Getters_Part2";
    assert(customer.getCustomerNote() == "its a test");
    customer.setCustomerNote("it worked");
    assert(customer.getCustomerNote() == "it worked");

    assert(customer.getCustomerPhoneNr() == "0757712657");
    customer.setCustomerPhoneNr("0123456789");
    assert(customer.getCustomerPhoneNr() == "0123456789");

    assert(customer.isGdprDeleted() == 0);
    customer.setGdprDeleted(true);
    assert(customer.isGdprDeleted() == 1);

    assert(customer.getFavorites().size() == 0);
    std::vector<int> testFavorites;
    testFavorites.push_back(0);
    testFavorites.push_back(1);
    customer.setFavoriteCar(testFavorites);
    assert(customer.getFavorites() == testFavorites);
};


//? tested if Object can be added and restored to/from Json
void testControllerAdd(customerController controller, customer newCustomer) {
    std::cout << "ControllerAdd_FindBy...";
    controller.customerAdd(newCustomer.getCustomerName(), newCustomer.getCustomerMail(), newCustomer.getCustomerAddress(),
            newCustomer.getCustomerPhoneNr(), newCustomer.getCustomerNote(), newCustomer.isGdprDeleted(), newCustomer.getFavorites());
    //? Test if FindCustomerByEmail works correct
    try {
        customer testCustomer = controller.FindCustomerByEmail(newCustomer.getCustomerMail());
        assert(typeid(testCustomer) == typeid(newCustomer));
    }
    catch (exception &ex) {
        assert(false);
    }
    E_mail testFalseMail;
    testFalseMail.mailAddress = "molnarbence@gmail.com";
    testFalseMail.mailPassword = "mb2014";
    try {
        customer testCustomer = controller.FindCustomerByEmail(testFalseMail);
        assert(false);
    }
    catch (exception &ex) {
        assert(true);
    }
    
    //? Test if FindCustomerByID works correct
    try {
        customer testCustomer = controller.FindCustomerByID(newCustomer.getCustomerID());
        assert(typeid(testCustomer) == typeid(newCustomer));
    }
    catch (exception &ex) {
        assert(false);
    }
    try {
        customer testCustomer = controller.FindCustomerByID(3);
        assert(false);
    }
    catch (exception &ex) {
        assert(true);
    }
    
    //? Test if FindCustomerByName works correct
    try {
        customer testCustomer = controller.FindCustomerByName(newCustomer.getCustomerName());
        assert(typeid(testCustomer) == typeid(newCustomer));
    }
    catch (exception &ex) {
        assert(false);
    }
    CustomerName testFalseName;
    testFalseName.firstName = "Bence";
    testFalseName.lastName = "Molnar";
    try {
        customer testCustomer = controller.FindCustomerByName(testFalseName);
        assert(false);
    }
    catch (exception &ex) {
        assert(true);
    }

    //? Test if FindCustomerByPhoneNr works correct
    try {
        customer testCustomer = controller.FindCustomerByPhoneNr(newCustomer.getCustomerPhoneNr());
        assert(typeid(testCustomer) == typeid(newCustomer));
    }
    catch (exception &ex) {
        assert(false);
    }

    try {
        customer testCustomer = controller.FindCustomerByPhoneNr("0757712657");
        assert(false);
    }
    catch (exception &ex) {
        assert(true);
    }
};


//? tested if all objects are listed
void testControllerList(customerController controller) {
    std::cout << "ControllerList" << "\n";
    std::vector<customer> customersFirst;
    customersFirst = controller.ListAllCostumersSortedByName("first");
    int cnt = 0;
    for (auto i : customersFirst) {
        // std::cout<<i.getCustomerID()<<" / "<<i.getCustomerName().firstName<<" "<<i.getCustomerName().lastName<<" / "<<
        //     i.getCustomerMail().mailAddress<<" / "<<i.getCustomerAddress().city<<" "<<i.getCustomerAddress().country<<" "<<
        //     i.getCustomerAddress().street<<" "<<i.getCustomerAddress().streetNumber<<" / "<<i.getCustomerNote()<<" / Favorites: ";
        // for (int idx = 0; idx < i.getFavorites().size(); idx++)
        //     std::cout << i.getFavorites()[idx] << " ";
        // std::cout << "\n";
        cnt++;
    }
    assert(cnt == customersFirst.size());
    cnt = 0;
    std::vector<customer> customersLast;
    customersLast = controller.ListAllCostumersSortedByName("last");
    for (auto i : customersLast) {
        // std::cout<<i.getCustomerID()<<" / "<<i.getCustomerName().firstName<<" "<<i.getCustomerName().lastName<<" / "<<
        //     i.getCustomerMail().mailAddress<<" / "<<i.getCustomerAddress().city<<" "<<i.getCustomerAddress().country<<" "<<
        //     i.getCustomerAddress().street<<" "<<i.getCustomerAddress().streetNumber<<" / "<<i.getCustomerNote()<<" / Favorites: ";
        // for (int idx = 0; idx < i.getFavorites().size(); idx++)
        //     std::cout << i.getFavorites()[idx] << " ";
        // std::cout << "\n";
        cnt++;
    }
    assert(cnt == customersLast.size());

};


// void testAdd() {

// };


void testAllFunctions() {
    customer newCustomer = testCreate();
    testSetters_GettersPart1(newCustomer);
    std::cout << "\n";
    testSetters_GettersPart2(newCustomer);
    std::cout << "\n";
    customerService service = customerService("../JsonDB/Customer.json");
    customerController controller = customerController(service);
    testControllerAdd(controller, newCustomer);
    testControllerList(controller);
}