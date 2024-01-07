// Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

// Input: root = [1,2,3,null,5,null,4]
// Output: [1,3,4]

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
    void helper(TreeNode* root, int level, vector<int> &res) {
        if(root == NULL) 
            return;

        if(res.size() == level) {
            res.push_back(root->val);
        }
        helper(root->right, level+1, res);
        helper(root->left, level+1, res);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        helper(root, 0, res);
        return res;    
    }
};