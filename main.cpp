#include <iostream>
#include "DataStructures.h"

using namespace std;

int main() {
    // Stack Test Cases
    cout << "Stack Test Cases:\n";
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    cout << "Stack after pushes: ";
    stack.display();

    stack.pop();
    cout << "After pop: ";
    stack.display();

    cout << "Peek top element: " << stack.peek() << endl;

    cout << "Search 20 in stack: " << (stack.search(20) ? "Found" : "Not Found") << endl;
    cout << "Search 100 in stack: " << (stack.search(100) ? "Found" : "Not Found") << endl;

    stack.rotateRight();
    cout << "After rotate right: ";
    stack.display();

    stack.rotateLeft();
    cout << "After rotate left: ";
    stack.display();

    cout << "\n";

    // Binary Search Tree Test Cases
    cout << "Binary Search Tree Test Cases:\n";
    BST bst;
    bst.insert(40);
    bst.insert(20);
    bst.insert(60);
    bst.insert(10);
    bst.insert(30);
    bst.insert(50);
    bst.insert(70);

    cout << "In-order Traversal: ";
    bst.inOrderTraversal(bst.root);
    cout << endl;

    cout << "Search 30 in BST: " << (bst.search(30) ? "Found" : "Not Found") << endl;
    cout << "Search 100 in BST: " << (bst.search(100) ? "Found" : "Not Found") << endl;

    bst.deleteNode(20);
    bst.deleteNode(60);
    cout << "In-order Traversal after deletions: ";
    bst.inOrderTraversal(bst.root);
    cout << "\n";

    // AVL Tree Test Cases
    cout << "\nAVL Tree Test Cases:\n";
    AVLTree avl;
    avl.root = avl.insert(avl.root, 50);
    avl.root = avl.insert(avl.root, 30);
    avl.root = avl.insert(avl.root, 70);
    avl.root = avl.insert(avl.root, 20);
    avl.root = avl.insert(avl.root, 40);
    avl.root = avl.insert(avl.root, 60);
    avl.root = avl.insert(avl.root, 80);

    cout << "In-order Traversal: ";
    avl.inOrderTraversal(avl.root);
    cout << endl;

    cout << "Search 40 in AVL: " << (avl.search(avl.root, 40) ? "Found" : "Not Found") << endl;
    cout << "Search 100 in AVL: " << (avl.search(avl.root, 100) ? "Found" : "Not Found") << endl;

    return 0;
}
