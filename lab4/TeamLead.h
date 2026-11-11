#ifndef LAB4_TEAM_LEAD_H
#define LAB4_TEAM_LEAD_H

#include "Manager.h"
#include "Developer.h"

/**
 * @class TeamLead
 * @brief Сотрудник, который совмещает обязанности менеджера и разработчика.
 */
class TeamLead : public Manager, public Developer {
protected:
    /// @brief Возвращает сумму бонусов за подчинённых и проекты.
    double getBonus() const override;

public:
    /**
     * @brief Инициализирует данные тимлида.
     * @param name Имя тимлида
     * @param baseSalary Базовый оклад
     * @param experience Стаж в годах
     * @param subordinateCount Количество подчинённых
     * @param projectCount Количество проектов
     */
    TeamLead(const string& name, double baseSalary, int experience,
             int subordinateCount, int projectCount);

    /// @brief Возвращает описание тимлида.
    string getInfo() const override;

    /**
     * @brief Создаёт копию тимлида.
     * @param other Тимлид, которого копируем
     */
    TeamLead(const TeamLead& other);

    /**
     * @brief Копирует данные в существующего тимлида.
     * @param other Тимлид, чьи данные копируем
     * @return Ссылка на текущего тимлида
     */
    TeamLead& operator=(const TeamLead& other);
};

#endif //LAB4_TEAM_LEAD_H