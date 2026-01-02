
#include <iostream>
using namespace std;

// Node structure for the tree
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};
// Binary Tree Class
class BinaryTree {
protected:
    Node* root;
    // Helper function for inorder traversal
    void inorderHelper(Node* node) {
        if (node == NULL) return;
        inorderHelper(node->left);
        cout << node->data << " ";
        inorderHelper(node->right);
    }
    // Helper function for preorder traversal
    void preorderHelper(Node* node) {
        if (node == NULL) return;
        cout << node->data << " ";
        preorderHelper(node->left);
        preorderHelper(node->right);
    }
    // Helper function for postorder traversal
    void postorderHelper(Node* node) {
        if (node == NULL) return;
        postorderHelper(node->left);
        postorderHelper(node->right);
        cout << node->data << " ";
    }
public:
    BinaryTree() {
        root = NULL;
    }
    // Insert node in binary tree (level order)
    void insert(int value) {
        Node* newNode = new Node(value);

        if (root == NULL) {
            root = newNode;
            cout << "Root node inserted successfully!" << endl;
            return;
        }
        // Use a simple queue simulation for level order insertion
        Node* queue[100];
        int front = 0, rear = 0;
        queue[rear++] = root;

        while (front < rear) {
            Node* current = queue[front++];

            if (current->left == NULL) {
                current->left = newNode;
                cout << "Node inserted successfully!" << endl;
                return;
            }
            else {
                queue[rear++] = current->left;
            }

            if (current->right == NULL) {
                current->right = newNode;
                cout << "Node inserted successfully!" << endl;
                return;
            }
            else {
                queue[rear++] = current->right;
            }
        }
    }
    // Inorder traversal
    void inorder() {
        if (root == NULL) {
            cout << "Tree is empty!" << endl;
            return;
        }
        cout << "Inorder Traversal: ";
        inorderHelper(root);
        cout << endl;
    }
    // Preorder traversal
    void preorder() {
        if (root == NULL) {
            cout << "Tree is empty!" << endl;
            return;
        }
        cout << "Preorder Traversal: ";
        preorderHelper(root);
        cout << endl;
    }
    // Postorder traversal
    void postorder() {
        if (root == NULL) {
            cout << "Tree is empty!" << endl;
            return;
        }
        cout << "Postorder Traversal: ";
        postorderHelper(root);
        cout << endl;
    }

    bool isEmpty() {
        return root == NULL;
    }
};
// Binary Search Tree Class
class BinarySearchTree : public BinaryTree {
private:
    // Helper function to insert in BST
    Node* insertBSTHelper(Node* node, int value) {
        if (node == NULL) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insertBSTHelper(node->left, value);
        }
        else if (value > node->data) {
            node->right = insertBSTHelper(node->right, value);
        }
        else {
            cout << "Duplicate value! Node not inserted." << endl;
            return node;
        }

        return node;
    }

    // Helper function to search in BST
    bool searchHelper(Node* node, int value) {
        if (node == NULL) return false;
        if (node->data == value) return true;
        if (value < node->data) return searchHelper(node->left, value);
        return searchHelper(node->right, value);
    }

public:
    BinarySearchTree() : BinaryTree() {}

    // Insert node following BST rules
    void insertBST(int value) {
        if (root == NULL) {
            root = new Node(value);
            cout << "Root node inserted successfully in BST!" << endl;
        }
        else {
            Node* oldRoot = root;
            root = insertBSTHelper(root, value);
            if (root != oldRoot || searchHelper(root, value)) {
                if (oldRoot == root && searchHelper(root, value)) {
                    // Duplicate was found and not inserted
                }
                else {
                    cout << "Node inserted successfully in BST!" << endl;
                }
            }
        }
    }

    // Search for a value in BST
    bool search(int value) {
        return searchHelper(root, value);
    }
};

// Menu for Binary Tree
void binaryTreeMenu() {
    BinaryTree bt;
    int choice, value;

    do {
        cout << "== Binary Tree Menu ==" << endl;
        cout << "1: Insert Node" << endl;
        cout << "2: Inorder Traversal" << endl;
        cout << "3: Preorder Traversal" << endl;
        cout << "4; Postorder Traversal" << endl;
        cout << "5: Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            bt.insert(value);
            break;
        case 2:
            bt.inorder();
            break;
        case 3:
            bt.preorder();
            break;
        case 4:
            bt.postorder();
            break;
        case 5:
            cout << "Returning to main menu..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);
}

// Menu for Binary Search Tree
void binarySearchTreeMenu() {
    BinarySearchTree bst;
    int choice, value;

    do {
        cout << " Binary Sear ch Tree Menu " << endl;
        cout << "1: Insert Node (BST)" << endl;
        cout << "2: Inorder Traversal" << endl;
        cout << "3: Preorder Traversal" << endl;
        cout << "4: Postorder Traversal" << endl;
        cout << "5: Search Node" << endl;
        cout << "6: Back to Main Menu" << endl;
        cout << "Enter your choice: "<<endl;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            bst.insertBST(value);
            break;
        case 2:
            bst.inorder();
            break;
        case 3:
            bst.preorder();
            break;
        case 4:
            bst.postorder();
            break;
        case 5:
            cout << "Enter value to search: ";
            cin >> value;
            if (bst.search(value))
                cout << "Value " << value << " found in BST!" << endl;
            else
                cout << "Value " << value << " not found in BST!" << endl;
            break;
        case 6:
            cout << "Returning to main menu..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);
}

// Main function
int main() {
    int choice;

    do {
        cout << "==== MAIN MENU ====" << endl;
        cout << "1. Binary Tree Operations" << endl;
        cout << "2. Binary Search Tree Operations" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            binaryTreeMenu();
            break;
        case 2:
            binarySearchTreeMenu();
            break;
        case 3:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 3);

   
}