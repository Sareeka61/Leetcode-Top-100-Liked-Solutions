// Given the root of a binary tree, return the length of the diameter of the tree.

// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

// The length of a path between two nodes is represented by the number of edges between them.

// Input: root = [1,2,3,4,5]
// Output: 3
// Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

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
    int diameterOfBinaryTree(TreeNode* root) {
        int maximum = 0;
        int answer = forLongestPath(root->left, maximum) + forLongestPath(root->right, maximum);
        return max(maximum, answer);
    }

private:
    int forLongestPath(TreeNode* root, int &maximum) {
        if(root == NULL) 
            return 0;

        int left = forLongestPath(root->left, maximum);
        int right = forLongestPath(root->right, maximum);
        maximum = max(maximum, left+right);
        return 1+max(left, right);
    }
};