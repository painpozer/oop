#include "Developer.h"

Developer::Developer(const string& name, double baseSalary, int experience, int projectCount)
    : SalariedEmployee(name, baseSalary, experience), projectCount(projectCount) {
}

double Developer::getBonus() const {
    return projectCount * 3000.0;
}

int Developer::getProjectCount() const {
    return projectCount;
}

string Developer::getInfo() const {
    return "Разработчик: " + getName() +
           ", проектов: " + to_string(projectCount);
}