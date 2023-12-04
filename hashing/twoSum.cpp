#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); i++)
        {
            int req = target - nums[i];
            if (seen.count(req))
            {
                return {i, seen[req]};
            }
            seen[nums[i]] = i;
        }
        return {};
    }
};