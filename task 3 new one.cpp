#include <iostream>
using namespace std;
struct Complex {
    float real;
    float imag;
};
Complex addition(Complex a, Complex b) {
    Complex res;
    res.real = a.real + b.real;
    res.imag = a.imag + b.imag;
    return res;
}
Complex subtract(Complex a, Complex b) {
    Complex res;
    res.real = a.real - b.real;
    res.imag = a.imag - b.imag;
    return res;
}
Complex multiply(Complex a, Complex b) {
    Complex res;
    res.real = a.real * b.real - a.imag * b.imag;
    res.imag = a.real * b.imag + a.imag * b.real;
    return res;
}
void print(const char* label, Complex c) {
    cout << label << c.real;
    if (c.imag >= 0) cout << " + " <<  c.imag << "i"<<endl;
    else             cout << " - " << -c.imag << "i"<<endl;
}
int main() {
    Complex c1, c2;
    cout << "Enter first complex number  (real+imag): ";
    cin  >> c1.real >> c1.imag;
    cout << "Enter second complex number (real+imag): ";
    cin  >> c2.real >> c2.imag;
    Complex sum  = addition(c1, c2);
    Complex diff = subtract(c1, c2);
    Complex prod = multiply(c1, c2);
    cout << "Results"<<endl;
    print("Addition    : ", sum);
    print("Subtraction : ", diff);
    print("Multiply    : ", prod);
    return 0;
}
