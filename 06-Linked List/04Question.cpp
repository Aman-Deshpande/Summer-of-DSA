// Palindrome List Cycle

// Problem Link: https://leetcode.com/problems/palindrome-linked-list/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        // tc: O(n), sc:O(1)
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // now slow points at the middle, do reverse the list from middle to end
        ListNode *prev = NULL;
        ListNode *curr = slow;
        while (curr != NULL)
        {
            ListNode *forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        // the list is now reverse and looks like:
        // 1->2<-2<-1
        ListNode *start = head;
        ListNode *end = prev;

        while (start != NULL)
        {
            if (start->val != end->val)
            {
                return false;
            }
            start = start->next;
            end = end->next;
        }
        return true;
    }
};