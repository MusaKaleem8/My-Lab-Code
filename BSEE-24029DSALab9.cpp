// BSEE-24029DSALab9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


int arr[100];     // Array to store elements
int n = 0;        // Number of elements in array

// Function to display the array
void displayArray() {
    // Check if array is empty
    if (n == 0) {
        cout << "Array is empty."<<endl;
        return;
    }

    // Print array elements
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to perform Bubble Sort
void bubbleSort() {
    // Check for corner cases
    if (n <= 1) {
        cout << "Array is too small to sort."<<endl;
        return;
    }

    // Display array before sorting
    cout << "Before Bubble Sort:"<<endl;
    displayArray();

    // Bubble Sort logic
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if elements are in wrong order
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Display array after sorting
    cout << "After Bubble Sort:";
    displayArray();
}

// Function to perform Selection Sort
void selectionSort() {
    // Check for corner cases
    if (n <= 1) {
        cout << "Array is too small to sort."<<endl;
        return;
    }

    // Display array before sorting
    cout << "Before Selection Sort:"<<endl;
    displayArray();

    // Selection Sort logic
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // Assume current index has minimum value

        // Find the minimum element in remaining array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap minimum element with current element
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    // Display array after sorting
    cout << "After Selection Sort:"<<endl;
    displayArray();
}

// Function to perform Insertion Sort
void insertionSort() {
    // Check for corner cases
    if (n <= 1) {
        cout << "Array is too small to sort."<<endl;
        return;
    }

    // Display array before sorting
    cout << "Before Insertion Sort:"<<endl;
    displayArray();

    // Insertion Sort logic
    for (int i = 1; i < n; i++) {
        int key = arr[i];    // Element to be inserted
        int j = i - 1;

        // Move elements greater than key one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert key at correct position
        arr[j + 1] = key;
    }

    // Display array after sorting
    cout << "After Insertion Sort:"<<endl;
    displayArray();
}

// Main function
int main() {
    int choice;

    do {
        // Display Menu
        cout << "---MENU---"<<endl;
        cout << "1:Enter elements in array"<<endl;
        cout << "2:Bubble Sort"<<endl;
        cout << "3:Selection Sort"<<endl;
        cout << "4:Insertion Sort"<<endl;
        cout << "5:Display array"<<endl;
        cout << "6:Exit"<<endl;
        cout << "Enter your choice:"<<endl;
        cin >> choice;

        // Perform action based on user choice
        switch (choice) {
        case 1:
            cout << "Enter number of elements (max 100): ";
            cin >> n;

            // Validate array size
            if (n < 0 || n > 100) {
                cout << "Invalid size."<<endl;
                n = 0;
            }
            else {
                cout << "Enter elements:"<<endl;
                for (int i = 0; i < n; i++) {
                    cin >> arr[i];
                }
            }
            break;

        case 2:
            bubbleSort();
            break;

        case 3:
            selectionSort();
            break;

        case 4:
            insertionSort();
            break;

        case 5:
            displayArray();
            break;

        case 6:
            cout << "Exiting program"<<endl;
            break;

        default:
            cout << "Invalid choice."<<endl;
        }

    } while (choice != 6);

    return 0;
}
