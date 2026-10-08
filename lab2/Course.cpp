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
/**
 * @brief Параметризованный конструктор (упрощённый)
 * @param name Название курса
 * @param maxStudents Максимальное количество студентов
 * @param hours Количество учебных часов
 * @note Некорректные значения (maxStudents <= 0, hours <= 0) корректируются
 *       к допустимым без выброса исключений. Студентов изначально 0,
 *       формат обучения — Очный
 */
Course::Course(string name, int maxStudents, int hours) :
    name(name),
    studentCount(0),
    maxStudents(maxStudents),
    hours(hours),
    format(CourseFormat::fullTime())
    // Проверка корректности входных данных
{
    if (this->maxStudents <= 0) this->maxStudents = 20;
    if (this->hours <= 0) this->hours = 72;
    objectCount++;
    cout << "[Course] Создан курс: " << this->name << endl;
}