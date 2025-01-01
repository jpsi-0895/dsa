#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
vector<int> twosum(const vector<int> &nums, int target)
{
    unordered_map<int, int> num_map;
    vector<int> result;

    for (int i = 0; i < nums.size(); i++)
    {
        int comp = target - nums[i];

        if (num_map.find(comp) != num_map.end())
        {
            result.push_back(num_map[comp]); // complement index
            result.push_back(i);             // current element index
            return result;
        }

        num_map[nums[i]] = i;
    }

    return result;
}

int main()
{
    vector<int> nums = {2,
                        7,
                        11,
                        15,
                        3,
                        6};

    int target = 9;

    vector<int> result = twosum(nums, target);

    if (!result.empty())
    {
        cout << "Indices of the two number sum to target: " << target << endl;
        cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    }

    return 0;
}