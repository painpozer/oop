#ifndef LAB3_POLYNOMIAL_H
#define LAB3_POLYNOMIAL_H

/**
 * @class Polynomial
 * @brief Класс для работы с многочленом вида ax^2 + bx + c.
 */
class Polynomial {
private:
    double a; ///< Коэффициент при x^2
    double b; ///< Коэффициент при x
    double c; ///< Свободный коэффициент
    mutable int calculateRootCount; ///< Количество вызовов поиска корней для этого объекта
    static int rootSearchCount; ///< Общее количество вызовов поиска корней

public:
    /**
     * @brief Создаёт нулевой многочлен.
     */
    Polynomial();

    /**
     * @brief Создаёт многочлен вида kx^2 + kx.
     * @param coef Коэффициент k, присваиваемый коэффициентам a и b
     */
    Polynomial(double coef);

    /**
     * @brief Создаёт многочлен с заданными коэффициентами.
     * @param a Коэффициент при x^2
     * @param b Коэффициент при x
     * @param c Свободный коэффициент
     */
    Polynomial(double a, double b, double c);

    /// @brief Деструктор класса Polynomial.
    ~Polynomial();
    /**
     * @brief Находит действительные корни многочлена.
     * @param x1 Переменная для первого найденного корня
     * @param x2 Переменная для второго найденного корня
     * @return Количество найденных действительных корней: 0, 1 или 2
     * @details При каждом вызове увеличивает счётчик этого объекта
     *          и общий счётчик поисков корней.
     */
    int calculateRoots(double& x1, double& x2) const;

    /**
     * @brief Возвращает количество вызовов поиска корней для этого объекта.
     * @return Число вызовов метода calculateRoots() у данного объекта
     */
    int getCalculateRootCount() const;

    /**
     * @brief Возвращает общее количество вызовов поиска корней.
     * @return Число вызовов метода calculateRoots() у всех объектов
     */
    static int getRootSearchCount();
};



#endif //LAB3_POLYNOMIAL_H
