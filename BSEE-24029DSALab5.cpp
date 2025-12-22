// BSEE-24029DSALab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node* prev;

    Node(int value) {
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;
    int size;

    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    // 1: Inserting at Front
    void InsertAtFront(int value) {
        Node* temp = new Node(value);

        if (head == nullptr) { // Empty list
            head = tail = temp;
        }
        else {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        size++;
    }

    // 2: Inserting at Tail
    void InsertAtTail(int value) {
        Node* temp = new Node(value);

        if (head == nullptr) { // Empty list
            head = tail = temp;
        }
        else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }

    // 3: Inserting at Any Index
    bool insertAtAnyNode(int value, int position) {
        if (position < 0 || position > size)
            return false;

        if (position == 0) {
            InsertAtFront(value);
            return true;
        }

        if (position == size) {
            InsertAtTail(value);
            return true;
        }

        Node* newNode = new Node(value);
        Node* temp = head;

        for (int i = 0; i < position - 1; i++)
            temp = temp->next;

        newNode->next = temp->next;
        newNode->prev = temp;

        temp->next->prev = newNode;
        temp->next = newNode;

        size++;
        return true;
    }

    // 4: Deleting from Start
    bool deleteFromStart() {
        if (head == nullptr)
            return false;

        Node* temp = head;

        if (head == tail) { // Only one element
            head = tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }

        delete temp;
        size--;
        return true;
    }

    // 5: DeletIng from End
    bool deleteFromEnd() {
        if (head == nullptr)
            return false;

        Node* temp = tail;

        if (head == tail) { // One element only
            head = tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete temp;
        size--;
        return true;
    }

    // 6: Deleting from Any Index
    bool deleteNodeFromAnyNode(int position) {
        if (position < 0 || position >= size)
            return false;

        if (position == 0)
            return deleteFromStart();

        if (position == size - 1)
            return deleteFromEnd();

        Node* temp = head;

        for (int i = 0; i < position; i++)
            temp = temp->next;

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
        size--;
        return true;
    }

    // 7 Checking if  linkedlist is empty
    bool IsEmpty() {
        return head == nullptr;
    }

    // 8: Printing Linked List
    void PrintLinkedList() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        cout << "Linked List: ";

        while (temp != nullptr) {
            cout << temp->value;
            if (temp->next != nullptr)
                cout << " <-> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int choice, value, position;

    while (true) {
        cout << "==MENU=="<<endl;
        cout << "1:Insert at Front"<<endl;
        cout << "2:Insert at Tail"<<endl;
        cout << "3:Insert at Any Index"<<endl;
        cout << "4:Delete from Start"<<endl;
        cout << "5:Delete from End"<<endl;
        cout << "6:Delete from Any Index"<<endl;
        cout << "7:Check if Empty"<<endl;
        cout << "8:Print Linked List"<<endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.InsertAtFront(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.InsertAtTail(value);
            break;

        case 3:
            cout << "Enter value and index: ";
            cin >> value >> position;
            if (!list.insertAtAnyNode(value, position))
                cout << "Invalid Index!" << endl;
            break;

        case 4:
            if (!list.deleteFromStart())
                cout << "List is empty!" << endl;
            break;

        case 5:
            if (!list.deleteFromEnd())
                cout << "List is empty!" << endl;
            break;

        case 6:
            cout << "Enter index: ";
            cin >> position;
            if (!list.deleteNodeFromAnyNode(position))
                cout << "Invalid Index!" << endl;
            break;

        case 7:
            if (list.IsEmpty())
                cout << "List is empty." << endl;
            else
                cout << "List is not empty." << endl;
            break;

        case 8:
            list.PrintLinkedList();
            break;

        default:
            cout << "Invalid choice!" << endl;
        }
    }
}



