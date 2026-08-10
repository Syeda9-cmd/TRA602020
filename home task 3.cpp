#include <iostream>
#include <string>
using namespace std;
struct Instructor {
    string name;
    string department;
};
struct Course {
    string     courseCode;
    string     courseName;
    int        creditHours;
    int        maxSeats;
    int        enrolledStudents;
    Instructor instructor; 
};
bool enrollStudent(Course &c) {
    if (c.enrolledStudents < c.maxSeats) {
        c.enrolledStudents++;
        return true;
    }
    cout << "Course Full!" << endl;
    return false;
}
void displayCourse(Course c) {
    int remaining = c.maxSeats - c.enrolledStudents;
    cout << "Code        : " << c.courseCode  <<"\n";
    cout << "Name        : " << c.courseName  << "\n";
    cout << "Credit Hours: " << c.creditHours << "\n";
    cout << "Instructor  : " << c.instructor.name
         << " (" << c.instructor.department << ")\n";
    cout << "Seats       : " << c.enrolledStudents << " / "
         << c.maxSeats << " (" << remaining << " remaining)\n";
}
int main() {
    Course c1;
    c1.courseCode             = "CS-301";
    c1.courseName             = "Object Oriented Programming";
    c1.creditHours            = 3;
    c1.maxSeats               = 2;
    c1.enrolledStudents       = 0;
    c1.instructor.name        = "Miss Eisha Nawaz";
    c1.instructor.department  = "CS Department";
    Course c2;
    c2.courseCode             = "CS-302";
    c2.courseName             = "Data Structures";
    c2.creditHours            = 3;
    c2.maxSeats               = 30;
    c2.enrolledStudents       = 0;
    c2.instructor.name        = "Mr. Ali Hassan";
    c2.instructor.department  = "CS Department";
    for (int i = 1; i <= 3; i++) {
        cout << "Enrolling student " << i << " in OOP... ";
        if (enrollStudent(c1))
            cout << "Success!\n";
    }
    cout << "\n=== Course Details ===\n";
    displayCourse(c1);
    cout << "\n";
    displayCourse(c2);
    return 0;
}
