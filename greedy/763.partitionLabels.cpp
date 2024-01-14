// You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

// Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

// Return a list of integers representing the size of these parts.

 

// Example 1:

// Input: s = "ababcbacadefegdehijhklij"
// Output: [9,7,8]
// Explanation:
// The partition is "ababcbaca", "defegde", "hijhklij".
// This is a partition so that each letter appears in at most one part.
// A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int>maxp;
        for(int i = 0; i< s.size(); i++) {
            char ch = s[i];
            maxp[ch] = i;
        }

        vector<int> result;
        int previous = -1;
        int maxi = 0;

        for(int i=0; i<s.size(); i++) {
            maxi = max(maxi, maxp[s[i]]);
            if(maxi == i) {
                result.push_back(maxi - previous);
                previous = maxi;
            }
        }
        return result;
    }
};