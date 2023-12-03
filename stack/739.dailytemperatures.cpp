// Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

// Constraints:

// 1 <= temperatures.length <= 105
// 30 <= temperatures[i] <= 100

// Intuition: Take a stack to store indices of array and take a vector to store the result. If the current temperature on the top of stack is less or equal to the new temperature, push the indices of new temperature to the stack. If it is greater then pop the index of temperature out of the stack and calculate the difference of the current index and popped index. Store it in the vector and push new index to the stack and continue.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {

        int nums = temperatures.size();
        vector<int> ans(nums, 0);
        stack<int> stac;
        stac.push(0);

        int i = 1;
        while (i < nums)
        {
            if (!stac.empty() && temperatures[i] <= temperatures[stac.top()])
            {
                stac.push(i);
            }
            else
            {
                while (!stac.empty() && temperatures[i] > temperatures[stac.top()])
                {
                    ans[stac.top()] = i - stac.top();
                    stac.pop();
                }
                stac.push(i);
            }
            i++;
        }
        return ans;
    }
};