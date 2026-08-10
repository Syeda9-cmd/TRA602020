#include <iostream>
using namespace std;
int main() {
    int   a = 10;
    float b = 3.14;
    char  c = 'Z';
    cout << "Variable  |  Value  |  Address\n";
    cout << "   a (int)   |  " << a << "     |  " << &a << "\n";
    cout << "   b (float) |  " << b << "  |  " << &b << "\n";
    cout << "   c (char)  |  " << c << "     |  " << (void*)&c << "\n";
    return 0;
}
