#include <iostream>
using namespace std;


/**
 * @brief функция заполняет массив случайными значениями от -50 до 49
 * @param size размер массива
 * @param arr указатель массива из n чисел
 *
 */
void fillArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100 - 50;
    }
}

/**
 * @brief ищет первый отриц элемент массива
 * @param size размер массива
 * @param arr указатель массива из n чисел
 */
void process(int*& arr, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            cout << "первый отрицательный элемент: " << arr[i] << endl;
            break;
        }
    }
}

/**
 * @brief функция выводит массив на экран
 * @param size размер массива
 * @param arr указатель массива из n чисел
 */
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

/**
 * @brief функция получает размер массива и выделяет под него память
 *
 */
int main ()
{
    int n;
    cout << "введите размер массива  ";
    cin >> n;
    cout << n;
    cout << endl;
    int* arr = new int[n];
    fillArray(arr, n);
    printArray(arr, n);
    cout << endl;
    process(arr, n);



}