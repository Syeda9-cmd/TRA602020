#include<iostream>
using namespace std;
struct Citizen {
    char cnicID[20];
    char name[30];
    char city[20];
    int age;
};
int main() {
    Citizen c;
    Citizen *ptr;
    ptr = &c;
    cout << "Enter CNIC ID: ";
    cin >> ptr->cnicID;
    cout << "Enter Name: ";
    cin >> ptr->name;
    cout << "Enter City: ";
    cin >> ptr->city;
    cout << "Enter Age: ";
    cin >> ptr->age;
    int choice;
    cout << "Press 1 to update city of residence, 0 to display record: ";
    cin >> choice;
    if (choice == 1) {
        cout << "Enter new city: ";
        cin >> ptr->city;
        cout << "--- Updated NADRA Record ---" << endl;
    } else {
        cout << "--- NADRA Record ---" << endl;
    }
    cout << "CNIC ID : " << ptr->cnicID << endl;
    cout << "Name    : " << ptr->name << endl;
    cout << "City    : " << ptr->city << endl;
    cout << "Age     : " << ptr->age << endl;
    return 0;
}
