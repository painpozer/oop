#include <iostream>
#include "Polynomial.h"
using namespace std;

/**
 * @brief Демонстрирует конструкторы, операторы и поиск корней Polynomial.
 * @return 0 при успешном завершении
 */
int main() {
    static_assert(!is_convertible<double, Polynomial>::value,
                  "Polynomial(double) must be explicit");

    cout << boolalpha;

    cout << "--- Конструкторы и explicit ---" << endl;
    Polynomial zero;
    Polynomial explicitPolynomial(2.0);
    Polynomial p(1.0, -3.0, 2.0);
    cout << "Нулевой многочлен: ";
    zero.print();
    cout << "Явное создание из числа: ";
    explicitPolynomial.print();
    cout << "Неявное преобразование double -> Polynomial запрещено." << endl;

    cout << "\n--- Унарные ++ и -- ---" << endl;
    Polynomial& prefixIncrementResult = ++p;
    cout << "После ++p: ";
    p.print();
    cout << "Префикс вернул ссылку на p: "
         << (&prefixIncrementResult == &p) << endl;

    Polynomial oldIncrement = p++;
    cout << "Копия, возвращённая p++: ";
    oldIncrement.print();
    cout << "p после p++: ";
    p.print();

    Polynomial& prefixDecrementResult = --p;
    cout << "После --p: ";
    p.print();
    cout << "Префикс вернул ссылку на p: "
         << (&prefixDecrementResult == &p) << endl;

    Polynomial oldDecrement = p--;
    cout << "Копия, возвращённая p--: ";
    oldDecrement.print();
    cout << "p после p--: ";
    p.print();

    cout << "\n--- Арифметическое присваивание ---" << endl;
    Polynomial assigned(1.0, 2.0, 3.0);
    Polynomial other(2.0, 1.0, 1.0);
    assigned += other;
    cout << "После +=: ";
    assigned.print();
    assigned -= other;
    cout << "После -=: ";
    assigned.print();
    assigned *= 2.0;
    cout << "После *= 2: ";
    assigned.print();
    assigned /= 2.0;
    cout << "После /= 2: ";
    assigned.print();

    cout << "\n--- Бинарная арифметика ---" << endl;
    Polynomial sum = p + other;
    Polynomial difference = p - other;
    Polynomial product = p * 2.0;
    Polynomial quotient = p / 2.0;
    cout << "p + other: ";
    sum.print();
    cout << "p - other: ";
    difference.print();
    cout << "p * 2: ";
    product.print();
    cout << "p / 2: ";
    quotient.print();

    cout << "\n--- Сравнения значений при x = 1 ---" << endl;
    cout << "p < other: " << (p < other) << endl;
    cout << "p > other: " << (p > other) << endl;
    cout << "p <= other: " << (p <= other) << endl;
    cout << "p >= other: " << (p >= other) << endl;
    cout << "p == other: " << (p == other) << endl;
    cout << "p != other: " << (p != other) << endl;

    cout << "\n--- Поиск корней у const-объекта ---" << endl;
    const Polynomial constPolynomial(1.0, -3.0, 2.0);
    double x1 = 0.0;
    double x2 = 0.0;
    const int rootsFound = constPolynomial.calculateRoots(x1, x2);
    cout << "Найдено корней: " << rootsFound << endl;
    if (rootsFound > 0) {
        cout << "x1 = " << x1 << endl;
    }
    if (rootsFound > 1) {
        cout << "x2 = " << x2 << endl;
    }
    cout << "Поисков для этого const-объекта: "
         << constPolynomial.getCalculateRootCount() << endl;
    cout << "Поисков всего: " << Polynomial::getRootSearchCount() << endl;

    return 0;
}