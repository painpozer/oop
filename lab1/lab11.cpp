#include <iostream>
using namespace std;

void fillArray(int (&arr)[10]) {
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 100;
    }
}

int main()
{
    int arr[10];
    fillArray(arr);
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";

    }
    return 0;
}