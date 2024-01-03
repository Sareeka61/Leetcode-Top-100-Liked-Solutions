// Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

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

    void kthsmallestHelper(TreeNode* root, vector<int> &result, int k) {
        if(!root || result.size()>k)
        return;

        kthsmallestHelper(root->left, result, k);
        if(result.size()<k)
            result.push_back(root->val);
        kthsmallestHelper(root->right, result, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> result;
        kthsmallestHelper(root, result, k);
        return result.back();    
    }
};