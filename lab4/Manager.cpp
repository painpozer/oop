#include "Manager.h"

Manager::Manager(const string& name, double baseSalary, int experience, int subordinateCount)
    : SalariedEmployee(name, baseSalary, experience), subordinateCount(subordinateCount) {
}

double Manager::getBonus() const {
    return subordinateCount * 5000.0;
}

int Manager::getSubordinateCount() const {
    return subordinateCount;
}

string Manager::getInfo() const {
    return "Менеджер: " + getName() +
           ", подчинённых: " + to_string(subordinateCount);
}

Manager::Manager(const Manager& other)
    : SalariedEmployee(other), subordinateCount(other.subordinateCount) {
}

Manager& Manager::operator=(const Manager& other) {
    if (this != &other) {
        SalariedEmployee::operator=(other);
        subordinateCount = other.subordinateCount;
    }

    return *this;
}