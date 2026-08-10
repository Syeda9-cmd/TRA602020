#include <iostream>
using namespace std;
int main() {
    char str[100];
    cout << "Enter a string: ";
    cin >> str;
    char *ptr = str;
    int length = 0;
    while (*ptr != '\0') {
        length++;
        ptr++;
    }
    ptr--;
    cout << "Length of string: " << length << endl;
    cout << " Reverse string:";
    for (int i = 0; i < length; i++) {
        cout << *ptr;
        ptr--;   
    }
    cout << endl;
    return 0;
}
