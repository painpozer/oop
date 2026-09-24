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

/**
 * @brief изменяет размер массива
 * @param arr наш массив
 * @param m Новый размер
 */
void reSizeArray(SafeArray& arr, int m) {
    int n = arr.size;

    if (m == n) {
        return;
    }

    int* newData = new int[m]{};

    if (m < n) {
        cout << "удалено: ";
        for (int i = m; i < n; i++) {
            cout << arr.data[i] << " ";
        }
        cout << endl;

        for (int i = 0; i < m; i++) {
            newData[i] = arr.data[i];
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            newData[i] = arr.data[i];
        }
    }

    delete[] arr.data;
    arr.data = newData;
    arr.size = m;
}

int main() {
    SafeArray arr = createArray(3);
    getElement(arr, 0) = 10;
    getElement(arr, 1) = 10;
    getElement(arr, 2) = 10;
    printSafe(arr);
    reSizeArray(arr, 9);
    printSafe(arr);

    return 0;
}