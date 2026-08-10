#include<iostream>
using namespace std;
struct Student {
    int rollNo;
    float marks[5];
};
int main() {
    Student s;
    cout << "Enter Roll No: ";
    cin >> s.rollNo;
    for(int i = 0; i < 5; i++) {
        cout << "Enter marks for subject " << i+1 << ": ";
        cin >> s.marks[i];
    }
    cout << "\nRoll No: " << s.rollNo << endl;
    for(int i = 0; i < 5; i++) {
        cout << "Subject " << i+1 << " Marks: " << s.marks[i] << endl;
    }
    return 0;
}
