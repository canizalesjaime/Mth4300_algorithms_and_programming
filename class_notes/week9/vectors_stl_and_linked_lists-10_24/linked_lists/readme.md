# Lecture notes

## table of contents
1. Linked Lists
2. Class Assignments


## Linked Lists
A **linked list** is a linear data structure where elements, called nodes, are stored in sequence, but unlike arrays, they are not stored in contiguous memory locations. Each node contains two parts:

* **Data:** The actual value the node holds.
* **Pointer (next):** A pointer/reference to the next node in the sequence.

The main advantage of linked lists over arrays is that they can grow and shrink dynamically, without needing to know their size in advance. However, they don't allow random access to elements, meaning you must traverse the list from the head to access a specific element.

### Basic Structure of a Node
In a **singly linked list**, each node points to the next node, and the last node points to ```nullptr``` (signifying the end of the list). Here's how a node is typically represented:

```cpp
struct Node {
    int data;        // Data part of the node
    Node* next;      // Pointer to the next node
};
```

### Singly Linked List Example
Let's build a simple singly linked list with basic operations like insertion, traversal, and deletion.

a. **Creating the Linked List**
We'll create a class ```LinkedList``` that manages the list, starting with an empty head pointer.

```cpp
#include <iostream>

// Node structure
struct Node {
    int data;
    Node* next;
};

// Linked List class
class LinkedList {
private:
    Node* head;  // Points to the first node (or nullptr if the list is empty)

public:
    // Constructor
    LinkedList() : head(nullptr) {}

    // Destructor to clean up memory
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // Method to insert a node at the end
    void insert(int value) {
        Node* newNode = new Node();  // Create a new node
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            // If list is empty, new node becomes the head
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;  // Traverse to the last node
            }
            temp->next = newNode;  // Insert at the end
        }
    }

    // Method to display the linked list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    // Method to delete a node by value
    void deleteNode(int value) {
        if (head == nullptr) {
            std::cout << "List is empty, cannot delete" << std::endl;
            return;
        }

        // If the head node holds the value to be deleted
        if (head->data == value) {
            Node* temp = head;
            head = head->next;  // Move head to the next node
            delete temp;        // Free memory of old head
            return;
        }

        // Search for the node to delete
        Node* current = head;
        Node* previous = nullptr;
        while (current != nullptr && current->data != value) {
            previous = current;
            current = current->next;
        }

        // If the value is found, delete the node
        if (current != nullptr) {
            previous->next = current->next;
            delete current;
        } else {
            std::cout << "Value not found in the list" << std::endl;
        }
    }
};
```
b. **Operations on Linked List**
Now let's use the ```LinkedList``` class to insert, display, and delete nodes.

```cpp
int main() {
    LinkedList list;

    // Insert elements
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    // Display the linked list
    std::cout << "Linked List: ";
    list.display();  // Output: 10 -> 20 -> 30 -> 40 -> nullptr

    // Delete an element
    list.deleteNode(20);
    std::cout << "After deleting 20: ";
    list.display();  // Output: 10 -> 30 -> 40 -> nullptr

    return 0;
}
```
### Key Linked List Operations
* **Insertion:**
  * To insert a new node, we can add it to the head (beginning), tail (end), or any position in between.
  * In our example, we added nodes at the end (tail insertion).

* **Traversal:**
  * Since linked lists don't provide random access (like arrays), we have to start from the ```head``` and follow the ```next``` pointers until we reach the desired node or the end of the list.

* **Deletion:**
  * Deleting a node involves adjusting the ```next``` pointer of the previous node to point to the node after the one being deleted, and then freeing the memory of the deleted node.

* **Search:**
  * To search for a node, we traverse the list from the ```head```, checking each node's data.


### Types of Linked Lists
* **Singly Linked List:** Each node points to the next node, and the last node points to ```nullptr```.
* **Doubly Linked List:** Each node has two pointers: one pointing to the next node and another pointing to the previous node. This allows traversal in both directions.
* **Circular Linked List:** The last node points back to the ```head```, forming a circle. This can be either singly or doubly linked.


### Example of a Doubly Linked List Node
```cpp
struct Node {
    int data;
    Node* next;  // Pointer to the next node
    Node* prev;  // Pointer to the previous node
};
```


#### Advantages of Linked Lists
* **Dynamic Size:** Linked lists can grow or shrink as needed, unlike arrays which require a fixed size.
* **Efficient Insertion/Deletion:** Inserting or deleting elements at the beginning or middle of the list is more efficient than arrays, as there’s no need to shift elements.

#### Disadvantages of Linked Lists
* **No Random Access:** Accessing elements requires linear traversal, unlike arrays where you can access any element in constant time.
* **Extra Memory:** Each node requires additional memory for the pointer(s), which can lead to increased memory usage compared to arrays.


### Conclusion
Linked lists are a fundamental data structure in computer science, used when dynamic size and efficient insertion/deletion are needed. The singly linked list is the simplest form, while more complex types like doubly and circular linked lists provide additional flexibility in traversal and manipulation.


## Class Assignments
1. Modify insertion and deletion to delete by position instead of value. 
2. Write a function that takes in a class ```LinkedList(singly linked list)```, and returns another linked list in the reverse order. Example: l1= 5->3->7->1 then the output should be l1_r= 1->7->3->5
3. Separate the interface from implementation for the ```LinkedList``` class given. 