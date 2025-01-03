**Counting Sort** is a non-comparative sorting algorithm that works by counting the number of occurrences of each distinct element in the input array. The count of each element is then used to place each element at its correct position in the sorted array.

Counting Sort is efficient when the range of input values (the difference between the maximum and minimum values) is not very large, because it works in linear time relative to the input size if the range is small.

### Steps of Counting Sort:
1. **Find the maximum element**: The algorithm first finds the maximum element in the input array.
2. **Count the frequency of each element**: Create a frequency array (count array) that stores the number of occurrences of each element.
3. **Update the count array**: For each element in the original array, increment its count in the count array.
4. **Cumulative count**: Modify the count array such that each element at index `i` stores the sum of the previous counts. This gives the actual position of the element in the output array.
5. **Place the elements in the sorted order**: Iterate through the original array, place the elements at their correct positions in the output array based on the modified count array.
6. **Copy the sorted array back to the original array**: Finally, copy the elements from the output array to the original array.

### Time Complexity:
- **Best, Average, Worst Case**: O(n + k), where:
  - `n` is the number of elements in the input array.
  - `k` is the range of the input (the difference between the maximum and minimum elements).
  
  This means Counting Sort can be linear when the range of numbers (`k`) is not too large.

### Space Complexity:
- O(n + k), where `n` is the size of the input array and `k` is the range of the input.

### C++ Code Implementation of Counting Sort

Here is an implementation of the **Counting Sort** algorithm in C++:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countingSort(vector<int>& arr) {
    if (arr.empty()) return;
    
    // Find the maximum and minimum elements
    int maxElem = *max_element(arr.begin(), arr.end());
    int minElem = *min_element(arr.begin(), arr.end());
    
    // The range of numbers in the array
    int range = maxElem - minElem + 1;

    // Create a count array to store the frequency of each element
    vector<int> count(range, 0);
    
    // Store the count of each element
    for (int i = 0; i < arr.size(); i++) {
        count[arr[i] - minElem]++;
    }

    // Modify the count array to store the cumulative frequency
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // Create an output array to store the sorted elements
    vector<int> output(arr.size());

    // Build the output array using the count array
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - minElem] - 1] = arr[i];
        count[arr[i] - minElem]--;
    }

    // Copy the sorted elements into the original array
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

void printArray(const vector<int>& arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    
    cout << "Original Array: ";
    printArray(arr);

    countingSort(arr);

    cout << "Sorted Array: ";
    printArray(arr);

    return 0;
}
```

### Explanation of the Code:
1. **Input Array**: `arr` is the input array to be sorted.
2. **Counting the Frequency**: We first find the minimum and maximum elements in the array to determine the range. Then, we create a **count array** where each index corresponds to a value in the original array, and the value at each index represents the frequency of that number.
3. **Cumulative Frequency**: After counting the frequency of each element, we modify the count array to contain the cumulative frequency, which helps in placing the elements in the correct position in the output array.
4. **Building the Output Array**: We place the elements into the output array using the cumulative count and decrement the count for each element placed.
5. **Copying Back**: Finally, we copy the elements from the output array back into the original array.

### Example Output:

```
Original Array: 4 2 2 8 3 3 1 
Sorted Array: 1 2 2 3 3 4 8 
```

### When to Use Counting Sort:
- Counting Sort is particularly useful when:
  - The range of input numbers (`k`) is small or moderate.
  - The input array contains non-negative integers.
  - The sorting needs to be stable (the relative order of elements with equal values is preserved).
  
### Limitations:
- It is inefficient when the range of input values (`k`) is large compared to the number of elements (`n`), because it requires extra space proportional to the range of input values.
- It does not work well for sorting arbitrary data types (e.g., floating point numbers, strings, or objects) unless those can be mapped to integers.

### Conclusion:
**Counting Sort** is a powerful sorting algorithm for specific use cases where the range of input values is small and the array contains integers. It has a time complexity of **O(n + k)**, which can be very efficient when the range `k` is small relative to the size of the array `n`.