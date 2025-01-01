### Linked List Implementation in C++: Step-by-Step

A **linked list** is a linear data structure where elements (called nodes) are stored non-contiguously in memory. Each node contains:
1. **Data**: The value or information stored in the node.
2. **Next Pointer**: A reference to the next node in the sequence.

There are various types of linked lists:
- **Singly Linked List**: Each node points to the next node in the list and the last node points to `NULL`.
- **Doubly Linked List**: Each node has two pointers: one to the next node and one to the previous node.
- **Circular Linked List**: The last node points back to the first node.

In this example, we'll focus on implementing a **Singly Linked List** in C++.

### Basic Operations on Singly Linked List:
1. **Insert**: Add a new node to the list.
   - At the beginning
   - At the end
   - At a given position
2. **Delete**: Remove a node from the list.
   - From the beginning
   - From the end
   - From a given position
3. **Display**: Print the elements of the list.
4. **Search**: Find an element in the list.

### C++ Code for Singly Linked List Implementation

```cpp
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;  // Data part
    Node* next;  // Pointer to the next node

    // Constructor to initialize the node with data and next pointer
    Node(int val) : data(val), next(nullptr) {}
};

// Singly Linked List class
class LinkedList {
private:
    Node* head;  // Pointer to the head of the list

public:
    // Constructor to initialize an empty list
    LinkedList() : head(nullptr) {}

    // Function to insert a node at the beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;  // Point new node to current head
        head = newNode;  // Make the new node the head of the list
    }

    // Function to insert a node at the end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;  // If the list is empty, make new node the head
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;  // Traverse to the last node
        }
        temp->next = newNode;  // Add the new node after the last node
    }

    // Function to delete a node from the beginning
    void deleteAtBeginning() {
        if (!head) {
            cout << "List is empty, nothing to delete.\n";
            return;
        }
        Node* temp = head;
        head = head->next;  // Move the head to the next node
        delete temp;  // Free the memory of the old head
    }

    // Function to delete a node from the end
    void deleteAtEnd() {
        if (!head) {
            cout << "List is empty, nothing to delete.\n";
            return;
        }
        if (!head->next) {
            delete head;  // If there is only one node, delete it
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->next) {
            temp = temp->next;  // Traverse to the second-to-last node
        }
        delete temp->next;  // Delete the last node
        temp->next = nullptr;  // Set the second-to-last node's next pointer to null
    }

    // Function to search for an element in the list
    bool search(int val) {
        Node* temp = head;
        while (temp) {
            if (temp->data == val) {
                return true;  // Element found
            }
            temp = temp->next;
        }
        return false;  // Element not found
    }

    // Function to display the entire linked list
    void display() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";  // End of the list
    }

    // Destructor to free all dynamically allocated memory
    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;  // Free memory of each node
        }
    }
};

int main() {
    LinkedList list;

    // Insert elements into the linked list
    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    // Display the linked list
    cout << "Linked list: ";
    list.display();

    // Delete an element from the beginning
    list.deleteAtBeginning();
    cout << "After deleting from beginning: ";
    list.display();

    // Delete an element from the end
    list.deleteAtEnd();
    cout << "After deleting from end: ";
    list.display();

    // Search for an element in the list
    int searchVal = 30;
    if (list.search(searchVal)) {
        cout << "Element " << searchVal << " found in the list.\n";
    } else {
        cout << "Element " << searchVal << " not found in the list.\n";
    }

    return 0;
}
```

### Explanation of the Code:

1. **Node Structure**:
   - Each node contains an integer `data` and a pointer `next` that points to the next node in the list.
   - The constructor `Node(int val)` initializes the node with the provided data and sets the `next` pointer to `nullptr`.

2. **LinkedList Class**:
   - **Private Member**: `head`, a pointer to the first node of the list.
   - **Public Member Functions**:
     - `insertAtBeginning(int val)`: Adds a node with value `val` at the beginning of the list.
     - `insertAtEnd(int val)`: Adds a node with value `val` at the end of the list.
     - `deleteAtBeginning()`: Deletes the first node of the list.
     - `deleteAtEnd()`: Deletes the last node of the list.
     - `search(int val)`: Searches for an element `val` in the list. Returns `true` if found, otherwise `false`.
     - `display()`: Prints the elements of the list in the format `data -> data -> ... -> NULL`.
     - `~LinkedList()`: Destructor to free all dynamically allocated memory by deleting nodes one by one.

3. **Main Function**:
   - The main function demonstrates how to create and manipulate the linked list by inserting elements at the beginning and end, deleting from the beginning and end, searching for an element, and displaying the list.

### Example Output:

```
Linked list: 20 -> 10 -> 30 -> 40 -> NULL
After deleting from beginning: 10 -> 30 -> 40 -> NULL
After deleting from end: 10 -> 30 -> NULL
Element 30 found in the list.
```

### Time Complexity:
- **Insertion at the beginning**: \(O(1)\)
- **Insertion at the end**: \(O(n)\) (since we need to traverse the list to reach the end)
- **Deletion from the beginning**: \(O(1)\)
- **Deletion from the end**: \(O(n)\) (since we need to traverse the list to find the second-to-last node)
- **Search**: \(O(n)\) (since we may have to traverse the entire list)
- **Display**: \(O(n)\) (since we need to print all nodes)

### Space Complexity:
- **Space Complexity**: \(O(n)\), where \(n\) is the number of elements in the list because we use dynamically allocated memory for each node.

### Conclusion:

This C++ implementation provides a simple, efficient, and clear example of a **singly linked list**. The key operations like insertion, deletion, and search are demonstrated. You can easily extend the implementation to include more complex operations such as reversing the list, merging two lists, etc.