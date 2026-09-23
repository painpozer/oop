#include <iostream>
using namespace std;

/**
 * @brief функция заполняет массив случайными числами
 * @param arr массив из 10 чисел
 */

void fillArray(int (&arr)[10]) {
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 100;
    }
}
/**
 * @brief функция выводит массив на экран
 * @param arr массив из 10 чисел
 */
void printArray(int (&arr)[10]) {
    for (auto i : arr) {
        cout << i << " ";
    }
}

/**
 * @brief функция меняет местами элементы массива по их индексам
 * @param arr массив из 10 чисел
 * @param i индекс первого меняемого элемента массива
 * @param j индекс второго меняемого элемента массива
 */
void swapElements(int (&arr)[10], int i, int j) {
    swap(arr[i], arr[j]);
}

/**
 * @brief функция умножает элементы массива на 2
 * @param arr массив из 10 чисел
 */
void multiplyByTwo(int (&arr)[10]) {
    for (int& i : arr) {
        i = i * 2;
    }
}

/**
 * @brief основная функция которая запускает остальные функции для заполнения масиива значениями, вывода их на экран, переставления элементов местами и умножения этих элементов на 2
 * @param arr массив из 10 чисел
 */
int main()
{
    int arr[10];
    fillArray(arr);
    printArray(arr);
    cout << endl;
    swapElements(arr, 8, 9);
    printArray(arr);
    cout << endl;
    multiplyByTwo((arr));
    printArray(arr);
    return 0;
}