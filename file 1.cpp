#include<iostream>
using namespace std;
struct Country {
    string name;
    float population;
};
int main() {
    Country c;
    cout << "Enter country name: ";
    cin >> c.name;
    cout << "Enter population (in millions): ";
    cin >> c.population;
    cout << "\nCountry Name: " << c.name << endl;
    cout << "Population: " << c.population << " million" << endl;
    return 0;
}
