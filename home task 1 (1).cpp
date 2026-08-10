#include <iostream>
#include <string>
using namespace std;
struct Date {
    int day;
    int month;
    int year;
};
struct Phonebook {
    string name;
    string city;
    string phone;
    Date   date;    
};
int main() {
    Phonebook pb;
    cout << "Enter name: "; cin >> pb.name;
    cout << "Enter city : "; cin >> pb.city;
    cout << "Enter phone number: "; cin >> pb.phone;
    cout << "Enter day : "; cin >> pb.date.day;
    cout << "Enter month : "; cin >> pb.date.month;
    cout << "Enter year : "; cin >> pb.date.year;
    cout << "\n--- Phonebook Entry ---\n";
    cout << "Name  : " << pb.name  <<endl;
    cout << "City  : " << pb.city  <<endl;
    cout << "Phone : " << pb.phone <<endl;
    cout << "Date  : " << pb.date.day   << "/"<< pb.date.month << "/"
                          << pb.date.year  <<endl;
    return 0;
}
