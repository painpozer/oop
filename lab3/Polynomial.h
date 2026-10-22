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

    /// @brief Вычисляет значение многочлена в точке x = 1.
    double valueAtOne() const;

public:
    /**
     * @brief Создаёт нулевой многочлен.
     */
    Polynomial();

    /**
     * @brief Создаёт многочлен вида kx^2 + kx.
     * @param coef Коэффициент k, присваиваемый коэффициентам a и b
     */
    explicit Polynomial(double coef);

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
     * @brief Увеличивает каждый коэффициент на единицу.
     * @return Ссылка на изменённый многочлен
     */
    Polynomial& operator++();

    /**
     * @brief Возвращает копию до увеличения, затем увеличивает коэффициенты.
     * @return Копия многочлена до изменения
     */
    Polynomial operator++(int);

    /**
     * @brief Уменьшает каждый коэффициент на единицу.
     * @return Ссылка на изменённый многочлен
     */
    Polynomial& operator--();

    /**
     * @brief Возвращает копию до уменьшения, затем уменьшает коэффициенты.
     * @return Копия многочлена до изменения
     */
    Polynomial operator--(int);

    /**
     * @brief Прибавляет коэффициенты другого многочлена.
     * @param other Многочлен, коэффициенты которого прибавляются
     * @return Ссылка на изменённый объект
     */
    Polynomial& operator+=(const Polynomial& other);

    /**
     * @brief Вычитает коэффициенты другого многочлена.
     * @param other Многочлен, коэффициенты которого вычитаются
     * @return Ссылка на изменённый объект
     */
    Polynomial& operator-=(const Polynomial& other);

    /**
     * @brief Умножает все коэффициенты на число.
     * @param number Число-множитель
     * @return Ссылка на изменённый объект
     */
    Polynomial& operator*=(double number);

    /**
     * @brief Делит все коэффициенты на число.
     * @param number Число-делитель, не равное нулю
     * @return Ссылка на изменённый объект
     */
    Polynomial& operator/=(double number);

    /**
      * @brief Складывает этот многочлен с другим.
      * @param other Второй многочлен
      * @return Новый многочлен, являющийся суммой
      */
     Polynomial operator+(const Polynomial& other) const;

     /**
      * @brief Вычитает другой многочлен из этого.
      * @param other Вычитаемый многочлен
      * @return Новый многочлен, являющийся разностью
      */
     Polynomial operator-(const Polynomial& other) const;

     /**
      * @brief Умножает многочлен на число.
      * @param number Число-множитель
      * @return Новый многочлен с умноженными коэффициентами
      */
     Polynomial operator*(double number) const;

     /**
      * @brief Делит многочлен на число.
      * @param number Число-делитель, не равное нулю
      * @return Новый многочлен с поделёнными коэффициентами
      */
     Polynomial operator/(double number) const;

     /**
      * @brief Сравнивает значения многочленов в точке x = 1.
      * @param other Многочлен для сравнения
      * @return true, если значение этого многочлена меньше значения other
      */
     bool operator<(const Polynomial& other) const;

     /**
      * @brief Сравнивает значения многочленов в точке x = 1.
      * @param other Многочлен для сравнения
      * @return true, если значение этого многочлена больше значения other
      */
     bool operator>(const Polynomial& other) const;

     /**
      * @brief Сравнивает значения многочленов в точке x = 1.
      * @param other Многочлен для сравнения
      * @return true, если значение этого многочлена не больше значения other
      */
     bool operator<=(const Polynomial& other) const;

     /**
      * @brief Сравнивает значения многочленов в точке x = 1.
      * @param other Многочлен для сравнения
      * @return true, если значение этого многочлена не меньше значения other
      */
     bool operator>=(const Polynomial& other) const;

     /**
      * @brief Проверяет равенство значений многочленов в точке x = 1.
      * @param other Многочлен для сравнения
      * @return true, если значения многочленов равны
      */
     bool operator==(const Polynomial& other) const;

     /**
      * @brief Проверяет неравенство значений многочленов в точке x = 1.
      * @param other Многочлен для сравнения
      * @return true, если значения многочленов различаются
      */
     bool operator!=(const Polynomial& other) const;

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
