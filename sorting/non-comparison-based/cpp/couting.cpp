#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void countingSort(vector<int> &arr)
{

    if (arr.empty())
        return;

    int maxElem = *max_element(arr.begin(), arr.end());
    int minElem = *min_element(arr.begin(), arr.end());

    int range = maxElem - minElem + 1;

    vector<int> count(range, 0);

    for (int i = 0; i < arr.size(); i++)
    {
        count[arr[i] - minElem]++;
    }

    for (int i = 1; i < range; i++)
    {
        count[i] += count[i - 1];
    }

    vector<int> output(arr.size());

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        output[count[arr[i] - minElem] - 1] = arr[i];
        count[arr[i] - minElem]--;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = output[i];
    }
}

void printArray(const vector<int> &arr)
{
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    cout << "Original Array: ";
    printArray(arr);

    countingSort(arr);
    cout << "Sorted Array: ";
    printArray(arr);
    return 0;
}