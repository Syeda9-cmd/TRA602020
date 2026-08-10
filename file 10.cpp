#include<iostream>
using namespace std;
struct Time {
    int hours;
    int minutes;
    int seconds;
};
int main() {
    Time t1, t2, t3;
    char colon;
    cout << "Enter first time (HH:MM:SS): ";
    cin >> t1.hours >> colon >> t1.minutes >> colon >> t1.seconds;
    cout << "Enter second time (HH:MM:SS): ";
    cin >> t2.hours >> colon >> t2.minutes >> colon >> t2.seconds;
    long totalSecs = (t1.hours * 3600 + t1.minutes * 60 + t1.seconds)
                   + (t2.hours * 3600 + t2.minutes * 60 + t2.seconds);
    t3.hours   =  totalSecs / 3600;
    t3.minutes = (totalSecs % 3600) / 60;
    t3.seconds =  totalSecs % 60;
    cout << "Result: " << t3.hours << ":"
         << t3.minutes << ":" << t3.seconds << endl;
    return 0;
}
