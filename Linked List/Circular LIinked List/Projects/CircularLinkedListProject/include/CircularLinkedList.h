#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

// Node structure for Circular Linked List
struct Node {
    int data;    // Data stored in the node
    Node* next;  // Pointer to the next node

    // Constructor to initialize node
    Node(int val);
};

// CircularLinkedList class declaration
class CircularLinkedList {
private:
    Node* head; // Pointer to the first node (head) of the circular linked list

public:
    // Constructor to initialize an empty list
    CircularLinkedList();

    // Function to insert a node at the end
    void insertAtEnd(int value);

    // Function to delete a node by value
    void deleteNode(int value);

    // Function to display the elements of the circular linked list
    void display();

    // Function to check if the list is empty
    bool isEmpty();

    // Function to search for an element in the list
    bool search(int value);
};

#endif // CIRCULAR_LINKED_LIST_H
