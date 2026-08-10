#include <iostream>
using namespace std;
void exchangeValues(int *p1, int *p2, int *p3, int *p4) {
    int temp;
    temp = *p1;
    *p1  = *p2;
    *p2  = temp;
    temp = *p3;
    *p3  = *p4;
    *p4  = temp;
}
int main() {
    int a, b, c, d;
    cout << "Enter 1st integer: "; cin >> a;
    cout << "Enter 2nd integer: "; cin >> b;
    cout << "Enter 3rd integer: "; cin >> c;
    cout << "Enter 4th integer: "; cin >> d;
    cout << "\nBefore exchange: a=" << a << "  b=" << b << "  c=" << c << "  d=" << d << "\n";
    exchangeValues(&a, &b, &c, &d);
    cout << "After  exchange: a=" << a << "  b=" << b << "  c=" << c << "  d=" << d << "\n";
    return 0;
}
