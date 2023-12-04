// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

// Example 1:
// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of /each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int maxArea = 0;
        stack<pair<int, int>> stac;
        int nums = heights.size();

        for (int i = 0; i < nums; i++)
        {
            int start = i;
            while(!stac.empty() && stac.top().second > heights[i]) {
                int index = stac.top().first;
                int width = i - index;
                int height = stac.top().second;
                stac.pop();
                maxArea = max(maxArea, height * width);
                start = index;
            }
            stac.push({start, heights[i]});
        }

        while(!stac.empty()) {
            int width = nums - stac.top().first;
            int height = stac.top().second;
            stac.pop();
            maxArea = max(maxArea, height * width);
        }
        return maxArea;
    }
};