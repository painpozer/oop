#include "Course.h"
#include <iostream>
using namespace std;

/// @brief Инициализация статического счётчика объектов
int Course::objectCount = 0;

/**
 * @brief Конструктор по умолчанию
 * @details Инициализирует курс значениями: "Без названия", Очный, 0 студентов, 20 максимум, 72 часа
 */
Course::Course() :
    name("Без названия"),
    studentCount(0),
    maxStudents(20),
    hours(72),
    format(CourseFormat::fullTime())
{
    objectCount++;
    cout << "[Course] Создан курс по умолчанию: " << name << endl;
}