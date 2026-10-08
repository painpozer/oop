#ifndef LAB2_COURSE_H
#define LAB2_COURSE_H

#include <string>
using namespace std;

class Course {
private:
    string name; ///< Название курса
    int studentCount; ///< Количество студентов
    int maxStudents; ///< Максимальное количество студентов
    int hours; ///< Количество часов
    static int objectCount; ///< Статический счётчик существующих объектов
    bool isStateValid() const;



};


#endif //LAB2_COURSE_H
