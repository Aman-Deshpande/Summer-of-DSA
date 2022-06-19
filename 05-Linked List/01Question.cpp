// Reverse Linked List

// Problem Link: https://leetcode.com/problems/reverse-linked-list/

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

private:
    void reverseLL(ListNode *&prev, ListNode *&curr)
    {
        if (curr == NULL)
        {
            return;
        }

        ListNode *forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;

        reverseLL(prev, curr);
    }

public:
    // TC:O(N) SC:O(1)
    ListNode *reverseListApproach1(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *prev = NULL;
        ListNode *curr = head;

        while (curr != NULL)
        {
            ListNode *forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        return prev;
    }

    // TC:O(N) SC:O(N)
    ListNode *reverseListApproach2(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *prev = NULL;
        ListNode *curr = head;

        reverseLL(prev, curr);

        return prev;
    }
};