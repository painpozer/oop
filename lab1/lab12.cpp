#include <iostream>
using namespace std;
/**
 * @brief функция получает размер массива и выделяет под него память
 * @param n размер массива
 * @param arr динамический массив из n чисел
 *
 */
int main ()
{
    int n;
    cout << "введите размер массива  ";
    cin >> n;
    cout << n;
    int* arr = new int[n];

}