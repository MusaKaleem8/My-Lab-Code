// BSEE-24029DSALab1Task3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class complex {
private:
    int a, b;
public:
    void Getvalue(int c, int d) {
        a = c;
        b = d;
    }
    void display() {
        cout << a << "+" << b << "i" << endl;
    }

};
int main()
{
    complex c1;
    int realpart;
    int imagpart;
    cout << "Enter real part" << endl;
    cin >> realpart;
    cout << "Enter imaginary part" << endl;
    cin >> imagpart;
    c1.Getvalue(realpart, imagpart);
    c1.display();
}
