Here's how you can implement the **Maximum Sum Subarray of Size K** problem in **C++** using the **Sliding Window** technique:

### Problem:
Given an array of integers, find the maximum sum of a subarray of size `K`.

### Approach:
1. **Initial Window**: Calculate the sum of the first `K` elements.
2. **Sliding the Window**: For each subsequent element in the array, update the sum by subtracting the element that's sliding out of the window and adding the element that's entering the window.
3. **Track Maximum Sum**: Keep track of the maximum sum encountered while sliding the window across the array.

### Time Complexity:
- **O(n)**, where `n` is the number of elements in the array, because we calculate the sum of the first `K` elements once, and then update it for each subsequent element in constant time.

### C++ Code:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSumSubarray(const vector<int>& arr, int K) {
    int n = arr.size();
    
    // Edge case: If array size is less than K, it's not possible to have a subarray of size K
    if (n < K) {
        cout << "Array size is smaller than K" << endl;
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
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int K = 3;
    
    int result = maxSumSubarray(arr, K);
    cout << "Maximum sum of subarray of size " << K << " is: " << result << endl;
    
    return 0;
}
```

### Explanation of the Code:
1. **Input**: The program takes an array `arr` and an integer `K`, representing the subarray size.
2. **Edge Case**: If the size of the array is less than `K`, it returns `-1` as it's impossible to find a subarray of size `K`.
3. **Window Calculation**: It calculates the sum of the first `K` elements (`window_sum`).
4. **Sliding the Window**: Then, for each subsequent element in the array, it updates the `window_sum` by subtracting the element that is no longer in the window and adding the new element.
5. **Maximum Sum**: It keeps track of the maximum sum encountered during this sliding process.
6. **Output**: It prints the maximum sum found for any subarray of size `K`.

### Example:

For the array `[2, 1, 5, 1, 3, 2]` and `K = 3`, the algorithm computes:

- First window sum (for indices 0 to 2): `2 + 1 + 5 = 8`
- Slide the window:
  - Remove 2, add 1 (window: `[1, 5, 1]`), sum = `7`
  - Remove 1, add 3 (window: `[5, 1, 3]`), sum = `9` (new max)
  - Remove 5, add 2 (window: `[1, 3, 2]`), sum = `6`
  
The maximum sum of a subarray of size `3` is `9`.

### Output:
```
Maximum sum of subarray of size 3 is: 9
```

This approach ensures that the sum of the subarrays is calculated efficiently in **O(n)** time, making it much faster than a brute-force approach.