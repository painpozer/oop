#include <iostream>
#include <ctime>
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
 * @brief ищет первый отриц элемент массива и выводит новый массив до первого отрицательного элемента
 * @param size размер массива
 * @param arr указатель массива из n чисел
 */
void process(int*& arr, int& size) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        int* newarr = new int[index];

        for (int i = 0; i < index; i++) {
            newarr[i] = arr[i];
        }

        delete[] arr;

        arr = newarr;
        size = index;
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
    srand(time(0));
    int n;
    cout << "введите размер массива  ";
    cin >> n;
    int* arr = new int[n];
    fillArray(arr, n);
    printArray(arr, n);
    cout << endl;
    process(arr, n);
    printArray(arr, n);
    cout << endl;
    delete[] arr;
    arr = nullptr;
    if (arr != nullptr) {
        cout << "Значение по указателю: " << *arr << endl;
    }
    else {
        cout << "Нельзя получить значение: arr = nullptr" << endl;
    }



}