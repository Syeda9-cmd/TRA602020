#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Student {
    int rollNo;
    string name;
    string section;
    float cgpa;
};
int main() {
    ofstream outFile("student.txt");
    Student students[2];
    students[0] = {1, "Ali Hassan",   "CS-A", 3.75};
    students[1] = {2, "Sara Ahmed",   "CS-B", 3.90};
    for (int i = 0; i < 2; i++) {
        outFile << students[i].rollNo  << "\n";
        outFile << students[i].name    << "\n";
        outFile << students[i].section << "\n";
        outFile << students[i].cgpa    << "\n";
        outFile << "---\n";
    }
    outFile << "Total students: 2\n";
    outFile.close();
    cout << "Student records written to student.txt\n\n";
    ifstream inFile("student.txt");
    cout << "          STUDENT DATABASE RECORDS        \n";
    cout << "==========================================\n";
    Student s;
    string separator;
    while (inFile >> s.rollNo) {
        inFile.ignore();
        getline(inFile, s.name);
        getline(inFile, s.section);
        inFile >> s.cgpa;
        inFile.ignore();
        getline(inFile, separator);
        if (separator == "---") {
            cout << "Roll No  : " << s.rollNo  << "\n";
            cout << "Name     : " << s.name    << "\n";
            cout << "Section  : " << s.section << "\n";
            cout << "CGPA     : " << s.cgpa    << "\n";
            cout << "------------------------------------------\n";
        } else {
            cout << "\n>>> " << s.rollNo << " " << s.name << " "
                 << s.section << " " << separator << "\n";
        }
    }
    inFile.close();
    return 0;
}
