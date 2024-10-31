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