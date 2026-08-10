#include <iostream>
#include <string>
using namespace std;
class University;
class Student {
private:
    string name;
    int marks;
    int semester;
public:
    Student(string n, int m, int s) : name(n), marks(m), semester(s) {}
    friend void display(Student, University);
};
class University {
private:
    string universityName;
    int ranking;
public:
    University(string uName, int r) : universityName(uName), ranking(r) {}
    friend void display(Student, University);
};
void display(Student s, University u) {
    cout << "_______Student & University Profile________" << endl;
    cout << "Student Name : " << s.name << endl;
    cout << "Marks        : " << s.marks << endl;
    cout << "Semester     : " << s.semester << endl;
    cout << "____________________________________________" << endl;
    cout << "University   : " << u.universityName << endl;
    cout << "Ranking      : " << u.ranking << endl;
}
int main() {
    Student s1("Ali Ahmed", 87, 4);
    University u1("Superior University", 12);
    display(s1, u1);
    return 0;
}
