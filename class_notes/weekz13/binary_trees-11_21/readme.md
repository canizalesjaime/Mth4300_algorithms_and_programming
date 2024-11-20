# Lecture notes

## table of contents
1. Binary Trees
2. Class Assignments


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


### Basic Binary Tree Operations:
#### Insertion:
The insertion operation places a new node at the correct position in the tree. Here's an example of inserting a node into a binary search tree (BST), where the left child contains a smaller value and the right child contains a larger value.

```cpp
// Function to insert a new node in the binary search tree (BST)
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);  // If the tree is empty, create a new node
    }
    
    if (value < root->data) {
        root->left = insert(root->left, value);  // Insert in the left subtree
    } else {
        root->right = insert(root->right, value); // Insert in the right subtree
    }
    
    return root;
}
```

#### Traversal:
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
4. Searching:
Searching involves finding whether a specific value exists in the tree.

```cpp
// Function to search for a value in a BST
bool search(Node* root, int key) {
    if (root == nullptr) {
        return false;  // Value not found
    }
    
    if (root->data == key) {
        return true;   // Value found
    }
    
    // Recur down the tree based on the value
    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}
```

#### Example Usage:
```cpp
int main() {
    Node* root = nullptr;

    // Insert nodes into the binary tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    // Display the in-order traversal
    cout << "In-order traversal: ";
    inOrder(root);
    cout << endl;

    // Search for a value in the tree
    int key = 40;
    if (search(root, key)) {
        cout << "Value " << key << " found in the tree." << endl;
    } else {
        cout << "Value " << key << " not found in the tree." << endl;
    }

    return 0;
}
```

### Complexity:
* Time Complexity:
  * Insertion, Deletion, Search: O(log n) for balanced trees (O(n) in the worst case for unbalanced trees).
* Space Complexity:
  * O(n), where n is the number of nodes in the tree.

### Conclusion:
Binary trees are a powerful data structure that can be used for efficient searching, sorting, and hierarchical data organization. Implementing binary trees in C++ is straightforward with the use of pointers and recursive functions for operations like insertion, traversal, and search.

## Class Assignments
1. Add a function to the BST data structure to return the height of the BST. 