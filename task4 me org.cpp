#include <iostream>
using namespace std;
void Largest(int *a, int *b, int *c) {
    int largest = *a;
    if (*b > largest) largest = *b;
    if (*c > largest) largest = *c;
    cout << "Largest  = " << largest << "\n";
}
void Smallest(int *a, int *b, int *c) {
    int smallest = *a;
    if (*b < smallest) smallest = *b;
    if (*c < smallest) smallest = *c;
    cout << "Smallest = " << smallest << "\n";
}
void Average(int *a, int *b, int *c) {
    double avg = (*a + *b + *c) / 3.0;
    cout << "Average  = " << avg << "\n";
}
int main() {
    int x, y, z, choice;
    cout << "Enter three integers:\n";
    cout << "  Number 1: "; cin >> x;
    cout << "  Number 2: "; cin >> y;
    cout << "  Number 3: "; cin >> z;
    do {
        cout << "\n-------- MENU --------\n";
        cout << "1. Find Largest\n";
        cout << "2. Find Smallest\n";
        cout << "3. Find Average\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: Largest (&x, &y, &z); break;
            case 2: Smallest(&x, &y, &z); break;
            case 3: Average (&x, &y, &z); break;
            case 4: cout << "Exiting...\n";   break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);
    return 0;
}
