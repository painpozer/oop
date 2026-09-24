#include <iostream>
using namespace std;

/**
 * @struct SafeArray
 * @brief Хранит динамический массив и количество его элементов
 */
struct SafeArray {
    int* data;
    int size;
};

/**
* @brief функция выделяет память и возвращает структурпу по значению
* @param size размер создаваемого массива
**/
SafeArray createArray(int size) {
    SafeArray arr;

    arr.data = new int[size];
    arr.size = size;

    return arr;
}

/**
* @brief функция определяет находится ли индекс за границей
* @param index индекс элемента массива
**/
int& getElement(SafeArray& arr, int index)
{
    if (index < 0 || index >= arr.size)
    {
        cout << "ошибка, индекс за границей";
        static int a = 0;
        return a;
    }
    return arr.data[index];
}

/**
* @brief функция выводит элементы массива через const
* @param arr наш массив который надо вывести
**/
void printSafe(const SafeArray& arr) {
    for (int i = 0; i < arr.size; i++) {
        cout << arr.data[i] << " ";
    }
    cout << endl;
}

int main() {
    SafeArray arr = createArray(3);
    getElement(arr, 0) = 10;
    getElement(arr, 1) = 10;
    getElement(arr, 2) = 10;
    printSafe(arr);
    return 0;
}