// DSA Lab 6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class Stack {
public:
    int top;
    int size;
    int* array;
    Stack(int a) {
        size = a;
        array = new int[size];
        top = -1;
    }
    bool isFull() {
        return top == size - 1;
    }
    bool isEmpty() {
        return top == -1;
    }
    void push(int value) {
        if (isFull()) {
            cout << "Stack is already full so cannot push another value"<<endl;
        }
        else {
            top++;
            array[top] = value;
            cout << value << "Pushed in stack"<<endl;
        }
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty so cannot pop" << endl;;
        }
        else {
            cout << array[top] << "Popped from stack"<<endl;
            top--;
        }
    }
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty so no top element."<<endl;
        }
        else {
            cout << "Top element is:" << array[top] << endl;
        }
    }
};
int main()
{
    int size;
    cout << "Enter stack size: ";
    cin >> size;

    Stack stack(size);

    int choice, value;

    while (true) {
        cout << "---MENU---";
        cout << "1:Push" << endl;
        cout << "2:Pop"<<endl;
        cout << "3:Peek (Top Element)"<<endl;
        cout << "4:Check if Empty"<<endl;
        cout << "5:Exit"<<endl;
        cout << "Enter your choice:"<<endl;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push:"<<endl;
            cin >> value;
            stack.push(value);
            break;

        case 2:
            stack.pop();
            break;

        case 3:
            stack.peek();
            break;

        case 4:
            if (stack.isEmpty())
                cout << "Stack is empty"<<endl;
            else
                cout << "Stack is not empty."<<endl;
            break;

        case 5:
            cout << "Exiting program"<<endl;
           

        default:
            cout << "Invalid choice"<<endl;
        }
    }

}

