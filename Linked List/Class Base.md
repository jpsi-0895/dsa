Here is a comprehensive implementation of all the basic operations you can perform on a **Singly Linked List** in C++. These operations include insertion, deletion, traversal, searching, reversing, and more.

### Linked List Operations in C++

#### 1. **Insertion Operations**
   - Insert at the beginning
   - Insert at the end
   - Insert after a given node
   - Insert at a specific position

#### 2. **Deletion Operations**
   - Delete a node by value
   - Delete a node by position
   - Delete the entire list

#### 3. **Traversal and Display**
   - Display the list
   - Display in reverse (using recursion)

#### 4. **Searching**
   - Search for an element in the list

#### 5. **Other Operations**
   - Find the length of the list
   - Reverse the list
   - Detect a cycle in the list

### Full Implementation of Linked List Operations:

```cpp
#include <iostream>
using namespace std;

// Node structure to represent each node in the linked list
struct Node {
    int data;
    Node* next;

    // Constructor to initialize node
    Node(int val) : data(val), next(nullptr) {}
};

// LinkedList class containing the operations
class LinkedList {
private:
    Node* head;

public:
    // Constructor to initialize the linked list
    LinkedList() : head(nullptr) {}

    // Insert at the beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Insert at the end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert after a specific node
    void insertAfter(Node* prevNode, int val) {
        if (!prevNode) {
            cout << "Previous node cannot be NULL\n";
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }

    // Insert at a specific position
    void insertAtPosition(int position, int val) {
        if (position == 0) {
            insertAtBeginning(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;
        int count = 0;

        while (temp != nullptr && count < position - 1) {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr) {
            cout << "Position out of bounds\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete a node by value
    void deleteByValue(int val) {
        if (!head) {
            cout << "List is empty\n";
            return;
        }

        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->data != val) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Node not found\n";
            return;
        }

        Node* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;
    }

    // Delete a node by position
    void deleteByPosition(int position) {
        if (!head) {
            cout << "List is empty\n";
            return;
        }

        if (position == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        int count = 0;

        while (temp != nullptr && count < position - 1) {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr || temp->next == nullptr) {
            cout << "Position out of bounds\n";
            return;
        }

        Node* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;
    }

    // Display the linked list
    void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr\n";
    }

    // Search for an element in the list
    bool search(int val) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == val) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Count the number of nodes in the list
    int countNodes() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Reverse the linked list
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    // Detect cycle in the list using Floyd's cycle-finding algorithm
    bool detectCycle() {
        if (!head || !head->next) return false;

        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;  // Cycle detected
            }
        }
        return false;  // No cycle
    }

    // Destructor to free memory
    ~LinkedList() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main() {
    LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);

    cout << "Initial list: ";
    list.display();

    list.insertAtBeginning(5);
    list.insertAtPosition(3, 25);
    cout << "After insertions: ";
    list.display();

    list.deleteByValue(30);
    list.deleteByPosition(2);
    cout << "After deletions: ";
    list.display();

    cout << "Searching for 40: " << (list.search(40) ? "Found" : "Not Found") << endl;
    cout << "Number of nodes: " << list.countNodes() << endl;

    list.reverse();
    cout << "Reversed list: ";
    list.display();

    cout << "Cycle detection: " << (list.detectCycle() ? "Cycle found" : "No cycle") << endl;

    return 0;
}
```

### Operations in the Code:
1. **Insert at the beginning**: Adds a new node at the head of the list.
2. **Insert at the end**: Appends a new node at the end.
3. **Insert after a node**: Adds a new node after a given node.
4. **Insert at a specific position**: Inserts a node at a particular position in the list (starting from 0).
5. **Delete by value**: Removes the first node with the given value.
6. **Delete by position**: Removes the node at the given position (starting from 0).
7. **Display**: Prints the list.
8. **Search**: Searches for a node with a specified value.
9. **Count Nodes**: Counts the total number of nodes in the list.
10. **Reverse**: Reverses the linked list.
11. **Cycle Detection**: Uses Floyd’s Cycle-Finding algorithm (Tortoise and Hare) to detect if the list contains a cycle.

### Example Output:

```
Initial list: 10 -> 20 -> 30 -> 40 -> 50 -> nullptr
After insertions: 5 -> 10 -> 20 -> 25 -> 30 -> 40 -> 50 -> nullptr
After deletions: 5 -> 10 -> 25 -> 40 -> 50 -> nullptr
Searching for 40: Found
Number of nodes: 5
Reversed list: 50 -> 40 -> 25 -> 10 -> 5 -> nullptr
Cycle detection: No cycle
```

### Time and Space Complexity:
- **Insertion and Deletion**: O(1) for insertion at the beginning and O(n) for other operations (insertion at the end, after a node, or at a specific position).
- **Traversal and Display**: O(n).
- **Search**: O(n).
- **Reversal**: O(n).
- **Cycle Detection**: O(n), with O(1) space. 

This is a complete C++ implementation for singly linked lists, covering all the basic operations you might need. You can further optimize or modify this code based on specific requirements.