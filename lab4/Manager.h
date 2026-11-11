#ifndef LAB4_MANAGER_H
#define LAB4_MANAGER_H

#include "SalariedEmployee.h"

/**
 * @class Manager
 * @brief Менеджер с бонусом за подчинённых.
 */
class Manager : public virtual SalariedEmployee {
private:
    int subordinateCount; ///< Количество подчинённых

protected:
    /// @brief Рассчитывает бонус за подчинённых.
    double getBonus() const override;

public:
    /**
     * @brief Инициализирует данные менеджера.
     * @param name Имя менеджера
     * @param baseSalary Базовый оклад
     * @param experience Стаж в годах
     * @param subordinateCount Количество подчинённых
     */
    Manager(const string& name, double baseSalary, int experience, int subordinateCount);

    /// @brief Возвращает количество подчинённых.
    int getSubordinateCount() const;

    /// @brief Возвращает описание менеджера.
    string getInfo() const override;

    /**
     * @brief Создаёт копию менеджера.
     * @param other Менеджер, которого копируем
     */
    Manager(const Manager& other);

    /**
     * @brief Копирует данные в существующего менеджера.
     * @param other Менеджер, чьи данные копируем
     * @return Ссылка на текущего менеджера
     */
    Manager& operator=(const Manager& other);
};

#endif //LAB4_MANAGER_H