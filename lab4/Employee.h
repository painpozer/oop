
#ifndef LAB4_EMPLOYEE_H
#define LAB4_EMPLOYEE_H


#include <string>
using namespace std;

/**
 * @class Employee
 * @brief Абстрактный базовый класс сотрудника компании.
 */
class Employee {
private:
    string name; ///< Имя сотрудника

public:
    /**
     * @brief Инициализирует имя сотрудника.
     * @param name Имя сотрудника
     */
    Employee(const string& name);

    /// @brief Обеспечивает корректное удаление наследников через Employee*.
    virtual ~Employee();

    /**
     * @brief Возвращает имя сотрудника.
     * @return Имя сотрудника
     */
    string getName() const;

    /**
     * @brief Рассчитывает зарплату сотрудника.
     * @return Зарплата с учётом особенностей должности
     */
    virtual double calculateSalary() const = 0;

    /**
     * @brief Формирует описание сотрудника.
     * @return Строка с информацией о сотруднике
     */
    virtual string getInfo() const = 0;

    /**
     * @brief Инициализирует имя из другого сотрудника.
     * @param other Сотрудник, которого копируем
     */
    Employee(const Employee& other);

    /**
     * @brief Присваивает имя другого сотрудника.
     * @param other Сотрудник, чьё имя копируем
     * @return Ссылка на текущего сотрудника
     */
    Employee& operator=(const Employee& other);
};
#endif //LAB4_EMPLOYEE_H
