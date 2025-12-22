// BSEE-24029DSALab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class ArrayList {
private:
    int* arr;          // pointer to array
    int elements;      // current number of elements in the array
    int capacity;      // total capacity of the array

public:
    // Constructor
    ArrayList(int cap = 5) {
        capacity = cap;
        elements = 0;
        arr = new int[capacity];
    }

    // Destructor
    ~ArrayList() {
        delete[] arr;
    }

    // checking if array is full
    bool IsFull() {
        return elements == capacity;
    }

    // checking if array is empty
    bool IsEmpty() {
        return elements == 0;
    }

    // expanding capacity of the array by 2
    void expand() {
        int newCapacity = capacity * 2;
        int* newArr = new int[newCapacity];
        for (int i = 0; i < elements; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;

    }

    // adding element at last
    void append(int value) {
        if (IsFull()) {
            expand();
        }
        arr[elements] = value;
        elements++;

    }

    // adding element at start
    void prepend(int value) {
        if (IsFull()) {
            expand();
        }
        for (int i = elements; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = value;
        elements++;

    }

    // adding element at specific index
    void addAtIndex(int index, int value) {
        if (index < 0 || index > elements) {
            cout << "Invalid Index!" << endl;
            return;
        }
        if (IsFull()) {
            expand();
        }
        for (int i = elements; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        elements++;

    }

    // deleting last element
    void deleteFromLast() {
        if (!IsEmpty()) {
            cout << "Element " << arr[elements - 1] << " deleted from last index." << endl;
            elements--;
        }
        else {
            cout << "Array is empty! Cannot delete." << endl;
        }
    }

    // deleting element from specific index
    void deleteFromIndex(int index) {
        if (IsEmpty()) {
            cout << "Array is empty! Cannot delete." << endl;
            return;
        }
        if (index < 0 || index >= elements) {
            cout << "Invalid Index!" << endl;
            return;
        }
        cout << "Element " << arr[index] << " deleted from index " << index << "." << endl;
        for (int i = index; i < elements - 1; i++) {
            arr[i] = arr[i + 1];
        }
        elements--;
    }

    // sort the array
    void sortArray() {
        if (IsEmpty()) {
            cout << "Array is empty! Cannot sort." << endl;
            return;
        }
        for (int i = 0; i < elements - 1; i++) {
            for (int j = 0; j < elements - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

    }

    // insert element at specific index
    void indexAt(int index, int value) {
        addAtIndex(index, value);
    }

    // delete element at specific index
    void deleteAt(int index, int value) {
        deleteFromIndex(index);
    }

    // search for an element
    int search(int value) {
        for (int i = 0; i < elements; i++) {
            if (arr[i] == value) {
                return i;
            }
        }
        return -1;
    }

    // get element at specific index
    int getAt(int index) {
        if (index < 0 || index >= elements) {
            cout << "Invalid Index!" << endl;
            return -1;
        }
        return arr[index];
    }

    // display the array
    void display() {
        if (IsEmpty()) {
            cout << "Array is empty!" << endl;
            return;
        }
        cout << "Array elements: ";
        for (int i = 0; i < elements; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

    }

    // get current elements count
    int getElements() {
        return elements;
    }

    // get current capacity
    int getCapacity() {
        return capacity;
    }
};

int main() {
    int capacity;
    cout << "Enter initial capacity of array: ";
    cin >> capacity;

    ArrayList list(capacity);
    int choice, value, index;

    do {
        cout << "=== Menu ===" << endl;
        cout << "1. Append element" << endl;
        cout << "2. Prepend element" << endl;
        cout << "3. Add at index" << endl;
        cout << "4. Delete from last" << endl;
        cout << "5. Delete from index" << endl;
        cout << "6. Sort array" << endl;
        cout << "7. Search element" << endl;
        cout << "8. Get element at index" << endl;
        cout << "9. Display array" << endl;
        cout << "10. Check if empty" << endl;
        cout << "11. Check if full" << endl;
        cout << "12. Get elements count" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to append: ";
            cin >> value;
            list.append(value);
            break;

        case 2:
            cout << "Enter value to prepend: ";
            cin >> value;
            list.prepend(value);
            break;

        case 3:
            cout << "Enter index: ";
            cin >> index;
            cout << "Enter value: ";
            cin >> value;
            list.addAtIndex(index, value);
            break;

        case 4:
            list.deleteFromLast();
            break;

        case 5:
            cout << "Enter index to delete: ";
            cin >> index;
            list.deleteFromIndex(index);
            break;

        case 6:
            list.sortArray();
            break;

        case 7:
            cout << "Enter value to search: ";
            cin >> value;
            index = list.search(value);
            if (index != -1) {
                cout << "Element found at index: " << index << endl;
            }
            else {
                cout << "Element not found!" << endl;
            }
            break;

        case 8:
            cout << "Enter index: ";
            cin >> index;
            value = list.getAt(index);
            if (value != -1) {
                cout << "Element at index " << index << ": " << value << endl;
            }
            break;

        case 9:
            list.display();
            break;

        case 10:
            if (list.IsEmpty()) {
                cout << "Array is empty." << endl;
            }
            else {
                cout << "Array is not empty." << endl;
            }
            break;

        case 11:
            if (list.IsFull()) {
                cout << "Array is full." << endl;
            }
            else {
                cout << "Array is not full." << endl;
            }
            break;

        case 12:
            cout << "Current elements count: " << list.getElements() << endl;
            break;

        case 0:
            cout << "Exiting program.!" << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}