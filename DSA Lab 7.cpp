// DSA Lab 7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

// Structure of node for linked list
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Creating Stack class
class Stack {
private:
    Node* top;  // Pointer for the top of the stack

public:
    Stack() {
        top = nullptr;
    }

    // Checking if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Pushing value onto  the stack
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;  // new node points to previous top
        top = newNode;        // update top
        cout << value << "Pushed in the Stack"<<endl;
    }

    // Poping value from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty so there is nothing to pop."<<endl;
            return;
        }
        Node* temp = top;
        cout << temp->data << "Popped from the Stack"<<endl;
        top = top->next; // move top down
        delete temp;
    }

    // Viewing top element of the stack
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty so there is no top element"<<endl;
        }
        else {
            cout << "Top element is: " << top->data << endl;
        }
    }
};

// Menu-driven program
int main() {
    Stack s;
    int choice, value;

    while (true) {
        cout << "---MENU ---"<<endl;
        cout << "1: Push element"<<endl;
        cout << "2: Pop element"<<endl;
        cout << "3: View top element"<<endl;
        cout << "4: Check if stack is empty"<<endl;
        cout << "5: Exit"<<endl;
        cout << "Enter your choice:"<<endl;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push:";
            cin >> value;
            s.push(value);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.peek();
            break;

        case 4:
            if (s.isEmpty())
                cout << "Stack is empty"<<endl;
            else
                cout << "Stack is not empty."<<endl;
            break;

        case 5:
            cout << "Exiting program..."<<endl;
            return 0;

        default:
            cout << "Invalid choice!."<<endl;
        }
    }

 
}