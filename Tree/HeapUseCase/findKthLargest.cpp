#include <iostream>
#include <queue>
using namespace std;
int findKthLargest(vector<int> &, int);
int main()
{
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    int result = findKthLargest(nums, k);

    cout << "The " << k << "-th largest elements is: " << result << endl;
    return 0;
}

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int> maxHeap;

    for (int num : nums)
    {
        maxHeap.push(num);
    }

    for (int i = 1; i < k; i++)
    {
        maxHeap.pop();
    }

    return maxHeap.top();
}