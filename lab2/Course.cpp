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
/**
 * @brief Параметризованный конструктор (полный)
 * @param name Название курса
 * @param format Формат обучения
 * @param studentCount Начальное количество студентов
 * @param maxStudents Максимальное количество студентов
 * @param hours Количество учебных часов
 * @note Некорректные значения корректируются к допустимым
 *       без выброса исключений
 */
Course::Course(string name, CourseFormat format, int studentCount, int maxStudents, int hours) :
    name(name),
    studentCount(studentCount),
    maxStudents(maxStudents),
    hours(hours),
    format(format)
    // Проверка корректности входных данных
{
    if (this->maxStudents <= 0) this->maxStudents = 20;
    if (this->hours <= 0) this->hours = 72;
    if (this->studentCount < 0) this->studentCount = 0;
    if (this->studentCount > this->maxStudents) this->studentCount = this->maxStudents;
    objectCount++;
    cout << "[Course] Создан курс: " << this->name << endl;
}
/// @brief Деструктор. Уменьшает счётчик объектов и печатает об этом в консоль
Course::~Course() {
    objectCount--;
    cout << "[Course] Уничтожен курс: " << name << " (осталось объектов: " << objectCount << ")" << endl;
}
/// @brief Получить название курса
string Course::getName() const {return name;}

/// @brief Получить формат обучения
CourseFormat Course::getFormat() const {return format;}

/// @brief Получить количество студентов
int Course::getStudentCount() const {return studentCount;}

/// @brief Получить максимальное количество студентов
int Course::getMaxStudents() const {return maxStudents;}

/// @brief Получить количество учебных часов
int Course::getHours() const {return hours;}

/**
 * @brief Получить текущее количество существующих объектов
 * @return Число живых экземпляров Course
 */
int Course::getObjectCount() {return objectCount;}

/**
 * @brief Преобразовать формат обучения в строку
 * @param format Формат обучения
 * @return Строковое представление формата
 * @retval "Очный"     для CourseFormat::fullTime()
 * @retval "Заочный"   для CourseFormat::partTime()
 * @retval "Неизвестно" для некорректного значения
 */
string Course::formatToString(CourseFormat format) {
    return format.toString();
}

/**
 * @brief Добавить одного студента на курс
 * @return true при успехе; false если курс уже заполнен
 * @warning При ошибке сообщение выводится в консоль
 */
bool Course::addStudent() {
    if (isFull()) {
        cerr << "Ошибка. Курс '" << name << "' уже заполнен (" << studentCount << "/" << maxStudents << ")" << endl;
        return false;
    }
    studentCount++;
    cout << "Студент добавлен на курс '" << name << "'. Всего: " << studentCount << endl;
    return true;
}

/**
 * @brief Удалить одного студента с курса
 * @return true при успехе; false если студентов уже нет
 */
bool Course::removeStudent() {
    if (studentCount <= 0) {
        cerr << "Ошибка. На курсе '" << name << "' нет студентов" << endl;
        return false;
    }
    studentCount--;
    cout << "Студент удален с курса '" << name << "'. Всего: " << studentCount << endl;
    return true;
}

/**
 * @brief Изменить количество учебных часов
 * @param newHours Новое количество часов (> 0)
 * @return true при успехе; false если newHours <= 0
 */
bool Course::changeHours(int newHours) {
    if (newHours <= 0) {
        cerr << "Ошибка. Количество часов должно быть > 0" << endl;
        return false;
    }
    hours = newHours;
    cout << "Курс '" << name << "': новое количество часов = " << hours << endl;
    return true;
}

/**
 * @brief Проверить, заполнен ли курс
 * @return true, если количество студентов достигло максимума
 */
bool Course::isFull() const {
    return studentCount >= maxStudents;
}

/**
 * @brief Проверка инвариантов состояния
 * @return true, если все поля согласованы
 * @details Проверяет: studentCount >= 0, studentCount <= maxStudents,
 *          maxStudents > 0, hours > 0.
 */
bool Course::isStateValid() const {
    if (studentCount < 0) return false;
    if (studentCount > maxStudents) return false;
    if (maxStudents <= 0) return false;
    if (hours <= 0) return false;
    return true;
}

/// @brief Вывести состояние курса в консоль
void Course::print() const {
    cout << "===== Курс: " << name << " =====" << endl;
    cout << "  Формат: " << formatToString(format) << endl;
    cout << "  Студентов: " << studentCount << " / " << maxStudents << endl;
    cout << "  Часов: " << hours << endl;
    cout << "  Статус: " << (isFull() ? "ЗАПОЛНЕН" : "ЕСТЬ МЕСТА") << endl;
    cout << "  Состояние: " << (isStateValid() ? "корректно" : "некорректно") << endl;
}