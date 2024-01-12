// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

// Example 1:

// Input: nums = [3,2,3]
// Output: 3

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int answer = 0;
        int count = 0;

        for(auto num:nums) {
            if(count == 0) {
                answer = num;
            }
            if(num == answer) {
                count++;
            }
            else {
                count--;
            }
        }
        return answer;
    }
};