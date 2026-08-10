#include <iostream>
using namespace std;
struct Data {
    string name;    
    string color;   
};
struct Car {
    string model;      
    float  topSpeed;   
    int    gears;
    Data   more;       
};
int main() {
    Car car;
    cout << "Enter car name   : "; cin >> car.more.name;
    cout << "Enter car color  : "; cin >> car.more.color;
    cout << "Enter model      : "; cin >> car.model;
    cout << "Enter top speed  : "; cin >> car.topSpeed;
    cout << "Enter no. of gears: "; cin >> car.gears;
    if (car.topSpeed > 200 && car.gears > 4) {
        cout << "Car Details";
        cout << "Name     : " << car.more.name  << endl;
        cout << "Color    : " << car.more.color << endl;
        cout << "Model    : " << car.model      << endl;
        cout << "Top Speed: " << car.topSpeed   << endl;
        cout << "Gears    : " << car.gears      << endl;
        cout << "Status   : Your car IS suitable for the race!"<<endl;
    } else {
        cout <<"Your car is NOT suitable for the race."<<endl;
    }
    return 0;
}
