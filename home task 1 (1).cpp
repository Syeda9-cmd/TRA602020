#include<iostream>
using namespace std;
struct Hotel {
    string name;
    int dishes;
    float bill;
};
int main() {
    Hotel h[3];
    float totalBill = 0;
    for(int i = 0; i < 3; i++) {
        cout << "Enter hotel name: ";
        cin >> h[i].name;
        cout << "Enter number of dishes: ";
        cin >> h[i].dishes;
        cout << "Enter total bill: ";
        cin >> h[i].bill;
        totalBill += h[i].bill;
    }
    float tax = totalBill * 0.15;
    cout << "\nAll Hotel Records:" << endl;
    for(int i = 0; i < 3; i++) {
        cout << "\nHotel : " << h[i].name  << endl;
        cout << "Dishes: " << h[i].dishes << endl;
        cout << "Bill  : $" << h[i].bill   << endl;
    }
    cout << "\nTotal Bill (before tax): $" << totalBill << endl;
    cout << "Tax (15%):               $" << tax << endl;
    cout << "Total Bill (after tax):  $" << totalBill + tax << endl;
    return 0;
}
