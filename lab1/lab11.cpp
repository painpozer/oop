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

int main()
{
    int arr[10];
    fillArray(arr);
    printArray(arr);
    return 0;
}