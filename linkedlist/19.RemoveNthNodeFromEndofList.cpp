// Given the head of a linked list, remove the nth node from the end of the list and return its head.

// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <bits/stdc++.h>
#include "/leetcode/precompiled/ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* left = dummy;
        ListNode* right = dummy;

        for (int i = 0; i <= n; i++) {
            if (right == NULL) {
                return head;
            }
            right = right->next;
        }

        while (right != NULL) {
            left = left->next;
            right = right->next;
        }

        left->next = left->next->next;

        return dummy->next;
    }
};
