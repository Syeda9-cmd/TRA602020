#include <iostream>
#include <string>
using namespace std;
struct Student {
    string name;
    string rollNo;   
    float  marks[3];
    float  gpa;
};
void calculateGPA(Student &s) {
    s.gpa = (s.marks[0] + s.marks[1] + s.marks[2])/300.0*4.0;   
}
void displayStudent(Student s) {
    cout << "Student Details:"<<endl;
    cout << "Name    : " << s.name    << endl;
    cout << "Roll No : " << s.rollNo  << endl;
    cout << "Marks   : " << s.marks[0] <<" "
	                     << s.marks[1] <<" "
                       	<< s.marks[2] << " "<<endl;
    cout << "GPA     : " << s.gpa    <<  "/4.0"<<endl;
}
int main() {
    Student students[2];
    for (int i = 0; i < 2; i++) {
        cout << "Student " << i + 1 <<endl;
        cout << "Enter name : ";
        cin  >> students[i].name;
        cout << "Enter roll number : ";
        cin  >> students[i].rollNo;
        for (int j = 0; j < 3; j++) {
            cout << "Enter marks for Subject " << j + 1 << ": ";
            cin  >> students[i].marks[j];
        }
        calculateGPA(students[i]);
        displayStudent(students[i]);
    }
    return 0;
}
