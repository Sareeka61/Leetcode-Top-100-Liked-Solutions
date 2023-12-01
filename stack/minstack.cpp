#include <bits/stdc++.h>
using namespace std;

class MinStack
{
public:
    struct node
    {
        int data;
        int minVal;
        node *next;
    };

    typedef struct node nd;
    node *head = NULL;

    MinStack() {
    }

    void push(int val)
    {
        node *newnode = new node;
        newnode->data = val;

        if (head == NULL)
        {
            newnode->minVal = val;
            newnode->next = NULL;
        }
        else
        {
            newnode->minVal = min(val, head->minVal);
            newnode->next = head;
        }
            head = newnode;
    }

    void pop()
    {
        if (head != NULL) {
            node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    int top()
    {
        if(head != NULL) {
        return head->data;
        }
        return -1;
    }

    int getMin()
    {
        if(head != NULL) {
            return head->minVal;
        }
        return -1;
    }
};