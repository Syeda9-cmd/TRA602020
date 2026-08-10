#include <iostream>
using namespace std;
int main() {
    int rows, cols;
    cout << "Enter number of rows   : "; cin >> rows;
    cout << "Enter number of columns: "; cin >> cols;
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * cols + j + 1;
        }
    }
    cout << "\nMatrix (" << rows << " x " << cols << "):\n";
    for (int i = 0; i < rows; i++) {
        cout << "  ";
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j];
            if (j < cols - 1) cout << "\t";
        }
        cout << "\n";
    }
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    cout << "\nMemory deallocated successfully.\n";
    return 0;
}
