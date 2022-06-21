// Linked List Cycle

// Problem Link: https://leetcode.com/problems/linked-list-cycle/

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
    // TC:O(N) SC:O(N)
    bool hasCycleApproach1(ListNode *head)
    {
        unordered_set<ListNode *> hashTable;
        ListNode *ptr1 = head;

        while (ptr1 != NULL)
        {
            if (hashTable.find(ptr1) != hashTable.end())
            {
                return true;
            }
            hashTable.insert(ptr1);
            ptr1 = ptr1->next;
        }
        return false;
    }

    // TC: O(N) SC: O(1)
    bool hasCycleApproach2(ListNode *head)
    {
        if(head == NULL) return false;
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) return true;
        }
        return false;
    }
};