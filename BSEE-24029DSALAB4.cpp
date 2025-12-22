#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int value) {
        this->value = value;
        next = nullptr;
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

    // Insert at head
    void InsertAtFront(int value) {
        Node* temp = new Node(value);
        temp->next = head;
        head = temp;

        if (size == 0)  // If list was empty, tail also points to new node
            tail = temp;

        size++;
    }

    // Insert at tail
    void InsertAtTail(int value) {
        Node* temp = new Node(value);

        if (head == nullptr) {
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }

        size++;
    }

    // Insert at index
    bool InsertAtIndex(int value, int position) {
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

        Node* temp = head;

        for (int i = 0; i < position - 1; i++)
            temp = temp->next;

        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;

        size++;
        return true;
    }

    // Delete from start
    bool deleteFromStart() {
        if (head == nullptr)
            return false;

        Node* temp = head;
        head = head->next;

        if (head == nullptr)  // if list became empty
            tail = nullptr;

        delete temp;
        size--;
        return true;
    }

    // Delete from end
    bool deleteFromEnd() {
        if (head == nullptr)
            return false;

        if (head->next == nullptr) {  // Only one element
            delete head;
            head = nullptr;
            tail = nullptr;
            size = 0;
            return true;
        }

        Node* temp = head;
        while (temp->next->next != nullptr)
            temp = temp->next;

        delete temp->next;
        temp->next = nullptr;
        tail = temp;

        size--;
        return true;
    }

    // Delete at index
    bool deleteNodeFromAnyIndex(int position) {
        if (position < 0 || position >= size || head == nullptr)
            return false;

        if (position == 0)
            return deleteFromStart();

        if (position == size - 1)
            return deleteFromEnd();

        Node* temp = head;
        for (int i = 0; i < position - 1; i++)
            temp = temp->next;

        Node* toDelete = temp->next;
        temp->next = toDelete->next;

        delete toDelete;
        size--;
        return true;
    }

    // Check if list is empty
    bool isEmpty() {
        return head == nullptr;
    }

    // Print list
    void printLinkedList() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        cout << "Linked List: ";

        while (temp != nullptr) {
            cout << temp->value;
            if (temp->next != nullptr)
                cout << " -> ";
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
        cout << "1: Insert at Front"<<endl;
        cout << "2: Insert at Tail"<<endl;
        cout << "3: Insert at Index"<<endl;
        cout << "4: Delete from Start" << endl;
        cout << "5: Delete from End" << endl;
        cout << "6: Delete from Index" << endl;
        cout << "7: Check if Empty" << endl;
        cout << "8: Print Linked List" << endl;
        cout << "Enter choice: " << endl;
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
            if (!list.InsertAtIndex(value, position))
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
            if (!list.deleteNodeFromAnyIndex(position))
                cout << "Invalid Index!" << endl;
            break;

        case 7:
            cout << (list.isEmpty() ? "List is empty." : "List is not empty.") << endl;
            break;

        case 8:
            list.printLinkedList();
            break;

        default:
            cout << "Invalid choice!" << endl;
        }
    }
}
