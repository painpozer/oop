#include <iostream>
#include <cmath>
#include <stdexcept>
#include "Polynomial.h"
using namespace std;

/// @brief Инициализация общего счётчика вызовов поиска корней.
int Polynomial::rootSearchCount = 0;

/**
 * @brief Конструктор по умолчанию.
 * @details Создаёт нулевой многочлен и обнуляет счётчик вызовов для объекта.
 */
Polynomial::Polynomial()
    : a(0.0), b(0.0), c(0.0), calculateRootCount(0) {
    cout << "Создан нулевой многочлен" << endl;
}

/**
 * @brief Параметризованный конструктор с одним коэффициентом.
 * @param coef Значение, которое присваивается коэффициентам a и b
 * @details Создаёт многочлен вида kx^2 + kx.
 */
Polynomial::Polynomial(double coef)
    : a(coef), b(coef), c(0.0), calculateRootCount(0) {
    cout << "Создан многочлен вида kx^2 + kx" << endl;
}

/**
 * @brief Параметризованный конструктор с тремя коэффициентами.
 * @param a Коэффициент при x^2
 * @param b Коэффициент при x
 * @param c Свободный коэффициент
 */
Polynomial::Polynomial(double a, double b, double c)
    : a(a), b(b), c(c), calculateRootCount(0) {
    cout << "Создан многочлен" << endl;
}

/// @brief Выводит сообщение об уничтожении объекта.
Polynomial::~Polynomial() {
    cout << "Объект уничтожен" << endl;
}

Polynomial& Polynomial::operator++() {
    ++a;
    ++b;
    ++c;
    return *this;
}

Polynomial Polynomial::operator++(int) {
    Polynomial oldValue(*this);
    ++(*this);
    return oldValue;
}

Polynomial& Polynomial::operator--() {
    --a;
    --b;
    --c;
    return *this;
}

Polynomial Polynomial::operator--(int) {
    Polynomial oldValue(*this);
    --(*this);
    return oldValue;
}

Polynomial& Polynomial::operator+=(const Polynomial& other) {
    a += other.a;
    b += other.b;
    c += other.c;
    return *this;
}

Polynomial& Polynomial::operator-=(const Polynomial& other) {
    a -= other.a;
    b -= other.b;
    c -= other.c;
    return *this;
}

Polynomial& Polynomial::operator*=(double number) {
    a *= number;
    b *= number;
    c *= number;
    return *this;
}

Polynomial& Polynomial::operator/=(double number) {
    if (number == 0.0) {
        throw invalid_argument("Нельзя делить многочлен на ноль");
    }

    a /= number;
    b /= number;
    c /= number;
    return *this;
}

Polynomial Polynomial::operator+(const Polynomial& other) const {
    Polynomial result(a, b, c);
    result += other;
    return result;
}

Polynomial Polynomial::operator-(const Polynomial& other) const {
    Polynomial result(a, b, c);
    result -= other;
    return result;
}

Polynomial Polynomial::operator*(double number) const {
    Polynomial result(a, b, c);
    result *= number;
    return result;
}

Polynomial Polynomial::operator/(double number) const {
    Polynomial result(a, b, c);
    result /= number;
    return result;
}

double Polynomial::valueAtOne() const {
    return a + b + c;
}

bool Polynomial::operator<(const Polynomial& other) const {
    return valueAtOne() < other.valueAtOne();
}

bool Polynomial::operator>(const Polynomial& other) const {
    return other < *this;
}

bool Polynomial::operator<=(const Polynomial& other) const {
    return !(other < *this);
}

bool Polynomial::operator>=(const Polynomial& other) const {
    return !(*this < other);
}

bool Polynomial::operator==(const Polynomial& other) const {
    return valueAtOne() == other.valueAtOne();
}

bool Polynomial::operator!=(const Polynomial& other) const {
    return !(*this == other);
}

/**
 * @brief Находит действительные корни многочлена.
 * @param x1 Переменная для первого найденного корня
 * @param x2 Переменная для второго найденного корня
 * @return Количество найденных действительных корней: 0, 1 или 2
 * @details Для линейного уравнения (a == 0) вычисляет один корень,
 *          если b не равно нулю. Для квадратного уравнения использует
 *          дискриминант.
 */
int Polynomial::calculateRoots(double& x1, double& x2) const {
    ++calculateRootCount;
    ++rootSearchCount;

    x1 = 0.0;
    x2 = 0.0;


    if (a == 0.0) {
        if (b == 0.0) {
            return 0;
        }

        x1 = -c / b;
        return 1;
    }

    double discriminant = b * b - 4.0 * a * c;

    if (discriminant < 0.0) {
        return 0;
    }

    if (discriminant == 0.0) {
        x1 = -b / (2.0 * a);
        return 1;
    }

    double squareRoot = sqrt(discriminant);
    x1 = (-b - squareRoot) / (2.0 * a);
    x2 = (-b + squareRoot) / (2.0 * a);

    return 2;
}

/**
 * @brief Возвращает количество поисков корней для этого объекта.
 * @return Число вызовов calculateRoots() у данного объекта
 */
int Polynomial::getCalculateRootCount() const {
    return calculateRootCount;
}

/**
 * @brief Возвращает общее количество поисков корней.
 * @return Число вызовов calculateRoots() у всех объектов
 */
int Polynomial::getRootSearchCount() {
    return rootSearchCount;
}
