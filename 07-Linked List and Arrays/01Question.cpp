// Rotate List

// Problem Link: https://leetcode.com/problems/rotate-list/

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
    ListNode *rotateRightApproach1(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL)
            return head;
        for (int i = 0; i < k; i++)
        {
            ListNode *temp = head;
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }

            ListNode *end = temp->next;
            temp->next = NULL;
            end->next = head;
            head = end;
        }
        return head;
    }

    ListNode *rotateRightApproach2(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL || k == 0)
            return head;

        // calculating length
        ListNode *temp = head;
        int length = 1;
        while (temp->next != NULL)
        {
            ++length;
            temp = temp->next;
        }

        // link last node to first node
        temp->next = head;

        k = k % length;       // when k is more than length of list
        int end = length - k; // to get end of the list

        while (end--)
        {
            temp = temp->next;
        }
        // breaking last node link and pointing to NULL
        head = temp->next;
        temp->next = NULL;

        return head;
    }
};