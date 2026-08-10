#include <iostream>
using namespace std;
int main() {
    int a, b, c, d, e;
    int *ptrArr[5];   
    ptrArr[0] = &a;
    ptrArr[1] = &b;
    ptrArr[2] = &c;
    ptrArr[3] = &d;
    ptrArr[4] = &e;
    cout << "Enter value for a: ";
    cin >> a;
    cout << "Enter value for b: ";
    cin >> b;
    cout << "Enter value for c: ";
    cin >> c;
    cout << "Enter value for d: ";
    cin >> d;
    cout << "Enter value for e: ";
    cin >> e;
    for (int i = 0; i < 5; i++) {
        cout << "ptrArr[" << i << "]\t" << *ptrArr[i] << "\t" << ptrArr[i] << endl;
    }
    return 0;
}
