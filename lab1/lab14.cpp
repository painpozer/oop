#include <iostream>
using namespace std;

/**
* @brief Выделяет память под двумерный массив (матрицу), заполненный нулями
* @param rows Количество строк
* @param cols Количество столбцов
**/
int** allocateMatrix(int rows, int cols) {
    int** matrix = new int*[rows]{};
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols]{};
    }
}



int main() {

    int rows = 3;
    int cols = 3;
    int** myMatrix = allocateMatrix(rows, cols);

    return 0;

}









