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
   int pathSumfromRoot(TreeNode* root, long int targetSum) {
    int count = 0;
    if(root->val == targetSum) 
        count++;
    if(root->left) {
        count += pathSumFromRoot(root->left, targetSum-root->val);
    }
    if(root->right) {
        count += pathSumfromRoot(root->right, targetSum-root->val);
    }
    return count;
   }

   int pathSum(TreeNode* root, int targetSum) {
    if(!root)
        return 0;
    int count = pathSumfromRoot(root, targetSum);
    count += pathSum(root->left, targetSum);
    count += pathSum(root->right, targetSum);
    return count;
   }
};