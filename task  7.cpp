#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements (minimum 8): ";
    cin >> n;
    if (n < 8) {
        cout << "Error: Need at least 8 elements!" << endl;
        return 1;
    }
    int arr[n];
    int *ptr = arr;
    int *maxPtr = arr;  
    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i < n; i++) {
        if (*(arr + i) > *maxPtr) {
            maxPtr = arr + i;  
        }
    }
    cout << "\nMaximum value : " << *maxPtr << endl;
    cout << "Address of max: " << maxPtr << endl;
    return 0;
}
