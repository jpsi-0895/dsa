#include <iostream>
#include "CircularLinkedList.h"

// Node constructor
Node::Node(int val) : data(val), next(nullptr) {}

// CircularLinkedList constructor
CircularLinkedList::CircularLinkedList() : head(nullptr) {}

// Function to insert a node at the end
void CircularLinkedList::insertAtEnd(int value) {
    Node* newNode = new Node(value);
    
    if (isEmpty()) {
        head = newNode;
        newNode->next = head; // Point to itself, forming the circular link
    } else {
        Node* temp = head;
        
        while (temp->next != head) {
            temp = temp->next;
        }
        
        temp->next = newNode;
        newNode->next = head; // Complete the circle
    }
}

// Function to delete a node by value
void CircularLinkedList::deleteNode(int value) {
    if (isEmpty()) {
        std::cout << "List is empty!" << std::endl;
        return;
    }
    
    Node* temp = head;
    Node* prev = nullptr;
    
    if (temp->data == value) {
        if (temp->next == head) {
            delete temp;
            head = nullptr;
            return;
        }

        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = head;
        delete temp;
        head = head->next;
    } else {
        prev = temp;
        temp = temp->next;

        while (temp != head && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        if (temp->data == value) {
            prev->next = temp->next;
            delete temp;
        } else {
            std::cout << "Node with value " << value << " not found!" << std::endl;
        }
    }
}

// Function to display the circular linked list
void CircularLinkedList::display() {
    if (isEmpty()) {
        std::cout << "List is empty!" << std::endl;
        return;
    }
    
    Node* temp = head;
    do {
        std::cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    std::cout << std::endl;
}

// Function to check if the list is empty
bool CircularLinkedList::isEmpty() {
    return head == nullptr;
}

// Function to search for a value in the list
bool CircularLinkedList::search(int value) {
    if (isEmpty()) {
        return false;
    }
    
    Node* temp = head;
    do {
        if (temp->data == value) {
            return true;
        }
        temp = temp->next;
    } while (temp != head);
    
    return false;
}
