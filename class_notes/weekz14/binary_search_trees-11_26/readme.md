# Lecture notes

## table of contents
1. Binary Search Trees
2. Class Assignments


## Binary Search Trees
A Binary Search Tree (BST) is a data structure that organizes elements (or nodes) in a hierarchical manner, making it efficient for operations like searching, insertion, and deletion. Here's a breakdown of how BSTs work in C++ and their basic concepts.

### Properties of a Binary Search Tree
* Each node has a key (or value).
* The left child of a node contains keys that are less than the node's key.
* The right child of a node contains keys that are greater than the node's key.
* No duplicate keys (optional, but common in BSTs).


### Insertion:
The insertion operation places a new node at the correct position in the tree. Here's an example of inserting a node into a binary search tree (BST), where the left child contains a smaller value and the right child contains a larger value.
Inserting a node into a Binary Search Tree (BST) involves placing a new value in the correct position according to the BST property:

* **Left subtree:** Nodes must have values smaller than the parent.
* **Right subtree:** Nodes must have values greater than the parent.


**Steps to Insert a Node**<br>
1. Start from the Root
   * Begin at the root of the tree.

2. Traverse to the Correct Position
   * If the new value is smaller than the current node, move to the left subtree.
   * If the new value is greater, move to the right subtree.
   * Repeat this process until a nullptr (empty spot) is reached.

3. Insert the Node
* Create a new node and attach it as a child where the nullptr was found.


```cpp
// Function to insert a new node in the binary search tree (BST)
Node* BinarySearchTree::insert(Node* start, int val)
{
     if (!root) 
    {
        root= new Node(val);
        return root;
    }

    if (!start) return new Node(val);  // found position to insert

    else if (val < start->data) start->left = insert(start->left, val);  

    else if (val > start->data) start->right = insert(start->right, val); 
    
    return start;
}
```


**Explanation of Code**<br>
1. Base Case
   * If the root is nullptr, create a new node with the given key, set root equal to it then return root. This handles the case where the tree is empty.
   * If ```start``` is the nullptr, create a new node with the given key and return it. This handles the case where a child needs to be added to a leaf.

2. Recursive Insertion
   * Depending on whether the key is smaller or larger than the current node's value, recursively call insertNode on the left or right subtree.

3. Update the Subtree
   * After inserting the new node, the parent's left or right pointer is updated with the result of the recursive call.

4. Return start
   * The function always returns the root of the current subtree to ensure proper linking of the tree.

#### Example Walkthrough
Insertions:
* Start with an empty tree: root = nullptr.
* Insert 5<
* Tree is empty, so 5 becomes the root.
```markdown
    5
```

* Insert 3
* 3 < 5, so insert 3 into the left subtree.
```markdown
    5
   /
  3
```

* Insert 8
* 8 > 5, so insert 8 into the right subtree.
```markdown
    5
   / \
  3   8
```

* Insert 2
* 2 < 5 (go left) and 2 < 3 (go left again), so insert 2 as the left child of 3.
```markdown

    5
   / \
  3   8
 /
2
```

* Insert 4
* 4 < 5 (go left) and 4 > 3 (go right), so insert 4 as the right child of 3.
```markdown
    5
   / \
  3   8
 / \
2   4
```
In-order Traversal After Inserts
The in-order traversal of a BST visits nodes in sorted order. For the example above, the output would be:
```
2 3 4 5 8
```
This confirms that the BST property is maintained after insertions.


### Search
Searching involves finding whether a specific value exists in the tree.

```cpp
// Function to search for a value in a BST
Node* BinarySearchTree::search(int val)
{
    Node* curr=root;
    while (curr)
    {
        if(val < curr->data) curr=curr->left;

        else if (val > curr->data) curr=curr->right;

        else return curr; // val==curr->data, so we found node
    }

    return nullptr;
}
```


### Deletion 
Below is an example of how to implement the deleteNode function in C++:

```cpp
// Function to delete a node by value
Node* BinarySearchTree::deleteNode(Node* start, int val)
{
    if(!start) return nullptr;

    else if(val < start->data) start->left=deleteNode(start->left,val);

    else if(val > start->data) start->right=deleteNode(start->right,val); 
    
    else
    {
        if(start->left && start->right)//two children
        {
            Node* min_node = findMin( start->right );
            start->data = min_node->data;
            start->right = deleteNode( start->right, start->data );
        }


       else //at most one children
       {
            Node* save_spot=start->left?start->left:start->right;
            delete start;
            return save_spot;
       } 

    }

    return start;
}
```


#### Explanation of Code
1. Base Case
   * If start is nullptr, the function returns nullptr, indicating the value doesn't exist in the tree.

2. Recursive Search
   * Depending on the comparison, traverse left or right(just like we did for insert).

3. Deletion Cases
   * Leaf nodes are simply deleted.
   * For nodes with one child, the child replaces the node.
   * For nodes with two children, the value of the node is replaced by its inorder successor, and the successor node is deleted recursively(the smallest node in the right subtree of the node to be deleted).

4. Inorder Traversal
   * Used to verify the tree structure remains valid after deletion.

#### Example Walkthrough
1. Input Tree:
```markdown
        5
       / \
      3   8
     / \
    2   4
```

2. Delete 3:
   * Node 3 has two children.
   * Replace 3 with its inorder successor (4).
   * Delete 4 from the right subtree.

3. Output Tree:
```markdown
        5
       / \
      4   8
     /
    2
```
This approach ensures the BST property is maintained throughout the operation.


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