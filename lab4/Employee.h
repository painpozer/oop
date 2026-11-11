
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
    static int employeeCount; ///< Количество живых сотрудников
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

    /// @brief Возвращает количество живых сотрудников.
    static int getEmployeeCount();

    /**
     * @brief Рассчитывает зарплату сотрудника.
     * @return Зарплата с учётом особенностей должности
     */
    virtual double calculateSalary() const = 0;

    /**
     * @brief Рассчитывает среднюю зарплату сотрудников.
     * @param employees Массив указателей на сотрудников
     * @param count Количество сотрудников в массиве
     * @return Средняя зарплата или 0.0 для пустого списка
     */
    static double getAverageSalary(Employee* const employees[], int count);

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

    /**
     * @brief Меняет имя сотрудника.
     * @param employee Сотрудник, которого переименовываем
     * @param newName Новое имя
     */
    friend void renameEmployee(Employee& employee, const string& newName);
};
#endif //LAB4_EMPLOYEE_H
