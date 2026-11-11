/**
 * @file main.cpp
 * @brief Тестовая программа для иерархии сотрудников.
 */
///
#include "TeamLead.h"
#include <cstddef>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief Загружает десять сотрудников из файла.
 * @return 0 при успешной загрузке, 1 при ошибке
 */
int main() {
    ifstream file("employees.txt");
    if (!file.is_open()) {
        cerr << "Не удалось открыть employees.txt\n";
        return 1;
    }

    const size_t expectedCount = 10;
    vector<Employee*> employees;
    int exitCode = 0;

    try {
        employees.reserve(expectedCount);
        string type, name;
        double baseSalary;
        int experience, roleCount;

        while (file >> type) {
            if (employees.size() == expectedCount) {
                throw runtime_error("В файле больше десяти записей");
            }

            if (!(file >> name >> baseSalary >> experience >> roleCount) ||
                baseSalary < 0.0 || experience < 0 || roleCount < 0) {
                throw runtime_error("Некорректные данные сотрудника типа " + type);
            }

            if (type == "Manager") {
                employees.push_back(new Manager(name, baseSalary, experience, roleCount));
            } else if (type == "Developer") {
                employees.push_back(new Developer(name, baseSalary, experience, roleCount));
            } else if (type == "TeamLead") {
                int projectCount;
                if (!(file >> projectCount) || projectCount < 0) {
                    throw runtime_error("Некорректное число проектов тимлида " + name);
                }

                employees.push_back(new TeamLead(name, baseSalary, experience, roleCount, projectCount));
            } else {
                throw runtime_error("Неизвестный тип сотрудника: " + type);
            }
        }

        if (file.bad() || employees.size() != expectedCount) {
            throw runtime_error("Не удалось прочитать десять сотрудников");
        }

        cout << "Загружено сотрудников: " << employees.size() << '\n';
        cout << "\n--- Полиморфный вывод ---\n";

        for (Employee* employee : employees) {
            cout << employee->getInfo()
                 << ", зарплата: " << employee->calculateSalary() << '\n';
        }
    } catch (const exception& error) {
        cerr << error.what() << '\n';
        exitCode = 1;
    }

    for (Employee* employee : employees) {
        delete employee;
    }

    return exitCode;
}