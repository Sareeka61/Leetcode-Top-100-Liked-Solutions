// Given the root of a binary tree, flatten the tree into a "linked list":

// The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
// The "linked list" should be in the same order as a pre-order traversal of the binary tree.

// Input: root = [1,2,5,3,4,null,6]
// Output: [1,null,2,null,3,null,4,null,5,null,6]

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
    void flatten(TreeNode* root) {
        if(!root) {
            return;
        }
        
        stack <TreeNode*> s;
        s.push(root);

        while(!s.empty()) {
            TreeNode* current = s.top();
            s.pop();

            if(current->right) {
                s.push(current->right);
            }
            if(current->left) {
                s.push(current->left);
            }

            if(!s.empty()) {
                current->right = s.top();
               }
               current->left = nullptr;
        }
    }
};
