// Merge Two Sorted Lists

// Problem Link: https://leetcode.com/problems/merge-two-sorted-lists/

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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr && list2 == nullptr)
            return nullptr;
        else if (list1 == nullptr)
            return list2;
        else if (list2 == nullptr)
            return list1;
        else
        {
            ListNode *temp1 = list1;
            ListNode *temp2 = list2;
            ListNode *head = nullptr;
            ListNode *t = nullptr;
            while (temp1 && temp2)
            {
                if (temp1->val < temp2->val)
                {
                    if (head == nullptr)
                    {
                        ListNode *temp = new ListNode(temp1->val);
                        head = temp;
                        t = temp;
                    }
                    else
                    {
                        ListNode *temp = new ListNode(temp1->val);
                        t->next = temp;
                        t = temp;
                    }
                    temp1 = temp1->next;
                }
                else
                {
                    if (head == nullptr)
                    {
                        ListNode *temp = new ListNode(temp2->val);
                        head = temp;
                        t = temp;
                    }
                    else
                    {
                        ListNode *temp = new ListNode(temp2->val);
                        t->next = temp;
                        t = temp;
                    }
                    temp2 = temp2->next;
                }
            }

            while (temp1 != nullptr)
            {
                ListNode *temp = new ListNode(temp1->val);
                t->next = temp;
                t = temp;
                temp1 = temp1->next;
            }

            while (temp2 != nullptr)
            {
                ListNode *temp = new ListNode(temp2->val);
                t->next = temp;
                t = temp;
                temp2 = temp2->next;
            }
            return head;
        }
    }
};