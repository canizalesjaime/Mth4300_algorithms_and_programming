# Lecture notes

## table of contents
1. Binary Trees


## Binary Trees
A ```binary tree``` in C++ is a hierarchical data structure in which each node has at most two children, often referred to as the left child and right child. Here's a breakdown of the essential concepts of binary trees and how to implement them in C++.

### Basic Concepts of a Binary Tree:
* Node: A basic unit of a binary tree. Each node contains:
  * Data: The value stored in the node.
  * Left child: A pointer/reference to the left child node.
  * Right child: A pointer/reference to the right child node.

* Root: The topmost node in a binary tree. All other nodes can be accessed by starting from the root.

* Leaf: A node that has no children (both left and right children are nullptr).

* Height: The number of edges on the longest path from the root to a leaf.

* Depth: The number of edges from the root to the node.

### Types of Binary Trees:
* Full Binary Tree: Every node has either 0 or 2 children.
* Complete Binary Tree: All levels are fully filled except possibly the last, which is filled from the left.
* Perfect Binary Tree: All internal nodes have two children, and all leaves are at the same level.
* Balanced Binary Tree: The difference between the height of the left and right subtrees is not more than one for every node.

### Structure of a Node in C++:
The fundamental building block of a binary tree is a node, which can be defined using a ```struct``` in C++.

```cpp
#include <iostream>
using namespace std;

// Define a structure for a node in a binary tree
struct Node {
    int data;             // Data stored in the node
    Node* left;           // Pointer to the left child
    Node* right;          // Pointer to the right child

    // Constructor to initialize a new node
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
```


### Traversal:
Traversal is the process of visiting all nodes in the tree. There are three primary methods:

1. In-order Traversal (Left, Root, Right):
For BSTs, this traversal returns elements in sorted order.
```cpp
// In-order traversal of the binary tree
void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);        // Visit left subtree
        cout << root->data << " ";  // Visit root
        inOrder(root->right);       // Visit right subtree
    }
}
```

2. Pre-order Traversal (Root, Left, Right):
Used for copying a tree or for prefix expression evaluation.
```cpp
// Pre-order traversal of the binary tree
void preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";  // Visit root
        preOrder(root->left);       // Visit left subtree
        preOrder(root->right);      // Visit right subtree
    }
}
```

3. Post-order Traversal (Left, Right, Root):
Useful for deleting a tree or postfix expression evaluation.
```cpp
// Post-order traversal of the binary tree
void postOrder(Node* root) {
    if (root != nullptr) {
        postOrder(root->left);      // Visit left subtree
        postOrder(root->right);     // Visit right subtree
        cout << root->data << " ";  // Visit root
    }
}
```