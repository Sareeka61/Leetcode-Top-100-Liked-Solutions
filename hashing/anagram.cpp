// create  a hashmap of vector of strings
// iterate through the vector of strings
// for the key, sort the current string and push in the map
// after iterating the vector, convert keys to vector
// return vector 


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector <string>> groups;

        for(string &s: strs) {
            string temp = s;
        
            sort(s.begin(), s.end());

            groups[s].push_back(temp);
        }

        vector<vector<string>> result;

        for(auto &group : groups)
            result.push_back(group.second);

            return result;
    }
};