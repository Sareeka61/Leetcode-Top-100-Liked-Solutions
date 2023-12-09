// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.

// Example: Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]

// Default comment provided: 
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };

#include <bits/stdc++.h>
#include "/leetcode/precompiled/ListNode.h"

using namespace std;

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *current = dummy;

        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val < list2->val)
            {
                current->next = list1;
                list1 = list1->next;
            }
            else
            {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        if (list1 != nullptr)
        {
            current->next = list1;
        }

        if (list2 != nullptr)
        {
            current->next = list2;
        }

        return dummy->next;
    }
};
