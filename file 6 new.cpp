#include<iostream>
using namespace std;
struct Distance {
    int feet;
    float inches;
};

struct Volume {
    Distance length;
    Distance width;
    Distance height;
};
float Feet(Distance d) {
    return d.feet + d.inches / 12.0;
}
int main() {
    Volume room = {{12, 6}, {10, 4}, {8, 0}};
    float l = Feet(room.length);
    float w = Feet(room.width);
    float h = Feet(room.height);
    float volume = l * w * h;
    cout << "Length : " << l << " ft" << endl;
    cout << "Width  : " << w << " ft" << endl;
    cout << "Height : " << h << " ft" << endl;
    cout << "Volume : " << volume << " cubic feet" << endl;
    return 0;
}
