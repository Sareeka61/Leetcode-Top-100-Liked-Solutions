// Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

// The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

// Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
// Output: 3
// Explanation: The paths that sum to 8 are shown.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
       if(!root)
        return 0;

        long long pathsFromRoot = countPaths(root, targetSum);

        long long pathsFromLeft = pathSum(root->left, targetSum);
        long long pathsFromRight = pathSum(root->right, targetSum);

        return static_cast<int>(pathsFromRoot + pathsFromLeft + pathsFromRight); 
    }

private:
    long long countPaths(TreeNode* node, int targetSum) {
        if(!node) {
            return 0;
        }

        long long paths = 0;

        if(node->val == targetSum) {
            paths++;
        }

        paths += countPaths(node->left, targetSum - node->val);
        paths += countPaths(node->right, targetSum - node->val);

        return paths;
    }
};