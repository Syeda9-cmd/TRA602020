#include<iostream>
using namespace std;
struct Time {
    int hours;
    int minutes;
    int seconds;
};
int main() {
    Time t1;
    char colon;
    cout << "Enter time (HH:MM:SS): ";
    cin >> t1.hours >> colon >> t1.minutes >> colon >> t1.seconds;
    long totalSecs = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    cout << "Total seconds: " << totalSecs << endl;
    return 0;
}
