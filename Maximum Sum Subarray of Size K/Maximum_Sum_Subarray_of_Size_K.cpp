#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int maxSumSubarray(const vector<int> &arr, int k)
{
    int n = arr.size();
    if (n == 0)
    {

        cout << "Array is empty." << endl;
    }
    if (k <= 0)
    {
        cout << "Subarray size k must be positive." << endl;
    }
    if (n < k)
    {
        cout << "Array size is smaller than K" << endl;
        return -1;
    }

    int window_sum = 0;
    for (int i = 0; i < k; i++)
    {
        window_sum += arr[i];
    }

    int max_sum = window_sum;

    for (int i = k; i < n; ++i)
    {
        window_sum += arr[i] - arr[i - k];
        max_sum = max(max_sum, window_sum);
    }

    return max_sum;
}

int main()
{
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;
    int result = maxSumSubarray(arr, k);

    cout << "K = " << k << "Result = " << result << endl;

    // Test Case 2: Edge case - Array is empty
    vector<int> arr2 = {};
    int K2 = 3;

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