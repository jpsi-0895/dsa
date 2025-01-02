### Selection Sort in C++

**Selection Sort** is a simple sorting algorithm that divides the list into two parts: a sorted part and an unsorted part. It repeatedly selects the minimum (or maximum, depending on the sorting order) element from the unsorted part and swaps it with the leftmost unsorted element, thereby expanding the sorted part.

The algorithm works as follows:
1. Start with the first element of the array and find the smallest element in the unsorted portion of the array.
2. Swap this smallest element with the element at the current position.
3. Move to the next element and repeat until the entire array is sorted.

### Time Complexity:
- **Best, Worst, and Average Case**: \(O(n^2)\), where \(n\) is the number of elements in the array. This happens because for each element, the algorithm scans the entire unsorted portion to find the minimum.

### Space Complexity:
- \(O(1)\), because the algorithm sorts the array in-place.

### C++ Code for Selection Sort:

```cpp
#include <iostream>
using namespace std;

// Function to perform selection sort
void selectionSort(int arr[], int n) {
    // One by one move boundary of unsorted subarray
    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in the unsorted array
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        // Swap the found minimum element with the element at index i
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    printArray(arr, n);

    selectionSort(arr, n);
    
    cout << "Sorted array: ";
    printArray(arr, n);
    
    return 0;
}
```

### Explanation:
1. **selectionSort Function**:
   - The outer loop (`i`) iterates over each element of the array.
   - The inner loop (`j`) searches the unsorted part of the array to find the minimum element.
   - Once the minimum element is found, it is swapped with the element at the beginning of the unsorted part (i.e., `arr[i]`).
   
2. **printArray Function**:
   - This function is used to print the array.

3. **Main Function**:
   - The array is initialized and passed to the `selectionSort` function to sort it.
   - After sorting, the sorted array is printed.

### Output:

```
Original array: 64 25 12 22 11 
Sorted array: 11 12 22 25 64 
```

### Explanation of the Steps:
- Initially, the unsorted array is: `[64, 25, 12, 22, 11]`.
- The first pass (i = 0): Finds 11 as the smallest element and swaps it with 64. New array: `[11, 25, 12, 22, 64]`.
- The second pass (i = 1): Finds 12 as the smallest element and swaps it with 25. New array: `[11, 12, 25, 22, 64]`.
- The third pass (i = 2): Finds 22 as the smallest element and swaps it with 25. New array: `[11, 12, 22, 25, 64]`.
- The fourth pass (i = 3): 25 is already the smallest element, so no swap is needed.
- Finally, the sorted array is: `[11, 12, 22, 25, 64]`.

### Summary:
- **Selection Sort** is a simple, in-place sorting algorithm but is inefficient for large datasets with a time complexity of \(O(n^2)\).
- Despite its inefficiency, it's easy to understand and implement.


### Insertion Sort in C++

**Insertion Sort** is a simple comparison-based sorting algorithm. It works by building a sorted portion of the array one element at a time by repeatedly picking the next element and inserting it into its correct position in the sorted portion.

### Algorithm Steps:
1. Start with the second element (index 1). Compare it with the first element.
2. If the second element is smaller, shift the first element to the right to make space, and insert the second element in the correct position.
3. Move to the next element, compare it with the elements in the sorted portion, shift the necessary elements to the right, and insert the element into the correct position.
4. Repeat this process until the entire array is sorted.

### Time Complexity:
- **Best Case**: \(O(n)\) when the array is already sorted.
- **Worst Case**: \(O(n^2)\) when the array is in reverse order.
- **Average Case**: \(O(n^2)\).

### Space Complexity:
- \(O(1)\) since the algorithm sorts the array in-place.

### C++ Code for Insertion Sort:

```cpp
#include <iostream>
using namespace std;

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    // Traverse from the second element to the last
    for (int i = 1; i < n; i++) {
        int key = arr[i];  // The current element to be inserted
        int j = i - 1;
        
        // Shift elements of arr[0..i-1] that are greater than key, to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        // Insert the key into its correct position
        arr[j + 1] = key;
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    printArray(arr, n);

    insertionSort(arr, n);
    
    cout << "Sorted array: ";
    printArray(arr, n);
    
    return 0;
}
```

### Explanation:
1. **insertionSort Function**:
   - The outer loop starts from the second element and compares it with the elements in the sorted portion of the array (to its left).
   - The inner `while` loop shifts elements of the sorted portion that are greater than the `key` to the right, making space for the `key` element.
   - After shifting the elements, the `key` is inserted into its correct position in the sorted part.

2. **printArray Function**:
   - This function is used to print the array before and after sorting.

3. **Main Function**:
   - The array is initialized and passed to the `insertionSort` function for sorting.
   - After sorting, the sorted array is printed.

### Output:

```
Original array: 12 11 13 5 6 
Sorted array: 5 6 11 12 13 
```

### Explanation of the Steps:
- Initially, the unsorted array is: `[12, 11, 13, 5, 6]`.
- The first pass (i = 1): The key is 11. Compare 11 with 12, shift 12 to the right, and place 11 in the first position. New array: `[11, 12, 13, 5, 6]`.
- The second pass (i = 2): The key is 13. 13 is already in the correct position, so no changes are made.
- The third pass (i = 3): The key is 5. Compare 5 with 13, 12, and 11, shift all of them to the right, and place 5 in the first position. New array: `[5, 11, 12, 13, 6]`.
- The fourth pass (i = 4): The key is 6. Compare 6 with 13, shift 13, 12, and 11 to the right, and place 6 in the second position. New array: `[5, 6, 11, 12, 13]`.
- Finally, the sorted array is: `[5, 6, 11, 12, 13]`.

### Summary:
- **Insertion Sort** is efficient for small data sets or nearly sorted data but inefficient for large data sets with a time complexity of \(O(n^2)\).
- It is an in-place, stable sorting algorithm with \(O(1)\) space complexity.
- The algorithm works similarly to how we sort playing cards in hand.

### Bubble Sort in C++

**Bubble Sort** is one of the simplest sorting algorithms. It works by repeatedly stepping through the list to be sorted, comparing each pair of adjacent items, and swapping them if they are in the wrong order. The process continues until no more swaps are needed, meaning the list is sorted.

### Algorithm Steps:
1. Start from the first element of the array.
2. Compare the current element with the next element.
3. If the current element is greater than the next element, swap them.
4. Repeat the process for every adjacent pair of elements in the array.
5. After each pass through the array, the largest unsorted element "bubbles" up to its correct position.
6. Repeat the process until no swaps are needed, indicating that the array is sorted.

### Time Complexity:
- **Best Case**: \(O(n)\), when the array is already sorted.
- **Worst Case**: \(O(n^2)\), when the array is sorted in reverse order.
- **Average Case**: \(O(n^2)\).

### Space Complexity:
- \(O(1)\), since the sorting is done in-place with no additional memory used.

### C++ Code for Bubble Sort:

```cpp
#include <iostream>
using namespace std;

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    bool swapped;
    
    // Traverse through all elements in the array
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        
        // Last i elements are already in place
        for (int j = 0; j < n - i - 1; j++) {
            // Compare adjacent elements
            if (arr[j] > arr[j + 1]) {
                // Swap the elements if they are in the wrong order
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        
        // If no elements were swapped in the inner loop, then the array is sorted
        if (!swapped)
            break;
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    printArray(arr, n);

    bubbleSort(arr, n);
    
    cout << "Sorted array: ";
    printArray(arr, n);
    
    return 0;
}
```

### Explanation:
1. **bubbleSort Function**:
   - The outer loop iterates over the entire array. The variable `swapped` is used to check if any elements were swapped during the inner loop.
   - The inner loop compares each pair of adjacent elements, and if they are in the wrong order, they are swapped.
   - After each pass, the largest element is moved to the correct position at the end of the array.
   - If no elements were swapped in an entire pass, the `swapped` flag will be `false`, and the algorithm terminates early, as the array is already sorted.

2. **printArray Function**:
   - This function simply prints the elements of the array.

3. **Main Function**:
   - The array is initialized and passed to the `bubbleSort` function for sorting.
   - After sorting, the sorted array is printed.

### Output:

```
Original array: 64 34 25 12 22 11 90 
Sorted array: 11 12 22 25 34 64 90 
```

### Explanation of the Steps:
- Initially, the unsorted array is: `[64, 34, 25, 12, 22, 11, 90]`.
- The first pass (i = 0): The largest element (90) is "bubbled" to the end of the array. The array becomes `[34, 25, 12, 22, 11, 64, 90]`.
- The second pass (i = 1): The second-largest element (64) is placed in its correct position. The array becomes `[25, 12, 22, 11, 34, 64, 90]`.
- The third pass (i = 2): The third-largest element (34) is placed in its correct position. The array becomes `[12, 22, 11, 25, 34, 64, 90]`.
- The fourth pass (i = 3): The array becomes `[12, 11, 22, 25, 34, 64, 90]`.
- The fifth pass (i = 4): The array becomes `[11, 12, 22, 25, 34, 64, 90]`, and now it's sorted.

### Optimization (Early Exit):
- If the array is already sorted before the last pass, the algorithm will break early and terminate. This optimization helps improve performance for nearly sorted arrays.

### Summary:
- **Bubble Sort** is simple and easy to understand but not efficient for large datasets with a time complexity of \(O(n^2)\).
- It is an in-place sorting algorithm with \(O(1)\) space complexity.
- Despite its inefficiency, it is used for educational purposes and for small data sets.