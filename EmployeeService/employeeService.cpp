#include "EmployeeService.h"

EmployeeService::EmployeeService(const string &dbFilePath) : dbFilePath(dbFilePath) {
    loadFromJson();
}

void EmployeeService::loadFromJson() {
    ifstream inFile(dbFilePath);
    if (inFile.is_open()) {
        json j;
        inFile >> j;
        for (const auto &item : j) {
            Employee emp(item["password"], item["lastName"], item["firstName"], item["email"],
                         item["position"], item["birthDate"], item["abbreviation"], item["salary"], item["remarks"]);
            employees.push_back(emp);
        }
        inFile.close();
    }
}

void EmployeeService::saveToJson() const {
    json j;
    for (const auto &emp : employees) {
        j.push_back({
                            {"password", emp.getPassword()},
                            {"lastName", emp.getLastName()},
                            {"firstName", emp.getFirstName()},
                            {"email", emp.getEmail()},
                            {"position", emp.getPosition()},
                            {"birthDate", emp.getBirthDate()},
                            {"abbreviation", emp.getAbbreviation()},
                            {"salary", emp.getSalary()},
                            {"remarks", emp.getRemarks()}
                    });
    }
    ofstream outFile(dbFilePath);
    if (outFile.is_open()) {
        outFile << j.dump(4);
        outFile.close();
    }
}

void EmployeeService::addEmployee(const Employee &employee) {
    employees.push_back(employee);
    saveToJson();
}

Employee EmployeeService::getEmployeeByEmail(const string &email) const {
    for (const auto &emp : employees) {
        if (emp.getEmail() == email) {
            return emp;
        }
    }
    throw runtime_error("Employee not found");
}

void EmployeeService::updateEmployee(const string &email, const Employee &updatedEmployee) {
    for (auto &emp : employees) {
        if (emp.getEmail() == email) {
            emp = updatedEmployee;
            saveToJson();
            return;
        }
    }
    throw runtime_error("Employee not found");
}

void EmployeeService::deleteEmployee(const string &email) {
    for (auto it = employees.begin(); it != employees.end(); ++it) {
        if (it->getEmail() == email) {
            employees.erase(it);
            saveToJson();
            return;
        }
    }
    throw runtime_error("Employee not found");
}

vector<Employee> EmployeeService::getAllEmployees() const {
    return employees;
}
