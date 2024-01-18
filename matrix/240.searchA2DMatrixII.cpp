// Write an efficient algorithm that searches for a value target in an m x n integer matrix. This matrix has the following properties:

// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.

// Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
// Output: true

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int start = 0;
        int end = n - 1;

        while (start < m && end >= 0)
        {
            if (matrix[start][end] == target)
            {
                return true;
            }

            if (target > matrix[start][end])
            {
                start++;
            }
            else
            {
                end--;
            }
        }
        return false;
    }
};