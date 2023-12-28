// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if(root==NULL) {
            return result;
        }

        queue <TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int level = q.size();
            vector<int> res;

            for(int i=0; i<level; i++) {
                TreeNode* front = q.front();
                q.pop();
                res.push_back(front->val);

                if(front->left != nullptr) {
                    q.push(front->left);
                }

                if(front->right != nullptr) {
                    q.push(front->right);
                }
            }

            result.push_back(res);
        }
        return result;
    }
};