In C++, a **stack** is a data structure that follows the **Last In, First Out (LIFO)** principle, where the last element added to the stack is the first one to be removed. The primary operations of a stack include:

1. **push**: Adds an element to the top of the stack.
2. **pop**: Removes the element from the top of the stack.
3. **top**: Returns the element at the top of the stack without removing it.
4. **empty**: Checks whether the stack is empty.
5. **size**: Returns the number of elements in the stack.

C++ provides a standard library container `std::stack` that supports stack operations. However, you can also implement your own stack using arrays or linked lists. I'll cover both methods here.

#### Explanation:

- **Node structure**: Each node contains a `data` field to store the element and a `next` pointer to link to the next node.
- **Push operation**: A new node is created and added to the top of the stack.
- **Pop operation**: The node at the top is removed, and memory is freed.
- **Peek operation**: Returns the data of the top node.
- **isEmpty**: Checks if the stack is empty by verifying if the `top` pointer is `nullptr`.
- **Size**: Traverses the linked list and counts the number of nodes to determine the size.

---

### Summary:

- **Array-based stack** uses a fixed-size array and is easy to implement but has a limitation on stack size.
- **Linked-list-based stack** has dynamic size, and you can push and pop elements without worrying about overflow or underflow due to fixed size. However, it requires additional memory for storing pointers.
- **`std::stack`** is a built-in container in the C++ Standard Library that simplifies stack operations and is based on `std::deque` by default.

### 1. **Using `std::stack` from the Standard Library**

#### Example with `std::stack`:

```cpp
#include <iostream>
#include <stack>

int main() {
    std::stack<int> s; // Create a stack of integers

    // Push elements onto the stack
    s.push(10);
    s.push(20);
    s.push(30);

    // Get and print the top element
    std::cout << "Top element: " << s.top() << std::endl; // Output: 30

    // Pop an element from the stack
    s.pop();
    std::cout << "Top element after pop: " << s.top() << std::endl; // Output: 20

    // Check if the stack is empty
    if (s.empty()) {
        std::cout << "The stack is empty!" << std::endl;
    } else {
        std::cout << "The stack is not empty." << std::endl; // Output: The stack is not empty.
    }

    // Get the size of the stack
    std::cout << "Stack size: " << s.size() << std::endl; // Output: 2

    return 0;
}
```

#### Explanation:

- `push(10)` adds `10` to the stack.
- `top()` returns the element at the top (without removing it).
- `pop()` removes the element at the top.
- `empty()` checks if the stack is empty.
- `size()` returns the number of elements in the stack.

### 2. **Implementing Stack Using Arrays**

#### Stack Implementation Using Arrays:

```cpp
#include <iostream>
#define MAX 100 // Define the maximum size of the stack

class Stack {
private:
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1; // Initialize stack as empty
    }

    // Push operation
    void push(int x) {
        if (top == MAX - 1) {
            std::cout << "Stack overflow!" << std::endl;
            return;
        }
        arr[++top] = x; // Increase top and insert the element
    }

    // Pop operation
    void pop() {
        if (top == -1) {
            std::cout << "Stack underflow!" << std::endl;
            return;
        }
        top--; // Decrease top, effectively removing the element
    }

    // Top operation
    int peek() {
        if (top == -1) {
            std::cout << "Stack is empty!" << std::endl;
            return -1;
        }
        return arr[top]; // Return the element at the top
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Get the size of the stack
    int size() {
        return top + 1;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "Top element: " << s.peek() << std::endl; // Output: 30
    s.pop();

    std::cout << "Top element after pop: " << s.peek() << std::endl; // Output: 20
    std::cout << "Stack size: " << s.size() << std::endl; // Output: 2

    if (s.isEmpty()) {
        std::cout << "The stack is empty!" << std::endl;
    } else {
        std::cout << "The stack is not empty." << std::endl; // Output: The stack is not empty.
    }

    return 0;
}
```

#### Explanation:

- **Stack class**: A custom class `Stack` is created with an array `arr` to store elements and an integer `top` to track the index of the top element.
- **Push operation**: Adds an element to the top, checking for stack overflow.
- **Pop operation**: Removes the top element, checking for stack underflow.
- **Peek operation**: Returns the top element without removing it.
- **isEmpty**: Checks if the stack is empty by verifying if `top == -1`.
- **Size**: Returns the current number of elements in the stack by returning `top + 1`.

### 3. **Implementing Stack Using Linked List**

#### Stack Implementation Using Linked List:

```cpp
#include <iostream>

// Define a node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Define the Stack class
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr; // Initialize the stack as empty
    }

    // Push operation
    void push(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = top; // Link the new node to the current top
        top = newNode; // Update the top pointer to the new node
    }

    // Pop operation
    void pop() {
        if (top == nullptr) {
            std::cout << "Stack underflow!" << std::endl;
            return;
        }
        Node* temp = top;
        top = top->next; // Move top to the next node
        delete temp; // Free memory
    }

    // Top operation
    int peek() {
        if (top == nullptr) {
            std::cout << "Stack is empty!" << std::endl;
            return -1;
        }
        return top->data; // Return the data at the top node
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Get the size of the stack
    int size() {
        int count = 0;
        Node* temp = top;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "Top element: " << s.peek() << std::endl; // Output: 30
    s.pop();

    std::cout << "Top element after pop: " << s.peek() << std::endl; // Output: 20
    std::cout << "Stack size: " << s.size() << std::endl; // Output: 2

    if (s.isEmpty()) {
        std::cout << "The stack is empty!" << std::endl;
    } else {
        std::cout << "The stack is not empty." << std::endl; // Output: The stack is not empty.
    }

    return 0;
}
```
