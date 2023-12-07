// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int result = 0;
        sort(nums.begin(), nums.end());
        set <vector<int>> numbers;
        vector<vector<int>> output;

        for (int i=0; i<nums.size(); i++) {
            int j = i+1;
            int k = nums.size() - 1;
            while(j < k) {
                if(nums[i] + nums[j] + nums[k] == result) {
                    numbers.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } else if(nums[i] + nums[j] + nums[k] < result) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        for (auto triplets : numbers) {
            output.push_back(triplets);
        }
        return output;
    }
};