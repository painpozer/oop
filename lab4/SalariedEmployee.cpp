#include "SalariedEmployee.h"

SalariedEmployee::SalariedEmployee(const string& name, double baseSalary, int experience)
    : Employee(name), baseSalary(baseSalary), experience(experience) {
}

double SalariedEmployee::getBonus() const {
    return 0.0;
}

double SalariedEmployee::calculateSalary() const {
    double experienceBonus = baseSalary * 0.05 * experience;
    return baseSalary + experienceBonus + getBonus();
}