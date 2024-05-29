
//
// Created by nagyb on 5/23/2024.
//

#include "UI.h"
#include <iostream>
#include <utility>
#include <string.h>
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
//    getline(cin,email);
    cin>>email;
    cout<<endl;
    cout<<"Type in your password: ";
//    getline(cin,password);
    cin>>password;
    cout<<endl;
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
                                mainRun= false;
                                run= false;
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
                                run = false;
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
                                run = false;
                                break;
                            case 1: {

                                int idOrder;
                                string dateOrder,statusOrder,beginOrder, endOrder, observationsOrder;
                                float billOrder;
                                int carId;
                                int customerId;
                                int employeeId;

                                cout<< "Enter Id of the Order: \n";
                                cin >> idOrder;
                                cout<< "\n Enter date of the Order: \n";
                                getline(cin,dateOrder);
                                statusOrder = "Reservation";
                                cout << "\n Enter begin order: \n";
                                cin >> beginOrder;
                                cout << "\n Enter end order: \n";
                                cin >> endOrder;
                                cout << "\n Enter observations order: \n";
                                getline(cin,observationsOrder);
                                cout << "\n Enter bill order: \n";
                                cin >> billOrder;



                                vector<Employee> vec_employee = ctrl->getAllEmployees();
                                for(int i = 0;  i<vec_employee.size(); i++){
                                    cout << vec_employee[i].getId() << ". " <<vec_employee[i].getFirstName() <<'\n';
                                }
                                cout<< "Pick Id Employee: ";
                                int decizieEmplyee;
                                cin>>decizieEmplyee;
                                Employee employe = ctrl->getEmployeeById(decizieEmplyee);


                                vector<Car> vec_car = ctrl->listallCars();
                                for(int i = 0;  i<vec_car.size(); i++){
                                    cout << vec_car[i].get_id() << ". " <<vec_car[i].get_model() <<'\n';
                                }
                                cout<< "Pick Id Employee: ";
                                int decizieCar;
                                cin>>decizieCar;
                                Car car = ctrl->returnCarbyID(decizieCar);

                                vector<customer> vec_cust = ctrl->getAllCustomer();
                                for(int i = 0;  i<vec_cust.size(); i++){
                                    cout << vec_cust[i].getCustomerID() << ". " <<vec_cust[i].getCustomerName().firstName<< ' '<<vec_cust[i].getCustomerName().lastName <<'\n';
                                }
                                cout<< "Pick Id Employee: ";
                                int decizieCustomer;
                                cin>>decizieCustomer;
                                customer customer = ctrl->getCustomerByID(decizieCustomer);

                                ctrl->addOrder(dateOrder,statusOrder,beginOrder, endOrder, billOrder, observationsOrder,
                                               car,customer, employe);

                                break;
                            }
                            case 2: {
                                //aperale functie delete reservation
                                int oldIdOrder;
                                vector<Order> vec_order = ctrl->listAllOrders();
                                for(int i = 0; i < vec_order.size(); i++){
                                    cout << vec_order[i].getIdOrder()<< ". " << vec_order[i].getCustomerOrder().getCustomerName().firstName<<' '<< vec_order[i].getCustomerOrder().getCustomerName().lastName<<'\n';
                                }
                                int decizieOrderId;
                                cout<< "Enter the order ID you want to change: ";
                                cin>>decizieOrderId;

                                Order ord1 = ctrl->getOrderById(decizieOrderId);
                                int employeeId = ord1.getWorkerOrder().getId();

                                string role = "Employee";
                                ctrl->deleteReservation(decizieOrderId,employeeId,role);
                                break;
                            }
                            case 3: {
                                //ctrl.changeReservation();
                                int oldIdOrder;
                                vector<Order> vec_order = ctrl->listAllOrders();
                                for(int i = 0; i < vec_order.size(); i++){
                                    if (vec_order[i].getStatusOrder()=="Reservation")
                                        cout << vec_order[i].getIdOrder()<< ". " << vec_order[i].getCustomerOrder().getCustomerName().firstName<<' '<< vec_order[i].getCustomerOrder().getCustomerName().lastName<<'\n';
                                }
                                int decizieOrderId;
                                ctrl->convertReservationToOrder(decizieOrderId);

                                break;
                            }
                            case 4: {
                                //ctrl.viewOrderForSpecificDate();
                                string startDate;
                                string endDate;
                                cout<< "\n Enter start date\n";
                                getline(cin,startDate);
                                cout<< "\n Enter end date\n";
                                getline(cin,endDate);
                                vector<Order> vec_orders = ctrl->getOrdersByDate(startDate,endDate);
                                for(int i = 0; i<vec_orders.size(); i++){
                                    cout<< vec_orders[i].getIdOrder()<< ' '<< vec_orders[i].getCarOrder().get_model()<< ' '<< vec_orders[i].getCustomerOrder().getCustomerName().firstName<< ' '<<vec_orders[i].getCustomerOrder().getCustomerName().lastName<<'\n';
                                }
                                break;

                            }
                            case 5: {
                                //ctrl.searchOrderByNumber();
                                int oldIdOrder;
                                vector<Order> vec_order = ctrl->listAllOrders();
                                for(int i = 0; i < vec_order.size(); i++){
                                    cout << vec_order[i].getIdOrder()<< ". " << vec_order[i].getCustomerOrder().getCustomerName().firstName<<' '<< vec_order[i].getCustomerOrder().getCustomerName().lastName<<'\n';
                                }
                                int decizieOrderId;
                                cout<< "Enter the order ID you want to change: ";
                                cin>>decizieOrderId;
                                Order order1 = ctrl->getOrderById(decizieOrderId);
                                cout<< order1.getCustomerOrder().getCustomerName().firstName<< ' '<< order1.getCustomerOrder().getCustomerName().lastName<< ' '<<order1.getCarOrder().get_model();
                                break;

                            }
                            case 6: {
                                //ctrl.seeTotalPrice();
                                string date;
                                cout<< "\n Enter date\n";
                                getline(cin,date);
                                cout<< "Total sum: "<< ctrl->getTotalSumOfADate(date)<<'\n';

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
                        mainRun= false;
                        break;
                    }
                    case 1: {
                        cout << "Choose option:\n1. Change password\n2. Change remarks;\n 0. Back\nType an option: ";
                        int opt2 = options();
                        switch (opt2) {
                            case 0:
                                run = false;
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
                                run = false;
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
                                cout << "Enter ID: ";
                                int id;
                                cin >> id;
                                cin.ignore();

                                cout << "Enter password: ";
                                string password;
                                getline(cin, password);

                                cout << "Enter nickname: ";
                                string nickname;
                                getline(cin, nickname);

                                cout << "Enter last name: ";
                                string lastName;
                                getline(cin, lastName);

                                cout << "Enter first name: ";
                                string firstName;
                                getline(cin, firstName);

                                cout << "Enter email: ";
                                string email;
                                getline(cin, email);

                                cout << "Enter position: ";
                                string position;
                                getline(cin, position);

                                cout << "Enter birthdate: ";
                                string birthDate;
                                getline(cin, birthDate);

                                cout << "Enter salary: ";
                                int salary;
                                cin >> salary;
                                cin.ignore();

                                cout << "Enter remarks: ";
                                string remarks;
                                getline(cin, remarks);

                                ctrl->addEmployee(id, password, nickname, lastName, firstName, email, position, birthDate, salary, remarks);
                                cout << "Employee created successfully." << endl;
                                break;
                            }
                            case 7:{
                                //change employee
                                cout << "Enter employee ID to update: ";
                                int id;
                                cin >> id;
                                cin.ignore();

                                Employee emp = ctrl->getEmployeeById(id);
                                size_t password = emp.getPassword();
                                string passw=std::to_string(password);

                                cout << "Enter new nickname: ";
                                string nickname;
                                getline(cin, nickname);

                                cout << "Enter new last name: ";
                                string lastName;
                                getline(cin, lastName);

                                cout << "Enter new first name: ";
                                string firstName;
                                getline(cin, firstName);

                                cout << "Enter new birthdate: ";
                                string birthDate;
                                getline(cin, birthDate);

                                cout << "Enter new salary: ";
                                int salary;
                                cin >> salary;
                                cin.ignore();

                                ctrl->updateEmployee(id, passw, nickname, lastName, firstName, emp.getPosition(), birthDate, salary, emp.getRemarks());
                                cout << "Employee updated successfully." << endl;
                                break;

                            }
                            case 8:{
                                //act/deac

                            }
                            case 9:{
                                //delete emp
                                cout << "Enter employee ID to delete: ";
                                int id;
                                cin >> id;
                                ctrl->deleteEmployee(id);
                                cout << "Employee deleted successfully." << endl;
                                break;

                            }
                            case 10:{
                                //change emp to admin
                                cout << "Enter employee ID to change to admin: ";
                                int id;
                                cin >> id;
                                Employee emp = ctrl->getEmployeeById(id);
                                size_t password = emp.getPassword();
                                string passw=std::to_string(password);
                                ctrl->updateEmployee(id, passw, emp.getNickname(), emp.getLastName(), emp.getFirstName(), "admin", emp.getBirthDate(), emp.getSalary(), emp.getRemarks());
                                cout << "Employee changed to Admin successfully." << endl;
                                break;

                            }
                            case 11:{
                                //change admin to emp
                                cout << "Enter admin ID to change to employee: ";
                                int id;
                                cin >> id;
                                Employee emp = ctrl->getEmployeeById(id);
                                size_t password = emp.getPassword();
                                string passw=std::to_string(password);
                                ctrl->updateEmployee(id, passw, emp.getNickname(), emp.getLastName(), emp.getFirstName(), "employee", emp.getBirthDate(), emp.getSalary(), emp.getRemarks());
                                cout << "Admin changed to employee successfully." << endl;
                                break;

                            }
                            case 12:{
                                //reset passw for emp
                                cout << "Enter employee ID to reset password: ";
                                int id;
                                cin >> id;
                                cin.ignore();

                                cout << "Enter new password: ";
                                string newPassword;
                                getline(cin, newPassword);

                                Employee emp = ctrl->getEmployeeById(id);
                                ctrl->updateEmployee(id, newPassword, emp.getNickname(), emp.getLastName(), emp.getFirstName(), emp.getPosition(), emp.getBirthDate(), emp.getSalary(), emp.getRemarks());
                                cout << "Password reset successfully." << endl;
                                break;


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
                                run = false;
                                break;
                            case 1: {
                                string first, last, mailAdd, mailPass, city, country, street, phone, note;
                                int streetNum;
                                bool gdpr;
                                vector<int> favorites;
                                cout << "Enter your First and Last name: ";
                                getline(cin, first);
                                getline(cin, last);
                                cout<<endl;
                                cout << "Enter email: ";
                                getline(cin, mailAdd);
                                cout<<endl;
                                cout << "Enter password: ";
                                getline(cin, mailPass);
                                cout<<endl;
                                cout << "Country of costumer:";
                                getline(cin, country);
                                cout<<endl;
                                cout << "City of costumer:";
                                getline(cin, city);
                                cout<<endl;
                                cout << "Street of costumer:";
                                getline(cin, street);
                                cout<<endl;
                                cout << "Number of house of costumer:";
                                cin >> streetNum;
                                cout<<endl;
                                cout << "Phone number of costumer:";
                                getline(cin, phone);
                                cout<<endl;
                                cout << "Note about costumer:";
                                getline(cin, note);
                                cout<<endl;

//                                ctrl->createCustomer()

                                //apelare functie create customer
                                ctrl->createCustomer({first,last}, {mailAdd, mailPass}, {country, city, street, streetNum},phone, note, gdpr, favorites);
                                break;



                                //apelare functie create customer

                            }
                            case 2: {
                                //aperale functie change customer
                                string first, last, mailAdd, mailPass, city, country, street, phone, note;
                                int streetNum;
                                bool gdpr;
                                vector<int> favorites;
                                cout << "Enter your First and Last name: ";
                                getline(cin, first);
                                getline(cin, last);
                                cout<<endl;
                                cout << "Enter email: ";
                                getline(cin, mailAdd);
                                cout<<endl;
                                cout << "Enter password: ";
                                getline(cin, mailPass);
                                cout<<endl;
                                cout << "Country of costumer:";
                                getline(cin, country);
                                cout<<endl;
                                cout << "City of costumer:";
                                getline(cin, city);
                                cout<<endl;
                                cout << "Street of costumer:";
                                getline(cin, street);
                                cout<<endl;
                                cout << "Number of house of costumer:";
                                cin >> streetNum;
                                cout<<endl;
                                cout << "Phone number of costumer:";
                                getline(cin, phone);
                                cout<<endl;
                                cout << "Note about costumer:";
                                getline(cin, note);
                                cout<<endl;
//                                ctrl->ChangeCustomer(first, last, mailAdd, mailPass, city, country, street, phone, note)
                                break;
                            }
                            case 3: {
                                //aperale functie delete customer
                                string email;
                                cout << "Give the email to delete a customer: ";
                                getline(cin, email);
                                cout << endl;
                                ctrl->customerDelete(email);
                                break;
                            }
                            case 4: {
                                //aperale functie anonymise customer
                                break;
                            }
                            case 5: {
                                //aperale functie view customers
                                string option;
                                cout << "Give a preference whichby to show the customers(first/last): ";
                                getline(cin, option);
                                cout<<endl;
                                ctrl->ListAllCostumersSortedByName(option);
                                break;
                            }
                            case 6: {
                                //aperale functie search customer by email
                                string email, password;
                                cout << "Search by email: ";
                                getline(cin, email);
                                cout<<endl;
                                cout << "Give password: ";
                                getline(cin, password);
                                ctrl->findCustomerByEmailandPassword(email, password);
                                break;
                            }
                            case 7: {
                                //aperale functie search customer by phone
                                string Phone_nr;
                                cout << "Give searched phone number: ";
                                getline(cin, Phone_nr);
                                cout<<endl;
                                ctrl->FindCustomerByPhoneNr(Phone_nr);
                                break;
                            }
                            case 8: {
                                //aperale functie search customer by name
                                string first, last;
                                cout << "Given first name: ";
                                getline(cin, first);
                                cout<<endl;
                                cout << "Last name: ";
                                getline(cin, last);
                                cout << endl;
                                ctrl->FindCustomerByName({first, last});
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
                                run = false;
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
                                run = false;
                                break;
                            case 1: {
                                //apelare functie create order

                                int idOrder;
                                string dateOrder,statusOrder,beginOrder, endOrder, observationsOrder;
                                float billOrder;
                                int carId;
                                int customerId;
                                int employeeId;

                                cout<< "Enter Id of the Order: \n";
                                cin >> idOrder;
                                cout<< "\n Enter date of the Order: \n";
                                getline(cin,dateOrder);
                                cout << "\n Enter status order: (Completed/ Reservation/ new): ";
                                cin >> statusOrder;
                                cout << "\n Enter begin order: \n";
                                cin >> beginOrder;
                                cout << "\n Enter end order: \n";
                                cin >> endOrder;
                                cout << "\n Enter observations order: \n";
                                getline(cin,observationsOrder);
                                cout << "\n Enter bill order: \n";
                                cin >> billOrder;



                                vector<Employee> vec_employee = ctrl->getAllEmployees();
                                for(int i = 0;  i<vec_employee.size(); i++){
                                    cout << vec_employee[i].getId() << ". " <<vec_employee[i].getFirstName() <<'\n';
                                }
                                cout<< "Pick Id Employee: ";
                                int decizieEmplyee;
                                cin>>decizieEmplyee;
                                Employee employe = ctrl->getEmployeeById(decizieEmplyee);


                                vector<Car> vec_car = ctrl->listallCars();
                                for(int i = 0;  i<vec_car.size(); i++){
                                    cout << vec_car[i].get_id() << ". " <<vec_car[i].get_model() <<'\n';
                                }
                                cout<< "Pick Id Employee: ";
                                int decizieCar;
                                cin>>decizieCar;
                                Car car = ctrl->returnCarbyID(decizieCar);

                                vector<customer> vec_cust = ctrl->getAllCustomer();
                                for(int i = 0;  i<vec_cust.size(); i++){
                                    cout << vec_cust[i].getCustomerID() << ". " <<vec_cust[i].getCustomerName().firstName<< ' '<<vec_cust[i].getCustomerName().lastName <<'\n';
                                }
                                cout<< "Pick Id Employee: ";
                                int decizieCustomer;
                                cin>>decizieCustomer;
                                customer customer = ctrl->getCustomerByID(decizieCustomer);

                                ctrl->addOrder(dateOrder,statusOrder,beginOrder, endOrder, billOrder, observationsOrder,
                                               car,customer, employe);
                                break;
                            }
                            case 2: {
                                //aperale functie change reservation
                                int oldIdOrder;
                                vector<Order> vec_order = ctrl->listAllOrders();
                                for(int i = 0; i < vec_order.size(); i++){
                                    if (vec_order[i].getStatusOrder()=="Reservation")
                                        cout << vec_order[i].getIdOrder()<< ". " << vec_order[i].getCustomerOrder().getCustomerName().firstName<<' '<< vec_order[i].getCustomerOrder().getCustomerName().lastName<<'\n';
                                }
                                int decizieOrderId;
                                ctrl->convertReservationToOrder(decizieOrderId);
                                break;
                            }
                            case 3: {
                                int oldIdOrder;
                                vector<Order> vec_order = ctrl->listAllOrders();
                                for(int i = 0; i < vec_order.size(); i++){
                                    cout << vec_order[i].getIdOrder()<< ". " << vec_order[i].getCustomerOrder().getCustomerName().firstName<<' '<< vec_order[i].getCustomerOrder().getCustomerName().lastName<<'\n';
                                }
                                int decizieOrderId;
                                cout<< "Enter the order ID you want to change: ";
                                cin>>decizieOrderId;

                                int idOrder;
                                string dateOrder,statusOrder,beginOrder, endOrder, observationsOrder;
                                float billOrder;
                                int carId;
                                int customerId;
                                int employeeId;

                                cout<< "Enter Id of the Order: \n";
                                cin >> idOrder;
                                cout<< "\n Enter date of the Order: \n";
                                getline(cin,dateOrder);
                                cout << "\n Enter status order: (Completed/ Reservation/ new): ";
                                cin >> statusOrder;
                                cout << "\n Enter begin order: \n";
                                cin >> beginOrder;
                                cout << "\n Enter end order: \n";
                                cin >> endOrder;
                                cout << "\n Enter observations order: \n";
                                getline(cin,observationsOrder);
                                cout << "\n Enter bill order: \n";
                                cin >> billOrder;



                                vector<Employee> vec_employee = ctrl->getAllEmployees();
                                for(int i = 0;  i<vec_employee.size(); i++){
                                    cout << vec_employee[i].getId() << ". " <<vec_employee[i].getFirstName() <<'\n';
                                }
                                cout<< "Pick Id Employee: ";
                                int decizieEmplyee;
                                cin>>decizieEmplyee;
                                Employee employe = ctrl->getEmployeeById(decizieEmplyee);


                                vector<Car> vec_car = ctrl->listallCars();
                                for(int i = 0;  i<vec_car.size(); i++){
                                    cout << vec_car[i].get_id() << ". " <<vec_car[i].get_model() <<'\n';
                                }
                                cout<< "Pick Id Employee: ";
                                int decizieCar;
                                cin>>decizieCar;
                                Car car = ctrl->returnCarbyID(decizieCar);

                                vector<customer> vec_cust = ctrl->getAllCustomer();
                                for(int i = 0;  i<vec_cust.size(); i++){
                                    cout << vec_cust[i].getCustomerID() << ". " <<vec_cust[i].getCustomerName().firstName<< ' '<<vec_cust[i].getCustomerName().lastName <<'\n';
                                }
                                cout<< "Pick Id Employee: ";
                                int decizieCustomer;
                                cin>>decizieCustomer;
                                customer customer = ctrl->getCustomerByID(decizieCustomer);

                                Order newOrder(idOrder,dateOrder,statusOrder,beginOrder, endOrder, billOrder, observationsOrder,
                                               car,customer, employe);

                                ctrl->updateOrder(decizieOrderId,newOrder);

                                break;
                            }
                            case 4: {
                                int oldIdOrder;
                                vector<Order> vec_order = ctrl->listAllOrders();
                                for(int i = 0; i < vec_order.size(); i++){
                                    cout << vec_order[i].getIdOrder()<< ". " << vec_order[i].getCustomerOrder().getCustomerName().firstName<<' '<< vec_order[i].getCustomerOrder().getCustomerName().lastName<<'\n';
                                }
                                int decizieOrderId;
                                cout<< "Enter the order ID you want to change: ";
                                cin>>decizieOrderId;
                                ctrl->completeOrder(decizieOrderId);
                                break;
                            }
                            case 5: {
                                //aperale functie retrieve order from another employee
                                int oldIdOrder;
                                vector<Order> vec_order = ctrl->listAllOrders();
                                for(int i = 0; i < vec_order.size(); i++){
                                    cout << vec_order[i].getIdOrder()<< ". " << vec_order[i].getCustomerOrder().getCustomerName().firstName<<' '<< vec_order[i].getCustomerOrder().getCustomerName().lastName<<'\n';
                                }
                                int decizieOrderId;
                                cout<< "Enter the order ID you want to change: ";
                                cin>>decizieOrderId;

                                vector<Employee> vec_cust = ctrl->getAllEmployees();
                                for(int i = 0;  i<vec_cust.size(); i++){
                                    cout << vec_cust[i].getId() << ". " <<vec_cust[i].getFirstName() <<'\n';
                                }
                                cout<< "Pick Id Employee: ";
                                int decizieEmplyee;
                                cin>>decizieEmplyee;
                                Employee newEmployee = ctrl->getEmployeeById(decizieEmplyee);

                                ctrl->takeOverOrder(decizieOrderId, newEmployee);

                                break;
                            }
                            case 6: {
                                //aperale functie give order to another employee
                                int oldIdOrder;
                                vector<Order> vec_order = ctrl->listAllOrders();
                                for(int i = 0; i < vec_order.size(); i++){
                                    cout << vec_order[i].getIdOrder()<< ". " << vec_order[i].getCustomerOrder().getCustomerName().firstName<<' '<< vec_order[i].getCustomerOrder().getCustomerName().lastName<<'\n';
                                }
                                int decizieOrderId;
                                cout<< "Enter the order ID you want to change: ";
                                cin>>decizieOrderId;

                                vector<Employee> vec_cust = ctrl->getAllEmployees();
                                for(int i = 0;  i<vec_cust.size(); i++){
                                    cout << vec_cust[i].getId() << ". " <<vec_cust[i].getFirstName() <<'\n';
                                }
                                cout<< "Pick Id Employee: ";
                                int decizieEmplyee;
                                cin>>decizieEmplyee;
                                Employee newEmployee = ctrl->getEmployeeById(decizieEmplyee);

                                ctrl->assignOrder(decizieOrderId, newEmployee);
                                break;
                            }
                            case 7: {
                                //apelare functie create reservation

                                int idOrder;
                                string dateOrder,statusOrder,beginOrder, endOrder, observationsOrder;
                                float billOrder;
                                int carId;
                                int customerId;
                                int employeeId;

                                cout<< "Enter Id of the Order: \n";
                                cin >> idOrder;
                                cout<< "\n Enter date of the Order: \n";
                                getline(cin,dateOrder);
                                statusOrder = "Reservation";
                                cout << "\n Enter begin order: \n";
                                cin >> beginOrder;
                                cout << "\n Enter end order: \n";
                                cin >> endOrder;
                                cout << "\n Enter observations order: \n";
                                getline(cin,observationsOrder);
                                cout << "\n Enter bill order: \n";
                                cin >> billOrder;



                                vector<Employee> vec_employee = ctrl->getAllEmployees();
                                for(int i = 0;  i<vec_employee.size(); i++){
                                    cout << vec_employee[i].getId() << ". " <<vec_employee[i].getFirstName() <<'\n';
                                }
                                cout<< "Pick Id Employee: ";
                                int decizieEmplyee;
                                cin>>decizieEmplyee;
                                Employee employe = ctrl->getEmployeeById(decizieEmplyee);


                                vector<Car> vec_car = ctrl->listallCars();
                                for(int i = 0;  i<vec_car.size(); i++){
                                    cout << vec_car[i].get_id() << ". " <<vec_car[i].get_model() <<'\n';
                                }
                                cout<< "Pick Id Employee: ";
                                int decizieCar;
                                cin>>decizieCar;
                                Car car = ctrl->returnCarbyID(decizieCar);

                                vector<customer> vec_cust = ctrl->getAllCustomer();
                                for(int i = 0;  i<vec_cust.size(); i++){
                                    cout << vec_cust[i].getCustomerID() << ". " <<vec_cust[i].getCustomerName().firstName<< ' '<<vec_cust[i].getCustomerName().lastName <<'\n';
                                }
                                cout<< "Pick Id Employee: ";
                                int decizieCustomer;
                                cin>>decizieCustomer;
                                customer customer = ctrl->getCustomerByID(decizieCustomer);

                                ctrl->addOrder(dateOrder,statusOrder,beginOrder, endOrder, billOrder, observationsOrder,
                                               car,customer, employe);
                                break;
                            }

                            case 8: {
                                //aperale functie delete reservation
                                int oldIdOrder;
                                vector<Order> vec_order = ctrl->listAllOrders();
                                for(int i = 0; i < vec_order.size(); i++){
                                    cout << vec_order[i].getIdOrder()<< ". " << vec_order[i].getCustomerOrder().getCustomerName().firstName<<' '<< vec_order[i].getCustomerOrder().getCustomerName().lastName<<'\n';
                                }
                                int decizieOrderId;
                                cout<< "Enter the order ID you want to change: ";
                                cin>>decizieOrderId;

                                Order ord1 = ctrl->getOrderById(decizieOrderId);
                                int employeeId = ord1.getWorkerOrder().getId();

                                string role = "Employee";
                                ctrl->deleteReservation(decizieOrderId,employeeId,role);

                                break;
                            }
                            case 9: {
                                //aperale functie change reservation
                                int oldIdOrder;
                                vector<Order> vec_order = ctrl->listAllOrders();
                                for(int i = 0; i < vec_order.size(); i++){
                                    cout << vec_order[i].getIdOrder()<< ". " << vec_order[i].getCustomerOrder().getCustomerName().firstName<<' '<< vec_order[i].getCustomerOrder().getCustomerName().lastName<<'\n';
                                }
                                int decizieOrderId;
                                cout<< "Enter the reservation ID you want to change: ";
                                cin>>decizieOrderId;

                                Order ord1 = ctrl->getOrderById(decizieOrderId);
                                int employeeId = ord1.getWorkerOrder().getId();
                                Employee employee= ctrl->getEmployeeById(employeeId);

                                string role = "Employee";

                                cout<< "Enter the order ID you want to change: ";
                                cin>>decizieOrderId;

                                int idOrder;
                                string dateOrder,statusOrder,beginOrder, endOrder, observationsOrder;
                                float billOrder;
                                int carId;
                                int customerId;


                                cout<< "Enter Id of the Order: \n";
                                cin >> idOrder;
                                cout<< "\n Enter date of the Order: \n";
                                getline(cin,dateOrder);
                                cout << "\n Enter status order: (Completed/ Reservation/ new): ";
                                cin >> statusOrder;
                                cout << "\n Enter begin order: \n";
                                cin >> beginOrder;
                                cout << "\n Enter end order: \n";
                                cin >> endOrder;
                                cout << "\n Enter observations order: \n";
                                getline(cin,observationsOrder);
                                cout << "\n Enter bill order: \n";
                                cin >> billOrder;



                                vector<Car> vec_car = ctrl->listallCars();
                                for(int i = 0;  i<vec_car.size(); i++){
                                    cout << vec_car[i].get_id() << ". " <<vec_car[i].get_model() <<'\n';
                                }
                                cout<< "Pick Id Employee: ";
                                int decizieCar;
                                cin>>decizieCar;
                                Car car = ctrl->returnCarbyID(decizieCar);

                                vector<customer> vec_cust = ctrl->getAllCustomer();
                                for(int i = 0;  i<vec_cust.size(); i++){
                                    cout << vec_cust[i].getCustomerID() << ". " <<vec_cust[i].getCustomerName().firstName<< ' '<<vec_cust[i].getCustomerName().lastName <<'\n';
                                }
                                cout<< "Pick Id Customer: ";
                                int decizieCustomer;
                                cin>>decizieCustomer;
                                customer customer = ctrl->getCustomerByID(decizieCustomer);

                                Order newOrder(idOrder,dateOrder,statusOrder,beginOrder, endOrder, billOrder, observationsOrder,
                                               car,customer, employee);

                                ctrl->updateReservation(decizieOrderId,employeeId,role,newOrder);

                                break;
                            }
                            case 10: {
                                //apelare functie view orders for specific date
                                string startDate;
                                string endDate;
                                cout<< "\n Enter start date\n";
                                getline(cin,startDate);
                                cout<< "\n Enter end date\n";
                                getline(cin,endDate);
                                vector<Order> vec_orders = ctrl->getOrdersByDate(startDate,endDate);
                                for(int i = 0; i<vec_orders.size(); i++){
                                    cout<< vec_orders[i].getIdOrder()<< ' '<< vec_orders[i].getCarOrder().get_model()<< ' '<< vec_orders[i].getCustomerOrder().getCustomerName().firstName<< ' '<<vec_orders[i].getCustomerOrder().getCustomerName().lastName<<'\n';
                                }
                                break;
                            }
                            case 11: {
                                //apelare functie search order by nr
                                int oldIdOrder;
                                vector<Order> vec_order = ctrl->listAllOrders();
                                for(int i = 0; i < vec_order.size(); i++){
                                    cout << vec_order[i].getIdOrder()<< ". " << vec_order[i].getCustomerOrder().getCustomerName().firstName<<' '<< vec_order[i].getCustomerOrder().getCustomerName().lastName<<'\n';
                                }
                                int decizieOrderId;
                                cout<< "Enter the order ID you want to change: ";
                                cin>>decizieOrderId;
                                Order order1 = ctrl->getOrderById(decizieOrderId);
                                cout<< order1.getCustomerOrder().getCustomerName().firstName<< ' '<< order1.getCustomerOrder().getCustomerName().lastName<< ' '<<order1.getCarOrder().get_model();
                                break;
                            }
                            case 12: {
                                string date;
                                cout<< "\n Enter date\n";
                                getline(cin,date);
                                cout<< "Total sum: "<< ctrl->getTotalSumOfADate(date)<<'\n';

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