
//
// Created by nagyb on 5/23/2024.
//

#include "UI.h"
#include <iostream>
#include <utility>
using namespace std;

UI::UI(Controller *ctrl) {
    this->ctrl = ctrl;
}

void UI::greeting() {
    cout<<"Welcome to CarSharing!\n";
}


pair<string, string> UI::authentication() {
    string email, password;
    cout<<"Authentication\n";
    cout<<"Type in your email: ";
    getline(cin,email);
    cout<<"Type in your password: ";
    getline(cin,password);
    return make_pair(email, password);
}

int UI::options(){
    int option;
    cin>>option;
    return option;
}

void UI::run() {
    this->greeting();
    cout << "Are you a customer or an employee?\n1. Customer\n2. Employee\n0. Exit\nType a number: ";
    int mainOpt = options();
    bool mainRun = true;
    while (mainRun) {
        if (mainOpt == 1) {//customer
            pair<string, string> auth = this->authentication();
            //apel functie identificare customer dupa email si password
            customer logedCust = ctrl->findCustomerByEmailandPassword(auth.first, auth.second);
            cout << "Choose option:\n1. Manage account\n2. Search car\n3. Manage order\n0. Exit\nType an option: ";
            int opt;
            bool run = true;
            while (run) {
                opt = options();
                switch (opt) {
                    case 0: {
                        run = false;
                        break;
                    }
                    case 1: {
                        cout
                                << "Choose option:\n1. Change password\n2. Change remarks\n3. Change favorites list\n4. View favorites list \n0. Back\nType an option: ";
                        int opt2 = options();
                        switch (opt2) {
                            case 0:
                                break;
                            case 1: {
                                string newPassword;
                                cout << "Enter a new password: ";
                                getline(cin, newPassword);
                                ctrl->changePassword(logedCust, newPassword);
                                cout << "Password changed!";
                                break;
                            }
                            case 2: {
                                string newNote;
                                cout << "Enter a new Note: ";
                                getline(cin, newNote);
                                ctrl->changeNote(logedCust, newNote);
                                cout << "Note changed!";
                                break;
                            }
                            case 3: {
                                string licencePlate;
                                cout << "Enter the car's licence plate you want to add: ";
                                getline(cin, licencePlate);
                                Car car = ctrl->findCarByLicensePlate(licencePlate);
                                ctrl->changeFavorite(logedCust, car);
                                break;
                            }
                            case 4: {
                                cout << "Your favorite list: \n";
                                vector<Car> favoriteCars = ctrl->getFavoritesList(logedCust);
                                for (auto i: favoriteCars) {
                                    cout << i.get_brand() << " " << i.get_model() << " " << i.get_lincensePlate()
                                         << "\n";
                                }
                                break;
                            }
                            default:
                                cout << "Choose a valid option: ";
                        }
                        break;
                    }
                    case 2: {
                        cout
                                << "Choose option:\n1. View cars for a specific date\n2. Search car by license plate\n3. View ordered cars\n0. Back\nType an option: ";
                        int opt2 = options();
                        switch (opt2) {
                            case 0:
                                break;
                            case 1: {
                                string begin, end;
                                cout << "From: ";
                                getline(cin, begin);
                                cout << "To: ";
                                getline(cin, end);
                                vector<Car> carList = ctrl->notOrderedCars(begin, end);
                                for (auto &car: carList) {
                                    cout << car.get_brand() << ' ' << car.get_model() << ' ' << car.get_gearbox() << ' '
                                         << car.get_dailyPrice() << endl;
                                }
                                break;
                            }
                            case 2: {
                                string licensePlate;
                                cout << "License plate: ";
                                getline(cin, licensePlate);
                                Car searchedCar = ctrl->findCarByLicensePlate(licensePlate);
                                cout << searchedCar.get_brand() << ' ' << searchedCar.get_model() << ' '
                                     << searchedCar.get_gearbox() << ' ' << searchedCar.get_dailyPrice() << endl;
                                break;
                            }
                            case 3: {
                                cout << "Your ordered cars:\n";
                                vector<Car> carList = ctrl->orderedCars(logedCust.getCustomerID());
                                for (auto &car: carList) {
                                    cout << car.get_brand() << ' ' << car.get_model() << ' ' << car.get_gearbox() << ' '
                                         << car.get_dailyPrice() << endl;
                                }
                                break;
                            }
                            default:
                                cout << "Choose a valid option: ";

                        }
                        break;
                    }
                    case 3: {
                        cout
                                << "Choose option:\n1. Create reservation\n2. Delete reservation\n3. Change reservation\n4. View orders for a specific date \n5. Search order by nr\n6. See total price\n0. Back\nType an option: ";
                        int opt2 = options();
                        switch (opt2) {
                            case 0:
                                break;
                            case 1: {
                                //ctrl.createReservation();
                                break;
                            }
                            case 2: {
                                //ctrl.deleteReservation();
                                break;
                            }
                            case 3: {
                                //ctrl.changeReservation();
                                break;
                            }
                            case 4: {
                                //ctrl.viewOrderForSpecificDate();
                                break;
                            }
                            case 5: {
                                //ctrl.searchOrderByNumber();
                                break;
                            }
                            case 6: {
                                //ctrl.seeTotalPrice();
                                break;
                            }
                            default:
                                cout << "Choose a valid option: ";
                        }
                        break;
                    }
                    default: {
                        cout << "Choose a valid option: ";
                    }
                }
            }
        }






        else if (mainOpt == 2) {//employee
            pair<string, string> auth = this->authentication();
            //apel functie identificare employee dupa email si password
            Employee logedEmpl = ctrl->findEmployeeByEmailandPassword(auth.first, auth.second);
            cout
                    << "Choose option:\n1. Manage account\n2. Manage employees\n3.Manage customers\n4. Manage cars\n5. Manage orders\n0. Exit\nType an option: ";
            int opt = options();
            bool run = true;
            while (run) {
                switch (opt) {
                    case 0: {
                        run = false;
                        break;
                    }
                    case 1: {
                        cout << "Choose option:\n1. Change password\n2. Change remarks;\n 0. Back\nType an option: ";
                        int opt2 = options();
                        switch (opt2) {
                            case 0:
                                break;
                            case 1: {
                                cout << "Enter new password: ";
                                string newPassword;
                                getline(cin, newPassword);
                                ctrl->updateEmployee(logedEmpl.getId(), newPassword, logedEmpl.getNickname(),logedEmpl.getLastName(), logedEmpl.getFirstName(), logedEmpl.getPosition(), logedEmpl.getBirthDate(), logedEmpl.getSalary(), logedEmpl.getRemarks());
                                break;
                            }
                            case 2: {
                                cout << "Enter new remarks: ";
                                string newRemarks;
                                getline(cin, newRemarks);
                                ctrl->changeRemarks(logedEmpl.getId(), newRemarks);
                                cout << "Remarks changed successfully." << endl;
                                break;
                            }
                            default: {
                                cout << "Choose a valid option: ";
                            }
                        }
                        break;
                    }
                    case 2: {
                        cout
                                << "Choose option:\n1. View employees\n2. Search employee by nickname\n3. Search employee by e-mail\n4. Search employee by name\n5. Search employee by birthdate\n";
                        if (logedEmpl.getPosition() == "admin")
                            cout
                                    << "6. Create employee\n7. Change employee\n8. Activate/deactivate employee\n9. Delete employee\n10. Change employee to admin\n11. Change admin to employee\n12. Reset password for employee\n13. View employee salary\n14. Change employees remarks\n";
                        cout << "0. Back\nType an option: ";
                        int opt2 = options();
                        switch (opt2) {
                            case 0:
                                break;
                            case 1: {

                                vector<Employee> employees = ctrl->getAllEmployees();
                                for (const auto &emp : employees) {
                                    cout << "ID: " << emp.getId() << ", Last Name: " << emp.getLastName() << ", First Name: " << emp.getFirstName() << ", Position: " << emp.getPosition() << endl;
                                }
                                break;
                            }
                            case 2: {
                                // search employee by nickname
                                cout << "Enter Nickname: ";
                                string nickname;
                                getline(cin, nickname);
                                Employee foundEmployee = ctrl->getEmployeeByNickname(nickname);
                                cout << "Employee found with ID: " << foundEmployee.getId() << ", Last Name: " << foundEmployee.getLastName() << ", First Name: " << foundEmployee.getFirstName() << ", Position: " << foundEmployee.getPosition() << endl;
                                break;

                            }
                            case 3: {
                                //search employee by email
                                cout << "Enter email: ";
                                string email;
                                getline(cin, email);
                                Employee foundEmployee = ctrl->getEmployeeByEmail(email);
                                cout << "Employee found with ID: " << foundEmployee.getId() << ", Last Name: " << foundEmployee.getLastName() << ", First Name: " << foundEmployee.getFirstName() << ", Position: " << foundEmployee.getPosition() << endl;

                                break;
                            }
                            case 4: {
                                cout << "Enter employee name: ";
                                string name;
                                getline(cin, name);
                                vector<Employee> employeesByName = ctrl->getEmployeesByName(name);

                                for (const auto &employee : employeesByName) {
                                    cout << "ID: " << employee.getId() << ", Last Name: " << employee.getLastName() << ", First Name: " << employee.getFirstName() << ", Position: " << employee.getPosition() << endl;
                                    }
                                break;
                            }
                            case 5: {
                                cout << "Enter birthdate: ";
                                string birthdate;
                                getline(cin, birthdate);
                                vector<Employee> employeesByBirthdate = ctrl->getEmployeesByBirthdate(birthdate);
                                for (const auto &employee : employeesByBirthdate) {
                                    cout << "ID: " << employee.getId() << ", Last Name: " << employee.getLastName() << ", First Name: " << employee.getFirstName() << ", Position: " << employee.getPosition() << endl;
                                    }
                                break;
                            }
                            case 6:{
                                //create employee
                            }
                            case 7:{
                                //change emplyee

                            }
                            case 8:{
                                //act/deac

                            }
                            case 9:{
                                //delete emp

                            }
                            case 10:{
                                //change emp to admin

                            }
                            case 11:{
                                //change admin to emp

                            }
                            case 12:{
                                //reset passw for emp


                            }
                            case 13:{
                                //view emp salary
                                cout << "Enter employee ID: ";
                                int ID;
                                cin>>ID;
                                Employee foundEmployee = ctrl->getEmployeeById(ID);
                                cout << "Employee found with ID: " << foundEmployee.getId() << ", Last Name: " << foundEmployee.getLastName() << ", First Name: " << foundEmployee.getFirstName() << ", Has the salary: " << foundEmployee.getSalary() << endl;


                            }
                            case 14:{
                                cout << "Enter employee ID: ";
                                int employeeId;
                                cin >> employeeId;
                                cin.ignore();
                                cout << "Enter new remarks: ";
                                string newRemarks;
                                getline(cin, newRemarks);
                                ctrl->changeRemarks(employeeId, newRemarks);
                                cout << "Remarks changed successfully." << endl;
                                break;
                            }
                            default: {
                                cout << "Choose a valid option: ";
                            }
                        }
                        break;
                    }
                    case 3: {
                        cout
                                << "Choose option:\n1. Create customer\n2. Change customer\n3. Delete customer\n4. Anonymise customer\n5. View customers\n6. Search customer by e-mail\n7. Search customer by phone nr\n8. Search customer by name\n9. Search customers by ordered car\n0. Back\nType an option: ";
                        int opt2 = options();
                        switch (opt2) {
                            case 0:
                                break;
                            case 1: {
                                string first, last, mailAdd, mailPass, city, country, street, phone, note;
                                int streetNum;
                                bool gdpr;
                                vector<int> favorites;
                                cout << "Enter your First and Last name: ";
                                getline(cin, first);
                                getline(cin, last);

                                //apelare functie create customer
                                break;
                            }
                            case 2: {
                                //aperale functie change customer
                                break;
                            }
                            case 3: {
                                //aperale functie delete customer
                                break;
                            }
                            case 4: {
                                //aperale functie anonymise customer
                                break;
                            }
                            case 5: {
                                //aperale functie view customers
                                break;
                            }
                            case 6: {
                                //aperale functie search customer by email
                                break;
                            }
                            case 7: {
                                //aperale functie search customer by phone
                                break;
                            }
                            case 8: {
                                //aperale functie search customer by name
                                break;
                            }
                            case 9: {
                                //aperale functie search customer by ordered car
                                break;
                            }
                            default: {
                                cout << "Choose a valid option: ";
                            }
                        }
                        break;
                    }
                    case 4: {
                        cout
                                << "Choose option:\n1. Create car\n2. Change car\n3. Delete car\n4. Deactivate car\n5. View cars for a specific date\n6. Search car by license plate\n7. View ordered cars\n0. Back\nType an option: ";
                        int opt2 = options();
                        switch (opt2) {
                            case 0:
                                break;
                            case 1: {
                                string brand, model, licensePlate, fuelType, gearbox, color, remarks;
                                int registrationYear, mileage, dailyPrice;
                                cout << "Brand: ";
                                getline(cin, brand);
                                cout << "Model: ";
                                getline(cin, model);
                                cout << "License plate: ";
                                getline(cin, licensePlate);
                                while (!ctrl->validateLicensePlate(licensePlate)) {
                                    cout << "Invalid license plate! Enter a valid license plate: ";
                                    getline(cin, licensePlate);
                                }
                                licensePlate = ctrl->modifyLicensePlate(licensePlate);
                                cout << "Registration year: ";
                                cin >> registrationYear;
                                while (!ctrl->validateRegistrationYear(registrationYear)) {
                                    cout << "Invalid registration year! Enter a valid registration year: ";
                                    cin >> registrationYear;
                                }
                                cout << "Mileage: ";
                                cin >> mileage;
                                while (!ctrl->validateMileage(mileage)) {
                                    cout << "Invalid mileage! Enter a valid mileage: ";
                                    cin >> mileage;
                                }
                                cout << "Fuel type: ";
                                getline(cin, fuelType);
                                cout << "Gearbox: ";
                                getline(cin, gearbox);
                                cout << "Color: ";
                                getline(cin, color);
                                cout << "Daily price: ";
                                cin >> dailyPrice;
                                while (!ctrl->validateDailyPrice(dailyPrice)) {
                                    cout << "Invalid daily price! Enter a valid daily price: ";
                                    cin >> dailyPrice;
                                }
                                cout << "Remarks: ";
                                getline(cin, remarks);
                                ctrl->addCar(true, licensePlate, model, brand, registrationYear, mileage, dailyPrice,
                                             fuelType, gearbox, color, remarks);
                                cout << "Car created.";
                                break;
                            }
                            case 2: {
                                string brand, model, licensePlate, fuelType, gearbox, color, remarks;
                                int id, registrationYear, mileage, dailyPrice;
                                cout << "ID: ";
                                cin >> id;
                                while (!ctrl->validateID(id)) {
                                    cout << "Invalid ID! Enter a valid ID: ";
                                    cin >> id;
                                }
                                cout << "Brand: ";
                                getline(cin, brand);
                                cout << "Model: ";
                                getline(cin, model);
                                cout << "License plate: ";
                                getline(cin, licensePlate);
                                while (!ctrl->validateLicensePlate(licensePlate)) {
                                    cout << "Invalid license plate! Enter a valid license plate: ";
                                    getline(cin, licensePlate);
                                }
                                licensePlate = ctrl->modifyLicensePlate(licensePlate);
                                cout << "Registration year: ";
                                cin >> registrationYear;
                                while (!ctrl->validateRegistrationYear(registrationYear)) {
                                    cout << "Invalid registration year! Enter a valid registration year: ";
                                    cin >> registrationYear;
                                }
                                cout << "Mileage: ";
                                cin >> mileage;
                                while (!ctrl->validateMileage(mileage)) {
                                    cout << "Invalid mileage! Enter a valid mileage: ";
                                    cin >> mileage;
                                }
                                cout << "Fuel type: ";
                                getline(cin, fuelType);
                                cout << "Gearbox: ";
                                getline(cin, gearbox);
                                cout << "Color: ";
                                getline(cin, color);
                                cout << "Daily price: ";
                                cin >> dailyPrice;
                                while (!ctrl->validateDailyPrice(dailyPrice)) {
                                    cout << "Invalid daily price! Enter a valid daily price: ";
                                    cin >> dailyPrice;
                                }
                                cout << "Remarks: ";
                                getline(cin, remarks);
                                ctrl->updateCar(id, true, licensePlate, model, brand, registrationYear, mileage,
                                                dailyPrice, fuelType, gearbox, color, remarks);
                                cout << "Car updated.";
                                break;
                            }
                            case 3: {
                                //aperale functie delete car
                                int id;
                                cout << "ID: ";
                                cin >> id;
                                while (!ctrl->validateID(id)) {
                                    cout << "Invalid ID! Enter a valid ID: ";
                                    cin >> id;
                                }
                                ctrl->deleteCar(id);
                                cout << "Car deleted.";
                                break;
                            }
                            case 4: {
                                //aperale functie deactivate car
                                int id;
                                cout << "ID: ";
                                cin >> id;
                                while (!ctrl->validateID(id)) {
                                    cout << "Invalid ID! Enter a valid ID: ";
                                    cin >> id;
                                }
                                ctrl->deactivate(id);
                                cout << "Car deactivated";
                                break;
                            }
                            case 5: {
                                string begin, end;
                                cout << "From: ";
                                getline(cin, begin);
                                cout << "To: ";
                                getline(cin, end);
                                vector<Car> carList = ctrl->notOrderedCars(begin, end);
                                for (auto &car: carList) {
                                    cout << car.get_brand() << ' ' << car.get_model() << ' ' << car.get_gearbox() << ' '
                                         << car.get_dailyPrice() << endl;
                                }
                                break;
                            }
                            case 6: {
                                string licensePlate;
                                cout << "License plate: ";
                                getline(cin, licensePlate);
                                Car searchedCar = ctrl->findCarByLicensePlate(licensePlate);
                                cout << searchedCar.get_brand() << ' ' << searchedCar.get_model() << ' '
                                     << searchedCar.get_gearbox() << ' ' << searchedCar.get_dailyPrice() << endl;
                                break;
                            }
                            case 7: {
                                int custID;
                                cout << "Customer ID: ";
                                cin >> custID;
                                vector<Car> carList = ctrl->orderedCars(custID);
                                for (auto &car: carList) {
                                    cout << car.get_brand() << ' ' << car.get_model() << ' ' << car.get_gearbox() << ' '
                                         << car.get_dailyPrice() << endl;
                                }
                                break;
                            }
                            default: {
                                cout << "Choose a valid option: ";
                            }
                        }
                        break;
                    }
                    case 5: {
                        cout
                                << "Choose option:\n1. Create order\n2. Change reservation to order\n3. Change order\n4. Complete order\n5. Retrieve order from another employee\n6. Give order to another employee\n7.Create reservation\n8.Delete reservation\n9.Change reservation\n10. View orders for a specific date\n11.Search order by nr\n12. See total price\n";
                        if (false)
                            cout << "13. Change order\n";
                        cout << "0. Back\nType an option: ";
                        int opt2 = options();
                        switch (opt2) {
                            case 0:
                                break;
                            case 1: {
                                //apelare functie create order
                                break;
                            }
                            case 2: {
                                //aperale functie change reservation
                                break;
                            }
                            case 3: {
                                //aperale functie change order
                                break;
                            }
                            case 4: {
                                //aperale functie complete order
                                break;
                            }
                            case 5: {
                                //aperale functie retrieve order from another employee
                                break;
                            }
                            case 6: {
                                //aperale functie give order to another employee
                                break;
                            }
                            case 7: {
                                //aperale functie create reservation
                                break;
                            }
                            case 8: {
                                //aperale functie delete reservation
                                break;
                            }
                            case 9: {
                                //aperale functie change reservation
                                break;
                            }
                            case 10: {
                                //apelare functie view orders for specific date
                                break;
                            }
                            case 11: {
                                //apelare functie search order by nr
                                break;
                            }
                            case 12: {
                                //apelare functie see total price
                                break;
                            }
                            default: {
                                cout << "Choose a valid option: ";
                            }
                                break;
                        }
                        break;
                    }
                    default: {
                        cout << "Choose a valid option: ";
                    }
                }
            }
        } else if (mainOpt == 0) {
            mainRun = false;
        } else cout << "Invalid option!\nChoose a valid option: ";
    }

}