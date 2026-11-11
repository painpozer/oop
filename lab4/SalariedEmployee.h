#ifndef LAB4_SALARIED_EMPLOYEE_H
#define LAB4_SALARIED_EMPLOYEE_H

#include "Employee.h"

/**
 * @class SalariedEmployee
 * @brief Промежуточный класс сотрудника с окладом и стажем.
 */
class SalariedEmployee : public Employee {
private:
    double baseSalary; ///< Базовый оклад
    int experience; ///< Стаж в годах

protected:
    /// @brief Возвращает бонус. По умолчанию бонус равен нулю.
    virtual double getBonus() const;

public:
    /**
     * @brief Инициализирует имя, оклад и стаж сотрудника.
     * @param name Имя сотрудника
     * @param baseSalary Базовый оклад
     * @param experience Стаж в годах
     */
    SalariedEmployee(const string& name, double baseSalary, int experience);

    /// @brief Рассчитывает зарплату с учётом стажа и бонуса.
    double calculateSalary() const override;

    /**
     * @brief Копирует имя, оклад и стаж сотрудника.
     * @param other Сотрудник, которого копируем
     */
    SalariedEmployee(const SalariedEmployee& other);

    /**
     * @brief Присваивает имя, оклад и стаж другого сотрудника.
     * @param other Сотрудник, чьи данные копируем
     * @return Ссылка на текущего сотрудника
     */
    SalariedEmployee& operator=(const SalariedEmployee& other);
};


#endif //LAB4_SALARIED_EMPLOYEE_H