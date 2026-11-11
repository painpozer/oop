#include "Employee.h"

Employee::Employee(const string& name) : name(name) {
}

Employee::~Employee() = default;

string Employee::getName() const {
    return name;
}

Employee::Employee(const Employee& other) : name(other.name) {
}

Employee& Employee::operator=(const Employee& other) {
    if (this != &other) {
        name = other.name;
    }

    return *this;
}