#include <iostream>
#include <string>
using namespace std;


class Address {
private:
    int HouseNumber;
    int StreetNumber;
    string CityName;

public:
    void input() {
        cout << "Enter house number: ";
        cin >> HouseNumber;
        cout << "Enter street number: ";
        cin >> StreetNumber;
        cin.ignore();
        cout << "Enter city name: ";
        getline(cin, CityName);
    }

    void display() {
        cout << "\n--- Address Information ---\n";
        cout << "House Number: " << HouseNumber << endl;
        cout << "Street Number: " << StreetNumber << endl;
        cout << "City Name: " << CityName << endl;
    }
};

void Loops() {
    int n;
    cout << "Enter a number to demonstrate loops: ";
    cin >> n;

    cout << "\nFor Loop: ";
    for (int i = 1; i <= n; i++) {
        cout << i << " ";
    }

    cout << "\nWhile Loop: ";
    int j = 1;
    while (j <= n) {
        cout << j << " ";
        j++;
    }
    cout << endl;
}


int main() {
    int choice;
    Address addr;

    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Demonstrate Loops (For & While)\n";
        cout << "2. Enter and Display Address\n";
        cout << "3. Exit Program\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            Loops();
            break;
        case 2:
            addr.input();
            addr.display();
            break;
        case 3:
            cout << "Exiting program\n";
            break;
        default:
            cout << "Invalid choice. Enter a valid choice\n";
        }
    } while (choice != 3);

    return 0;
}
