// Given an integer numRows, return the first numRows of Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;

        for(int i = 0; i < numRows; i++) {
            result.push_back(vector<int>(i+1, 1));
        }

        for(int i=2; i<numRows; i++) {
            for(int j = 1; j<result[i].size()-1; j++){
                result[i][j] = result[i-1][j-1] + result[i-1][j];
            }
        }
        return result;
    }
};