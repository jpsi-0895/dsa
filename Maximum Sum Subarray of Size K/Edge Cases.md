When handling edge cases in the **Maximum Sum Subarray of Size K** problem, we need to consider situations where the input array or the value of `K` could lead to unexpected or invalid results. Below are the edge cases you should consider and handle in the C++ code:

### Edge Cases:

1. **Array Size is Less Than K**:
   - If the array size is smaller than `K`, it’s not possible to find a subarray of size `K`. In this case, you should return an error or handle the situation gracefully.

2. **Array is Empty**:
   - If the array is empty (i.e., `arr.size() == 0`), the function should handle it and return a value indicating the problem (e.g., `-1` or print an error message).

3. **K is Zero or Negative**:
   - If `K` is zero or negative, it doesn't make sense to look for a subarray of size zero or negative, so the function should either return `-1` or an error message.

4. **All Elements are Negative**:
   - In this case, the algorithm should still work correctly, returning the maximum sum which could be the largest negative number (or the least negative sum of a subarray of size `K`).

5. **K Equals the Length of the Array**:
   - If `K` is equal to the length of the array, there is only one subarray of size `K`, which is the entire array itself. The sum of this subarray should be returned.

### Updated C++ Code with Edge Case Handling:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSumSubarray(const vector<int>& arr, int K) {
    int n = arr.size();

    // Edge case 1: Array is empty
    if (n == 0) {
        cout << "Array is empty!" << endl;
        return -1;
    }

    // Edge case 2: K is 0 or negative
    if (K <= 0) {
        cout << "Subarray size K must be positive!" << endl;
        return -1;
    }

    // Edge case 3: Array size is smaller than K
    if (n < K) {
        cout << "Array size is smaller than K!" << endl;
        return -1;
    }

    // Step 1: Calculate the sum of the first K elements
    int window_sum = 0;
    for (int i = 0; i < K; ++i) {
        window_sum += arr[i];
    }

    // Step 2: Slide the window and find the maximum sum
    int max_sum = window_sum;  // Initialize max_sum with the sum of the first window
    for (int i = K; i < n; ++i) {
        window_sum += arr[i] - arr[i - K];  // Slide the window (add new element, remove old element)
        max_sum = max(max_sum, window_sum);  // Update max_sum if needed
    }

    return max_sum;
}

int main() {
    // Test Case 1: Standard case
    vector<int> arr1 = {2, 1, 5, 1, 3, 2};
    int K1 = 3;
    cout << "Maximum sum of subarray of size " << K1 << " is: " << maxSumSubarray(arr1, K1) << endl;

    // Test Case 2: Edge case - Array is empty
    vector<int> arr2 = {};
    int K2 = 3;
    cout << "Maximum sum of subarray of size " << K2 << " is: " << maxSumSubarray(arr2, K2) << endl;

    // Test Case 3: Edge case - K is 0 or negative
    vector<int> arr3 = {1, 2, 3};
    int K3 = 0;
    cout << "Maximum sum of subarray of size " << K3 << " is: " << maxSumSubarray(arr3, K3) << endl;

    // Test Case 4: Edge case - Array size is smaller than K
    vector<int> arr4 = {1, 2};
    int K4 = 3;
    cout << "Maximum sum of subarray of size " << K4 << " is: " << maxSumSubarray(arr4, K4) << endl;

    // Test Case 5: Edge case - All elements are negative
    vector<int> arr5 = {-1, -2, -3, -4, -5};
    int K5 = 2;
    cout << "Maximum sum of subarray of size " << K5 << " is: " << maxSumSubarray(arr5, K5) << endl;

    // Test Case 6: Edge case - K equals the length of the array
    vector<int> arr6 = {1, 2, 3, 4};
    int K6 = 4;
    cout << "Maximum sum of subarray of size " << K6 << " is: " << maxSumSubarray(arr6, K6) << endl;

    return 0;
}
```

### Explanation of Edge Case Handling:

1. **Empty Array**: If the array has no elements, the function returns `-1` and prints an error message: `"Array is empty!"`.
2. **K is Zero or Negative**: If `K` is less than or equal to zero, the function returns `-1` and prints the message: `"Subarray size K must be positive!"`.
3. **Array Size is Smaller than K**: If the array has fewer elements than `K`, it’s not possible to form a subarray of size `K`, so the function returns `-1` and prints `"Array size is smaller than K!"`.
4. **All Elements Negative**: The sliding window technique works correctly even if all elements are negative, as it will simply calculate the largest sum possible.
5. **K Equals Array Length**: When `K` equals the array length, there is only one subarray of size `K`, which is the entire array. The function will return the sum of the entire array.

### Example Outputs:

1. **Standard case**:
   ```
   Maximum sum of subarray of size 3 is: 9
   ```

2. **Edge case - Array is empty**:
   ```
   Array is empty!
   Maximum sum of subarray of size 3 is: -1
   ```

3. **Edge case - K is 0 or negative**:
   ```
   Subarray size K must be positive!
   Maximum sum of subarray of size 0 is: -1
   ```

4. **Edge case - Array size is smaller than K**:
   ```
   Array size is smaller than K!
   Maximum sum of subarray of size 3 is: -1
   ```

5. **Edge case - All elements are negative**:
   ```
   Maximum sum of subarray of size 2 is: -1
   ```

6. **Edge case - K equals the length of the array**:
   ```
   Maximum sum of subarray of size 4 is: 10
   ```

This updated version ensures that the function handles edge cases appropriately and provides meaningful feedback when encountering issues.