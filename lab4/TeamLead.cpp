#include "TeamLead.h"

TeamLead::TeamLead(const string& name, double baseSalary, int experience, int subordinateCount, int projectCount)
    : SalariedEmployee(name, baseSalary, experience), Manager(name, baseSalary, experience, subordinateCount), Developer(name, baseSalary, experience, projectCount) {
}

double TeamLead::getBonus() const {
    return Manager::getBonus() + Developer::getBonus();
}

string TeamLead::getInfo() const {
    return "Тимлид: " + getName() +
           ", подчинённых: " + to_string(getSubordinateCount()) +
           ", проектов: " + to_string(getProjectCount());
}