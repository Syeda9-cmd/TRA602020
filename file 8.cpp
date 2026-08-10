#include<iostream>
using namespace std;
struct Date {
    int month;
    int day;
    int year;
};
int main() {
    Date d;
    char slash;
    cout << "Enter date (MM/DD/YYYY): ";
    cin >> d.month >> slash >> d.day >> slash >> d.year;
    cout << "Date: " << d.month << "/"
         << d.day << "/" << d.year << endl;
    return 0;
}
