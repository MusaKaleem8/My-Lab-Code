// BSEE-24029DSALab13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> //for input/output
#include <vector>    // for dynamic arrays
#include <list>      // for chaining linked list
using namespace std;
//enum to select collision handling technique
enum Technique {
    CHAINING = 1,
    LINEAR = 2,
    QUADRATIC = 3,
    DOUBLE_HASHING = 4
};

class HashTable {
private:
    int tableSize;   // size of hash table
    int prime;     //prime number used in double hashing
    Technique technique;//collison handling technique selected

    vector<int> table; // store keys
    vector<bool> occupied;  //true idf slot is occupied
    vector<bool> deletedSlot; // true if slot was deleted

    vector<list<int>> chainTable; // used for chaining

    int hash1(int key) {    // Primary hash function
        return key % tableSize;
    }

    int hash2(int key) {   //secondary hash function
        return prime - (key % prime);
    }

public: 
    HashTable(int size, Technique tech) {
        tableSize = size;
        technique = tech;
        prime = size - 1; // Used for double hashing
        // If chaining is selected
        if (technique == CHAINING) {
            chainTable.resize(tableSize);
        }
        // If open addressing is selected
        else {
            table.resize(tableSize, -1);
            occupied.resize(tableSize, false);
            deletedSlot.resize(tableSize, false);
        }
    }

    // Insert
    void insert(int key) {
        // Chaining insertion
        if (technique == CHAINING) {
            int index = hash1(key);
            chainTable[index].push_back(key);
            cout << "Inserted using Chaining"<<endl;
            return;
        }
        // Open addressing insertion
        int index = hash1(key);

        for (int i = 0; i < tableSize; i++) {
            int newIndex;
            // Linear Probing
            if (technique == LINEAR)
                newIndex = (index + i) % tableSize;
            // Quadratic Probing
            else if (technique == QUADRATIC)
                newIndex = (index + i * i) % tableSize;
            else
                // Double Hashing
                newIndex = (index + i * hash2(key)) % tableSize;
            // Insert if slot is empty or deleted
            if (!occupied[newIndex] || deletedSlot[newIndex]) {
                table[newIndex] = key;
                occupied[newIndex] = true;
                deletedSlot[newIndex] = false;
                cout << "Inserted at index " << newIndex << endl;
                return;
            }
        }

        cout << "Hash table is FULL!"<<endl;
    }

    // SEARCH
    void search(int key) {
        // Search in chaining
        if (technique == CHAINING) {
            int index = hash1(key);
            for (int x : chainTable[index]) {
                if (x == key) {
                    cout << "Key found at index " << index << endl;
                    return;
                }
            }
            cout << "Key not found"<<endl;
            return;
        }
        // Search in open addressing
        int index = hash1(key);

        for (int i = 0; i < tableSize; i++) {
            int newIndex;

            if (technique == LINEAR)
                newIndex = (index + i) % tableSize;
            else if (technique == QUADRATIC)
                newIndex = (index + i * i) % tableSize;
            else
                newIndex = (index + i * hash2(key)) % tableSize;

            if (!occupied[newIndex] && !deletedSlot[newIndex])
                break;

            if (occupied[newIndex] && table[newIndex] == key) {
                cout << "Key found at index " << newIndex << endl;
                return;
            }
        }

        cout << "Key not found"<<endl;
    }

    // DELETE
    void remove(int key) {
        // Delete in chaining
        if (technique == CHAINING) {
            int index = hash1(key);
            chainTable[index].remove(key);
            cout << "Key deleted"<<endl;
            return;
        }
        // Delete in open addressing
        int index = hash1(key);

        for (int i = 0; i < tableSize; i++) {
            int newIndex;

            if (technique == LINEAR)
                newIndex = (index + i) % tableSize;
            else if (technique == QUADRATIC)
                newIndex = (index + i * i) % tableSize;
            else
                newIndex = (index + i * hash2(key)) % tableSize;

            if (!occupied[newIndex] && !deletedSlot[newIndex])
                break;

            if (occupied[newIndex] && table[newIndex] == key) {
                occupied[newIndex] = false;
                deletedSlot[newIndex] = true;
                cout << "Key deleted from index " << newIndex << endl;
                return;
            }
        }

        cout << "Key not found"<<endl;
    }

    // DISPLAY
    void display() {
        //display chaining taBLE
        if (technique == CHAINING) {
            for (int i = 0; i < tableSize; i++) {
                cout << i << ": ";
                for (int x : chainTable[i])
                    cout << x << " -> ";
                cout << "NULL"<<endl;
            }
            return;
        }
        //display open addressing table
        for (int i = 0; i < tableSize; i++) {
            cout << i << ": ";
            if (occupied[i])
                cout << table[i];
            else
                cout << "EMPTY";
            cout << endl;
        }
    }
};

int main() {
    int size, choice, tech;

    cout << "Enter Hash Table Size: ";
    cin >> size;

    cout << "Choose Collision Handling Technique:"<<endl;
    cout << "1;Chaining"<<endl;
    cout << "2:Linear Probing"<<endl;
    cout << "3:Quadratic Probing"<<endl;
    cout << "4:Double Hashing"<<endl;
    cin >> tech;

    HashTable ht(size, static_cast<Technique>(tech));

    do {
        cout << "MENU";
        cout << "1:Insert"<<endl;
        cout << "2:Search"<<endl;
        cout << "3:Delete"<<endl;
        cout << "4:Display"<<endl;
        cout << "0:Exit"<<endl;
        cin >> choice;

        int key;
        switch (choice) {
        case 1:
            cout << "Enter key: ";
            cin >> key;
            ht.insert(key);
            break;
        case 2:
            cout << "Enter key: ";
            cin >> key;
            ht.search(key);
            break;
        case 3:
            cout << "Enter key: ";
            cin >> key;
            ht.remove(key);
            break;
        case 4:
            ht.display();
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice"<<endl;
        }
    } while (choice != 0);
    return 0;
}
