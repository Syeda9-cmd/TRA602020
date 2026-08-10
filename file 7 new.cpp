#include<iostream>
using namespace std;
struct Employee {
    int empNumber;
    float compensation;
};
int main() {
    Employee emp[3];
    for(int i = 0; i < 3; i++) {
        cout << "Enter employee number for employee " << i+1 << ": ";
        cin >> emp[i].empNumber;
        cout << "Enter compensation for employee " << i+1 << ": $";
        cin >> emp[i].compensation;
    }
    cout << "\nEmployee Records:" << endl;
    for(int i = 0; i < 3; i++) {
        cout << "\nEmployee " << i+1 << ":" << endl;
        cout << "Number: "       << emp[i].empNumber << endl;
        cout << "Compensation: $" << emp[i].compensation << endl;
    }
    return 0;
}
