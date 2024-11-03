#include <iostream>
#include "linked_list.h"


LinkedList::LinkedList() : head(nullptr) {}


LinkedList::~LinkedList() 
{
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}


void LinkedList::insert(int value) 
{
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


void LinkedList::display() 
{
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;
}


void LinkedList::deleteNode(int value) 
{
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

