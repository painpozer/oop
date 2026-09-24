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

/**
 * @brief Красиво выводит матрицу на экран
 * @param matrix Указатель на матрицу
 * @param rows Количество строк
 * @param cols Количество столбцов
 * @param showBorders Рисовать ли рамку из '*' (по умолчанию true)
 * @param title Заголовок над матрицей (по умолчанию "Matrix")
 */
void printMatrix(int** matrix, int rows, int cols, bool showBorders = true, string title = "Matrix") {
    cout << "\n ||| " << title << " |||\n";

    if (showBorders) {
        cout << "*";
        for (int j = 0; j < cols; ++j) {
            cout << "******";
        }
        cout << "*\n";
    }

    for (int i = 0; i < rows; ++i) {
        if (showBorders) cout << "*";
        for (int j = 0; j < cols; ++j) {
            cout << " " << matrix[i][j];
            int len = to_string(matrix[i][j]).length();
            for (int k = len; k < 4; ++k) cout << " ";
            if (showBorders) cout << "*";
        }
        cout << "\n";
    }

    if (showBorders) {
        cout << "*";
        for (int j = 0; j < cols; ++j) {
            cout << "******";
        }
        cout << "*\n";
    }
    cout << endl;
}

int main() {

    int rows = 7;
    int cols = 2;
    int** myMatrix = allocateMatrix(rows, cols);
    fillMatrix(myMatrix, rows, cols);
    printMatrix(myMatrix, rows, cols, true);

    return 0;

}









