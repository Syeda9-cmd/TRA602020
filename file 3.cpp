#include<iostream>
using namespace std;
struct Car {
    string model;
    string color;
    float price;
};
int main() {
    Car cars[5];
    for(int i = 0; i < 5; i++) {
        cout << "Enter model of car " << i+1 << ": ";
        cin >> cars[i].model;
        cout << "Enter color of car " << i+1 << ": ";
        cin >> cars[i].color;
        cout << "Enter price of car " << i+1 << ": ";
        cin >> cars[i].price;
    }
    int choice;
    cout << "\nEnter 1 to see most costly car, 2 to see all cars: ";
    cin >> choice;
    if(choice == 1) {
        int maxIndex = 0;
        for(int i = 1; i < 5; i++) {
            if(cars[i].price > cars[maxIndex].price)
                maxIndex = i;
        }
        cout << "\nMost Costly Car:" << endl;
        cout << "Model: " << cars[maxIndex].model << endl;
        cout << "Color: " << cars[maxIndex].color << endl;
        cout << "Price: " << cars[maxIndex].price << endl;
    }
    else if(choice == 2) {
        for(int i = 0; i < 5; i++) {
            cout << "\nCar " << i+1 << ":" << endl;
            cout << "Model: " << cars[i].model << endl;
            cout << "Color: " << cars[i].color << endl;
            cout << "Price: " << cars[i].price << endl;
        }
    }
    return 0;
}
