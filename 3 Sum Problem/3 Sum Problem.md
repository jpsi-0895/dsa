The **3Sum** problem is a common problem often asked in coding interviews. The task is to find all unique triplets in an array that sum up to a given target, typically zero. Here's a detailed approach to solving it in C++.

### Problem Description
You are given an array of integers, and you need to find all unique triplets in the array that sum to zero.

### Solution Outline
The approach to solve this problem is as follows:

1. **Sort the Array**: Sorting helps to simplify the search for triplets, as you can use a two-pointer technique to efficiently find the remaining two numbers that add up to the target.
  
2. **Use a Loop**: For each element in the array, treat it as the first element of a potential triplet. Then, use two pointers (one starting from the element right after the current one, and the other from the end of the array) to find the other two elements.

3. **Avoid Duplicates**: To avoid counting duplicate triplets, skip over duplicate elements during both the loop and the two-pointer searches.

### C++ Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    int n = nums.size();

    // Sort the array
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; ++i) {
        // Skip duplicate elements for the first number of the triplet
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        // Use two-pointer technique to find pairs that sum to -nums[i]
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                result.push_back({nums[i], nums[left], nums[right]});
                
                // Move left pointer to the right to skip duplicates
                while (left < right && nums[left] == nums[left + 1]) left++;
                // Move right pointer to the left to skip duplicates
                while (left < right && nums[right] == nums[right - 1]) right--;

                // Move both pointers
                left++;
                right--;
            } else if (sum < 0) {
                // If the sum is less than zero, move the left pointer to the right to increase the sum
                left++;
            } else {
                // If the sum is greater than zero, move the right pointer to the left to decrease the sum
                right--;
            }
        }
    }

    return result;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum(nums);

    cout << "Triplets that sum to 0 are:\n";
    for (const auto& triplet : result) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
```

### Explanation of the Code

1. **Sort the Input Array**: 
   - Sorting ensures that the triplets can be found efficiently using the two-pointer technique.

2. **Outer Loop**: 
   - The outer loop (indexed by `i`) iterates over each number in the array. For each number, treat it as the first number of the triplet.

3. **Two Pointers**:
   - After fixing the first number (`nums[i]`), two pointers (`left` and `right`) are used to find the other two numbers that sum with `nums[i]` to zero.
   - If the sum of the three numbers is zero, add the triplet to the result.
   - If the sum is less than zero, move the `left` pointer to the right to increase the sum.
   - If the sum is greater than zero, move the `right` pointer to the left to decrease the sum.

4. **Skip Duplicates**:
   - After adding a valid triplet, both the `left` and `right` pointers are moved to skip over duplicate numbers to avoid adding the same triplet again.

5. **Edge Case Handling**:
   - The solution works even if the array contains fewer than three elements.
   - If there are duplicates in the array, they are automatically skipped, ensuring that only unique triplets are returned.

### Time Complexity
- Sorting the array takes \(O(n \log n)\).
- The two-pointer search runs in \(O(n)\) for each element in the array, leading to an overall time complexity of \(O(n^2)\).

### Example Input and Output
**Input:**
```cpp
{-1, 0, 1, 2, -1, -4}
```

**Output:**
```
Triplets that sum to 0 are:
-1 -1 2 
-1 0 1 
```

This solution efficiently finds all unique triplets that sum to zero in \(O(n^2)\) time.