// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int lpos = 1;
        int rpos = n - 2;
        int left_max = height[0];
        int right_max = height[n - 1];
        int trapped_water = 0;

        while (lpos <= rpos)
        {
            if (height[lpos] > left_max)
            {
                left_max = height[lpos];
            }

            if (height[rpos] > right_max)
            {
                right_max = height[rpos];
            }

            if (left_max <= right_max)
            {
                trapped_water += max(0, left_max - height[lpos]);
                lpos++;
            }
            else
            {
                trapped_water += max(0, right_max - height[rpos]);
                rpos--;
            }
        }
        return trapped_water;
    }
};
