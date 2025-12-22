// BSEE-24029DSALab8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    // Insert at rear
    void enqueue(int value) {
        Node* temp = new Node(value);

        if (rear == nullptr) {  // Queue empty
            front = rear = temp;
        }
        else {
            rear->next = temp;
            rear = temp;
        }

        cout << "Enqueued: " << value << endl;
    }

    // Remove front
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return;
        }

        Node* temp = front;
        cout << "Dequeued: " << front->data << endl;

        front = front->next;

        if (front == nullptr)
            rear = nullptr;

        delete temp;
    }

    // Front element
    void showFront() {
        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Front element: " << front->data << endl;
    }

    // Check empty
    void isEmpty() {
        if (front == nullptr)
            cout << "Queue is empty" << endl;
        else
            cout << "Queue is NOT empty" << endl;
    }

    // Display all
    void display() {
        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    while (true) {
        cout << "---MENU---" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2:Dequeue" << endl;
        cout << "3:Show Front" << endl;
        cout << "4:Check Empty" << endl;
        cout << "5: Display" << endl;
        cout << "6:Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.showFront();
            break;
        case 4:
            q.isEmpty();
            break;
        case 5:
            q.display();
            break;
        case 6:
            return 0;
        default:
            cout << "Invalid choice!" << endl;
        }
    }
}
