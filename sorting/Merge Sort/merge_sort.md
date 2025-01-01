### Merge Sort – Data Structures and Algorithms in C++: Step-by-Step

**Merge Sort** is a **divide and conquer** algorithm that splits the input array into two halves, recursively sorts each half, and then merges the sorted halves back together. The process is done in a systematic way, and it ensures that the array is sorted with a time complexity of \(O(n \log n)\).

### Steps to Implement Merge Sort:

1. **Divide**: 
   - The array is divided into two halves by finding the middle.
   
2. **Conquer**: 
   - Each half is sorted recursively. This continues until the subarrays are reduced to individual elements, as single elements are trivially sorted.

3. **Combine**: 
   - The sorted halves are merged back together to form a sorted array. This step involves comparing elements from both halves and merging them in sorted order.

### Key Concepts:
- **Divide and Conquer**: We divide the problem into smaller subproblems and conquer them by solving them recursively. Finally, we combine the results to get the final answer.
- **Merging**: The core of the merge sort algorithm is merging two sorted halves together efficiently.

### C++ Code for Merge Sort

Let's implement **Merge Sort** step by step:

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // For std::copy

using namespace std;

// Function to merge two halves of the array
void merge(vector<int>& arr, int left, int mid, int right) {
    // Find the sizes of the two subarrays to merge
    int n1 = mid - left + 1; // Left subarray size
    int n2 = right - mid;    // Right subarray size

    // Create temporary arrays to hold the values
    vector<int> leftArr(n1), rightArr(n2);

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        rightArr[i] = arr[mid + 1 + i];

    // Merge the temporary arrays back into the original array
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of leftArr[], if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy remaining elements of rightArr[], if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Function to implement Merge Sort
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        // Find the middle point
        int mid = left + (right - left) / 2;

        // Recursively sort the first half
        mergeSort(arr, left, mid);

        // Recursively sort the second half
        mergeSort(arr, mid + 1, right);

        // Merge the two halves
        merge(arr, left, mid, right);
    }
}

// Function to print the array
void printArray(const vector<int>& arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    // Example input
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Given array: ";
    printArray(arr);

    // Perform merge sort on the array
    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
```

### Step-by-Step Explanation of the Code:

1. **merge() function**:
   - The `merge()` function takes care of merging two sorted halves of the array.
   - It uses temporary arrays `leftArr` and `rightArr` to store the left and right halves of the array.
   - The function then compares the elements from both halves and places the smaller one into the original array `arr`.
   - After the main loop, any leftover elements from either of the two halves are copied into the original array.

2. **mergeSort() function**:
   - This function recursively divides the array into two halves and sorts each half.
   - The base case of the recursion is when `left >= right`, meaning the subarray is already sorted or contains only one element.
   - For each call, the array is split into two parts using the midpoint `mid = left + (right - left) / 2`.
   - The function then calls itself recursively for the left and right halves, and after that, it merges the two sorted halves back together.

3. **printArray() function**:
   - A simple utility function to print the elements of the array to verify the result.

4. **Main function**:
   - The array is initialized and printed.
   - The `mergeSort()` function is called to sort the array.
   - Finally, the sorted array is printed.

### Example Walkthrough:

**Input:**
```
{12, 11, 13, 5, 6, 7}
```

**Step 1: Split the array recursively:**
```
Initial Array: [12, 11, 13, 5, 6, 7]
Split into two halves: [12, 11, 13] and [5, 6, 7]
```

Now recursively split each half:

```
[12, 11, 13] -> [12] and [11, 13]
[11, 13] -> [11] and [13]
[5, 6, 7] -> [5] and [6, 7]
[6, 7] -> [6] and [7]
```

**Step 2: Merge sorted halves:**

After splitting, the merge steps would be:

1. Merge `[11]` and `[13]` -> `[11, 13]`
2. Merge `[12]` and `[11, 13]` -> `[11, 12, 13]`
3. Merge `[6]` and `[7]` -> `[6, 7]`
4. Merge `[5]` and `[6, 7]` -> `[5, 6, 7]`
5. Finally, merge `[11, 12, 13]` and `[5, 6, 7]` -> `[5, 6, 7, 11, 12, 13]`

**Output:**
```
Sorted array: 5 6 7 11 12 13
```

### Time Complexity:

- **Time Complexity**: 
   - The time complexity of **Merge Sort** is \(O(n \log n)\), where \(n\) is the number of elements in the array. This is because we divide the array into two halves \(\log n\) times, and for each level of recursion, we process all \(n\) elements.
   
- **Space Complexity**: 
   - The space complexity is \(O(n)\) due to the temporary arrays used in the merging step.

### Conclusion:

- **Merge Sort** is a very efficient algorithm with a consistent time complexity of \(O(n \log n)\), making it a great choice for large datasets.
- It is also a stable sorting algorithm (i.e., the relative order of equal elements is preserved).
