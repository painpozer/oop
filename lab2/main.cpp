/**
 * @file main.cpp
 * @brief Демонстрация работы класса Course
 *
 * Создаёт три курса разными конструкторами, выполняет корректные
 * и некорректные операции, проверяет независимость объектов и
 * корректность состояния после всех манипуляций
 */

#include <iostream>
#include <clocale>
#include "Course.h"

/**
 * @brief Точка входа в программу.
 * Последовательно выполняет:
 * создание трёх объектов Course разными конструкторами;
 * вывод начального состояния и счётчика объектов;
 * набор корректных операций (добавление/удаление студентов, смена часов);
 * набор некорректных операций (переполнение, удаление из пустого,
 * отрицательные часы);
 * проверку независимости объектов друг от друга;
 * завершение с автоматическим вызовом деструкторов
 * @return 0 при нормальном завершении.
 */
int main() {
    cout << "===== Тест класса Course =====" << endl;

    // Создание объектов разными конструкторами
    cout << "--- Создание объектов ---" << endl;
    Course course1;                                                     // по умолчанию
    Course course2("Введение в C++", 1, 36);                            // упрощённый параметризованный
    Course course3("Базы данных", CourseFormat::partTime(), 5, 30, 72); // полный параметризованный
    cout << endl;

    cout << "Всего объектов: " << Course::getObjectCount() << endl << endl;
        // Начальное состояние объектов
    cout << "--- Начальное состояние ---" << endl;
    course1.print();
    cout << endl;

    course2.print();
    cout << endl;

    course3.print();
    cout << endl;


    // Корректные операции
    cout << "--- Корректные операции ---" << endl;

    course1.addStudent();
    course1.addStudent();

    course2.addStudent();
    course2.removeStudent();

    course3.addStudent();
    course3.changeHours(40);

    cout << endl;


    // Некорректные операции
    cout << "--- Некорректные операции ---" << endl;

    // Удаление студента с пустого курса
    Course emptyCourse;
    emptyCourse.removeStudent();

    // Заполняем course2 до максимума
    course2.addStudent();
    course2.addStudent();
    course2.addStudent();

    // Попытка добавить больше максимального количества
    course2.addStudent();

    // Попытка установить отрицательное количество часов
    course3.changeHours(-10);

    cout << endl;


    // Повторная проверка состояния
    cout << "--- Состояние после операций ---" << endl;

    course1.print();
    cout << endl;

    course2.print();
    cout << endl;

    course3.print();
    cout << endl;


    // Проверка независимости объектов
    cout << "--- Проверка независимости объектов ---" << endl;

    cout << "До изменения course1:" << endl;
    cout << "course1: " << course1.getStudentCount() << " студентов" << endl;
    cout << "course2: " << course2.getStudentCount() << " студентов" << endl;
    cout << "course3: " << course3.getStudentCount() << " студентов" << endl;

    cout << "\nДобавляем студента только в course1..." << endl;

    course1.addStudent();

    cout << "\nПосле изменения course1:" << endl;
    cout << "course1: " << course1.getStudentCount() << " студентов" << endl;
    cout << "course2: " << course2.getStudentCount() << " студентов" << endl;
    cout << "course3: " << course3.getStudentCount() << " студентов" << endl;


    // Проверка корректности состояния
    cout << "\n--- Проверка состояния ---" << endl;

    cout << "course1: "
         << (course1.isStateValid() ? "корректно" : "некорректно")
         << endl;

    cout << "course2: "
         << (course2.isStateValid() ? "корректно" : "некорректно")
         << endl;

    cout << "course3: "
         << (course3.isStateValid() ? "корректно" : "некорректно")
         << endl;

    cout << "\nСейчас существует объектов: "
         << Course::getObjectCount()
         << endl;

    return 0;


    return 0;
}