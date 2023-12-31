// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

// Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// Output: [3,9,20,null,null,15,7]

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

class Solution
{
private:
    unordered_map<int, int> inorderIndex;

    TreeNode *buildTreeHelper(vector<int> &preorder, int preStart, int preEnd, int inStart, int inEnd)
    {
        if (preStart > preEnd || inStart > inEnd)
        {
            return nullptr;
        }

        int rootValue = preorder[preStart];
        TreeNode *root = new TreeNode(rootValue);

        int rootIndexInorder = inorderIndex[rootValue];
        int leftSubtreeSize = rootIndexInorder - inStart;

        root->left = buildTreeHelper(preorder, preStart + 1, preStart + leftSubtreeSize, inStart, rootIndexInorder - 1);
        root->right = buildTreeHelper(preorder, preStart + leftSubtreeSize + 1, preEnd, rootIndexInorder + 1, inEnd);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {

        int n = inorder.size();
        for (int i = 0; i < n; i++)
        {
            inorderIndex[inorder[i]] = i;
        }

        return buildTreeHelper(preorder, 0, n - 1, 0, n - 1);
    }
};