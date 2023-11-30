#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<string> uniqueCharacters;
        string temp = s;
        sort(s.begin(), s.end());
        uniqueCharacters{s}.push_back(temp);
    }
    return count.temp();
};