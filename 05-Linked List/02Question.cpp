// Middle of the Linked List

// Problem Link: https://leetcode.com/problems/middle-of-the-linked-list/

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
    // TC: O(N)
    ListNode *middleNodeApproach1(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *ptr = head;
        int length = 0;
        while (ptr->next != NULL)
        {
            length++;
            ptr = ptr->next;
        }

        int newHeadIdx;
        if (length % 2 == 0)
        {
            newHeadIdx = length / 2;
        }
        else
        {
            newHeadIdx = length / 2 + 1;
        }

        length = 0;
        ptr = head;
        while (length != newHeadIdx)
        {
            ptr = ptr->next;
            length++;
        }

        return ptr;
    }

    // TC: O(Length of LL)
    ListNode *middleNodeApproach1(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *fast = head;
        ListNode *slow = head;

        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
};