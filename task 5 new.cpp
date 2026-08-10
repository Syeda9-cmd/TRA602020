#include <iostream>
using namespace std;

int main() {
    float arr[10];

    cout << "Enter 10 floating-point values:" << endl;
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];         
    }

    float *ptr = arr + 9;      

    cout << "\nArray in reverse order:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << *ptr << " ";  
        ptr--;                 
    }
    cout << endl;

    return 0;
}
