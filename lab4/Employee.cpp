#include "Employee.h"

int Employee::employeeCount = 0;

Employee::Employee(const string& name) : name(name) {
    ++employeeCount;
}

Employee::~Employee() {
    --employeeCount;
}

string Employee::getName() const {
    return name;
}

Employee::Employee(const Employee& other) : name(other.name) {
    ++employeeCount;
}

Employee& Employee::operator=(const Employee& other) {
    if (this != &other) {
        name = other.name;
    }

    return *this;
}

int Employee::getEmployeeCount() {
    return employeeCount;
}