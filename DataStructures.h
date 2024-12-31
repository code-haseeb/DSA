#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

#include <iostream>
#include <vector>
#include <algorithm> // For max
using namespace std;

// ** Stack Operations **
class Stack {
private:
    vector<int> stack;

public:
    // Push into the stack
    void push(int value) {
        stack.push_back(value);
    }

    // Pop from the stack
    void pop() {
        if (!stack.empty()) {
            stack.pop_back();
        } else {
            cout << "Stack is empty!" << endl;
        }
    }

    // Peek the top element of the stack
    int peek() {
        if (!stack.empty()) {
            return stack.back();
        }
        return -1;  // Indicating the stack is empty
    }

    // Search in the stack
    bool search(int value) {
        for (int i = 0; i < stack.size(); i++) {
            if (stack[i] == value)
                return true;
        }
        return false;
    }

    // Rotate right (shift top to bottom)
    void rotateRight() {
        if (!stack.empty()) {
            int top = stack.back();
            stack.pop_back();
            stack.insert(stack.begin(), top);
        }
    }

    // Rotate left (shift bottom to top)
    void rotateLeft() {
        if (!stack.empty()) {
            int bottom = stack[0];
            stack.erase(stack.begin());
            stack.push_back(bottom);
        }
    }

    // Display the stack
    void display() {
        if (stack.empty()) {
            cout << "Stack is empty!" << endl;
        } else {
            for (int val : stack) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
};

// ** Binary Search Tree (BST) Operations **
class BST {
public:
    struct Node {
        int data;
        Node* left;
        Node* right;

        Node(int value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root = nullptr;

    // Insert into BST
    void insert(int value) {
        root = insertRec(root, value);
    }

    // Search in BST
    bool search(int value) {
        return searchRec(root, value);
    }

    // Delete from BST
    void deleteNode(int value) {
        root = deleteRec(root, value);
    }

    // In-order traversal
    void inOrderTraversal(Node* node) {
        if (node == nullptr) return;
        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);
    }

private:
    Node* insertRec(Node* node, int value) {
        if (!node) return new Node(value);
        if (value < node->data)
            node->left = insertRec(node->left, value);
        else if (value > node->data)
            node->right = insertRec(node->right, value);
        return node;
    }

    bool searchRec(Node* node, int value) {
        if (!node) return false;
        if (node->data == value) return true;
        if (value < node->data) return searchRec(node->left, value);
        return searchRec(node->right, value);
    }

    Node* deleteRec(Node* root, int key) {
        if (!root) return root;

        if (key < root->data)
            root->left = deleteRec(root->left, key);
        else if (key > root->data)
            root->right = deleteRec(root->right, key);
        else {
            if (!root->left) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (!root->right) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteRec(root->right, temp->data);
        }
        return root;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left) current = current->left;
        return current;
    }
};

// ** AVL Tree Operations **
class AVLTree {
public:
    struct Node {
        int data;
        Node* left;
        Node* right;
        int height;

        Node(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
    };

    Node* root = nullptr;

    // Insert into AVL Tree
    Node* insert(Node* node, int value) {
        if (!node) return new Node(value);
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }

        node->height = max(height(node->left), height(node->right)) + 1;
        int balance = getBalance(node);

        if (balance > 1 && value < node->left->data)
            return rightRotate(node);
        if (balance < -1 && value > node->right->data)
            return leftRotate(node);
        if (balance > 1 && value > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && value < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // In-order traversal of AVL Tree
    void inOrderTraversal(Node* node) {
        if (node == nullptr) return;
        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);
    }

    // Search in AVL Tree
    bool search(Node* node, int value) {
        if (!node) return false;
        if (node->data == value) return true;
        if (value < node->data) return search(node->left, value);
        return search(node->right, value);
    }

private:
    int height(Node* node) {
        return node ? node->height : 0;
    }

    int getBalance(Node* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }
};

#endif
