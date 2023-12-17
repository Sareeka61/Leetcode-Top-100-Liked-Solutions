// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

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

        ListNode* reverse(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* current = head;

        while (current) {
            ListNode* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, *fast = head, *temp = head;

        while(fast) {
            slow = slow->next;
            fast = fast->next;

            if (fast) {
                fast = fast->next;
            }
        }
            slow = reverse(slow);
        
        while(slow) {
            if(temp->val != slow->val) 
            return false;

            temp = temp->next;
            slow = slow->next;
        }
        return true;
    }
};