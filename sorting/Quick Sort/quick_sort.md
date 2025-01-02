### Quick Sort – Data Structures and Algorithms in C++

**Quick Sort** is another popular **divide and conquer** algorithm used to sort an array or a list. It works by selecting a "pivot" element from the array, partitioning the array around the pivot, and recursively sorting the subarrays.

### Quick Sort Algorithm

1. **Pivot Selection**: Choose an element from the array to act as the pivot. There are various strategies to choose the pivot:
   - First element
   - Last element
   - Random element
   - Median of three

2. **Partitioning**: Rearrange the elements of the array such that:
   - All elements less than the pivot are placed before the pivot.
   - All elements greater than the pivot are placed after it.
   
   After this, the pivot is in its correct position in the sorted array.

3. **Recursion**: Recursively apply the quicksort algorithm to the subarrays on the left and right of the pivot.

### Time Complexity

- **Best and Average Case**: \(O(n \log n)\) when the pivot splits the array into two nearly equal halves.
- **Worst Case**: \(O(n^2)\) when the pivot is always the smallest or largest element (e.g., if the array is already sorted).
- **Space Complexity**: \(O(\log n)\) for the recursive stack in the best case.

### C++ Code for Quick Sort

Let's implement Quick Sort step-by-step in C++:

```cpp
#include <iostream>
#include <vector>

using namespace std;

// Function to partition the array into two halves based on the pivot
int partition(vector<int>& arr, int low, int high) {
    // Choose the last element as pivot
    int pivot = arr[high];
    int i = low - 1; // Pointer for the smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]); // Swap arr[i] and arr[j]
        }
    }
    // Swap the pivot element with the element at i + 1 to place the pivot in the correct position
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Function to perform the Quick Sort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Find pivot element such that arr[pivot] is in the correct position
        int pi = partition(arr, low, high);

        // Recursively sort the two halves
        quickSort(arr, low, pi - 1);  // Sort elements before pivot
        quickSort(arr, pi + 1, high); // Sort elements after pivot
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
    vector<int> arr = {10, 80, 30, 90, 40, 50, 70};

    cout << "Given array: ";
    printArray(arr);

    // Perform Quick Sort on the array
    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
```

### Step-by-Step Explanation of the Code:

1. **partition() function**:
   - The `partition()` function selects the last element as the pivot.
   - It then rearranges the array such that all elements smaller than the pivot are moved to the left of the pivot and all elements greater than the pivot are moved to the right.
   - Finally, it places the pivot in its correct position in the sorted array and returns the index of the pivot.

2. **quickSort() function**:
   - This function is the main part of the Quick Sort algorithm.
   - It recursively divides the array into two subarrays: elements before the pivot and elements after the pivot.
   - Each subarray is sorted by calling the `quickSort()` function again on the subarrays.

3. **printArray() function**:
   - A simple utility function to print the elements of the array to verify the result.

4. **Main function**:
   - The array is initialized with some test data.
   - The `quickSort()` function is called to sort the array.
   - The sorted array is printed.

### Example Walkthrough:

**Input:**
```
{10, 80, 30, 90, 40, 50, 70}
```

**Step 1: First partitioning:**

- Pivot: 70 (last element)
- After partitioning, the array becomes:
  ```
  [10, 30, 40, 50, 70, 90, 80]
  ```
  Pivot (70) is now in its correct position at index 4.

**Step 2: Recursively apply Quick Sort on the two subarrays:**

1. Left subarray: `[10, 30, 40, 50]`
   - Pivot: 50 (last element)
   - After partitioning, the array becomes:
     ```
     [10, 30, 40, 50]
     ```
     Pivot (50) is in its correct position at index 3.

2. Right subarray: `[90, 80]`
   - Pivot: 80 (last element)
   - After partitioning, the array becomes:
     ```
     [10, 30, 40, 50, 70, 80, 90]
     ```
     Pivot (80) is in its correct position at index 6.

**Step 3: Recursion ends when the subarrays contain one or zero elements.**

**Output:**
```
Sorted array: 10 30 40 50 70 80 90
```

### Time Complexity:
- **Best Case**: \(O(n \log n)\), when the pivot divides the array into two roughly equal halves.
- **Average Case**: \(O(n \log n)\), which happens when the pivot does a good job of dividing the array.
- **Worst Case**: \(O(n^2)\), which happens when the pivot is always the smallest or largest element (for example, if the array is already sorted or reverse-sorted).

### Space Complexity:
- **Space Complexity**: \(O(\log n)\) on average for the recursion stack, as the depth of the recursion tree is logarithmic in the best and average cases.
- In the worst case, the recursion depth can be as large as \(O(n)\), leading to \(O(n)\) space complexity.

### Conclusion:
- **Quick Sort** is an efficient sorting algorithm with a **best-case** and **average-case time complexity** of \(O(n \log n)\).
- It is typically faster than other \(O(n \log n)\) algorithms, like Merge Sort, due to smaller hidden constants and the fact that it sorts in place (does not require extra space for merging).
- However, its **worst-case** time complexity is \(O(n^2)\), which can be mitigated by using better pivot selection strategies (like random pivot or median of three).


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
