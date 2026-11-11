#ifndef LAB4_DEVELOPER_H
#define LAB4_DEVELOPER_H

#include "SalariedEmployee.h"

/**
 * @class Developer
 * @brief Разработчик с бонусом за проекты.
 */
class Developer : public virtual SalariedEmployee {
private:
    int projectCount; ///< Количество проектов

protected:
    /// @brief Рассчитывает бонус за проекты.
    double getBonus() const override;

public:
    /**
     * @brief Инициализирует данные разработчика.
     * @param name Имя разработчика
     * @param baseSalary Базовый оклад
     * @param experience Стаж в годах
     * @param projectCount Количество проектов
     */
    Developer(const string& name, double baseSalary, int experience, int projectCount);

    /// @brief Возвращает количество проектов.
    int getProjectCount() const;

    /// @brief Возвращает описание разработчика.
    string getInfo() const override;

    /**
     * @brief Создаёт копию разработчика.
     * @param other Разработчик, которого копируем
     */
    Developer(const Developer& other);

    /**
     * @brief Копирует данные в существующего разработчика.
     * @param other Разработчик, чьи данные копируем
     * @return Ссылка на текущего разработчика
     */
    Developer& operator=(const Developer& other);
};

#endif //LAB4_DEVELOPER_H