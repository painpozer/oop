#include "Employee.h"

Employee::Employee(const string& name) : name(name) {
}

Employee::~Employee() = default;

string Employee::getName() const {
    return name;
}