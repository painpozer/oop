#include <iostream>
using namespace std;

/**
* @brief Выделяет память под двумерный массив (матрицу), заполненный нулями
* @param rows Количество строк
* @param cols Количество столбцов
**/
int** allocateMatrix(int rows, int cols) {
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

/**
* @brief функция заполнения
* @param matrix Наша матрица
* @param rows Количество строк
* @param cols Количество столбцов
**/
void fillMatrix(int** matrix, int rows, int cols) {
    cout << "введи " << rows * cols << " элементов" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j]; // Теперь здесь память существует, SIGBUS не будет!
        }
    }
}

int main() {

    int rows = 2;
    int cols = 2;
    int** myMatrix = allocateMatrix(rows, cols);
    fillMatrix(myMatrix, rows, cols);

    return 0;

}









