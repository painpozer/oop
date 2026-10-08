#ifndef LAB2_COURSE_H
#define LAB2_COURSE_H

#include <string>
using namespace std;

class CourseFormat {
private:
    int type; ///< 0 - Очный, 1 - Заочный
public:
    CourseFormat(int type) {
        if (type == 1) {
            type = 1;  // Заочный
        } else {
            type = 0;  // Очный
        }
    }
    string toString() const {
        switch (type) {
            case 0: return "Очный";
            case 1: return "Заочный";
        }
        return "Неизвестно";
    }

    static CourseFormat fullTime() { return CourseFormat(0); }
    static CourseFormat partTime() { return CourseFormat(1); }
};

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
    Course();




};


#endif //LAB2_COURSE_H
