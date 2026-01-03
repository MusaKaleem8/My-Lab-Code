// BSEE-24029DSAlab11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
// Node for avl tree
struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};
// Getting the height of  the node. If node is null or empty then the height is zero.
int getHeight(Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}
// Getting the maximum of  the two values
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Creating a new node
Node* createNode(int value) {
    Node* node = new Node();
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;      // New node will be initially at height 1
    return node;
}
// Getting the balance factor(height of left subtree - height of right subtree)
int getBalance(Node* node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}
// Right rotation (LL case)
Node* rightRotate(Node* y) {
    Node* x = y->left; //new root after the rotation
    Node* T2 = x->right; //rearrange subtree

    // Performing rotation
    x->right = y;
    y->left = T2;

    // Updating the heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;  //returing new root
}
// Left rotation (RR case)
Node* leftRotate(Node* x) {
    Node* y = x->right;//new root after the rotation
    Node* T2 = y->left;//rearrange subtree

    // Performing rotation
    y->left = x;
    x->right = T2;

    // Updating heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y; //returing new root
}
// Insert into AVL Tree
Node* insert(Node* root, int value) {

    // Normal BST insertion
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else {
        cout << "Duplicate value not allowed."<<endl;
        return root;
    }
    //  Updateing height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Getting the balance factor
    int balance = getBalance(root);

    // Apply rotations

    // Left Left (LL)
    if (balance > 1 && value < root->left->data)
        return rightRotate(root);

    // Right Right (RR)
    if (balance < -1 && value > root->right->data)
        return leftRotate(root);

    // Left Right (LR)
    if (balance > 1 && value > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left (RL)
    if (balance < -1 && value < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
// Inorder traversal
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
//Menu-driven program
int main() {
    Node* root = NULL;
    int choice, value;

    do {
        cout << "==MENU===" << endl;
        cout << "1: Insert node"<<endl;
        cout << "2: Display inorder traversal"<<endl;
        cout << "3: Exit"<<endl;
        cout << "Enter your choice:"<<endl;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert:"<<endl;
            cin >> value;
            root = insert(root, value);
            break;

        case 2:
            if (root == NULL)
                cout << "Tree is empty."<<endl;
            else {
                cout << "Inorder Traversal:"<<endl;
                inorder(root);
                cout << endl;
            }
            break;

        case 3:
            cout << "Exiting program.";
            break;

        default:
            cout << "Invalid choice."<<endl;
        }

    } while (choice != 3);
        return 0;
}
