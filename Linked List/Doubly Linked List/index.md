A **Doubly Linked List (DLL)** is a type of linked list in which each node contains three parts:
1. **Data**: Stores the data element.
2. **Next pointer**: Points to the next node in the list.
3. **Prev pointer**: Points to the previous node in the list.

Here are the basic operations on a doubly linked list in C++:

### 1. **Insertion Operations**
   - **Insert at the beginning**: Add a new node at the head of the list.
   - **Insert at the end**: Add a new node at the tail of the list.
   - **Insert at a specific position**: Insert a new node at a specified index.

### 2. **Deletion Operations**
   - **Delete from the beginning**: Remove the head node.
   - **Delete from the end**: Remove the tail node.
   - **Delete from a specific position**: Remove a node at a specified index.

### 3. **Traversal Operations**
   - **Forward Traversal**: Traverse from head to tail using the `next` pointers.
   - **Backward Traversal**: Traverse from tail to head using the `prev` pointers.

Here is a basic C++ implementation that demonstrates the common operations on a doubly linked list:

```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    // Constructor
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Constructor to initialize an empty list
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Insert at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (!head) { // If the list is empty
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!tail) { // If the list is empty
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Insert at a specific position
    void insertAtPosition(int value, int position) {
        if (position < 1) {
            cout << "Invalid position!" << endl;
            return;
        }

        if (position == 1) {
            insertAtBeginning(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* temp = head;
        int count = 1;

        while (temp != nullptr && count < position) {
            temp = temp->next;
            count++;
        }

        if (!temp) {
            cout << "Position out of range!" << endl;
            return;
        }

        newNode->next = temp;
        newNode->prev = temp->prev;
        if (temp->prev) {
            temp->prev->next = newNode;
        }
        temp->prev = newNode;
    }

    // Delete from the beginning
    void deleteFromBeginning() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    // Delete from the end
    void deleteFromEnd() {
        if (!tail) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    // Delete from a specific position
    void deleteFromPosition(int position) {
        if (position < 1) {
            cout << "Invalid position!" << endl;
            return;
        }

        if (position == 1) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        int count = 1;

        while (temp != nullptr && count < position) {
            temp = temp->next;
            count++;
        }

        if (!temp) {
            cout << "Position out of range!" << endl;
            return;
        }

        if (temp->prev) {
            temp->prev->next = temp->next;
        }
        if (temp->next) {
            temp->next->prev = temp->prev;
        }
        delete temp;
    }

    // Forward Traversal
    void forwardTraversal() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Backward Traversal
    void backwardTraversal() {
        Node* temp = tail;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    dll.insertAtBeginning(10);   // 10
    dll.insertAtEnd(20);         // 10 20
    dll.insertAtEnd(30);         // 10 20 30
    dll.insertAtBeginning(5);    // 5 10 20 30
    dll.insertAtPosition(15, 3); // 5 10 15 20 30

    cout << "Forward Traversal: ";
    dll.forwardTraversal();      // 5 10 15 20 30

    cout << "Backward Traversal: ";
    dll.backwardTraversal();     // 30 20 15 10 5

    dll.deleteFromBeginning();   // 10 15 20 30
    dll.deleteFromEnd();         // 10 15 20
    dll.deleteFromPosition(2);   // 10 20

    cout << "After Deletions (Forward Traversal): ";
    dll.forwardTraversal();      // 10 20

    return 0;
}
```

### Key Points:
1. **Node class**: Each node contains `data`, `next`, and `prev` pointers.
2. **DoublyLinkedList class**: Manages the head and tail pointers and performs the insertion, deletion, and traversal operations.
3. **Insertion**: The `insertAtBeginning()`, `insertAtEnd()`, and `insertAtPosition()` methods handle inserting at different positions in the list.
4. **Deletion**: The `deleteFromBeginning()`, `deleteFromEnd()`, and `deleteFromPosition()` methods handle removing nodes from various positions.
5. **Traversal**: The `forwardTraversal()` and `backwardTraversal()` methods allow for forward and backward traversals of the list.

### Time Complexity:
- **Insertion and Deletion** (at the beginning, end, or specific position): O(1) for beginning and end; O(n) for specific position (if the position is not at the beginning or end).
- **Traversal**: O(n) for both forward and backward traversal.

This implementation allows efficient management of a doubly linked list in C++.

### **Circular Linked List in C++ - Step by Step Explanation**

A **circular linked list** is a variation of a linked list where the last node points back to the first node, forming a loop. It can be either a **singly circular linked list** (where each node points to the next node) or a **doubly circular linked list** (where each node has pointers to both its next and previous nodes).

In a **singly circular linked list**, the last node's `next` pointer points to the first node, rather than pointing to `NULL` as in a normal singly linked list.

### **Operations in Circular Linked List**
In a circular linked list, we perform several operations like insertion, deletion, traversal, and searching. Let's go through these operations step by step.

### **Step 1: Define the Node Structure**

A circular linked list node typically contains two parts:
- Data: The data value that the node holds.
- Next: A pointer to the next node in the list (or the head if it's the last node).

Here's how you define a `Node` structure in C++:

```cpp
struct Node {
    int data;    // Data stored in the node
    Node* next;  // Pointer to the next node

    // Constructor to initialize node
    Node(int val) : data(val), next(nullptr) {}
};
```

### **Step 2: Define the Circular Linked List Class**

Now, let's define a `CircularLinkedList` class. This class will manage the list and provide various operations like insertion, deletion, traversal, and so on.

```cpp
class CircularLinkedList {
private:
    Node* head; // Pointer to the first node (head) of the circular linked list

public:
    // Constructor to initialize an empty list
    CircularLinkedList() : head(nullptr) {}

    // Function to insert a node at the end
    void insertAtEnd(int value);

    // Function to delete a node by value
    void deleteNode(int value);

    // Function to display the elements of the circular linked list
    void display();

    // Function to check if the list is empty
    bool isEmpty() { return head == nullptr; }

    // Function to search for an element in the list
    bool search(int value);
};
```

### **Step 3: Implementing the Operations**

Let's break down each operation in the circular linked list:

#### **1. Insertion at the End**

In a circular linked list, to insert a node at the end, we need to:
- Traverse to the last node (whose `next` pointer points to the head).
- Insert the new node by making the last node’s `next` point to the new node and the new node's `next` point to the head.

```cpp
void CircularLinkedList::insertAtEnd(int value) {
    Node* newNode = new Node(value);
    
    // If the list is empty, the new node points to itself
    if (isEmpty()) {
        head = newNode;
        newNode->next = head; // Point to itself, forming the circular link
    } else {
        Node* temp = head;
        
        // Traverse to the last node
        while (temp->next != head) {
            temp = temp->next;
        }
        
        // Insert the new node at the end
        temp->next = newNode;
        newNode->next = head; // Complete the circle
    }
}
```

#### **2. Deletion by Value**

To delete a node from the circular linked list:
- Traverse the list and find the node with the given value.
- Adjust the `next` pointer of the previous node to skip the node to be deleted.

```cpp
void CircularLinkedList::deleteNode(int value) {
    if (isEmpty()) {
        std::cout << "List is empty!" << std::endl;
        return;
    }
    
    Node* temp = head;
    Node* prev = nullptr;
    
    // If the node to be deleted is the head node
    if (temp->data == value) {
        // If there's only one node in the list
        if (temp->next == head) {
            delete temp;
            head = nullptr;
            return;
        }
        
        // Traverse to the last node
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        
        // Make the previous node's next point to the head (last node points to the head now)
        prev->next = head;
        delete temp;
        head = head->next; // Update the head
    } else {
        prev = temp;
        temp = temp->next;
        
        // Search for the node to delete
        while (temp != head && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }
        
        // If node is found, delete it
        if (temp->data == value) {
            prev->next = temp->next;
            delete temp;
        } else {
            std::cout << "Node with value " << value << " not found!" << std::endl;
        }
    }
}
```

#### **3. Displaying the Circular Linked List**

To display the circular linked list:
- Start from the `head` and traverse the list, printing each node’s data until we come back to the head.

```cpp
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
```

#### **4. Searching for a Value**

To search for a value in the list:
- Start from the `head` and traverse the list until we find the node with the matching value.

```cpp
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
    
    return false; // Value not found
}
```

### **Step 4: Main Function to Test**

Now, let’s create a `main` function to test our circular linked list operations.

```cpp
int main() {
    CircularLinkedList cll;

    // Inserting elements at the end
    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cll.insertAtEnd(40);
    
    std::cout << "Circular Linked List: ";
    cll.display();
    
    // Searching for a value
    std::cout << "Searching for 20: " << (cll.search(20) ? "Found" : "Not Found") << std::endl;
    
    // Deleting a node
    cll.deleteNode(30);
    std::cout << "After deleting 30: ";
    cll.display();
    
    // Deleting a node that doesn't exist
    cll.deleteNode(100);
    
    return 0;
}
```

### **Expected Output**

```cpp
Circular Linked List: 10 20 30 40 
Searching for 20: Found
After deleting 30: 10 20 40 
Node with value 100 not found!
```

### **Conclusion**

This is a basic implementation of a **singly circular linked list** in C++. The operations demonstrated include:
1. **Insertion at the end**
2. **Deletion by value**
3. **Displaying the list**
4. **Searching for a value**

In a **doubly circular linked list**, you would also manage a `prev` pointer for each node to allow traversal in both directions.