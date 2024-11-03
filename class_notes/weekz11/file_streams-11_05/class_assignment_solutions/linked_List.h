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
    LinkedList();
    // Destructor to clean up memory
    ~LinkedList() ;
    // Method to insert a node at the end
    void insert(int value);
    // Method to display the linked list
    void display();
    // Method to delete a node by value
    void deleteNode(int value);
};