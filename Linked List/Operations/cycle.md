Cycle detection in a linked list is an important problem where you need to determine if the list contains a cycle (i.e., a node's `next` pointer eventually points back to a previous node, creating a loop). There are several ways to detect cycles in a linked list, but the most efficient approach is **Floyd’s Cycle-Finding Algorithm**, also known as the **Tortoise and Hare** algorithm. 

### Key Idea:
The idea is to use two pointers:
1. **Slow pointer (tortoise)** moves one step at a time.
2. **Fast pointer (hare)** moves two steps at a time.

If the list contains a cycle, at some point, the fast pointer will catch up with the slow pointer. If the fast pointer reaches the end of the list (`nullptr`), then the list doesn't contain a cycle.

### Steps of Floyd's Cycle-Finding Algorithm:
1. Initialize two pointers: `slow` and `fast`. Both start at the head of the linked list.
2. Move `slow` by one step and `fast` by two steps at each iteration.
3. If the list has a cycle, the `slow` and `fast` pointers will eventually meet at the same node. If `fast` reaches `nullptr`, then there is no cycle.
4. The time complexity of this approach is O(n), and the space complexity is O(1) since only two pointers are used.

### C++ Code for Cycle Detection:

```cpp
#include <iostream>
using namespace std;

// Definition of the Node structure
struct Node {
    int data;
    Node* next;
    
    // Constructor to create a new node
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to detect a cycle in the linked list
bool detectCycle(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return false;  // If the list is empty or contains just one node, no cycle.
    }
    
    Node* slow = head;  // Slow pointer (tortoise)
    Node* fast = head;  // Fast pointer (hare)
    
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;           // Move slow by one step
        fast = fast->next->next;     // Move fast by two steps
        
        if (slow == fast) {
            return true;  // Cycle detected when both pointers meet
        }
    }
    
    return false;  // No cycle detected
}

// Function to append a new node to the list
void append(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to create a cycle in the linked list (for testing)
void createCycle(Node* head, int pos) {
    Node* temp = head;
    Node* cycleNode = nullptr;
    int counter = 1;
    
    // Traverse to the position where we want to create a cycle
    while (temp->next != nullptr) {
        if (counter == pos) {
            cycleNode = temp;  // Save the node to create a cycle
        }
        temp = temp->next;
        counter++;
    }
    
    // If cycleNode is found, create a cycle by linking the last node to it
    if (cycleNode != nullptr) {
        temp->next = cycleNode;
    }
}

int main() {
    Node* head = nullptr;
    
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);
    append(head, 5);
    
    // Uncomment the following line to create a cycle (e.g., a cycle at position 3)
    // createCycle(head, 3);
    
    if (detectCycle(head)) {
        cout << "Cycle detected!" << endl;
    } else {
        cout << "No cycle detected." << endl;
    }
    
    return 0;
}
```

### Explanation:

1. **Node Structure**: 
   - A `Node` is defined with an integer `data` and a pointer `next` pointing to the next node in the list.

2. **`detectCycle` Function**:
   - It initializes two pointers: `slow` (tortoise) and `fast` (hare), both starting from the `head`.
   - The `slow` pointer moves one step at a time, while the `fast` pointer moves two steps at a time.
   - If `slow` and `fast` meet at any point, a cycle is detected.
   - If `fast` reaches `nullptr` (end of the list), there is no cycle.

3. **`createCycle` Function** (for testing):
   - This function helps to manually create a cycle in the linked list by linking the last node back to a node at a given position (index).
   - For example, if `pos = 3`, the last node will point to the node at position 3, creating a cycle.

4. **`main` Function**:
   - First, a linked list is created with nodes containing the values `1, 2, 3, 4, 5`.
   - Then, the cycle detection function `detectCycle` is called to check if there is a cycle in the linked list.
   - If there is a cycle, it prints "Cycle detected!". Otherwise, it prints "No cycle detected.".

### Example 1: No Cycle
For a regular list without any cycle:

```
1 -> 2 -> 3 -> 4 -> 5 -> NULL
```

The output will be:

```
No cycle detected.
```

### Example 2: With Cycle
If you uncomment the `createCycle(head, 3)` line, you create a cycle at position `3`, so the list becomes:

```
1 -> 2 -> 3 -> 4 -> 5
          ^           |
          |-----------|
```

In this case, the output will be:

```
Cycle detected!
```

### Time Complexity:
- **O(n)**: The algorithm traverses the list only once, making it linear in time complexity.

### Space Complexity:
- **O(1)**: The space complexity is constant because only two pointers (`slow` and `fast`) are used for cycle detection.

### Summary:
- Floyd's Cycle-Finding Algorithm (Tortoise and Hare) is an efficient way to detect cycles in a linked list.
- By using two pointers that move at different speeds, the algorithm can detect cycles in O(n) time and O(1) space.