The **2 Sum Problem** is a common algorithmic problem where you are given an array of integers and a target sum. The goal is to find two numbers in the array whose sum equals the target. You are required to return the indices of the two numbers that add up to the target.

### Problem Statement:
Given an array of integers `nums` and a target integer `target`, return the indices of the two numbers such that they add up to `target`. You may assume that each input would have exactly one solution, and you may not use the same element twice.

### Example:
- **Input**: `nums = [2, 7, 11, 15]`, `target = 9`
- **Output**: `[0, 1]` 
- **Explanation**: Because `nums[0] + nums[1] == 9`, we return `[0, 1]`.

### Approach:
1. **Brute Force Approach (O(n²))**:
   - For each element `i`, check all the subsequent elements `j` to see if their sum equals the target. This approach has a time complexity of O(n²).

2. **Optimal Approach (O(n)) - Using a Hash Map**:
   - As you iterate through the array, for each number, check if the complement (i.e., `target - num`) is already in a hash map. If it is, that means we've found the two numbers that sum to the target. This allows us to solve the problem in linear time.

### C++ Code (Optimal Approach with Hash Map):
```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(const vector<int>& nums, int target) {
    unordered_map<int, int> num_map;  // To store the value and its index
    vector<int> result;
    
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        
        // Check if the complement exists in the hash map
        if (num_map.find(complement) != num_map.end()) {
            result.push_back(num_map[complement]);  // The index of the complement
            result.push_back(i);  // The current index
            return result;
        }
        
        // Store the current number and its index
        num_map[nums[i]] = i;
    }
    
    return result;  // In case no solution is found, though problem guarantees one solution
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    vector<int> result = twoSum(nums, target);
    
    if (!result.empty()) {
        cout << "Indices of the two numbers that sum to " << target << ": ";
        cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    } else {
        cout << "No solution found!" << endl;
    }

    return 0;
}
```

### Explanation:

1. **Input**: We have an array `nums` and a `target` integer.
2. **Hash Map**: We use an unordered map (`unordered_map<int, int>`) to store the numbers we've seen so far and their corresponding indices.
3. **Loop**: For each number in the array:
   - Compute the complement, which is `target - nums[i]`.
   - Check if the complement exists in the map. If it does, return the indices of the complement and the current number.
   - If not, store the current number and its index in the map.
4. **Output**: Return the indices of the two numbers that sum up to the target.

### Time Complexity:
- **O(n)**, where `n` is the number of elements in the array. This is because we only iterate through the array once, and each map operation (insertion and lookup) takes constant time on average.

### Space Complexity:
- **O(n)**, where `n` is the number of elements in the array. The space complexity is due to the storage of the hash map, which may contain up to `n` elements.

### Example Walkthrough:

For the array `nums = [2, 7, 11, 15]` and target `9`:

1. **First Iteration** (`i = 0`):
   - `nums[0] = 2`
   - `complement = 9 - 2 = 7`
   - The map is empty, so store `2` with index `0`: `{2: 0}`.

2. **Second Iteration** (`i = 1`):
   - `nums[1] = 7`
   - `complement = 9 - 7 = 2`
   - The complement `2` is in the map with index `0`, so return `[0, 1]`.

Thus, the result is `[0, 1]`, which are the indices of the numbers `2` and `7` that sum to `9`.

### Edge Cases:

1. **Single Pair**:
   - If the array has only two elements, they should always sum to the target, so the code should return their indices.
   
2. **Negative Numbers**:
   - The solution works with negative numbers as well. For example, `nums = [-1, 4, 6, 5]` and `target = 4` will return `[0, 2]`.

3. **Large Arrays**:
   - The solution should handle arrays of larger sizes efficiently, as it operates in **O(n)** time complexity.

This C++ solution is efficient and solves the 2 sum problem optimally using a hash map.