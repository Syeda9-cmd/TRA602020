#include <iostream>
using namespace std;
void inputArray(int *arr, int size) {
    cout << "Enter " << size << " values:\n";
    for (int i = 0; i < size; i++) {
        cout << "  Element [" << i << "]: ";
        cin >> *(arr + i);
    }
}
int main() {
    int SIZE = 5;
    int arr[SIZE];
    inputArray(arr, SIZE);
    cout << "\nArray values are:\n  ";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i];
        if (i < SIZE - 1) cout << "  ";
    }
    cout << "\n";
    return 0;
}
