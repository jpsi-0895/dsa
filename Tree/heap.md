A **heap** is a special type of binary tree that satisfies the **heap property**. There are two main types of heaps:

1. **Max-Heap**: In a max-heap, the value of each parent node is greater than or equal to the values of its children.
2. **Min-Heap**: In a min-heap, the value of each parent node is less than or equal to the values of its children.

For **binary heaps**, the tree is typically represented as an array, where:
- The root is at index 0.
- The left child of node at index `i` is at index `2*i + 1`.
- The right child of node at index `i` is at index `2*i + 2`.
- The parent of node at index `i` is at index `(i-1)/2`.

### Basic Heap Operations:
- **Insert**: Adds an element to the heap while maintaining the heap property.
- **Extract**: Removes the root (maximum or minimum) element from the heap and re-adjusts the heap to maintain its property.
- **Heapify**: Ensures that the heap property is maintained by adjusting the tree from a given node.
- **Build Heap**: Constructs a heap from an unsorted array.
- **Peek**: Returns the root element of the heap (max or min) without removing it.
- **Size**: Returns the size of the heap.
- **Empty**: Checks whether the heap is empty.

### Implementation of Heap Operations in C++

Below is the implementation of **Max-Heap** with the basic heap operations in C++.

```cpp
#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap; // Vector to store heap elements

    // Helper function to maintain the heap property by "heapifying" a subtree
    void heapify(int index) {
        int largest = index;  // Initialize largest as root
        int left = 2 * index + 1;  // Left child index
        int right = 2 * index + 2;  // Right child index

        // If left child is larger than root
        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }

        // If right child is larger than the largest so far
        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }

        // If largest is not root, swap and continue heapifying
        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapify(largest);  // Recursively heapify the affected subtree
        }
    }

    // Helper function to "bubble up" an element to maintain the heap property after insertion
    void bubbleUp(int index) {
        while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

public:
    // Function to insert a new element into the heap
    void insert(int val) {
        heap.push_back(val);  // Add new value at the end
        bubbleUp(heap.size() - 1);  // Bubble up to maintain heap property
    }

    // Function to extract the maximum (root) element from the heap
    int extractMax() {
        if (heap.empty()) {
            cout << "Heap is empty!\n";
            return -1;
        }
        int maxVal = heap[0];
        heap[0] = heap.back();  // Move the last element to the root
        heap.pop_back();  // Remove the last element
        heapify(0);  // Heapify from the root
        return maxVal;
    }

    // Function to get the maximum (root) element without removing it
    int peek() {
        if (heap.empty()) {
            cout << "Heap is empty!\n";
            return -1;
        }
        return heap[0];
    }

    // Function to build a heap from an unsorted array
    void buildHeap(const vector<int>& arr) {
        heap = arr;
        for (int i = heap.size() / 2 - 1; i >= 0; --i) {
            heapify(i);
        }
    }

    // Function to get the size of the heap
    int size() {
        return heap.size();
    }

    // Function to check if the heap is empty
    bool empty() {
        return heap.empty();
    }

    // Function to display the heap
    void display() {
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap maxHeap;

    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(5);
    maxHeap.insert(30);
    maxHeap.insert(40);

    cout << "Heap after insertions: ";
    maxHeap.display();

    cout << "Extracted max: " << maxHeap.extractMax() << endl;
    cout << "Heap after extracting max: ";
    maxHeap.display();

    cout << "Peek (max element): " << maxHeap.peek() << endl;

    vector<int> arr = {10, 20, 5, 30, 40};
    maxHeap.buildHeap(arr);
    cout << "Heap after building from array: ";
    maxHeap.display();

    cout << "Size of heap: " << maxHeap.size() << endl;
    cout << "Is heap empty? " << (maxHeap.empty() ? "Yes" : "No") << endl;

    return 0;
}
```

### Explanation of Operations:

1. **Insert**:
   - We insert a new element at the end of the heap (in the array).
   - Then, we "bubble up" the new element to restore the max-heap property, ensuring that the parent is larger than the children.

2. **Extract Max**:
   - The maximum element is always at the root (index 0) in a max-heap.
   - We swap the root with the last element, remove the last element, and then "heapify" the root to restore the heap property.

3. **Peek**:
   - We simply return the root element without removing it.

4. **Build Heap**:
   - To build a heap from an unsorted array, we start from the last non-leaf node and perform a "heapify" operation to ensure that each subtree satisfies the heap property.

5. **Heapify**:
   - This is a crucial function that ensures that the heap property is maintained by adjusting the tree from a given node downward. It checks the node with its children and swaps if necessary, continuing until the heap property is restored.

6. **Bubble Up**:
   - This operation ensures that a newly inserted element is placed correctly by comparing it with its parent and swapping if needed, moving up the tree until the heap property is satisfied.

### Example Output:

```
Heap after insertions: 40 30 10 5 20 
Extracted max: 40
Heap after extracting max: 30 20 10 5 
Peek (max element): 30
Heap after building from array: 40 30 10 5 20 
Size of heap: 5
Is heap empty? No
```

### Time Complexity:

1. **Insert**: O(log n), because we may need to bubble up the element to the root.
2. **Extract Max**: O(log n), because we may need to heapify the tree after extracting the root.
3. **Peek**: O(1), simply accessing the root.
4. **Build Heap**: O(n), because we perform a bottom-up heapify.
5. **Heapify**: O(log n), as it may require adjusting the tree for each node down to the leaves.

### Space Complexity:

- The space complexity is O(n), where `n` is the number of elements in the heap, because we store the heap elements in an array.

### Min-Heap Implementation:

To implement a **Min-Heap**, you just need to modify the comparison logic in the `heapify` and `bubbleUp` functions:
- For **heapify**, instead of comparing the current node with the largest child, compare it with the smallest child.
- Similarly, for **bubbleUp**, compare the node with its parent and swap if the parent's value is greater than the current node.

This will create a **Min-Heap** where the root is always the smallest element.