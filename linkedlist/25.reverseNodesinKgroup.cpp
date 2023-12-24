// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.

// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]

// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

// Input: root = [1,2,2,3,4,4,3]
// Output: true

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) {
            return head;
        }

        int count = 0;

        ListNode* current = head;
        while(current != nullptr && count < k) {
            current = current ->next;
            count++;
        }

        if(count == k) {
            ListNode* reversedHead = reverseList(head, k);
            head->next = reverseKGroup(current, k);
            return reversedHead;
        } else {
            return head;
        }
    }

    private:
        ListNode* reverseList(ListNode* head, int k) {
            ListNode* prev = nullptr;
            ListNode* current = head;
            ListNode* next = nullptr;

            while(k>0 && current != nullptr) {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
                k--;
            }
            return prev;
        }
};