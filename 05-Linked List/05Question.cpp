// Add Two Numbers

// Problem Link: https://leetcode.com/problems/add-two-numbers/

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int sum, carry = 0, d1, d2;
        ListNode *head = nullptr, *tail = nullptr;

        while (l1 && l2)
        {
            d1 = l1->val;
            d2 = l2->val;

            sum = d1 + d2 + carry;
            carry = sum / 10;
            sum = sum % 10;

            if (!tail)
            {
                head = new ListNode(sum);
                tail = head;
            }
            else
            {
                tail->next = new ListNode(sum);
                tail = tail->next;
            }

            l1 = l1->next;
            l2 = l2->next;
        }

        l1 = (l1) ? l1 : l2;

        while (carry && l1)
        {
            sum = l1->val + carry;
            carry = sum / 10;
            sum = sum % 10;

            tail->next = new ListNode(sum);
            tail = tail->next;
            l1 = l1->next;
        }

        if (l1)
            tail->next = l1;

        if (carry)
        {
            tail->next = new ListNode(carry);
        }

        return head;
    }
};
