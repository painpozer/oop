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

int main() {

    return 0;
}