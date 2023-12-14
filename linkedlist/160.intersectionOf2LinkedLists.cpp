// Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

// Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
// Output: Intersected at '8'

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       ListNode *tempA = headA;
        ListNode *tempB = headB;

        while (tempA->next != nullptr) {
            tempA = tempA->next;
        }

        while (tempB->next != nullptr) {
            tempB = tempB->next;
        }

        if (tempA != tempB) {
            return nullptr;
        }

        int lenA = 0, lenB = 0;
        tempA = headA;
        tempB = headB;

        while (tempA != nullptr) {
            lenA++;
            tempA = tempA->next;
        }

        while (tempB != nullptr) {
            lenB++;
            tempB = tempB->next;
        }

        while (lenA > lenB) {
            headA = headA->next;
            lenA--;
        }

        while (lenB > lenA) {
            headB = headB->next;
            lenB--;
        }

        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
};

