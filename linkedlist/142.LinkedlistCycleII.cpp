// Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

// Do not modify the linked list.

// Input: head = [3,2,0,-4], pos = 1
// Output: tail connects to node index 1
// Explanation: There is a cycle in the linked list, where tail connects to the second node.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <bits/stdc++.h>
#include "/leetcode/precompiled/ListNode.h"
using namespace std;

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fastpointer = head;
        ListNode* slowpointer = head;

        if(head == NULL || head->next == NULL) {
            return NULL;
        }

        while (slowpointer != NULL && fastpointer != NULL && fastpointer->next != NULL) {
            slowpointer = slowpointer->next;
            fastpointer = fastpointer->next->next;

            if(slowpointer == fastpointer)
                break;
        
        }

        if(slowpointer != fastpointer) {
            return NULL;
        }

        slowpointer = head;
        
        while(slowpointer != fastpointer) {
            slowpointer = slowpointer->next;
            fastpointer = fastpointer->next;
        }

        return slowpointer;
    }
};