// BSEE-24029DSALab1Task4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Complex {
private:
    int a;
    int b;
public:

    void Getvalue(int c, int d) {
        a = c;
        b = d;
    }

    void display() const {
        if (b >= 0)
            cout << a << " + " << b << "i" << endl;
        else
            cout << a << " - " << -b << "i" << endl;
    }

    Complex add(const Complex& c2) const {
        Complex temp;
        temp.a = a + c2.a;
        temp.b = b + c2.b;
        return temp;
    }

    Complex subtract(const Complex& c2) const {
        Complex temp;
        temp.a = a - c2.a;
        temp.b = b - c2.b;
        return temp;
    }
};

int main() {
    Complex complex1, complex2, result;
    int real1, imag1, real2, imag2;

    cout << "Enter first complex number:" << endl;
    cout << "Real part:" << endl;
    cin >> real1;
    cout << "Imaginary part:" << endl;;
    cin >> imag1;

    cout << "Enter second complex number:" << endl;
    cout << "Real part:" << endl;
    cin >> real2;
    cout << "Imaginary part:" << endl;
    cin >> imag2;

    complex1.Getvalue(real1, imag1);
    complex2.Getvalue(real2, imag2);

    cout << "First Complex Number:" << endl;
    complex1.display();
    cout << "Second Complex Number:" << endl;
    complex2.display();

    result = complex1.add(complex2);
    cout << "Addition " << endl;
    result.display();

    result = complex1.subtract(complex2);
    cout << "Subtraction" << endl;;
    result.display();
}
