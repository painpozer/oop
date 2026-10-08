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
    CourseFormat(int formatCode);
    string toString() const;

    /// @brief Фабрики для читаемости
    static CourseFormat fullTime();
    static CourseFormat partTime();
};

/**
 * @class Course
 * @brief Класс, описывающий учебный курс.
 */
class Course {
private:
    string name; ///< Название курса
    int studentCount; ///< Количество студентов
    int maxStudents; ///< Максимальное количество студентов
    int hours; ///< Количество часов
    CourseFormat format; ///< Формат обучения
    static int objectCount; ///< Статический счётчик существующих объектов


public:
    /**
     * @brief Конструктор по умолчанию.
     */
    Course();

    /**
     * @brief Параметризованный конструктор (упрощённый, 3 аргумента).
     * Создаёт новый курс без студентов, с очным форматом по умолчанию.
     *
     * @param name Название курса
     * @param maxStudents Максимальное количество студентов
     * @param hours Количество учебных часов
     */
    Course(string name, int maxStudents, int hours); // <--- ВОТ ЭТОГО НЕ ХВАТАЛО

    /**
     * @brief Параметризованный конструктор (полный, 5 аргументов).
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

    bool isStateValid() const;
};

#endif //LAB2_COURSE_H