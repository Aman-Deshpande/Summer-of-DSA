// Remove Nth Node From End of List

// Problem Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEndApproach1(ListNode *head, int n)
    {
        int length = 0;
        ListNode *ptr = head;

        while (ptr != NULL)
        {
            ptr = ptr->next;
            length++;
        }

        if (length == n)
        {
            ListNode *node = head;
            return node->next;
        }

        int c = length - n;
        ptr = head;

        for (int i = 1; i < c; i++)
        {
            ptr = ptr->next;
        }

        ListNode *temp = ptr->next;
        ptr->next = ptr->next->next;
        delete (temp);

        return head;
    }

    
    ListNode *removeNthFromEndApproach2(ListNode *head, int n)
    {
        ListNode *start = new ListNode();
        start->next = head;

        ListNode *fast = start;
        ListNode *slow = start;

        for (int i = 1; i <= n; ++i)
            fast = fast->next;

        while (fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return start->next;
    }
};