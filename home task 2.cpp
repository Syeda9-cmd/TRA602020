#include <iostream>
using namespace std;
struct Parameters {
    double length;
    double width;
};
struct Result {
    double area;
    double perimeter;
};
struct Rectangle {
    Parameters info;    
    Result     result;   
};
int main() {
    Rectangle rect;
    cout << "Enter length: "; cin >> rect.info.length;
    cout << "Enter width : "; cin >> rect.info.width;
    rect.result.area      = rect.info.length * rect.info.width;
    rect.result.perimeter = 2 * (rect.info.length + rect.info.width);
    cout << "\n--- Rectangle Results ---\n";
    cout << "Length    : " << rect.info.length    << endl;
    cout << "Width     : " << rect.info.width     << endl;
    cout << "Area      : " << rect.result.area      << endl;
    cout << "Perimeter : " << rect.result.perimeter << endl;
    return 0;
}
