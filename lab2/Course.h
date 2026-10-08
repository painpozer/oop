#ifndef LAB2_COURSE_H
#define LAB2_COURSE_H

#include <string>
using namespace std;

/**
 * @brief Формат обучения на курсе.
 * Пользовательский тип, определяющий формат обучения.
 */
class CourseFormat {
private:
    int type; ///< 0 - Очный, 1 - Заочный
public:
    /**
     * @brief Конструктор с кодом формата
     * @param type Код в диапазоне [0, 1]. Иначе приводится к 0 (Очный)
     */
    CourseFormat(int type) {
        if (type == 1) {
            type = 1;  // Заочный
        } else {
            type = 0;  // Очный
        }
    }
    /**
     * @brief Преобразовать формат обучения в строку
     * @return "Очный" или "Заочный"
     */
    string toString() const {
        switch (type) {
            case 0: return "Очный";
            case 1: return "Заочный";
        }
        return "Неизвестно";
    }
    /// @brief Фабрики для читаемости
    static CourseFormat fullTime() { return CourseFormat(0); }
    static CourseFormat partTime() { return CourseFormat(1); }
};

/**
 * @class Course
 * @brief Класс, описывающий учебный курс.
 *
 * Хранит информацию о курсе: название, формат обучения,
 * количество студентов, максимальное количество студентов
 * и количество учебных часов.
 * Поддерживает операции добавления и удаления студентов,
 * изменения количества часов и проверки заполненности курса.
 * Ведёт подсчёт существующих объектов через статический счётчик.
 *
 */
class Course {
private:
    string name; ///< Название курса
    int studentCount; ///< Количество студентов
    int maxStudents; ///< Максимальное количество студентов
    int hours; ///< Количество часов
    CourseFormat format; ///< Формат обучения
    static int objectCount; ///< Статический счётчик существующих объектов
    bool isStateValid() const;
public:
    /**
     * @brief Конструктор по умолчанию.
     *
     * Создаёт курс с названием "Без названия",
     * очным форматом обучения, без студентов,
     * максимальным количеством 20 студентов
     * и количеством 72 учебных часов.
     */
    Course();

    /**
     * @brief Параметризованный конструктор.
     *
     * Создаёт новый курс без студентов.
     *
     * @param name Название курса
     * @param format Формат обучения
     * @param maxStudents Максимальное количество студентов
     * @param hours Количество учебных часов
     */
    Course(string name, CourseFormat format, int maxStudents, int hours);

    /**
     * @brief Параметризованный конструктор с количеством студентов.
     *
     * @param name Название курса
     * @param format Формат обучения
     * @param studentCount Начальное количество студентов
     * @param maxStudents Максимальное количество студентов
     * @param hours Количество учебных часов
     */
    Course(string name, CourseFormat format, int studentCount, int maxStudents, int hours);

    /// Деструктор. Уменьшает счётчик существующих объектов.
    ~Course();

    /// @brief Получить название курса
    string getName() const;

    /// @brief Получить формат обучения
    CourseFormat getFormat() const;

    /// @brief Получить количество студентов
    int getStudentCount() const;

    /// @brief Получить максимальное количество студентов
    int getMaxStudents() const;

    /// @brief Получить количество учебных часов
    int getHours() const;

    /**
     * @brief Получить текущее количество существующих объектов
     * @return Число живых экземпляров Course
     */
    static int getObjectCount();

    /**
     * @brief Преобразовать формат обучения в строку
     * @param format Формат обучения
     * @return Строковое представление формата
     */
    static string formatToString(CourseFormat format);

    /**
     * @brief Добавить одного студента на курс
     * @return true при успехе, false если курс уже заполнен
     */
    bool addStudent();

    /**
     * @brief Удалить одного студента с курса
     * @return true при успехе, false если студентов уже нет
     */
    bool removeStudent();

    /**
     * @brief Изменить количество учебных часов
     * @param newHours Новое количество часов (должно быть > 0)
     * @return true при успехе, false если новое значение некорректно
     */
    bool changeHours(int newHours);

    /**
     * @brief Проверить, заполнен ли курс
     * @return true, если количество студентов достигло максимума
     */
    bool isFull() const;

    /// @brief Вывести состояние курса
    void print() const;

};


#endif //LAB2_COURSE_H
